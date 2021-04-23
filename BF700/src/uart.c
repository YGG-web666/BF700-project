/*
 * uart.c
 *
 *  Created on: 2021年4月22日
 *      Author: YGG
 */
#include "uart.h"
void UartCallback(uint32_t  iid,void* handlerArg);


/************************
函数名称：uart0_Config
函数作用：UART0配置初始化
函数参数：baudrate 波特率
函数返回值：无
函数作者：YGG
*************************/
void uart0_Config(uint32_t baudrate)
{

	*pREG_UART0_CLK &= ~UART_CLK_DIV_MASK;
	*pREG_UART0_CLK |= UART_CLK_1DIV;							//每1个sclk0 产生一个UART_CLK

	*pREG_UART0_CLK &= ~BAUD_MASK;
	*pREG_UART0_CLK |= baudrate;

	*pREG_UART0_CTL &= ~UART_MODE_MASK;
	*pREG_UART0_CTL |= UART_MODE_UART;							//串口模式
	*pREG_UART0_CTL &= ~UART_LENGTH_MASK;
	*pREG_UART0_CTL |= UART_LENGTH_8BIT;							//数据长度8位

	*pREG_UART0_IMSK_SET = ((0x01<<5)|(0x01)|(0x01<<8));

	*pREG_UART0_CTL &= ~UART_EN_MASK;
	*pREG_UART0_CTL |= UART_EN;									//使能
//	adi_int_InstallHandler(INTR_UART0_STAT,UartCallback,NULL,true);
}
/************************
函数名称：uart_echo
函数作用：UART0回显
函数参数：无
函数返回值：无
函数作者：YGG
*************************/
void uart_echo(void)
{
	uint8_t date = 0x00;

	while((*pREG_UART0_STAT & UART0_RX_STAT_DR) == 0); //接收到数据跳出
    date = *pREG_UART0_RBR;
    while( (*pREG_UART0_STAT & UART0_TX_STAT_THRE) == 0);   //发送完成跳出
    *pREG_UART0_THR = date;
}
/************************
函数名称：UartCallback
函数作用：UART0中断
函数参数：无
函数返回值：无
函数作者：YGG
*************************/
void UartCallback(uint32_t  iid,void* handlerArg)
{
	if(*pREG_UART0_STAT & UART0_RX_STAT_DR)     //接收完成中断
	{
		*pREG_UART0_STAT &= ~(1<<0);
	}

	if(*pREG_UART0_STAT & UART0_TX_STAT_THRE)   //发送完成中断
	{

	}
}
/************************
函数名称：fputc
函数作用：printf重定向
函数参数：无
函数返回值：无
函数作者：YGG
*************************/
static int fputc(int c,FILE *stream)
{
	while(*pREG_UART0_STAT & UART0_TX_STAT_THRE);  //等待串口发送完成

	*pREG_UART0_THR = c;

	return c;
}
