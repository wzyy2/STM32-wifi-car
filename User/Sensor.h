//*********************************************************************
//
//  Copyright (c) UESTC Roboteam 2011 ， All rights reserved.
// 
//  Sensor.c - 传感器相关函数文件
//
//      该文件是电子科技大赛第六届巡线机器人大赛赛事组委会提供的模板
//  程序的传感器相关函数文件。用户须完善下面的各传感器初始化、读取等
//  函数方可正常使用。
//
//  2011年10月29日
//
//********************************************************************

#include "MyF4Config.h"

extern enum dir direction;
#define lled  GPIOAin(1) 
#define mled 	GPIOAin(2) 
#define rled 	GPIOAin(3) 
//********************************************************************
// 函数名: SensorInit() 
// 说  明: 传感器读取端口的初始化函数
// 时  间: 2011.10.29  
// 输  入: 无
// 输  出: 无
// 返  回: 无
// 注  意: 
//********************************************************************    
// 修改者:
// 时  间:
// 描  述:
//********************************************************************
void SensorInit(void)
{

   // ******* 用户添加读取巡线传感器的IO口初始化代码 ********

   // ******* 用户添加避障传感器所在IO口的中断配置代码 ********
   // 说明：避障传感器使用IO中断读取，提高相应效率。
   //       勿忘中断注册
		GPIO_InitTypeDef  GPIO_InitStructure;
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;             //设置选中的引脚工作模为输出模式
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //设置GPIO的输出方式PP推挽输出
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;	
  	GPIO_Init(GPIOD, &GPIO_InitStructure); 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;	
  	GPIO_Init(GPIOC, &GPIO_InitStructure); 
}


//********************************************************************
// 函数名: SensorRead() 
// 说  明: 传感器读取端口的初始化函数
// 时  间: 2011.10.29  
// 输  入: flag：判断之前赛道情况，0：黑直线，否则：拐角
// 输  出: 无
// 返  回: pathinfo ：机器人偏离黑线的情况。
//                    0 :无偏离
//                    负:左偏，越负越左，此时右边传感器压黑线
//                    正:右偏，越正越右，此时左边传感器压黑线
// 注  意: 注意方向！！！
//********************************************************************    
// 修改者:
// 时  间:
// 描  述:
//********************************************************************

//4 3 2 1          8 7 6 5         10 9 8 7          15 14 13 12 11
//     



int16_t SensorRead(int16_t flag)
{
   int16_t pathinfo,put = 0;
   pathinfo =(GPIOD->IDR & 0x00ff) | (GPIOC->IDR & 0xff00);
	 if(pathinfo & 0x08)
		 put=16;
	 else	 if(pathinfo & 0x04)
		 put=13;
//	 else  if(pathinfo & 0x02)
//		 put=9;
	 else  if(pathinfo & 0x01)
		 put=9;
	 else  if(pathinfo & 0x80)
		 put=3;
	 else  if(pathinfo & 0x40)
		 put=2;	 
	 else  if(pathinfo & 0x20)
		 put=1;	 
		if(pathinfo & 0x1000)
		 put=-16;
	 else	 if(pathinfo & 0x2000)
		 put=-13;
	 else  if(pathinfo & 0x4000)
		 put=-11;
	 else  if(pathinfo & 0x8000)
		 put=-9;
	 else  if(pathinfo & 0x0100)
		 put=-3;	  
	 else  if(pathinfo & 0x0200)
		 put=-2;
	 else  if(pathinfo & 0x0400)
		 put=-1;	 
	 
	pathinfo = pathinfo | 0x02;
	 
	 
  switch(pathinfo & 0xffff)      // 根据电平判断机器人的偏离情况，返回相应数值
   {
		 case 0x0002: 
		 {
		 if(flag<-4)
			 put=-10;
		 else if(flag < 4 && flag > -4)
			 put = 0;
		 else
			 put=10;
		 }
		 break; 	//全黑线 十字路口 探测什么的 待修改
		 case 0xffff: 
		 {
			 put=0;	 break; 	//全黑线 十字路口 探测什么的 待修改
		 }
		 default: break; 
   }  
	 if(pathinfo & 0xff00 == 0xff00)
		 put =0;
	 else if(pathinfo & 0x00ff == 0x00ff)
		 put =0;	 
	 else if(my_abs(put)>6)
	 {
		 if(pathinfo & 0x10)
		 put=0;	
		 else  if(pathinfo & 0x0800)
		 put=0;	
		 		 else  if(pathinfo & 0x0400)
		 put=0;	
				 		 		 else  if(pathinfo & 0x20)
		 put=0;	
	 }
		return put;
}


//********************************************************************
// 函数名: IntDodge() 
// 说  明: 避障中断服务函数
// 时  间: 2011.10.29  
// 输  入: 无
// 输  出: 无
// 返  回: 无
// 注  意: 注意方向！！！
//********************************************************************    
// 修改者:
// 时  间:
// 描  述:
//********************************************************************
/*void IntDodge(void)
{
  // ******** 用户添加避障代码 *********
}
*/

//************************* End File *********************************
