/*
 * uart_codes.c
 *
 *  Created on: 9 May 2023
 *      Author: ferdi.kurnaz
 */
///////////////////////////////////////
//-------imports---------------------//
#include "common_data.h"
#include "uart_code.h"
#include "r_ioport_cfg.h"
#include "r_sci_uart_cfg.h"
#include "r_sci_uart.h"
#include "r_ioport.h"
#include "r_ioport_api.h"
#include "hal_data.h"

//////////////////////////////////////
//------------descriptions----------//
fsp_err_t err = FSP_SUCCESS;
uint8_t banner[] = MEGABANNER;
uint8_t buffer[11];        //{0x02,'','','','',''};

//////////////////////////////////////
//------------methods---------------//
fsp_err_t uart_init(void) {
    err = R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);
    return err;
}

fsp_err_t uart_write_banner(void) {
    err = R_SCI_UART_Write(&g_uart0_ctrl, banner, sizeof(banner));
    return err;
}

uint8_t * uart_read(void) {
    R_SCI_UART_Read(&g_uart0_ctrl, buffer, sizeof(buffer));
    return &buffer;
}

fsp_err_t uart_write(uint8_t * p_src) {
    err = R_SCI_UART_Write(&g_uart0_ctrl, p_src, sizeof(buffer));
    return err;
}

fsp_err_t uart_stop(void) {
    err = R_GPT_Stop(&g_timer0_ctrl);
    return err;
}
fsp_err_t uart_start(void) {
    err = R_GPT_Start(&g_timer0_ctrl);
    return err;
}
