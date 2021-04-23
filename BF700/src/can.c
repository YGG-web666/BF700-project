/*
 * can.c
 *
 *  Created on: 2021年4月22日
 *      Author: YGG
 */

#include "can.h"

void Can_config(void)
{
	*pREG_CAN0_CLK = 19; //TQ = (BRP + 1)/SCLK0 =  1/5MHz
	*pREG_CAN0_TIMING |= 6; //TSEG1
	*pREG_CAN0_TIMING |= 1<<4; //TSEG2
	*pREG_CAN0_TIMING |= 0<<7; //不重复采样
	*pREG_CAN0_TIMING |= 0<<8; //同步TQ数   （1 + SJW）
	*pREG_CAN0_CTL &= ~(0x01<<7);//EXIT CONFGRATION mode

	*pREG_CAN0_CTL &= ~(0x01<<7); // (Exit Configuration Mode)
	*pREG_CAN0_CTL |= (0x01<<1); 	//Device Net Mode
}

/************************
函数名称：CAN_MailboxX_ReadInit
函数作用：Can0接收邮箱初始化
函数参数：Boxnum （1-32）邮箱号;stdid （0xXXX）11位标准ID
函数返回值：无
函数作者：YGG
*************************/
void CAN_MailboxX_ReadInit(uint8_t Boxnum,uint16_t stdId)
{
	*pREG_CAN0_MC1 |= (0x01<<Boxnum); //enable mailbox8
	*pREG_CAN0_MD1 |= (0x01<<Boxnum); //DIR  input

	*(uint32_t *)(REG_CAN0_AM00H + 8*Boxnum) = 0x01<<14;
	*(uint32_t *)(REG_CAN0_AM00H + 8*Boxnum) |= stdId<<2;//滤波掩码

	*(uint32_t *)(REG_CAN0_MB00_ID1 + 0x20*Boxnum) = 0;
	*(uint32_t *)(REG_CAN0_MB00_ID1 + 0x20*Boxnum) |= stdId<<2;//
}
