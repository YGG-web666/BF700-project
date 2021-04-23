/*
 * port.c
 *
 *  Created on: 2021年4月22日
 *      Author: YGG
 */
#include "port.h"


/************************
函数名称：Gpio_Init
函数作用：Gpio初始化
函数参数：无
函数返回值：无
函数作者：YGG
*************************/
void Gpio_Init(void)
{
	Uart0_Port_Init();
	CAN_Port_Init();
	Sport_port_Init();
}
/************************
函数名称：Uart0_Port_Init
函数作用：USB转串口管脚初始化
函数参数：无
函数返回值：无
管脚：PB8 TX  PB9RX
函数作者：YGG
*************************/
void Uart0_Port_Init(void)
{
	*pREG_PORTB_FER_CLR  |= 1<<8;
	*pREG_PORTB_INEN_CLR |= 1<<8;
	*pREG_PORTB_DIR_SET  |= 1<<8;

	*pREG_PORTB_FER_CLR  |= 1<<9;
	*pREG_PORTB_DIR_CLR  |= 1<<9;
	*pREG_PORTB_INEN_SET |= 1<<9;

	*pREG_PORTB_FER |= 1<<8;										//引脚复用
	*pREG_PORTB_FER |= 1<<9;										//引脚复用

}
/************************
函数名称：CAN_Port_Init
函数作用：CAN管脚初始化
函数参数：无
函数返回值：无
管脚： PC2 RX  PC3 TX
函数作者：YGG
*************************/
void CAN_Port_Init(void)
{
	*pREG_PORTC_MUX |= (1 << 4 | 1 << 6);
	*pREG_PORTA_FER |= ((0x01<<2) | (0x01<<3));
}

/************************
函数名称：Sport_port_Init
函数作用：SPORT管脚初始化
函数参数：无
函数返回值：无
管脚：
函数作者：YGG
*************************/
void Sport_port_Init(void)
{
	*pREG_PORTC_FER |= ((0x01<<7)|(0x01<<8)|(0x01<<9));	//端口复用
	*pREG_PORTC_MUX |= ((0x02<<14)|(0x02<<16)|(0x02<<18));	//端口复用功能
	*pREG_PORTC_FER |= ((0x01<<4)|(0x01<<5)|(0x01<<6));	//端口复用
	*pREG_PORTC_MUX |= ((0x01<<8)|(0x01<<10)|(0x01<<12));	//端口复用功能
}
