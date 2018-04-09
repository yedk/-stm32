#include "card.h"


void Card()
{
	if(USART_RX_STA_2==12)
	{
		//cardID[10]=0x00;

		cardID[9]=USART_RX_BUF2[7];
		cardID[8]=USART_RX_BUF2[8];
		cardID[7]=USART_RX_BUF2[9];
		cardID[6]=USART_RX_BUF2[10];
		cardID[5]=0x00;
		cardID[4]=0x00;
		cardID[3]=0x0B;
		cardID[2]=0x00;
		cardID[1]=0x08;
		cardID[0]=0x00;
		USART_RX_STA_2=0;
		INFORM = 2;
	}
}
