/*
 * port.c
 *
 *  Created on: 2021��4��22��
 *      Author: YGG
 */
#include "port.h"


/************************
�������ƣ�Gpio_Init
�������ã�Gpio��ʼ��
������������
��������ֵ����
�������ߣ�YGG
*************************/
void Gpio_Init(void)
{
	Uart0_Port_Init();
	CAN_Port_Init();
	Sport_port_Init();
}
/************************
�������ƣ�Uart0_Port_Init
�������ã�USBת���ڹܽų�ʼ��
������������
��������ֵ����
�ܽţ�PB8 TX  PB9RX
�������ߣ�YGG
*************************/
void Uart0_Port_Init(void)
{
	*pREG_PORTB_FER_CLR  |= 1<<8;
	*pREG_PORTB_INEN_CLR |= 1<<8;
	*pREG_PORTB_DIR_SET  |= 1<<8;

	*pREG_PORTB_FER_CLR  |= 1<<9;
	*pREG_PORTB_DIR_CLR  |= 1<<9;
	*pREG_PORTB_INEN_SET |= 1<<9;

	*pREG_PORTB_FER |= 1<<8;										//���Ÿ���
	*pREG_PORTB_FER |= 1<<9;										//���Ÿ���

}
/************************
�������ƣ�CAN_Port_Init
�������ã�CAN�ܽų�ʼ��
������������
��������ֵ����
�ܽţ� PC2 RX  PC3 TX
�������ߣ�YGG
*************************/
void CAN_Port_Init(void)
{
	*pREG_PORTC_MUX |= (1 << 4 | 1 << 6);
	*pREG_PORTA_FER |= ((0x01<<2) | (0x01<<3));
}

/************************
�������ƣ�Sport_port_Init
�������ã�SPORT�ܽų�ʼ��
������������
��������ֵ����
�ܽţ�
�������ߣ�YGG
*************************/
void Sport_port_Init(void)
{
	*pREG_PORTC_FER |= ((0x01<<7)|(0x01<<8)|(0x01<<9));	//�˿ڸ���
	*pREG_PORTC_MUX |= ((0x02<<14)|(0x02<<16)|(0x02<<18));	//�˿ڸ��ù���
	*pREG_PORTC_FER |= ((0x01<<4)|(0x01<<5)|(0x01<<6));	//�˿ڸ���
	*pREG_PORTC_MUX |= ((0x01<<8)|(0x01<<10)|(0x01<<12));	//�˿ڸ��ù���
}
