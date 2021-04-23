/*
 * uart.h
 *
 *  Created on: 2021Äê4ÔÂ22ÈÕ
 *      Author: YGG
 */

#ifndef UART_H_
#define UART_H_
#include "BF700.h"

#define BAUD_2400		41667
#define BAUD_4800		20833
#define BAUD_9600		10417
#define BAUD_19200		5208
#define BAUD_38400		2604
#define BAUD_57600		1736
#define BAUD_115200		868
#define BAUD_230400		434
#define BAUD_921600		109
#define BAUD_1500K		67
#define BAUD_3000K		33
#define BAUD_6250K		16

#define UART_CLK_DIV_MASK		0X80000000
#define UART_CLK_1DIV			0X80000000
#define UART_CLK_16DIV			0X00000000
#define BAUD_MASK				0x0000FFFF
#define UART_MODE_MASK			(0X03<<4)
#define UART_MODE_UART			(0X00<<4)
#define UART_MODE_MDB			(0X01<<4)
#define UART_MODE_SIR			(0X02<<4)
#define UART_LENGTH_MASK		(0X03<<8)
#define UART_LENGTH_5BIT		(0X00<<8)
#define UART_LENGTH_6BIT		(0X01<<8)
#define UART_LENGTH_7BIT		(0X02<<8)
#define UART_LENGTH_8BIT		(0X03<<8)
#define UART_EN_MASK			(uint32_t)0X01
#define UART_EN					(uint32_t)0X01

#define UART0_RX_STAT_DR		1<<0
#define UART0_TX_STAT_THRE		1<<5

void uart0_Config(uint32_t baudrate);
void uart_echo(void);
#endif /* UART_H_ */
