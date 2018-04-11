#ifndef __TTL2TCP_H
#define __TTL2TCP_H

//#include "sys.h"
#include "usart.h"


extern char USART_RX_BUF[USART_REC_LEN];
extern u16 USART_RX_STA; 
extern char zj_flag1;
extern char zj_flag2;
extern char DG;

void tcpcmd(void);
void Send2Pc(char * buf,char len);

#endif
