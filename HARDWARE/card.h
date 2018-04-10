#ifndef __CARD_H
#define __CARD_H
#include "sys.h"
#include "usart.h"


extern u8 USART_RX_BUF2[USART_REC_LEN];
extern u16 USART_RX_STA_2; 
//extern u8 USART_RX_BUF2[USART_REC_LEN];
//extern u16 USART_RX_STA_2;
extern u8 INFORM;
extern char cardID[12];

void Card(void);

#endif
