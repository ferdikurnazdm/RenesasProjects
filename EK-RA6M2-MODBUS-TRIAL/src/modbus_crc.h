/*
 * modbus_crc.h
 *
 *  Created on: 20 Haz 2023
 *      Author: ferdi.kurnaz
 */

#ifndef MODBUS_CRC_H_
#define MODBUS_CRC_H_
#include "common_data.h"
#include "hal_data.h"

uint16_t generate_crc_16(uint8_t *buffer, uint16_t buffer_lenght);

#endif /* MODBUS_CRC_H_ */
