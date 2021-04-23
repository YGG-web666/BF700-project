/*
 * twi.h
 *
 *  Created on: 2021Äê4ÔÂ22ÈÕ
 *      Author: YGG
 */

#ifndef TWI_H_
#define TWI_H_
#include "BF700.h"

#define BUFFER_SIZE   (8)

#define TWIDEVNUM     (0u)        /* TWI device number */
#define PRESCALEVALUE (12u)       /* fSCLK/10MHz (125 sclk0_0) */
#define BITRATE       (100u)      /* kHz */
#define DUTYCYCLE     (50u)       /* percent */

void Init_Twi(uint32_t const  DeviceNum,
				uint16_t const Prescale,
				uint16_t const BitRate,
				uint16_t const DutyCycle,
				uint16_t const Address
										);
void Twi_Close(void);
void Twi_WriteData(uint8_t* data,uint16_t len);
void Twi_ReadRegister(uint8_t reg, uint8_t *value);
#endif /* TWI_H_ */
