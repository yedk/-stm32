#include "card.h"
#include "delay.h"


void Card()
{
	if(USART_RX_STA_2==12)
	{
		//cardID[10]=0x00;


		BEEP=1;
		delay_ms(500);
		BEEP=0;
		cardID[11]=0x0f;
		cardID[10]=0x01;
		cardID[9]=USART_RX_BUF2[6];
		cardID[8]=USART_RX_BUF2[5];
		//cardID[7]=USART_RX_BUF2[9];
		//cardID[6]=USART_RX_BUF2[10];
		cardID[6]=USART_RX_BUF2[2];
		cardID[7]=USART_RX_BUF2[4];
		cardID[5]=0x00;
		cardID[4]=0x00;
		cardID[3]=0x0B;
		cardID[2]=0x00;
		cardID[1]=0x0A;
		cardID[0]=0x00;
		USART_RX_STA_2=0;
		INFORM = 2;
	}
}
