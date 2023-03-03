#include "REDLED_thread.h"
#include "bsp_cfg.h"
#include "r_ioport.h"
/* REDLED Thread entry function */
/* pvParameters contains TaskHandle_t */
void REDLED_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (300);
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_11, BSP_IO_LEVEL_HIGH);
        vTaskDelay (300);
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_11, BSP_IO_LEVEL_LOW);


    }
}
