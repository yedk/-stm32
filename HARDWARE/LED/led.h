#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PCout(4)// PC4
#define LED1 PCout(5)// PC5	
#define BEEP PCout(9)// PC9
//#define BEEP PBout(8)//PB8

#define sk_car_dector1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) //sk_car_dector1 = PB0
#define sk_car_dector2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) //sk_car_dector2 = PB8

void LED_BEEP_Init(void);//��ʼ��
void LED0_Init(void);
//void LED0_Init(void);//��ʼ��
//void BEEP_Init(void);

		 				    
#endif
