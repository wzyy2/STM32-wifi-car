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

#define sce0   GPIO_ResetBits(GPIOE, GPIO_Pin_15)  //Ƭѡ
#define res0   GPIO_ResetBits(GPIOE, GPIO_Pin_14)  //��λ,0��λ
#define dc0    GPIO_ResetBits(GPIOE, GPIO_Pin_13)   //1д���ݣ�0дָ��
#define sdin0  GPIO_ResetBits(GPIOE, GPIO_Pin_12)   //����
#define sclk0  GPIO_ResetBits(GPIOE, GPIO_Pin_11)   //ʱ��

#define sce1   GPIO_SetBits(GPIOE, GPIO_Pin_15)  //Ƭѡ
#define res1   GPIO_SetBits(GPIOE, GPIO_Pin_14)  //��λ,0��λ
#define dc1    GPIO_SetBits(GPIOE, GPIO_Pin_13)   //1д���ݣ�0дָ��
#define sdin1  GPIO_SetBits(GPIOE, GPIO_Pin_12)   //����
#define sclk1  GPIO_SetBits(GPIOE, GPIO_Pin_11)   //ʱ��

  
/*�������� ��������
GPIO_DeInit ���³�ʼ����Χ�豸GPIOx��ؼĴ���������Ĭ�ϸ�λֵ
GPIO_AFIODeInit ��ʼ����������(remap, event control�� EXTI ����) �Ĵ���
GPIO_Init ����GPIO_��ʼ���ṹָ����Ԫ�س�ʼ����Χ�豸GPIOx
GPIO_StructInit ���GPIO_��ʼ���ṹ��GPIO_InitStruct���ڵ�Ԫ��Ϊ��λֵ
GPIO_ReadInputDataBit ��ָ���˿�������������
GPIO_ReadInputData ��ָ���˿���������
GPIO_ReadOtputDataBit ��ָ���˿������������
GPIO_ReadOtputData ��ָ���˿��������
GPIO_SetBits ��1ָ���Ķ˿�����
GPIO_ResetBits ��0ָ���Ķ˿�����
GPIO_WriteBit ���û����ѡ������ݶ˿�����
GPIO_Write дָ�����ݵ�GPIOx�˿ڼĴ���
GPIO_ANAPinConfig �������ֹ GPIO 4 ģ������ģʽ
GPIO_PinLockConfig ����GPIO���żĴ���
GPIO_EventOutputConfig ѡ��GPIO������Ϊ�¼����
GPIO_EventOutputCmd �������ֹ�¼����
GPIO_PinRemapConfig �ı�ָ�����ŵ�Ӱ��
GPIO_EMIConfig �������ֹGPIO 8 �� 9 ��EMI ģʽ
GPIO_InitTypeDef GPIO_InitStructure;
//���̶���
#define   KEY_OK    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) 
#define   KEY_DOWN   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)
#define   KEY_UP    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)
#define   KEY_ESC   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3)	  
*/
//6x8.h�ļ���
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
void LCD_write_shu(unsigned char row, unsigned char page,unsigned char c) ;//row:�� page:ҳ dd:�ַ�
void write_count(u8 x,u8 y,int count);
void LCD_write_tu(char (*imagee)[320]); //row:�� page:ҳ dd:�ַ�





#endif//_5110_H_