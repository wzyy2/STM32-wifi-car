//*********************************************************************
//
//  Copyright (c) UESTC Roboteam 2011 ， All rights reserved.
// 
//  PID.H - PID算法文件
//
//      该文件是电子科技大赛第六届巡线机器人大赛赛事组委会提供的模板
//  程序的PID算法头文件。用户可直接调用其中的函数。算法无需初始化。
//  可统一成整形计算，提高效率。
//
//  2011年10月29日
//
//********************************************************************

#ifndef _PID_H_
#define _PID_H_
#include "MyF4Config.h"


// 以下宏定义由用户根据机器人调试设定
#define epsilon   2           // 积分死区阈值
#define dt        1       // 控制周期
#define MAX       9000           // 最大输出限制
#define MIN       -9000          // 最小输出限制
static float Kp = 1000   ;      // 比例系数
static float Kd = 2500    ;    // 微分系数
static float Ki   =     0 ;      // 积分系数



float PIDcal(float setpoint,float actual_position)
{
	static float pre_error = 0;         // 定义前一次误差
	static float integral = 0;          // 定义积分项累加值
	float error;                        // 定义最新误差
	float derivative;                   // 定义微分项
	float output;                       // 定义输出

	// 计算误差
	error = setpoint -actual_position;

	// 积分死区设置，在误差极小的情况下不做积分处理，保证稳定性
	if(my_abs(error) > epsilon)
	{
	   integral = integral + error*dt;   // 积分项
	}

	derivative = (error - pre_error)/dt; // 微分项

	output = Kp*error + Ki*integral + Kd*derivative; // 各项乘以系数得到PID输出

	// 输出限幅，确保输出不会太夸张
	if(output > MAX)
	{
		output = MAX;
	}
	else if(output < MIN)
	{
		output = MIN;
	}

        // 更新误差
        pre_error = error;

        return output;
}



void Change_mypid(u8 which,float value)
{
				switch(which)
		  	{
					case 1:
					{
						Kp = value;		
				    break;
					}
					case 2:
					{
						Kd = value;		
				    break;
					}
				 case 3:
					{
						Ki = value;		
				    break;
					}
		    }
}
#endif 

//************************* End File *********************************
