/*
 * adau1977.c
 *
 *  Created on: 2021Äê4ÔÂ22ÈÕ
 *      Author: YGG
 */
#include "adau1977.h"

struct Config_Table Config_array_Adau1977[16] = {

		 {ADAU1977_REG_BOOST			,	0xDA},
		 {ADAU1977_REG_MICBIAS			,	0x0D},
		 {ADAU1977_REG_BLOCK_POWER_SAI	,	0x70},
		 {ADAU1977_REG_SAI_CTRL0		,	0x1B},/*I2S 48kHz*/
		 {ADAU1977_REG_SAI_CTRL1		,	0x08},//
		 {ADAU1977_REG_CMAP12			,	0x01},
		 {ADAU1977_REG_CMAP34			,	0x23},
		 {ADAU1977_REG_SAI_OVERTEMP		,	0xf0},
		 {ADAU1977_REG_POST_ADC_GAIN1 	,	0xA0},
		 {ADAU1977_REG_POST_ADC_GAIN2 	,	0xA0},
		 {ADAU1977_REG_POST_ADC_GAIN3 	,	0xA0},
		 {ADAU1977_REG_POST_ADC_GAIN4 	,	0xA0},
		 {ADAU1977_REG_ADC_CLIP			,	0x00},
		 {ADAU1977_REG_DC_HPF_CAL		,	0x00},
		 {ADAU1977_REG_BLOCK_POWER_SAI	,	0x7f},
		 {ADAU1977_REG_MISC_CONTROL		,	0x00}
};

static uint8_t Adau1977_All_Reg[28];

void Adau1977_ReadAll(uint8_t* data)
{
	int i = 0;
	int len = sizeof(Adau1977_All_Reg);
	for(i = 0;i<len;i++)
	{
		Twi_ReadRegister(i,&data[i]);
	}
}

void Init_Adau1977(void)
{
	int i = 0,delay1=0xffff;
	int len = sizeof(Config_array_Adau1977)/sizeof(struct Config_Table);
	uint8_t sendBuffer[2];
	uint8_t tempdata = 0;
	Init_Adau1977_IIC();

	sendBuffer[0] = ADAU1977_REG_POWER;
	sendBuffer[1] = 0x01;
	Twi_WriteData(sendBuffer,2);
	while(delay1--)
	{
		asm("nop;");
	}

	sendBuffer[0] = ADAU1977_REG_PLL;
	sendBuffer[1] = 0x03;
	Twi_WriteData(sendBuffer,2);
	delay1=0xffff;
	while(delay1--)
	{
		asm("nop;");
	}

	Twi_ReadRegister(ADAU1977_REG_PLL,&tempdata);
	delay1=0xffff;
	while(delay1--)
	{
		asm("nop;");
	}

	while(!((tempdata & 0x80)>>7)  )
	{
		Twi_ReadRegister(ADAU1977_REG_PLL,&tempdata);
		asm("nop;");
	}

	for(i = 0;i < len;i++)
	{
		sendBuffer[0] = (uint8_t)Config_array_Adau1977[i].Reg_Add;
		sendBuffer[1] = (uint8_t)Config_array_Adau1977[i].Value;
		Twi_WriteData(sendBuffer,2);
	}
	Adau1977_ReadAll(Adau1977_All_Reg);

	Adau1977_CLOSE();
}

