/*
 * modbus_rtu_code.c
 *
 *  Created on: 19 Haz 2023
 *      Author: ferdi.kurnaz
 */

#include "common_data.h"
#include "hal_data.h"
#include "r_ioport_cfg.h"
#include "r_sci_uart_cfg.h"
#include "modbus_rtu_code.h"
#include "common_utils.h"
#include "modbus_crc.h"
//---------------------------------------//
uint8_t rx_data[32];
uint8_t tx_data[8];
uint16_t salt_data[10];
fsp_err_t status_modbus;
//---------------------------------------//
/* Callback function */
void uart_callback(uart_callback_args_t *p_args)
{
    uart_event_t ue1 =UART_EVENT_RX_CHAR;
    uart_event_t ue2 =UART_EVENT_RX_COMPLETE;
    if (p_args->event == ue1){
        R_BSP_SoftwareDelay(10000, BSP_DELAY_UNITS_MILLISECONDS);
    }
    if (p_args->event == ue2){
        R_BSP_SoftwareDelay(10000, BSP_DELAY_UNITS_MILLISECONDS);
    }
    uint32_t foo = p_args->data;
    salt_data[0] = (uint16_t)(rx_data[3]  << 8 | rx_data[4]);
    salt_data[1] = (uint16_t)(rx_data[5]  << 8 | rx_data[6]);
    salt_data[2] = (uint16_t)(rx_data[7]  << 8 | rx_data[8]);
    salt_data[3] = (uint16_t)(rx_data[9]  << 8 | rx_data[10]);
    salt_data[4] = (uint16_t)(rx_data[11] << 8 | rx_data[12]);
    //p_args->data;
    /* TODO: add your own code here */
}




fsp_err_t modbus_rtu_init(){
    return status_modbus = R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);
}

fsp_err_t modbus_shut_down(){
    return status_modbus = R_SCI_UART_Close(&g_uart0_ctrl);
}

void modbus_send(uint8_t * data){
    status_modbus = R_SCI_UART_Write(&g_uart0_ctrl, data, 8);
}

void modbus_read(){
    status_modbus = R_SCI_UART_Read(&g_uart0_ctrl, rx_data, 32);
}

void modbus_generate_request(){
    tx_data[0] = 0x05; // SLAVE ADRESS
    tx_data[1] = 0x03; // FUNCTION CODE
    tx_data[2] = 0x00; // REGISTER START ADRESS MSB
    tx_data[3] = 0x04; // REGISTER START ADRESS LSB
    tx_data[4] = 0X00; // QUANTITY MSB
    tx_data[5] = 0x05; // QUANTITY LSB

    uint16_t crc = generate_crc_16(tx_data, 6);
    tx_data[6] = (uint8_t)(crc & 0xFF);        // CRC LOW
    tx_data[7] = (uint8_t)((crc >> 8) & 0xFF); // CRC HIGH
    modbus_send(tx_data);
}






