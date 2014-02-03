





/*
  * @brief  串口检查事件
 */
/*void com_serial_checkEvent(void)
{
    switch(receiveStatus)
    {
        case FINDING_0X55 :
        {
            if(uart1_receiveValidBufferSize() < 1)
                break;
            uint8_t byte = 0;
            uart1_readReceiveBuffer(&byte,1);
            if(byte == (uint8_t)(0x55))
                com_serial_receiveStatus = NEED_0XAA;
        }
        break;
        case NEED_0XAA :
        {
            if(uart1_receiveValidBufferSize() < 1)
                break;
            uint8_t byte = 0;
            uart1_readReceiveBuffer(&byte,1);
            if(byte == (uint8_t)(0xAA))
                com_serial_receiveStatus = NEED_LENGTH;
            else if(byte == (uint8_t)(0x55))
                break; // ????0x55????
            else
                com_serial_receiveStatus = FINDING_0X55;
        }
        break;
        case NEED_LENGTH :
        {
            if(uart1_receiveValidBufferSize() < 1)
                break;
            uint8_t length = 0;
            uart1_readReceiveBuffer(&length,1);
            if(length < 4 || length > RECEIVE_BUFFER_SIZE)
                break;
            com_serial_receiveLength = length;
            com_serial_receiveStatus = GETTING_DATA;
        }
        break;
        case GETTING_DATA :
        {
            if(uart1_receiveValidBufferSize() < com_serial_receiveLength)
                break;
            //
            uart1_readReceiveBuffer(com_serial_receiveBuffer,com_serial_receiveLength);
            if(math_crc16(0,com_serial_receiveBuffer,com_serial_receiveLength) == 0)
                engine_handlePacket_serial(com_serial_receiveBuffer,com_serial_receiveLength-2);
            //
            com_serial_receiveStatus = FINDING_0X55;
        }
        break;
    }
}

*/

#ifdef USE_FLASH
/**
  * @brief  擦除FLASH
  * @param  FALSH地址
  * @retval 成功0 失败-1
  */
int32_t flash_erase(const uint32_t * page)
{
    int32_t rt = FLASH_COMPLETE;
    FLASH_Unlock();
    rt = FLASH_ErasePage((uint32_t)page);
    FLASH_Lock();
    if(rt != FLASH_COMPLETE)
        return -1;
    return 0;
}

int32_t flash_write(const uint32_t * target,const uint32_t * source,int32_t length)
{
    int32_t ok = 1;
    FLASH_Unlock();
    for(int32_t i=0;i<length;i++)
    {
        if(FLASH_ProgramWord((uint32_t)(target+i),source[i]) != FLASH_COMPLETE)
        {
            ok = 0;
            break;
        }
    }
    FLASH_Lock();
    if(! ok)
        return -1;
    return 0;
}
#endif /* USE_FLASH */
