#include "sys.h"
#include "ttl2tcp.h"
#include "delay.h"
#include <string.h>
#include "xfs5152ce.h"


extern u8 INFORM;
extern char* pc_voice;

void Send2Pc(char * buf,char len)
{
	u16 t;
	//char len;
	//len = strlen(buf);
	//len = USART_RX_STA&0x3fff;//���ݽ��ճ��ȣ�
	//�õ���Ϣ�����ݳ��ȣ�
	for(t=0;t<len;t++)
	{
		USART_SendData(USART1,*buf);//
		buf++;
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͣ�
	}
}


void tcpcmd()
{
	char ack[6]={0x00,0x04,0x00,0x0A,0x00,0x00};
	//char len;
//	char t=0;
	//char a =-1;
	char i=0;
	char voice1[50];
//	char *voice_p_temp;
	if(USART_RX_STA&0x8000)
	{
		if((USART_RX_BUF[1]==0x04)&&(USART_RX_BUF[2]==0x00)&&(USART_RX_BUF[3]==0x00)&&(USART_RX_BUF[4]==0x00)&&(USART_RX_BUF[5]==0x00))
		{
			
			INFORM=1;//բ��������־��
			USART_RX_BUF[5]=0;
			USART_RX_STA=0;
			INFORM=1;
			BEEP=1;
			delay_ms(1000);
			BEEP=0;
			Send2Pc(ack,6);
		}
		else if((USART_RX_BUF[2]==0x00)&&(USART_RX_BUF[3]==0x01))
		{
			//Send2Pc(ack,6);
			for(i=0;i<=(USART_RX_BUF[1]-4);i++)
			{
				voice1[i]=USART_RX_BUF[(i+6)];
			}
			//Send2Pc(&a,1);
			Send2Pc(USART_RX_BUF,18);
			//memcpy(voice1,USART_RX_BUF[6],(USART_RX_BUF[1]-4));
			XFS_FrameInfo(voice1,(USART_RX_BUF[1]-4));
			//XFS_FrameInfo(voice1,4);
			//
			Send2Pc(ack,6);
		}
		else if((USART_RX_BUF[1]==0x04)&&(USART_RX_BUF[2]==0x00)&&(USART_RX_BUF[3]==0x00)&&(USART_RX_BUF[4]==0x00)&&(USART_RX_BUF[5]==0x01))
		{
			
			INFORM=1;//բ��������־��
			//BEEP=1;
			//delay_ms(1000);
			//BEEP=0;
			USART_RX_BUF[5]=0;
			Send2Pc(ack,6);
		}
		USART_RX_STA=0;//���ձ�־���㣻
	}
}

