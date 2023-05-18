/*
 * uart_code.h
 *
 *  Created on: 9 May 2023
 *      Author: ferdi.kurnaz
 */

#ifndef UART_CODE_H_
#define UART_CODE_H_
#define MEGABANNER "MEGA ENDUSTRI"


fsp_err_t uart_init(void);
fsp_err_t uart_write_banner(void);
fsp_err_t uart_write(uint8_t * p_src);
fsp_err_t uart_stop(void);
fsp_err_t uart_start(void);
uint8_t * uart_read(void);

#endif /* UART_CODE_H_ */
