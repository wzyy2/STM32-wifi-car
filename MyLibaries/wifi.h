#ifndef _WIFI_H_
#define _WIFI_H_
#include "MyF4Config.h"
typedef unsigned char u8;
typedef unsigned short u16;


 
void wifi_Init(void);
void send_image(u8 *image,u16 lenth);
//u8 *receive_tcp();
#endif//_WIFI_H_

