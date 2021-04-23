/*
 * twi.c
 *
 *  Created on: 2021Äê4ÔÂ22ÈÕ
 *      Author: YGG
 */

#include "twi.h"
#include <drivers/twi/adi_twi.h>

static ADI_TWI_HANDLE hDevice_Twi;
uint8_t deviceMemory[ADI_TWI_MEMORY_SIZE];
uint8_t devBuffer[BUFFER_SIZE];

void Twi_ReadRegister(uint8_t reg, uint8_t *value)
{
	ADI_TWI_RESULT eResult;
	unsigned char Rx_Data;

	/* write register address */
	devBuffer[0] = reg;
	eResult = adi_twi_Write(hDevice_Twi, devBuffer, 1u, true);
	if(eResult!=ADI_TWI_SUCCESS)
	{
		printf("TWI write failed 0x%08X\n", eResult);
	}

	/* read register value */
	eResult = adi_twi_Read(hDevice_Twi, &Rx_Data, 1u, false);
	if(eResult!=ADI_TWI_SUCCESS)
	{
		printf("TWI Read failed 0x%08X\n", eResult);
	}

	*value =  Rx_Data;
}

void Init_Twi(uint32_t const  DeviceNum,
				uint16_t const Prescale,
				uint16_t const BitRate,
				uint16_t const DutyCycle,
				uint16_t const Address
										)
{
	adi_twi_Open(DeviceNum, ADI_TWI_MASTER, &deviceMemory[0],
				ADI_TWI_MEMORY_SIZE, &hDevice_Twi);

	adi_twi_SetPrescale(hDevice_Twi, Prescale);

	adi_twi_SetBitRate(hDevice_Twi, BitRate);

	adi_twi_SetDutyCycle(hDevice_Twi, DutyCycle);

	adi_twi_SetHardwareAddress(hDevice_Twi, Address);
}

void Twi_WriteData(uint8_t* data,uint16_t len)
{
	ADI_TWI_RESULT eResult;
	eResult = adi_twi_Write(hDevice_Twi, data, len, false);
	if(eResult!=ADI_TWI_SUCCESS)
	{
		printf("adi_twi_Write failed 0x%08X\n", eResult);
	}
}

void Twi_Close(void)
{
	ADI_TWI_RESULT eResult;
	eResult = adi_twi_Close(hDevice_Twi);
	if(eResult!=ADI_TWI_SUCCESS)
	{
		printf("adi_twi_Close failed 0x%08X\n", eResult);
	}
}

