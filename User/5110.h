/*******************************************************************************
* File Name          : main.c
* Author             : Wuhan R&D Center, Embest
* Date First Issued  : 08/08/2008
* Description        : Main program body
********************************************************************************/
#ifndef _5110_H_
#define _5110_H_



/* Includes ------------------------------------------------------------------*/
#include "MyF4Config.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#define ADC1_DR_Address    ((u32)0x4001244C)

#define sce0   GPIO_ResetBits(GPIOE, GPIO_Pin_15)  //片选
#define res0   GPIO_ResetBits(GPIOE, GPIO_Pin_14)  //复位,0复位
#define dc0    GPIO_ResetBits(GPIOE, GPIO_Pin_13)   //1写数据，0写指令
#define sdin0  GPIO_ResetBits(GPIOE, GPIO_Pin_12)   //数据
#define sclk0  GPIO_ResetBits(GPIOE, GPIO_Pin_11)   //时钟

#define sce1   GPIO_SetBits(GPIOE, GPIO_Pin_15)  //片选
#define res1   GPIO_SetBits(GPIOE, GPIO_Pin_14)  //复位,0复位
#define dc1    GPIO_SetBits(GPIOE, GPIO_Pin_13)   //1写数据，0写指令
#define sdin1  GPIO_SetBits(GPIOE, GPIO_Pin_12)   //数据
#define sclk1  GPIO_SetBits(GPIOE, GPIO_Pin_11)   //时钟

  
/*函数名称 功能描述
GPIO_DeInit 重新初始化外围设备GPIOx相关寄存器到它的默认复位值
GPIO_AFIODeInit 初始化交错功能(remap, event control和 EXTI 配置) 寄存器
GPIO_Init 根据GPIO_初始化结构指定的元素初始化外围设备GPIOx
GPIO_StructInit 填充GPIO_初始化结构（GPIO_InitStruct）内的元素为复位值
GPIO_ReadInputDataBit 读指定端口引脚输入数据
GPIO_ReadInputData 读指定端口输入数据
GPIO_ReadOtputDataBit 读指定端口引脚输出数据
GPIO_ReadOtputData 读指定端口输出数据
GPIO_SetBits 置1指定的端口引脚
GPIO_ResetBits 清0指定的端口引脚
GPIO_WriteBit 设置或清除选择的数据端口引脚
GPIO_Write 写指定数据到GPIOx端口寄存器
GPIO_ANAPinConfig 允许或禁止 GPIO 4 模拟输入模式
GPIO_PinLockConfig 锁定GPIO引脚寄存器
GPIO_EventOutputConfig 选择GPIO引脚作为事件输出
GPIO_EventOutputCmd 允许或禁止事件输出
GPIO_PinRemapConfig 改变指定引脚的影射
GPIO_EMIConfig 允许或禁止GPIO 8 和 9 的EMI 模式
GPIO_InitTypeDef GPIO_InitStructure;
//键盘定义
#define   KEY_OK    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) 
#define   KEY_DOWN   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)
#define   KEY_UP    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)
#define   KEY_ESC   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3)	  
*/
//6x8.h文件：
/*-----------------------------------------------
6 x 8 font
1 pixel space at left and bottom
index = ASCII - 32
-----------------------------------------------*/
void LCD_write_byte(unsigned char dt, unsigned char command);
void LCD_init(void);
void LCD_set_XY(unsigned char X, unsigned char Y);
void LCD_clear(void);
void LCD_write_char(unsigned char c);
void LCD_write_String(unsigned char X,unsigned char Y,char *s);
void LCD_write_shu(unsigned char row, unsigned char page,unsigned char c) ;//row:列 page:页 dd:字符
void write_count(u8 x,u8 y,int count);
void LCD_write_tu(char (*imagee)[320]); //row:列 page:页 dd:字符





#endif//_5110_H_
