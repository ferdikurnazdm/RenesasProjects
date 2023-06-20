/*
 * modbus_rtu_code.h
 *
 *  Created on: 19 Haz 2023
 *      Author: ferdi.kurnaz
 */

#ifndef MODBUS_RTU_CODE_H_
#define MODBUS_RTU_CODE_H_


fsp_err_t modbus_rtu_init(void);
fsp_err_t modbus_shut_down(void);
uint16_t modbus_calculate_crc(unsigned char buf[], int len);
unsigned int hex_swap(uint16_t hex);
void insert_crc(void);
void modbus_generate_request(void);
void modbus_send(uint8_t * data);
void modbus_read(void);

#endif /* MODBUS_RTU_CODE_H_ */
