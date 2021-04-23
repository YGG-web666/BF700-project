/*
 * uart.c
 *
 *  Created on: 2021��4��22��
 *      Author: YGG
 */
#include "uart.h"
void UartCallback(uint32_t  iid,void* handlerArg);


/************************
�������ƣ�uart0_Config
�������ã�UART0���ó�ʼ��
����������baudrate ������
��������ֵ����
�������ߣ�YGG
*************************/
void uart0_Config(uint32_t baudrate)
{

	*pREG_UART0_CLK &= ~UART_CLK_DIV_MASK;
	*pREG_UART0_CLK |= UART_CLK_1DIV;							//ÿ1��sclk0 ����һ��UART_CLK

	*pREG_UART0_CLK &= ~BAUD_MASK;
	*pREG_UART0_CLK |= baudrate;

	*pREG_UART0_CTL &= ~UART_MODE_MASK;
	*pREG_UART0_CTL |= UART_MODE_UART;							//����ģʽ
	*pREG_UART0_CTL &= ~UART_LENGTH_MASK;
	*pREG_UART0_CTL |= UART_LENGTH_8BIT;							//���ݳ���8λ

	*pREG_UART0_IMSK_SET = ((0x01<<5)|(0x01)|(0x01<<8));

	*pREG_UART0_CTL &= ~UART_EN_MASK;
	*pREG_UART0_CTL |= UART_EN;									//ʹ��
//	adi_int_InstallHandler(INTR_UART0_STAT,UartCallback,NULL,true);
}
/************************
�������ƣ�uart_echo
�������ã�UART0����
������������
��������ֵ����
�������ߣ�YGG
*************************/
void uart_echo(void)
{
	uint8_t date = 0x00;

	while((*pREG_UART0_STAT & UART0_RX_STAT_DR) == 0); //���յ���������
    date = *pREG_UART0_RBR;
    while( (*pREG_UART0_STAT & UART0_TX_STAT_THRE) == 0);   //�����������
    *pREG_UART0_THR = date;
}
/************************
�������ƣ�UartCallback
�������ã�UART0�ж�
������������
��������ֵ����
�������ߣ�YGG
*************************/
void UartCallback(uint32_t  iid,void* handlerArg)
{
	if(*pREG_UART0_STAT & UART0_RX_STAT_DR)     //��������ж�
	{
		*pREG_UART0_STAT &= ~(1<<0);
	}

	if(*pREG_UART0_STAT & UART0_TX_STAT_THRE)   //��������ж�
	{

	}
}
/************************
�������ƣ�fputc
�������ã�printf�ض���
������������
��������ֵ����
�������ߣ�YGG
*************************/
static int fputc(int c,FILE *stream)
{
	while(*pREG_UART0_STAT & UART0_TX_STAT_THRE);  //�ȴ����ڷ������

	*pREG_UART0_THR = c;

	return c;
}
