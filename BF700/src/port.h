/*
 * port.h
 *
 *  Created on: 2021��4��22��
 *      Author: YGG
 */

#ifndef PORT_H_
#define PORT_H_
#include "BF700.h"



void Gpio_Init(void);
void Uart0_Port_Init(void);
void CAN_Port_Init(void);
void Sport_port_Init(void);
#endif /* PORT_H_ */
