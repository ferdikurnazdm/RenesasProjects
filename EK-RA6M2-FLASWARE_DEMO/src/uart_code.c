/*
 * uart_code.c
 *
 *  Created on: 5 Haz 2023
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
uint8_t buffer[12];                 //[11];        //{0x02,'','','','',''};
int array_size = 0;

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
    return &buffer[0];
}

fsp_err_t uart_write(uint8_t * p_src) {
    err = R_SCI_UART_Write(&g_uart0_ctrl, p_src, sizeof(buffer));
    return err;
}

int get_array_size() {
    array_size = 0;
    int m = 0;
    for (m = 0; m < (int)sizeof(buffer); ++m) {
        if (buffer[m] !='\0' && buffer[m] != '\n') {
            array_size++;
        }
    }
    return array_size;
}
