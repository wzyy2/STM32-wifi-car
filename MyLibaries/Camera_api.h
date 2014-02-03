#include "MyF4Config.h"


#define SCCB_SIC_H()     GPIOB->BSRRL = GPIO_Pin_8
#define SCCB_SIC_L()     GPIOB->BSRRH = GPIO_Pin_8
#define SCCB_SID_H()     GPIOB->BSRRL = GPIO_Pin_9
#define SCCB_SID_L()     GPIOB->BSRRH = GPIO_Pin_9
#define SCCB_DATA_IN      SCCB_SID_IN()
#define SCCB_DATA_OUT     SCCB_SID_OUT()
#define SCCB_SID_STATE	 GPIOB->IDR&0x0200
#define DCMI_TIMEOUT_MAX               10000

#define OV2640_DEVICE_WRITE_ADDRESS    0x60
#define OV2640_DEVICE_READ_ADDRESS     0x61




const unsigned char OV2640_JPEG_INIT[][2]=
{
  0xff, 0x00,
  0x2c, 0xff,
  0x2e, 0xdf,
  0xff, 0x01,
  0x3c, 0x32,
  0x11, 0x00,
  0x09, 0x02,
  0x04, 0x28,
  0x13, 0xe5,
  0x14, 0x48,
  0x2c, 0x0c,
  0x33, 0x78,
  0x3a, 0x33,
  0x3b, 0xfB,
  0x3e, 0x00,
  0x43, 0x11,
  0x16, 0x10,
  0x39, 0x92,
  0x35, 0xda,
  0x22, 0x1a,
  0x37, 0xc3,
  0x23, 0x00,
  0x34, 0xc0,
  0x36, 0x1a,
  0x06, 0x88,
  0x07, 0xc0,
  0x0d, 0x87,
  0x0e, 0x41,
  0x4c, 0x00,
  0x48, 0x00,
  0x5B, 0x00,
  0x42, 0x03,
  0x4a, 0x81,
  0x21, 0x99,
  0x24, 0x40,
  0x25, 0x38,
  0x26, 0x82,
  0x5c, 0x00,
  0x63, 0x00,
  0x61, 0x70,
  0x62, 0x80,
  0x7c, 0x05,
  0x20, 0x80,
  0x28, 0x30,
  0x6c, 0x00,
  0x6d, 0x80,
  0x6e, 0x00,
  0x70, 0x02,
  0x71, 0x94,
  0x73, 0xc1,
  0x12, 0x40,//0x40
  0x17, 0x11,
  0x18, 0x43,
  0x19, 0x00,
  0x1a, 0x4b,
  0x32, 0x09,
  0x37, 0xc0,
  0x4f, 0x60,
  0x50, 0xa8,
  0x6d, 0x00,
  0x3d, 0x38,
  0x46, 0x3f,
  0x4f, 0x60,
  0x0c, 0x3c,
  0xff, 0x00,
  0xe5, 0x7f,
  0xf9, 0xc0,
  0x41, 0x24,
  0xe0, 0x14,
  0x76, 0xff,
  0x33, 0xa0,
  0x42, 0x20,
  0x43, 0x18,
  0x4c, 0x00,
  0x87, 0xd5,
  0x88, 0x3f,
  0xd7, 0x03,
  0xd9, 0x10,
  0xd3, 0x82,
  0xc8, 0x08,
  0xc9, 0x80,
  0x7c, 0x00,
  0x7d, 0x00,
  0x7c, 0x03,
  0x7d, 0x48,
  0x7d, 0x48,
  0x7c, 0x08,
  0x7d, 0x20,
  0x7d, 0x10,
  0x7d, 0x0e,
  0x90, 0x00,
  0x91, 0x0e,
  0x91, 0x1a,
  0x91, 0x31,
  0x91, 0x5a,
  0x91, 0x69,
  0x91, 0x75,
  0x91, 0x7e,
  0x91, 0x88,
  0x91, 0x8f,
  0x91, 0x96,
  0x91, 0xa3,
  0x91, 0xaf,
  0x91, 0xc4,
  0x91, 0xd7,
  0x91, 0xe8,
  0x91, 0x20,
  0x92, 0x00,
  0x93, 0x06,
  0x93, 0xe3,
  0x93, 0x05,
  0x93, 0x05,
  0x93, 0x00,
  0x93, 0x04,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x96, 0x00,
  0x97, 0x08,
  0x97, 0x19,
  0x97, 0x02,
  0x97, 0x0c,
  0x97, 0x24,
  0x97, 0x30,
  0x97, 0x28,
  0x97, 0x26,
  0x97, 0x02,
  0x97, 0x98,
  0x97, 0x80,
  0x97, 0x00,
  0x97, 0x00,
  0xc3, 0xed,
  0xa4, 0x00,
  0xa8, 0x00,
  0xc5, 0x11,
  0xc6, 0x51,
  0xbf, 0x80,
  0xc7, 0x10,
  0xb6, 0x66,
  0xb8, 0xA5,
  0xb7, 0x64,
  0xb9, 0x7C,
  0xb3, 0xaf,
  0xb4, 0x97,
  0xb5, 0xFF,
  0xb0, 0xC5,
  0xb1, 0x94,
  0xb2, 0x0f,
  0xc4, 0x5c,
  0xc0, 0x64,
  0xc1, 0x4B,
  0x8c, 0x00,
  0x86, 0x3D,
  0x50, 0x00,
  0x51, 0xC8,
  0x52, 0x96,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x5a, 0xC8,
  0x5b, 0x96,
  0x5c, 0x00,
  0xd3, 0x7f,
  0xc3, 0xed,
  0x7f, 0x00,
  0xda, 0x00,
  0xe5, 0x1f,
  0xe1, 0x67,
  0xe0, 0x00,
  0xdd, 0x7f,
  0x05, 0x00,

  0x12, 0x40,//0x40
  0xd3, 0x7f,
  0xc0, 0x16,
  0xC1, 0x12,
  0x8c, 0x00,
  0x86, 0x3d,
  0x50, 0x00,
  0x51, 0x2C,
  0x52, 0x24,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x5A, 0x2c,
  0x5b, 0x24,
  0x5c, 0x00,
};

const unsigned char OV2640_YUV422[][2]= 
{
  0xFF, 0x00,
  0x05, 0x00,
  0xDA, 0x10,
  0xD7, 0x03,
  0xDF, 0x00,
  0x33, 0x80,
  0x3C, 0x40,
  0xe1, 0x77,
  0x00, 0x00,
};

const unsigned char OV2640_JPEG[][2]=
{
  0xe0, 0x14,
  0xe1, 0x77,
  0xe5, 0x1f,
  0xd7, 0x03,
  0xda, 0x12,
  0xe0, 0x00,
  0xFF, 0x01,
  0x04, 0x08,
};

const unsigned char OV2640_160x120_JPEG[][2]=
{
  0xff, 0x01,
  0x12, 0x40,
  0x17, 0x11,
  0x18, 0x43,
  0x19, 0x00,
  0x1a, 0x4b,
  0x32, 0x09,
  0x4f, 0xca,
  0x50, 0xa8,
  0x5a, 0x23,
  0x6d, 0x00,
  0x39, 0x12,
  0x35, 0xda,
  0x22, 0x1a,
  0x37, 0xc3,
  0x23, 0x00,
  0x34, 0xc0,
  0x36, 0x1a,
  0x06, 0x88,
  0x07, 0xc0,
  0x0d, 0x87,
  0x0e, 0x41,
  0x4c, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0xc0, 0x64,
  0xc1, 0x4b,
  0x86, 0x35,
  0x50, 0x89,
  0x51, 0xc8,
  0x52, 0x96,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x57, 0x00,
  0x5a, 0x50,
  0x5b, 0x3c,
  0x5c, 0x00,
  0xe0, 0x00,
};

void SCCB_Init(void)
{
  	GPIO_InitTypeDef  GPIO_InitStructure;
	I2C_InitTypeDef  I2C_InitStruct;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* Connect I2C1 pins to AF4 */
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_I2C1);
  
  /* Configure I2C1 GPIOs */  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure I2C1 */
  /* I2C DeInit */ 
  I2C_DeInit(I2C1);
    

 
  /* Set the I2C structure parameters */
  I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
  I2C_InitStruct.I2C_OwnAddress1 = 0xFE;
  I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStruct.I2C_ClockSpeed = 30000;
  
  /* Initialize the I2C peripheral w/ selected parameters */
  I2C_Init(I2C1, &I2C_InitStruct);
	
	  /* Enable the I2C peripheral */
  I2C_Cmd(I2C1, ENABLE);
}




uint8_t OV_WriteReg(uint16_t Addr, uint8_t Data)
{
  uint32_t timeout = DCMI_TIMEOUT_MAX;
  
  /* Generate the Start Condition */
  I2C_GenerateSTART(I2C1, ENABLE);

  /* Test on I2C1 EV5 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }
   
  /* Send DCMI selcted device slave Address for write */
  I2C_Send7bitAddress(I2C1, OV2640_DEVICE_WRITE_ADDRESS, I2C_Direction_Transmitter);
 
  /* Test on I2C1 EV6 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }
 
  /* Send I2C1 location address LSB */
  I2C_SendData(I2C1, (uint8_t)(Addr));

  /* Test on I2C1 EV8 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }
  
  /* Send Data */
  I2C_SendData(I2C1, Data);

  /* Test on I2C1 EV8 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }  
 
  /* Send I2C1 STOP Condition */
  I2C_GenerateSTOP(I2C1, ENABLE);
  
  /* If operation is OK, return 0 */
  return 0;
}

/**
  * @brief  Reads a byte from a specific Camera register
  * @param  Addr: OV2640 register address.
  * @retval data read from the specific register or 0xFF if timeout condition
  *         occured. 
  */
uint8_t OV_ReadReg(uint16_t Addr)
{
  uint32_t timeout = DCMI_TIMEOUT_MAX;
  uint8_t Data = 0;

  /* Generate the Start Condition */
  I2C_GenerateSTART(I2C1, ENABLE);

  /* Test on I2C1 EV5 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  } 
  
  /* Send DCMI selcted device slave Address for write */
  I2C_Send7bitAddress(I2C1, OV2640_DEVICE_READ_ADDRESS, I2C_Direction_Transmitter);
 
  /* Test on I2C1 EV6 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  } 

  /* Send I2C1 location address LSB */
  I2C_SendData(I2C1, (uint8_t)(Addr));

  /* Test on I2C1 EV8 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  } 
  
  /* Clear AF flag if arised */
  I2C1->SR1 |= (uint16_t)0x0400;

  /* Generate the Start Condition */
  I2C_GenerateSTART(I2C1, ENABLE);
  
  /* Test on I2C1 EV6 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  } 
  
  /* Send DCMI selcted device slave Address for write */
  I2C_Send7bitAddress(I2C1, OV2640_DEVICE_READ_ADDRESS, I2C_Direction_Receiver);
   
  /* Test on I2C1 EV6 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }  
 
  /* Prepare an NACK for the next data received */
  I2C_AcknowledgeConfig(I2C1, DISABLE);

  /* Test on I2C1 EV7 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED))
  {
    /* If the timeout delay is exeeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }   
    
  /* Prepare Stop after receiving data */
  I2C_GenerateSTOP(I2C1, ENABLE);

  /* Receive the Data */
  Data = I2C_ReceiveData(I2C1);

  /* return the read data */
  return Data;
}


void OV_Reset(void)
{
	OV_WriteReg(0xff, 0x01);
	OV_WriteReg(0x12,0x80);
}

u8 OV_ReadID(void)
{
	u8 temp;
//	OV_WriteReg(0xff, 0x01);
	temp = OV_ReadReg(0x1c);
  	return temp;
}


u8 OV_Jpeg(void)
{
	uint32_t i;
	u8 temp;
	
	temp = OV_ReadID();
	OV_Reset();
	
	
  for(i=0; i<(sizeof(OV2640_JPEG_INIT)/2); i++)
  {
    OV_WriteReg(OV2640_JPEG_INIT[i][0], OV2640_JPEG_INIT[i][1]);
		delay_ms(1);
  }

  /* Set to output YUV422 */
  for(i=0; i<(sizeof(OV2640_YUV422)/2); i++)
  {
   OV_WriteReg(OV2640_YUV422[i][0], OV2640_YUV422[i][1]);
		delay_ms(1);
  }

  OV_WriteReg(0xff, 0x01);
	delay_ms(1);
  OV_WriteReg(0x15, 0x00);

  /* Set to output JPEG */
  for(i=0; i<(sizeof(OV2640_JPEG)/2); i++)
  {
    OV_WriteReg(OV2640_JPEG[i][0], OV2640_JPEG[i][1]);
		delay_ms(1);
  }
	for(i=0; i<(sizeof(OV2640_160x120_JPEG)/2); i++)
  {
    OV_WriteReg(OV2640_160x120_JPEG[i][0], OV2640_160x120_JPEG[i][1]);
		delay_ms(1);
  }
//OV_WriteReg(0xff, 0x00);
//OV_WriteReg(0xc7, 0x10);
	
//	for(i=0; i<(sizeof(OV2640_QVGA)/2); i++)
//  {
 //   OV_WriteReg(OV2640_QVGA[i][0], OV2640_QVGA[i][1]);
 //   delay_ms(1);
 // }
  	return temp;
}


/**
  * @brief  Configures the OV2640 camera brightness.
  * @param  Brightness: Brightness value, where Brightness can be: 
  *         0x40 for Brightness +2,
  *         0x30 for Brightness +1,
  *         0x20 for Brightness 0,
  *         0x10 for Brightness -1,
  *         0x00 for Brightness -2,
  * @retval None
  */
void OV2640_BrightnessConfig(uint8_t Brightness)
{
  OV_WriteReg(0xff, 0x00);
  OV_WriteReg(0x7c, 0x00);
  OV_WriteReg(0x7d, 0x04);
  OV_WriteReg(0x7c, 0x09);
  OV_WriteReg(0x7d, Brightness);
  OV_WriteReg(0x7d, 0x00);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const static u8 OV2640_AUTOEXPOSURE_LEVEL0[]=
{
	0xFF,	0x01,	0xff,
	0x24,	0x20,	0xff,
	0x25,	0x18,	0xff,
	0x26,	0x60,	0xff,
	0x00,	0x00,	0x00
};

const static u8 OV2640_AUTOEXPOSURE_LEVEL1[]=
{
	0xFF,	0x01,	0xff,
	0x24,	0x34,	0xff,
	0x25,	0x1c,	0xff,
	0x26,	0x70,	0xff,
	0x00,	0x00,	0x00
};
const static u8 OV2640_AUTOEXPOSURE_LEVEL2[]=
{
	0xFF,	0x01,	0xff,
	0x24,	0x3e,	0xff,
	0x25,	0x38,	0xff,
	0x26,	0x81,	0xff,
	0x00,	0x00,	0x00
};
const static u8 OV2640_AUTOEXPOSURE_LEVEL3[]=
{
	0xFF,	0x01,	0xff,
	0x24,	0x48,	0xff,
	0x25,	0x40,	0xff,
	0x26,	0x81,	0xff,
	0x00,	0x00,	0x00
};
const static u8 OV2640_AUTOEXPOSURE_LEVEL4[]=
{
	0xFF,	0x01,	0xff,
	0x24,	0x58,	0xff,
	0x25,	0x50,	0xff,
	0x26,	0x92,	0xff,
	0x00,	0x00,	0x00
};
void SCCB_WriteRegs(const u8* pbuf)
{
	while(1)
	{
		if((*pbuf == 0) && (*(pbuf + 1) == 0))
		{
			break;
		}
		else
		{
			OV_WriteReg(*pbuf++, *pbuf++);
		}
	}
}
void OV2640_AutoExposure(u8 level)
{
	switch(level)
	{
		case 0:
			SCCB_WriteRegs(OV2640_AUTOEXPOSURE_LEVEL0);
			break;
		case 1:
			SCCB_WriteRegs(OV2640_AUTOEXPOSURE_LEVEL1);
			break;
		case 2:
			SCCB_WriteRegs(OV2640_AUTOEXPOSURE_LEVEL2);
			break;
		case 3:
			SCCB_WriteRegs(OV2640_AUTOEXPOSURE_LEVEL3);
			break;
		case 4:
			SCCB_WriteRegs(OV2640_AUTOEXPOSURE_LEVEL4);
			break;
		default:
			SCCB_WriteRegs(OV2640_AUTOEXPOSURE_LEVEL0);
			break;
	}
	
}
/**
  * @brief  Configures the OV2640 camera Black and white mode.
  * @param  BlackWhite: BlackWhite value, where BlackWhite can be: 
  *         0x18 for B&W,
  *         0x40 for Negative,
  *         0x58 for B&W negative,
  *         0x00 for Normal,
  * @retval None
  */
void OV2640_BandWConfig(uint8_t BlackWhite)
{
  OV_WriteReg(0xff, 0x00);
  OV_WriteReg(0x7c, 0x00);
  OV_WriteReg(0x7d, BlackWhite);
  OV_WriteReg(0x7c, 0x05);
  OV_WriteReg(0x7d, 0x80);
  OV_WriteReg(0x7d, 0x80);
}

/**
  * @brief  Configures the OV2640 camera color effects.
  * @param  value1: Color effects value1
  * @param  value2: Color effects value2
  *         where value1 and value2 can be: 
  *         value1 = 0x40, value2 = 0xa6 for Antique,
  *         value1 = 0xa0, value2 = 0x40 for Bluish,
  *         value1 = 0x40, value2 = 0x40 for Greenish,
  *         value1 = 0x40, value2 = 0xc0 for Reddish,
  * @retval None
  */
void OV2640_ColorEffectsConfig(uint8_t value1, uint8_t value2)
{
  OV_WriteReg(0xff, 0x00);
  OV_WriteReg(0x7c, 0x00);
  OV_WriteReg(0x7d, 0x18);
  OV_WriteReg(0x7c, 0x05);
  OV_WriteReg(0x7d, value1);
  OV_WriteReg(0x7d, value2);
}

/**
  * @brief  Configures the OV2640 camera contrast.
  * @param  value1: Contrast value1
  * @param  value2: Contrast value2
  *         where value1 and value2 can be: 
  *         value1 = 0x28, value2 = 0x0c for Contrast +2,
  *         value1 = 0x24, value2 = 0x16 for Contrast +1,
  *         value1 = 0x20, value2 = 0x20 for Contrast 0,
  *         value1 = 0x1c, value2 = 0x2a for Contrast -1,
  *         value1 = 0x18, value2 = 0x34 for Contrast -2,
  * @retval None
  */
void OV2640_ContrastConfig(uint8_t value1, uint8_t value2)
{
  OV_WriteReg(0xff, 0x00);
  OV_WriteReg(0x7c, 0x00);
  OV_WriteReg(0x7d, 0x04);
  OV_WriteReg(0x7c, 0x07);
  OV_WriteReg(0x7d, 0x20);
  OV_WriteReg(0x7d, value1);
  OV_WriteReg(0x7d, value2);
  OV_WriteReg(0x7d, 0x06);
}



