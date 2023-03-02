/* generated thread header file - do not edit */
#ifndef REDLED_THREAD_H_
#define REDLED_THREAD_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void REDLED_thread_entry(void * pvParameters);
                #else
extern void REDLED_thread_entry(void *pvParameters);
#endif
FSP_HEADER
FSP_FOOTER
#endif /* REDLED_THREAD_H_ */
