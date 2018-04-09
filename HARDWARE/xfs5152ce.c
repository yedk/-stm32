#include "xfs5152ce.h"




/**************芯片设置命令***************/
char XFS_StopCom[] = {0xFD,0x00,0x01,0x02};//停止合成
char XFS_SuspendCom[] = {0xFD,0x00,0x01,0x03};//暂停合成
char XFS_RecoverCom[] = {0xFD,0x00,0x01,0x04};//恢复合成
char XFS_ChackCom[] = {0xFD,0x00,0x01,0x21};//状态查询
char XFS_PowerDownCom[] = {0xfd,0x00,0x01,0x88};//进入POWER DOWN模式
/****************************/

/*****************************
*名称： YS-XFS5051 文本合成函数
******************************/

void XFS_FrameInfo(char *HZdata,char HZ_Length)
{
	char Frame_Info[50];
	//int  HZ_Length;
	
	int  i = 0;
	//HZ_Length =strlen(HZdata);
	
	Frame_Info[0] = 0xFD ;
	Frame_Info[1] = 0x00 ;
	Frame_Info[2] = HZ_Length+2;
	Frame_Info[3] = 0x01;   //构造命令字：合成播放命令
	Frame_Info[4] = 0x01;  //文本编码格式：GBK
	
	
	memcpy(&Frame_Info[5],HZdata,HZ_Length);
	USART_SendData(USART3,0xF5);
	while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
	for(i=0;i<HZ_Length+5;i++)
	{
		USART_SendData(USART3,Frame_Info[i]);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
	}
}

/*************************
*功能设置函数
*对XFS进行配置；
**************************/

void XFS_Set(char *Info_data)
{
	char Com_Len;
	char i;
	Com_Len = strlen(Info_data);
	for(i=0;i<Com_Len;i++)
	{
		USART_SendData(USART3,*Info_data++);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);
	}
}

