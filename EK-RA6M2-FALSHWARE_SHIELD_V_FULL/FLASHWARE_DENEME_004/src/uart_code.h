/*
 * uart_code.h
 *
 *  Created on: 22 Haz 2023
 *      Author: ferdi.kurnaz
 */

#ifndef UART_CODE_H_
#define UART_CODE_H_
#define MEGABANNER "MEGA ENDUSTRI"
#define BANNER1 "FERDI KURNAZ"

fsp_err_t uart0_init(void);
fsp_err_t uart1_init(void);
fsp_err_t uart0_write(uint8_t * p_src);
fsp_err_t uart1_write(uint8_t * p_src);
uint8_t * uart0_read(void);
uint8_t * uart1_read(void);
fsp_err_t uart0_shut_down(void);
fsp_err_t uart1_shut_down(void);
fsp_err_t uart_write_banner(void);
void uart_buffer0_set_zero(void);
void uart_buffer1_set_zero(void);
void uart_buffer0_set_default_q1(void);
void uart_buffer0_set_default_q2(void);
void uart_buffer1_set_default_q1(void);
void uart_buffer1_set_default_q2(void);

#endif /* UART_CODE_H_ */
