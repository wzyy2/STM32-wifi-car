#include "MyF4Config.h"

/*****************************************/
/*************系统DMA通道配置*************/
/*****************************************/
void DMA_Config()
{
	DMA_InitTypeDef DMA_InitStructure;
	//复位DMA1的6通道
	DMA_DeInit(DMA1_Stream6);
	DMA_InitStructure.DMA_PeripheralBaseAddr = SRC_Const_Buffer; //定义外设地址
	DMA_InitStructure.DMA_MemoryBaseAddr = DST_Buffer; //定义内存地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;//外设到内存
	DMA_InitStructure.DMA_BfferSize = BufferSize;//DMA缓存大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;//外设地址寄存器递增
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//内存地址寄存器递增
	DMA_InitStructure.DMA_peripheralDataSize = DMA_PeripheralDataSize_Word;//外设数据宽度
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;//内存数据宽度
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;//工作模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;//优先级
	//DMA_InitStructure.DMA_M2M = 
	DMA_Init(DMA1_Stream6);//初始化所设置的参数
	DMA_ITConfig(DMA1_Stream6 , DMA_IT_TC , ENABLE);//开启DMA传输完成中断
	CurrDataCounter = DMA_GetCurrDataCounter(DMA1_Stream6);//读出当前数据量计数值
}

/*****************************************/
/*************系统Systick配置*************/
/*****************************************/
void SysTick_Conf()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	SysTick_SetReload(168);
	SysTick_CounterCmd(SysTick_Counter_Enable);
	SysTick_ITConfig(ENABLE);
}

/*****************************************/
/*************系统NVIC配置****************/
/*****************************************/
void NVIC_Config()
{
	NVIC_InitTypeDef   NVIC_InitStructure;
  //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);         //配置中断优先级分组
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream6_IRQn;         //启用或禁用的IRQ通道，具体见stm32f4xx.h
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00; //抢占优先级为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;        //响应优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           
  NVIC_Init(&NVIC_InitStructure);                         
}