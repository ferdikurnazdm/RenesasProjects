#include "BLUERED_thread.h"
#include "bsp_cfg.h"
#include "r_ioport.h"

/* BLUERED Thread entry function */
/* pvParameters contains TaskHandle_t */
void BLUERED_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    bsp_io_level_t LEVEL;
    /* TODO: add your own code here */
    while (1)
    {
        LEVEL=R_BSP_PinRead(BSP_IO_PORT_01_PIN_05);
        if (LEVEL==BSP_IO_LEVEL_LOW)
        {
            R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_12, BSP_IO_LEVEL_HIGH);
            vTaskDelay (10000);
        }
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_12, BSP_IO_LEVEL_LOW);
        vTaskDelay (1);
    }
}
