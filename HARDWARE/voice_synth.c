#include "voice_synth.h"

void query()
{
		USART_SendData(USART3,0xFD);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0x00);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0x01);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0x21);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
}

void power_saving()
{
		USART_SendData(USART3,0xFD);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0x00);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0x01);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0x88);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
}

void weak_up()
{
	USART_SendData(USART3,0xFD);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0x00);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0x01);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET)
		{};
	  USART_SendData(USART3,0xFF);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
}

void send_voice()
{
	char nlength;
	char i;
	char buf;
	nlength = strlen(voice_code);
		USART_SendData(USART3,0xFD00);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
	  USART_SendData(USART3,0x0A01);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
		USART_SendData(USART3,0x00);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
		for(i=0;i<nlength;i++)
			{
				buf=voice_code[i];
				while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
			}
		
}
