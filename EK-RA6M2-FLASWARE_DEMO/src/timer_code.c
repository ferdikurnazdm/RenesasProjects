/*
 * timer_code.c
 *
 *  Created on: 9 May 2023
 *      Author: ferdi.kurnaz
 */
////////////////////////////////////////////////////
//-----------imports------------------------------//
#include "common_data.h"
#include "r_ioport_cfg.h"
#include "r_ioport.h"
#include "r_ioport_api.h"
#include "hal_data.h"
#include "timer_code.h"

///////////////////////////////////////////////////
//-----------descriptions------------------------//
fsp_err_t err_gpt = FSP_SUCCESS;

////////////////////////////////////////////////////
//-----------methods------------------------------//
uint32_t period_calculate(uint32_t desired_u_sec) {
    uint32_t pclkd_freq_hz = (R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_PCLKD)>>g_timer0_cfg.source_div);
    uint64_t step_1 = ((uint64_t)pclkd_freq_hz*desired_u_sec);
    uint64_t step_2 = step_1 / gpt_usec_per_sec;
    uint32_t period_count_in = (uint32_t)step_2;
    return period_count_in;
}

fsp_err_t gpt_init(void) {
    err_gpt = R_GPT_Open(&g_timer0_ctrl, &g_timer0_cfg);
    err_gpt = R_GPT_Start(&g_timer0_ctrl);
    return err_gpt;
}

fsp_err_t gpt_update_period(uint32_t period) {
    err_gpt = R_GPT_PeriodSet(&g_timer0_ctrl, period);
    return err_gpt;
}
