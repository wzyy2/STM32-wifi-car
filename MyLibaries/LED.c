#include "MyF4Config.h"
/*****************************************/
/*****************LED配置*****************/
/*****************************************/
void LED_Config()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	/************配置状态灯的引脚*************/	
	//设置GPIOE的14脚参数
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_8;                         //选择GPIOE的14脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;             //设置选中的引脚工作模为输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;            //设置GPIO的输出方式PP推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;          //定义GPIO的最高输出频率2MHz
	//初始化所设置的GPIOE参数
	GPIO_Init(GPIOA , &GPIO_InitStructure);
}

