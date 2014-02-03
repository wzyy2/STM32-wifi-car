#include "MyF4Config.h"

/*****************************************/
/**************系统GPIO配置***************/
/*****************************************/
//不包含GPIO端口的复用
void GPIO_Config()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	/************配置状态灯的引脚*************/	
	//设置GPIOE的14脚参数
	GPIO_InitStructure.GPIO_Pin= Red;                         //选择GPIOE的14脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;             //设置选中的引脚工作模为输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;            //设置GPIO的输出方式PP推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;          //定义GPIO的最高输出频率2MHz
	//初始化所设置的GPIOE参数
	GPIO_Init(LED , &GPIO_InitStructure);
	
	/*****************************************/
	/************配置USART1的引脚*************/
	/*****************************************/
	//TX
	GPIO_InitStructure.GPIO_Pin = COM1_TX;                //选择GPIOB的6脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;          //设置选中的引脚工作模式，IN：输入模式；OUT：输出模式；AF：复用模式；AN：模拟模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //设置GPIO的输出方式，PP：推挽输出；OD：开漏输出
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;      //定义GPIO的最高输出频率2MHz、25MHz、50MHz 、100MHz 
	GPIO_Init(GPIO_USART1, &GPIO_InitStructure);        //初始化所设置的GPIOD参数
  //RX
	GPIO_InitStructure.GPIO_Pin = COM1_RX;                //选择GPIOB的7脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;          //设置选中的引脚工作模式，IN：输入模式；OUT：输出模式；AF：复用模式；AN：模拟模式
	//初始化所设置的GPIOB参数                            
  GPIO_Init(GPIO_USART1 , &GPIO_InitStructure);
	
	/*****************************************/
	/************配置USART2的引脚*************/
	/*****************************************/
	//TX
	GPIO_InitStructure.GPIO_Pin = COM2_TX;                
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;          
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;      
	GPIO_Init(GPIO_USART2, &GPIO_InitStructure);       
  //RX
	GPIO_InitStructure.GPIO_Pin = COM2_RX;               
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;          
	//初始化所设置的GPIOB参数                            
  GPIO_Init(GPIO_USART2 , &GPIO_InitStructure);        
}

/*****************************************/
/**********系统USART端口配置**************/
/*****************************************/
void USART_Config()
{
	USART_InitTypeDef USART_InitStructure;     //定义USART初始化结构体
	USART_Cmd(COM_PORT1 , DISABLE);          //关闭串口
	//GPIOA的2、3脚复用为USART1的引脚
  GPIO_PinAFConfig(GPIO_USART1 , GPIO_PinSource6 , GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIO_USART1 , GPIO_PinSource7 , GPIO_AF_USART1);
	
	//串口1参数设置
	USART_InitStructure.USART_BaudRate = 115200;                                      //波特率：115200、57600、38400、9600、4800、2400、1200
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;                       //表示一个帧中发送或者接收到的数据位
  USART_InitStructure.USART_StopBits = USART_StopBits_1;                            //停止位
  USART_InitStructure.USART_Parity = USART_Parity_No;                               //奇偶模式
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //使能或关闭硬件流控制模式
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                   //使能或关闭发送和接收模式   

	USART_Init(COM_PORT1 , &USART_InitStructure);
	//使能USART1
	USART_Cmd(COM_PORT1 , ENABLE);
	
	GPIO_PinAFConfig(GPIO_USART2 , GPIO_PinSource5 , GPIO_AF_USART2);
  GPIO_PinAFConfig(GPIO_USART2 , GPIO_PinSource7 , GPIO_AF_USART2);
	
	//串口2参数设置
	USART_InitStructure.USART_BaudRate = 115200;                                        //波特率：115200、57600、38400、9600、4800、2400、1200
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;                       //表示一个帧中发送或者接收到的数据位
  USART_InitStructure.USART_StopBits = USART_StopBits_1;                            //停止位
  USART_InitStructure.USART_Parity = USART_Parity_No;                               //奇偶模式
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //使能或关闭硬件流控制模式
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                   //使能或关闭发送和接收模式   

	USART_Init(COM_PORT2 , &USART_InitStructure);
	//使能USART2
	USART_Cmd(COM_PORT2 , ENABLE);
}
