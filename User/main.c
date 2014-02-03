/****************************************************/
//    在此DEMO中加入USART1/USART2的输出与GPIOE接口的1
//个状态灯的定义,并且打开了FPU，加入了ARM_MATH.H
//数学运算头文件；系统时钟来源为HSE 25MHz，系统主
//频定义为最快速度168MHz.
/****************************************************/
 
#include "MyF4Config.h"
#include "dcmi_ov7620.h"  
#include "Sensor.h"   
#include "Camera_api.h"  
#include "5110.h"  
#include "PID.h"  
#include "MotorCtl.h"  
#include "key.h"
#include "wifi.h"


u8 rev_buf[1000];
u8 rev_flag=0;
uint8_t rev_cnt=0;

char frame_flag=0;
char MY_image[102400];
int i=0,y=0;




void communication_checkEvent(u8 *buf);




u32 find_length(u8 *image)
{
	long b;
	u32 a;
	b = DMA_GetCurrDataCounter(DMA2_Stream1);
	for(a=(25400-b)*4+10;a<(25600-b)*4+10;a++)
	{
		if(MY_image[a] == 0xff && MY_image[a+1] == 0xd9)
			return a+1;
	}
	return 0;	
}
void send_jpg()
{
	long a,b=20;
	if(frame_flag == 1)
	{
		
		frame_flag = 0;		
		if(i == 2)
		{
			write_count(4,4,DMA_GetCurrDataCounter(DMA2_Stream1));
			for(a=0;a<(25600-DMA_GetCurrDataCounter(DMA2_Stream1))*4+10;a++)
			{
				//USART_printf(USART3, "%c",MY_image[i]);			
				//printf("%c",MY_image[i]);		
				USART_SendData(USART3, MY_image[a]);
				while( USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET );
				if(MY_image[a] == 0xff)
				{
					if(MY_image[a+1] == 0xD9)
					{
						USART_SendData(USART3, MY_image[a+1]);
						while( USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET );
						break;
					}
				}
			}
		}
		DMA_Cmd(DMA2_Stream1, DISABLE);
	  DMA_SetCurrDataCounter(DMA2_Stream1,25600);
		DMA_Cmd(DMA2_Stream1, ENABLE); 
	  DCMI_CaptureCmd(ENABLE); 	
	//	OV_qvga(&(MY_image[0]));	
	}
}

void control_gear(float yangjiao,float zhuanjiao)  //输入0-255 稳定133
{
	if(yangjiao<=130)
	{
		yangjiao = 6.375 + yangjiao*(0.071);  //15.825        //24.375
	}
	else
	{
		yangjiao = 15.825 + (yangjiao-133)*(0.070);
	}
	if(zhuanjiao<=130) //90
	{
		zhuanjiao = 6.375 + zhuanjiao*(0.048);
	}
	else //160
	{
		zhuanjiao = 12.765 + (zhuanjiao-133)*(0.025);
	}
	TIM_SetCompare3(TIM3,13125*(yangjiao/255));
	TIM_SetCompare4(TIM3,13125*(zhuanjiao/255));
}

void control_direction(char turn)  //1上 2下 3左 4右 5结束
{
	static u8 d_count;
	static u8 h_count;
	switch(turn){
		case 1:
		MotorCtl(9800,0);
		break;
		case 2:
		MotorCtl(-9500,200);  //9200
		break;
		case 3:
		MotorCtl(7000,2000); // 9000 5000 
		break;
		case 4:
		MotorCtl(7000,-2000);
		break;
		default:
		MotorCtl(0,0);
		break;
	}
		
}


void put_image()
{
	u32 length=0;

			if(frame_flag == 1)
			{
				frame_flag = 0;	
				length = find_length(MY_image);		
				//write_count(3,3,MY_image[length]);	
	//		write_count(4,4,data);
				//write_count(2,2,length);	
				if(length > 1000 )
				{
					send_image(MY_image,length+1);

				}
				DMA_Cmd(DMA2_Stream1, DISABLE);
				DMA_SetCurrDataCounter(DMA2_Stream1,25600);
				DMA_Cmd(DMA2_Stream1, ENABLE); 
				DCMI_CaptureCmd(ENABLE); 
				}	
}







int main(void)
{ 
	int ov_id;
	RCC_Config();       //系统时钟配置
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	delay_init();
	MotorInit();	
	NVIC_Configuration();
	//SensorInit();
 	LCD_init();	
	LCD_clear();
	TIM3_PWM_Init();  //舵机初始化
	SCCB_Init();
	
	control_gear(133,133) ;
	ov_id=OV_Jpeg();
	//OV2640_AutoExposure(2);
  //OV2640_BrightnessConfig(0x30);
	//OV_Reset();
  OV_qvga(&(MY_image[0]));	
	control_direction(1) ;
	USART_Config();     //USART端口配置
	USART_printf(USART3, "1");
	DCMI_JPEGCmd(ENABLE);
	MotorCtl(0,0);
	wifi_Init();	
	while(1)
	{			
		communication_checkEvent(rev_buf); //检查
		delay_ms(10);		
	}
}


void communication_checkEvent(u8 *buf)
{
	u16 length;
		static u32 count2=0;
	static int zhuanjiao=133,yangjiao=133;
	length = buf[2] | buf[3] << 8;
	if( rev_flag == 0 &&  buf[1] == 0x0c) //这是合格的自定义命令包buf[10] == 0x55  &&  buf[1] == 0x0c && length == 11 &&
	{
		control_direction(buf[5]);
		switch(buf[6])
		{
		case 1:
			yangjiao-=20;
			break;
		case 2:
			yangjiao+=20;
			break;
		}
		switch(buf[7])
		{
		case 1:
			zhuanjiao+=20;
			break;
		case 2:
			zhuanjiao-=20;
			break;
		}	
		if(zhuanjiao > 255)
			zhuanjiao = 255;
		if(yangjiao > 255)
			yangjiao = 255;
		if(zhuanjiao < 0)
			zhuanjiao = 0;
		if(yangjiao < 0)
			yangjiao = 0;
		control_gear(zhuanjiao,yangjiao);	
			put_image();	
		write_count(3,3,buf[5]);	
		write_count(4,4,count2);
		count2++;
	}
	rev_flag = 1;
}


void USART3_IRQHandler(void)
{
		uint8_t data;	
		static u16 pkg_len=0;
    if(USART_GetFlagStatus(USART3,USART_FLAG_RXNE) == SET)
    {
			USART_ClearFlag(USART3,USART_FLAG_RXNE);
			
			
			
			data = (uint8_t)USART_ReceiveData(USART3);
			if(rev_flag)
			{
				rev_buf[rev_cnt++] = data ;		//放入缓冲 			
				if((rev_cnt > (pkg_len - 1) && rev_cnt > 4) || rev_buf[0]!=0xaa || rev_cnt > 50 ) //终止 
				{
					rev_cnt = 0; 
					rev_flag =0;
				}
				else if(rev_cnt == 4)
					pkg_len = rev_buf[2] | ( rev_buf[3]<<8 ) ;		
			}	
			else 
				rev_cnt = 0;		
    }
}



void DCMI_IRQHandler(void)
{  	
  if (DCMI_GetITStatus(DCMI_IT_FRAME) != RESET) //?????
	{
		frame_flag=1;
		i++;
		DCMI_ClearITPendingBit(DCMI_IT_FRAME); 	
	}
}
