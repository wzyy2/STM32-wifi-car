/*#include "MyF4Config.h"   //头文件  移植的话怎么做不用讲了吧


#define USE_FLASH   //非STM32用户请注释 若想使用FLASH功能请自行更换
#define PRINTF(Data,value)   USART_printf( USART3, Data,value) 
#define SCANF        




void Insert_param(uint8_t *name,u32 value) //
void communication_checkEvent();






#ifdef USE_FLASH


//参数列表  本来也想写成函数加入删除的格式的 后来发现太麻烦 
typedef struct
{
    float acc_offset[3];
    float acc_gain[3];
    float gyr_offset[3];
    float gyr_gain[3];
    float mag_offset[3];
    float mag_gain[3];
} param_t;
static param_t param_ram;
static const param_t * param_flash = (const param_t *)PARAM_FLASH_ADDRESS;

int32_t flash_erase(const uint32_t * page);
int32_t flash_write(const uint32_t * target,const uint32_t * source,int32_t length);


#endif /* USE_FLASH */ */