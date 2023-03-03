/* generated thread header file - do not edit */
#ifndef BLUERED_THREAD_H_
#define BLUERED_THREAD_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void BLUERED_thread_entry(void * pvParameters);
                #else
extern void BLUERED_thread_entry(void *pvParameters);
#endif
FSP_HEADER
FSP_FOOTER
#endif /* BLUERED_THREAD_H_ */
