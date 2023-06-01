/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define BOARD_ACTIVATE (BSP_IO_PORT_01_PIN_11)
#define GPT_OUTOUT_PIN (BSP_IO_PORT_01_PIN_13)
#define RED_ALARM_LED (BSP_IO_PORT_03_PIN_12)
extern const ioport_cfg_t g_bsp_pin_cfg; /* RA6M2-EK.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif /* BSP_PIN_CFG_H_ */
