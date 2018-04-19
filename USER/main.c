/******************

@Author:ye
@Date:
**************************/

#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "break_machine.h"
#include "ttl2tcp.h"
#include "led.h"
#include "card.h"
#include "tim.h"
#include "exti.h"
#include "wdg.h"
//#include "voice_synth.h"
#include "xfs5152ce.h"
#include "coil.h"
#include "key.h"



#define BM_flag        1  //Õ¢»ú±êÖ¾£»
#define CARD_flag      2  //Ë¢¿¨±êÖ¾£»
//#define UPLOAD_IC_flag 3  //ÉÏ´«IC¿¨ÐÅÏ¢£»
//#define UPLOAD_flag    4  //ÉÏ´«ÐÅÏ¢±êÖ¾£»

u8 INFORM=0;
u8 out;
char zj_flag1=0;            //Õ¢»ú¶¨Ê±±êÖ¾£»µ±zj_flag=1µÄÊ±ºò£¬¶¨Ê±500ms;
char zj_flag2=0;
char cardID[12];
char DG=0;                    //ÓÐµØ¸Ð±äÁ¿£»

char out1=0;
char voice[]={0xB6,0xE0,0xB6,0xF8,0xB7,0xD6,0xBF,0xD8,0xD6,0xC6,0xCF,0xB5,0xCD,0xB3,0xC6,0xF4,0xB6,0xAF,0xCD,0xEA,0xB3,0xC9};
char shutDOWN1[8]={0x00,0x06,0x00,0x0c,0x00,0x00,0x01,0x0f};
//char shutDOWN2[8]={0x00,0x06,0x00,0x0c,0x00,0x00,0x01,0x0f};

int main()
{
	delay_init();           //ÑÓÊ±³õÊ¼»¯£»
	//KEY_Init();
	break_machine_init();   //Õ¢»ú³õÊ¼»¯£»
	sk_coil_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);      //´®¿Ú³õÊ¼»¯£»ttl2Pc
	uart2_init(9600);     //´®¿Ú2³õÊ¼»¯£»cardID
	uart3_init(9600);     //ÓïÒôÄ£¿é´®¿Ú3³õÊ¼»¯
	LED_BEEP_Init();
	//LED0_Init();          //¼ì²âÑ¹ÏßÄ£¿é³õÊ¼»¯
	TIM_Init(4999,7199);  //¶¨Ê±Æ÷¶¨Ê±500ms
	//EXTIX_Init();
	
	
	IWDG_Init(6,625);
	XFS_FrameInfo(voice,22);
//	Send2Pc(test);
	while(1)
	{
		tcpcmd();
		Card();
		IWDG_Feed(); //Î¹¹·
		if(INFORM==BM_flag)
		{
			zj_flag1=1;
			zj_flag2=1;
		}

		IWDG_Feed();
		//ÅÐ¶ÏÆû³µÊÇ·ñ³öÃÅ¡£³öÃÅÔò·¢ËÍÕ¢»úÒÑ±ÕºÏÖ¸Áî¡
		out = zj_Scan(0);
		if(out==1)
		{
			Send2Pc(shutDOWN1,8);
		}
		IWDG_Feed(); //Î¹¹·
	}
}
















