#include "break_machine.h"

void break_machine_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能PB端口；
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; //闸机开关---->PB.4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出；
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO口速度为50MHZ；
	GPIO_Init(GPIOB,&GPIO_InitStructure);//根据设定参数初始化GPIO.4
	GPIO_ResetBits(GPIOB,GPIO_Pin_4);    //初始设置为输出低电平
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_1);  
}
