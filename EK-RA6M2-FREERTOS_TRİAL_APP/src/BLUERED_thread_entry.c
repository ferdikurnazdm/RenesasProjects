#include "BLUERED_thread.h"
#include "bsp_pin_cfg.h"
#include "bsp_api.h"
#include "r_ioport.h"
/* BLUERED Thread entry function */
/* pvParameters contains TaskHandle_t */
void BLUERED_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1000);
        /* fsp_err_t status;
         bsp_io_level_t *Pin_Level;
         status = R_IOPORT_PinRead(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_05, &Pin_Level);
         if(Pin_Level==0)
         {
             R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_12, BSP_IO_LEVEL_HIGH);
         }
         else
         {
             R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_12, BSP_IO_LEVEL_LOW);
         }*/

        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_12, BSP_IO_LEVEL_HIGH);
        vTaskDelay (1000);
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_12, BSP_IO_LEVEL_LOW);
        vTaskDelay (1000);
    }
}
