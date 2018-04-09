#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PCout(4)// PC4
#define LED1 PCout(5)// PC5	
#define BEEP PCout(9)// PC9
//#define BEEP PBout(8)//PB8

#define sk_car_dector1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) //sk_car_dector1 = PB0
#define sk_car_dector2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) //sk_car_dector2 = PB8

void LED_BEEP_Init(void);//初始化
void LED0_Init(void);
//void LED0_Init(void);//初始化
//void BEEP_Init(void);

		 				    
#endif
