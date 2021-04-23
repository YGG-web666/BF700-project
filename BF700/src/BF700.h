/*****************************************************************************
 * BF700.h
 *****************************************************************************/

#ifndef __BF700_H__
#define __BF700_H__
#include <services/gpio/adi_gpio.h>
#include <drivers/twi/adi_twi.h>
#include <services/pwr/adi_pwr.h>
#include <drivers/sport/adi_sport.h>
#include <services/spu/adi_spu.h>
#include "stdio.h"

#include "port.h"
#include "uart.h"
#include "can.h"
#include "twi.h"
#include "sport.h"
#include "adau1977.h"


struct Config_Table
{
	short Reg_Add;
	char  Value;
};

#endif /* __BF700_H__ */
