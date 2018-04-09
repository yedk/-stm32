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



#define BM_flag        1  //բ����־��
#define CARD_flag      2  //ˢ����־��
//#define UPLOAD_IC_flag 3  //�ϴ�IC����Ϣ��
//#define UPLOAD_flag    4  //�ϴ���Ϣ��־��

u8 INFORM=0;
u8 out;
char zj_flag1=0;            //բ����ʱ��־����zj_flag=1��ʱ�򣬶�ʱ500ms;
char zj_flag2=0;
char cardID[11];
//char test[10];
//char voice_code[]={0xBF,0xc6,0xB4,0xF3,0xD1,0xB6,0xB7,0xC9};
//char voice[]={0xC4,0xE3,0xBA,0xC3};
char voice[]={0xCE,0xD2,0xCA,0xC7,0xBF,0xC6,0xB4,0xF3,0xD1,0xB6,0xB7,0xC9};
char shutDOWN1[6]={0x00,0x04,0x00,0x0c,0x00,0x01};
char shutDOWN2[6]={0x00,0x04,0x00,0x0c,0x00,0x02};

int main()
{
	delay_init();           //��ʱ��ʼ����
	KEY_Init();
	break_machine_init();   //բ����ʼ����
	sk_coil_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);      //���ڳ�ʼ����ttl2Pc
	uart2_init(9600);     //����2��ʼ����cardID
	uart3_init(9600);     //����ģ�鴮��3��ʼ��
	LED_BEEP_Init();
	LED0_Init();          //���ѹ��ģ���ʼ��
	TIM_Init(4999,7199);  //��ʱ����ʱ500ms
	
	
	IWDG_Init(6,625);
	XFS_FrameInfo(voice,12);
//	Send2Pc(test);
	while(1)
	{
		tcpcmd();
		Card();
		IWDG_Feed(); //ι��
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
				Send2Pc(cardID,10);
				 //if((sk_coil1)==1)  //ˢ����ȦΪ�͵�ƽ��ʱ���ϴ�����Ϣ��
				 //{
				 // cardID[5]=0x01;
					//Send2Pc(cardID);
				 //}
				//else if((sk_coil2)==1)  //ˢ����ȦΪ�͵�ƽ��ʱ���ϴ�����Ϣ��
				 //{
				//cardID[5]=0x02;
					//Send2Pc(cardID);
				 //}
				 break;
			default:
				INFORM=0;
				break;
		}
		//�ж������Ƿ���š���������բ���ѱպ�ָ�
		out = KEY_Scan(1);
		/*if(out==KEY0_PRES)
		{
			Send2Pc(shutDOWN1,6);
		}
		else if(out==KEY1_PRES)
		{
			Send2Pc(shutDOWN2,6);
		}
		IWDG_Feed(); //ι��*/
	}
}
















