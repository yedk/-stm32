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
	//len = USART_RX_STA&0x3fff;//数据接收长度；
	//得到消息的数据长度；
	for(t=0;t<len;t++)
	{
		USART_SendData(USART1,*buf);//
		buf++;
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送；
	}
}


void tcpcmd()
{
	char ack[8]={0x00,0x06,0x00,0x0A,0x00,0x00,0x01,0x0f};
	char ack1[8]={0x00,0x06,0x00,0x0D,0x00,0x00,0x01,0x0f};
	char i=0;
	char voice1[50];
	if(USART_RX_STA&0x8000)
	{
		if((USART_RX_BUF[1]==0x06)&&(USART_RX_BUF[2]==0x00)&&(USART_RX_BUF[3]==0x00)&&(USART_RX_BUF[4]==0x00)&&(USART_RX_BUF[5]==0x00))
		{
			Send2Pc(ack,8);
			INFORM=1;//闸机开启标志；
			//USART_RX_BUF[5]=0;
			//USART_RX_STA=0;
			Send2Pc(ack1,8);
		}
		else if((USART_RX_BUF[2]==0x00)&&(USART_RX_BUF[3]==0x01))
		{
			ack[5]=0x01;
			Send2Pc(ack,8);
			for(i=0;i<=(USART_RX_BUF[1]-6);i++)
			{
				voice1[i]=USART_RX_BUF[(i+6)];
			}
			XFS_FrameInfo(voice1,(USART_RX_BUF[1]-6));
			ack1[5]=0x01;
			Send2Pc(ack1,8);
		}
		else if((USART_RX_BUF[1]==0x06)&&(USART_RX_BUF[2]==0x00)&&(USART_RX_BUF[3]==0x02)&&(USART_RX_BUF[4]==0x00))//查询地感状态指令
		{
			ack[5]=0x02;
			Send2Pc(ack,8);
			if(USART_RX_BUF[5]==0)
				DG=0;
			if(USART_RX_BUF[5]==0x02)
			{
				DG=1;
			}
			ack1[5]=0x02;
			Send2Pc(ack1,8);
		}
		USART_RX_STA=0;//接收标志清零；
	}
}

