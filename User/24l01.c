#include "24l01.h"



//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//NRF24L01驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/13
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
    
const u8 TX_ADDRESS[TX_ADR_WIDTH]={0x34,0x43,0x10,0x10,0x01}; //发送地址
const u8 RX_ADDRESS[RX_ADR_WIDTH]={0x34,0x43,0x10,0x10,0x01}; //发送地址



u8 SPI3_ReadWriteByte(u8 TxData);

void SPI3_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
  	SPI_InitTypeDef  SPI_InitStructure; 
	
	GPIO_StructInit(&GPIO_InitStructure);
	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 ;
	//	GPIO_Init(GPIOC, &GPIO_InitStructure);
		
		GPIO_PinAFConfig(GPIOC, GPIO_Pin_10, GPIO_AF_SPI3);
  GPIO_PinAFConfig(GPIOC, GPIO_Pin_11, GPIO_AF_SPI3);
  GPIO_PinAFConfig(GPIOC, GPIO_Pin_12, GPIO_AF_SPI3); 
	  


	
	SPI_Cmd(SPI3, DISABLE); // SPI外设不使能
	SPI_I2S_DeInit(SPI3);
	
	
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3 , ENABLE); 
		
		
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //SPI设置为双线双向全双工
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//SPI主机
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//发送接收8位帧结构
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;		//时钟悬空低
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;	//数据捕获于第1个时钟沿
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS信号由软件控制
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;		//定义波特率预分频的值:波特率预分频值为16
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//数据传输从MSB位开始
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRC值计算的多项式
	SPI_Init(SPI3, &SPI_InitStructure);  //根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器
 
	SPI_Cmd(SPI3, ENABLE); //使能SPI外设
		SPI3_ReadWriteByte(0xff); 

}  

//初始化24L01的IO口
void NRF24L01_Init()
{ 	
GPIO_InitTypeDef GPIO_InitStructure;
//ce
	             //设置选中的引脚工作模为输出模式
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;            //设置GPIO的输出方式PP推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	//PA4 推挽 	  
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化指定IO
  
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;   
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;             //设置选中的引脚工作模为输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //设置GPIO的输出方式PP推挽输出	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0; 	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);							 
		 


 //SPI3_Init();
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3  | GPIO_Pin_5;  
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;  
	GPIO_InitStructure.GPIO_Pin =    GPIO_Pin_4;
  GPIO_Init(GPIOB, &GPIO_InitStructure); 




	NRF24L01_CE=0; 			//使能24L01
	NRF24L01_CSN=1;			//SPI片选取消  
	 		 	 
}
//检测24L01是否存在
//返回值:0，成功;1，失败	
void SPI3_SetSpeed(u8 SPI_BaudRatePrescaler)
{
  //	assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
	//SPI3->CR1&=0XFFC7;
	//SPI3->CR1|=SPI_BaudRatePrescaler;	//设置SPI3速度 
	//SPI_Cmd(SPI3,ENABLE); 
} 

//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
u8 SPI3_ReadWriteByte(u8 TxData)
{		
	/*u32 retry=0;				 	
	while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE) == RESET) //检查指定的SPI标志位设置与否:发送缓存空标志位
		{
		retry++;
		if(retry>20000)return 0;
		}			  
	SPI_I2S_SendData(SPI3, TxData); //通过外设SPIx发送一个数据
	retry=0;

	while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE) == RESET)//检查指定的SPI标志位设置与否:接受缓存非空标志位
		{
		retry++;
		if(retry>20000)return 0;
		}	  						    
	return SPI_I2S_ReceiveData(SPI3); //返回通过SPIx最近接收的数据			*/ 		  
	
	 unsigned char i,spi_dat;  

   for (i=0;i<8;i++)  
 {                                  
	  
if((TxData & 0x80)==0x80)PBout(5)=1;  
  else PBout(5)=0;   
	 TxData =(TxData<<1);
	 spi_dat=(spi_dat<<1); 
	 GPIO_ResetBits(GPIOB,GPIO_Pin_3);
		GPIO_SetBits(GPIOB,GPIO_Pin_3); 
	
 }  
 return 0;
}




u8 SPI_RW(u8 byte)
{
	u8 bit_ctr;
   	for(bit_ctr=0;bit_ctr<8;bit_ctr++) // output 8-bit
   	{
		if(byte & 0x80)
				GPIO_SetBits(GPIOB,GPIO_Pin_5);
		else
				GPIO_ResetBits(GPIOB,GPIO_Pin_5);// output 'byte', MSB to MOSI
		byte = (byte << 1);           // shift next bit into MSB..
		GPIO_SetBits(GPIOB,GPIO_Pin_3);                     // Set SCK high..
		byte |= GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4);       		  // capture current MISO bit
		GPIO_ResetBits(GPIOB,GPIO_Pin_3);            		  // ..then set SCK low again
   	}
    return(byte);           		  // return read byte
}




u8 spi_write(u8 TxData)
{
	 unsigned char i;  

   for (i=0;i<8;i++)  
 {                                  
	  
if(TxData & 0x80)PBout(5)=1;  
  else PBout(5)=0;   
	 TxData =(TxData<<1);
	 GPIO_ResetBits(GPIOB,GPIO_Pin_3);
		GPIO_SetBits(GPIOB,GPIO_Pin_3); 
	
 }  
 return 0;
}

u8 spi_read()
{	
	 u8 i,spi_dat=0;  

		for (i=0;i<8;i++)  
	{                                  
	  spi_dat <<=1;
		GPIO_SetBits(GPIOB,GPIO_Pin_3);
		GPIO_ResetBits(GPIOB,GPIO_Pin_3); 
	if(PBin(4)) spi_dat++;
 } 
 return spi_dat;
}





u8 NRF24L01_Check()
{
	u8 buf[5]={0XA5,0XA5,0XA5,0XA5,0XA5};
	u8 i;
	//SPI3_SetSpeed(SPI_BaudRatePrescaler_32); //spi速度为9Mhz（24L01的最大SPI时钟为10Mhz）   	 
	NRF24L01_Write_Buf(WRITE_REG_NRF+TX_ADDR,buf,5);//写入5个字节的地址.	
	NRF24L01_Read_Buf(TX_ADDR,buf,5); //读出写入的地址  
	for(i=0;i<5;i++){  if(buf[i]!=0XA5)break;	 				 }			   
	if(i!=5)return 1;//检测24L01错误	
	return 0;		 //检测到24L01
}	 	 
//SPI写寄存器
//reg:指定寄存器地址
//value:写入的值
u8 NRF24L01_Write_Reg(u8 reg,u8 value)
{
	u8 status;	
   	NRF24L01_CSN=0;                 //使能SPI传输
  	status =SPI_RW(reg);//发送寄存器号 
  	SPI_RW(value);      //写入寄存器的值
  	NRF24L01_CSN=1;                 //禁止SPI传输	   
  	return(status);       			//返回状态值
}
//读取SPI寄存器值
//reg:要读的寄存器
u8 NRF24L01_Read_Reg(u8 reg)
{
	u8 reg_val;	    
 	NRF24L01_CSN = 0;          //使能SPI传输		
  	SPI_RW(reg);   //发送寄存器号
  	reg_val=SPI_RW(0xff);//读取寄存器内容
  	NRF24L01_CSN = 1;          //禁止SPI传输		    
  	return(reg_val);           //返回状态值
}	
//在指定位置读出指定长度的数据
//reg:寄存器(位置)
//*pBuf:数据指针
//len:数据长度
//返回值,此次读到的状态寄存器值 
u8 NRF24L01_Read_Buf(u8 reg,u8 *pBuf,u8 len)
{
	u8 status,u8_ctr;	       
  	NRF24L01_CSN = 0;           //使能SPI传输
  	status=SPI_RW(reg);//发送寄存器值(位置),并读取状态值   	   

 	for(u8_ctr=0;u8_ctr<len;u8_ctr++)  {pBuf[u8_ctr]=SPI_RW(0xff); }//读出数据
	
  	NRF24L01_CSN=1;       //关闭SPI传输
  	return status;        //返回读到的状态值
}
//在指定位置写指定长度的数据
//reg:寄存器(位置)
//*pBuf:数据指针
//len:数据长度
//返回值,此次读到的状态寄存器值
u8 NRF24L01_Write_Buf(u8 reg, u8 *pBuf, u8 len)
{
	u8 status,u8_ctr;	    
 	NRF24L01_CSN = 0;          //使能SPI传输
  	status = SPI_RW(reg);//发送寄存器值(位置),并读取状态值
  	for(u8_ctr=0; u8_ctr<len; u8_ctr++){ SPI_RW(*pBuf++); } //写入数据	 
  	NRF24L01_CSN = 1;       //关闭SPI传输
  	return status;          //返回读到的状态值
}				   
//启动NRF24L01发送一次数据
//txbuf:待发送数据首地址
//返回值:发送完成状况
u8 NRF24L01_TxPacket(u8 *txbuf)
{
	u8 sta;
 	SPI3_SetSpeed(SPI_BaudRatePrescaler_8);//spi速度为9Mhz（24L01的最大SPI时钟为10Mhz）   
	NRF24L01_CE=0;
  	NRF24L01_Write_Buf(WR_TX_PLOAD,txbuf,TX_PLOAD_WIDTH);//写数据到TX BUF  32个字节
 	NRF24L01_CE=1;//启动发送	   
	while(NRF24L01_IRQ!=0);//等待发送完成
	sta=NRF24L01_Read_Reg(STATUS);  //读取状态寄存器的值	   
	NRF24L01_Write_Reg(WRITE_REG_NRF+STATUS,sta); //清除TX_DS或MAX_RT中断标志
	if(sta&MAX_TX)//达到最大重发次数
	{
		NRF24L01_Write_Reg(FLUSH_TX,0xff);//清除TX FIFO寄存器 
		return MAX_TX; 
	}
	if(sta&TX_OK)//发送完成
	{
		return TX_OK;
	}
	return 0xff;//其他原因发送失败
}
//启动NRF24L01发送一次数据
//txbuf:待发送数据首地址
//返回值:0，接收完成；其他，错误代码
u8 NRF24L01_RxPacket(u8 *rxbuf)
{
	u8 sta;		    							   
	SPI3_SetSpeed(SPI_BaudRatePrescaler_8); //spi速度为9Mhz（24L01的最大SPI时钟为10Mhz）   
	sta=NRF24L01_Read_Reg(STATUS);  //读取状态寄存器的值    	 
	NRF24L01_Write_Reg(WRITE_REG_NRF+STATUS,sta); //清除TX_DS或MAX_RT中断标志
	if(sta&RX_OK)//接收到数据
	{
		NRF24L01_Read_Buf(RD_RX_PLOAD,rxbuf,RX_PLOAD_WIDTH);//读取数据
		NRF24L01_Write_Reg(FLUSH_RX,0xff);//清除RX FIFO寄存器 
		return 0; 
	}	   
	return 1;//没收到任何数据
}					    
//该函数初始化NRF24L01到RX模式
//设置RX地址,写RX数据宽度,选择RF频道,波特率和LNA HCURR
//当CE变高后,即进入RX模式,并可以接收数据了		   
void NRF24L01_RX_Mode()
{
	NRF24L01_CE=0;	  
  	NRF24L01_Write_Buf(WRITE_REG_NRF+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH);//写RX节点地址
	  
  	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_AA,0x01);    //使能通道0的自动应答    
  	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_RXADDR,0x01);//使能通道0的接收地址  	 
  	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_CH,40);	     //设置RF通信频率		  
  	NRF24L01_Write_Reg(WRITE_REG_NRF+RX_PW_P0,RX_PLOAD_WIDTH);//选择通道0的有效数据宽度 	    
  	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_SETUP,0x0f);//设置TX发射参数,0db增益,2Mbps,低噪声增益开启   
  	NRF24L01_Write_Reg(WRITE_REG_NRF+CONFIG, 0x0f);//配置基本工作模式的参数;PWR_UP,EN_CRC,16BIT_CRC,接收模式 
  	NRF24L01_CE = 1; //CE为高,进入接收模式 
}						 
//该函数初始化NRF24L01到TX模式
//设置TX地址,写TX数据宽度,设置RX自动应答的地址,填充TX发送数据,选择RF频道,波特率和LNA HCURR
//PWR_UP,CRC使能
//当CE变高后,即进入RX模式,并可以接收数据了		   
//CE为高大于10us,则启动发送.	 
void NRF24L01_TX_Mode()
{														 
	NRF24L01_CE=0;	    
  	NRF24L01_Write_Buf(WRITE_REG_NRF+TX_ADDR,(u8*)TX_ADDRESS,TX_ADR_WIDTH);//写TX节点地址 
  	NRF24L01_Write_Buf(WRITE_REG_NRF+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH); //设置TX节点地址,主要为了使能ACK	  

  	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_AA,0x01);     //使能通道0的自动应答    
  	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_RXADDR,0x01); //使能通道0的接收地址  
  	NRF24L01_Write_Reg(WRITE_REG_NRF+SETUP_RETR,0x1a);//设置自动重发间隔时间:500us + 86us;最大自动重发次数:10次
  	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_CH,40);       //设置RF通道为40
  	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_SETUP,0x0f);  //设置TX发射参数,0db增益,2Mbps,低噪声增益开启   
  	NRF24L01_Write_Reg(WRITE_REG_NRF+CONFIG,0x0e);    //配置基本工作模式的参数;PWR_UP,EN_CRC,16BIT_CRC,接收模式,开启所有中断
	NRF24L01_CE=1;//CE为高,10us后启动发送
}		  




