#ifndef __COIL_H
#define __COIL_H

#include "sys.h"
#include "delay.h"
#include "usart.h"
//#include "exti.h"

#define sk_coil1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define sk_coil2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)

//extern char out1;
//extern char out2;
extern u8 INFORM;

void sk_coil_init(void);
//void zj_coil_init();

#endif
