/*
 * uart_code.h
 *
 *  Created on: 5 Haz 2023
 *      Author: ferdi.kurnaz
 */

#ifndef UART_CODE_H_
#define UART_CODE_H_

#define MEGABANNER "MEGA ENDUSTRI"


fsp_err_t uart_init(void);
fsp_err_t uart_write_banner(void);
fsp_err_t uart_write(uint8_t * p_src);
uint8_t * uart_read(void);
int get_array_size();

#endif /* UART_CODE_H_ */
