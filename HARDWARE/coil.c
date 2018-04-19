#include "coil.h"

char zj_up=1;
void sk_coil_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_8|GPIO_Pin_9; //刷卡线圈1|刷卡线圈2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入；
	GPIO_Init(GPIOB,&GPIO_InitStructure);//
}

u8 zj_Scan(u8 mode)
{	 
	
	if(mode)zj_up=1;  //支持连按		  
	/*if(key_up&&(KEY0==0||KEY1==0))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
	}else if(KEY0==1&&KEY1==1)key_up=1; */
			if(zj_up)
	{
		if(zj_d==0)
		{
		delay_ms(10);//去抖动 
		zj_up=0;
		if((zj_d)==0)return 1;
	}
}else if((zj_d)==1)zj_up=1; 
 	return 0;// 无按键按下

	}
/*void zj_coil_init(void)
{
		EXTIX_Init();
}
*/
