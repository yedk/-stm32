#include "sys.h"
#include "usart1.h"

extern unsigned int INFORM;

void uart1_init(u32 bound)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef  NVIC_InitTStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin10;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	NVIC_InitTStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitTStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitTStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitTStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitTStructure);
	
	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//1个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;   //无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//收发模式
	
	USART_Init(USART1,&USART_InitStructure);//初始化串口1；
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1,ENABLE);//使能串口1；
	
}

u8 countU1=0;
void USART1_IRQHandler(void)
{
	u8 Res,i;
	static u8 cmd
}