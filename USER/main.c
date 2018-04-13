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
//#include "exti.h"
#include "wdg.h"
//#include "voice_synth.h"
#include "xfs5152ce.h"
#include "coil.h"
#include "key.h"



#define BM_flag        1  //闸机标志；
#define CARD_flag      2  //刷卡标志；
//#define UPLOAD_IC_flag 3  //上传IC卡信息；
//#define UPLOAD_flag    4  //上传信息标志；

u8 INFORM=0;
u8 out;
char zj_flag1=0;            //闸机定时标志；当zj_flag=1的时候，定时500ms;
char zj_flag2=0;
char cardID[12];
char DG=0;                    //有地感变量；

//char test[10];
//char voice_code[]={0xBF,0xc6,0xB4,0xF3,0xD1,0xB6,0xB7,0xC9};
//char voice[]={0xC4,0xE3,0xBA,0xC3};
//char voice[]={0xCE,0xD2,0xCA,0xC7,0xBF,0xC6,0xB4,0xF3,0xD1,0xB6,0xB7,0xC9};
char voice[]={0xB6,0xE0,0xB6,0xF8,0xB7,0xD6,0xBF,0xD8,0xD6,0xC6,0xCF,0xB5,0xCD,0xB3,0xC6,0xF4,0xB6,0xAF,0xCD,0xEA,0xB3,0xC9};
char shutDOWN1[8]={0x00,0x04,0x00,0x0c,0x00,0x01,0x01,0x0f};
char shutDOWN2[8]={0x00,0x04,0x00,0x0c,0x00,0x02,0x01,0x0f};

int main()
{
	delay_init();           //延时初始化；
	KEY_Init();
	break_machine_init();   //闸机初始化；
	sk_coil_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);      //串口初始化；ttl2Pc
	uart2_init(9600);     //串口2初始化；cardID
	uart3_init(9600);     //语音模块串口3初始化
	LED_BEEP_Init();
	LED0_Init();          //检测压线模块初始化
	TIM_Init(4999,7199);  //定时器定时500ms
	
	
	IWDG_Init(6,625);
	XFS_FrameInfo(voice,22);
//	Send2Pc(test);
	while(1)
	{
		tcpcmd();
		Card();
		IWDG_Feed(); //喂狗
		//Send2Pc(&test[0]);
		//XFS_FrameInfo(voice,4);
		//delay_ms(50000);
		switch(INFORM)
		{
			case BM_flag:
				if(INFORM==BM_flag)
				{
				  INFORM=0;
				}
				 zj_flag1=1;
				 zj_flag2=1;
				//XFS_FrameInfo(pc_voice);
				 break;
			case CARD_flag:
				if(INFORM==CARD_flag)
				{
				 INFORM=0;
				}
				if(DG==0)
				Send2Pc(cardID,12);
				else if(DG==1)
				{
					if((sk_coil1)==0)
					{
						Send2Pc(cardID,12);
					}
				}
				 break;
			default:
				INFORM=0;
				break;
		}
		//判断汽车是否出门。出门则发送闸机已闭合指令。
		out = KEY_Scan(1);
		/*if(out==KEY0_PRES)
		{
			Send2Pc(shutDOWN1,8);
		}
		else if(out==KEY1_PRES)
		{
			Send2Pc(shutDOWN2,8);
		}
		IWDG_Feed(); //喂狗*/
	}
}
















