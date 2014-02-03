#include "delay.h"
 

static __IO uint32_t TimingDelay;


void delay_init()	 
{

  if (SysTick_Config(SystemCoreClock / 10))
  { 
    /* Capture error */ 
    while (1);
  }

}			

void delay_ms(__IO uint32_t nTime)
{	 		  	  
	TimingDelay = nTime;   
	while(TimingDelay != 0);     
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}