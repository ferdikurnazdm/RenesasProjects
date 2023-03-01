#include "hal_data.h"
#include "bsp_pin_cfg.h"
#include "r_ioport.h"
#include "r_wdt.h"
#define COUNTER 30
volatile uint16_t loop_counter;
/*#include "bsp_api.h"*/
FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{
    R_DEBUG->DBGSTOPCR_b.DBGSTOP_WDT = 0;
    R_WDT_Open(&g_wdt0_ctrl, &g_wdt0_cfg);
    R_WDT_Refresh(&g_wdt0_ctrl);
    for (loop_counter = 0; loop_counter < COUNTER; loop_counter++)
    {
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_12, BSP_IO_LEVEL_HIGH);
        R_BSP_SoftwareDelay(125, BSP_DELAY_UNITS_MILLISECONDS);
        R_WDT_Refresh(&g_wdt0_ctrl);
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_12, BSP_IO_LEVEL_LOW);
        R_BSP_SoftwareDelay(125, BSP_DELAY_UNITS_MILLISECONDS);
        R_WDT_Refresh(&g_wdt0_ctrl);
    }
    while(1)
    {
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_11, BSP_IO_LEVEL_HIGH);
        R_BSP_SoftwareDelay(250, BSP_DELAY_UNITS_MILLISECONDS);
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_11, BSP_IO_LEVEL_LOW);
        R_BSP_SoftwareDelay(250, BSP_DELAY_UNITS_MILLISECONDS);
    }

    /* TODO: add your own code here */

#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

        /* Enable reading from data flash. */
        R_FACI_LP->DFLCTL = 1U;

        /* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
         * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open (&g_ioport_ctrl, g_ioport.p_cfg);
    }
}

#if BSP_TZ_SECURE_BUILD

BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ();

/* Trustzone Secure Projects require at least one nonsecure callable function in order to build (Remove this if it is not required to build). */
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ()
{

}
#endif
