#include "coil.h"

void sk_coil_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_8; //ˢ����Ȧ1|ˢ����Ȧ2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//�������룻
	GPIO_Init(GPIOB,&GPIO_InitStructure);//
}


/*void zj_coil_init(void)
{
		EXTIX_Init();
}
*/
