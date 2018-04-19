#ifndef __COIL_H
#define __COIL_H

#include "sys.h"
#include "delay.h"
#include "usart.h"
//#include "exti.h"

#define sk_coil1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define sk_coil2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
#define zj_d  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//¶ÁÈ¡°´¼ü0,Õ¢ÃÅ1

//extern char out1;
//extern char out2;
//char zj_up;
extern u8 INFORM;

void sk_coil_init(void);
u8 zj_Scan(u8 mode);
//void zj_coil_init();

#endif
