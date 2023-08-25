/*
 * uart_code.c
 *
 *  Created on: 22 Haz 2023
 *      Author: ferdi.kurnaz
 */
#include "common_data.h"
#include "uart_code.h"
#include "r_ioport_cfg.h"
#include "r_sci_uart_cfg.h"
#include "r_sci_uart.h"
#include "r_ioport.h"
#include "r_ioport_api.h"
#include "hal_data.h"
//--------------------------------------------//
fsp_err_t err = FSP_SUCCESS;
uint8_t banner[] = MEGABANNER;
uint8_t banner_1[] = BANNER1;
uint8_t buffer_0[12];
uint8_t buffer_1[12];//[11];        //{0x02,'','','','',''};
uint8_t buffer_default_q1[12] ={0x02,'0','4','Q','1','5','0','0',0x03,'R','\0','\0'};
uint8_t buffer_default_q2[12] ={0x02,'0','4','Q','2','5','0','0',0x03,'Q','\0','\0'};
uint8_t buffer_set_zero[12]  ={0x02,'0','0','0','0','0','0','0',0x03,'3','\0','\0'};
int array_size = 0;
//-------------------------------------------//

fsp_err_t uart0_init(void) {
    err = R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);
    return err;
}

fsp_err_t uart1_init(void) {
    err = R_SCI_UART_Open(&g_uart1_ctrl, &g_uart1_cfg);
    return err;
}

fsp_err_t uart_write_banner(void) {
    err = R_SCI_UART_Write(&g_uart0_ctrl, banner, sizeof(banner));
    err = R_SCI_UART_Write(&g_uart1_ctrl, banner_1, sizeof(banner_1));
    return err;
}

uint8_t * uart0_read(void) {
    R_SCI_UART_Read(&g_uart0_ctrl, buffer_0, sizeof(buffer_0));
    return &buffer_0[0];
}

uint8_t * uart1_read(void) {
    R_SCI_UART_Read(&g_uart1_ctrl, buffer_1, sizeof(buffer_1));
    return &buffer_1[0];
}

fsp_err_t uart0_write(uint8_t * p_src) {
    err = R_SCI_UART_Write(&g_uart0_ctrl, p_src, sizeof(buffer_0));
    return err;
}

fsp_err_t uart1_write(uint8_t * p_src) {
    err = R_SCI_UART_Write(&g_uart1_ctrl, p_src, sizeof(buffer_1));
    return err;
}

void uart_buffer0_set_zero(void) {
    for (size_t i = 0; i < sizeof(buffer_0); ++i) {
        buffer_0[i] = buffer_set_zero[i];
    }
}

void uart_buffer1_set_zero(void) {
    for (size_t i = 0; i < sizeof(buffer_0); ++i) {
        buffer_1[i] = buffer_set_zero[i];
    }
}

void uart_buffer0_set_default_q1(void) {
    for (size_t i = 0; i < sizeof(buffer_0); ++i) {
        buffer_0[i] = buffer_default_q1[i];
    }
}

void uart_buffer0_set_default_q2(void) {
    for (size_t i = 0; i < sizeof(buffer_0); ++i) {
        buffer_0[i] = buffer_default_q2[i];
    }
}

void uart_buffer1_set_default_q1(void) {
    for (size_t i = 0; i < sizeof(buffer_1); ++i) {
        buffer_1[i] = buffer_default_q1[i];
    }
}

void uart_buffer1_set_default_q2(void) {
    for (size_t i = 0; i < sizeof(buffer_1); ++i) {
        buffer_1[i] = buffer_default_q2[i];
    }
}
