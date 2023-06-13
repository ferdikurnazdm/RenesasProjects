/*
 * timer_code.c
 *
 *  Created on: 5 Haz 2023
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
#include "bsp_cfg.h"
#include "bsp_api.h"
#include "board_cfg.h"
#include "bsp_pin_cfg.h"
#include "r_gpt_cfg.h"
#include "r_gpt.h"
#include "r_timer_api.h"

///////////////////////////////////////////////////
//-----------descriptions------------------------//
fsp_err_t err_gpt = FSP_SUCCESS;
timer_status_t * p_gpt_timer_0;
timer_status_t * p_gpt_timer_1;


////////////////////////////////////////////////////
//-----------methods------------------------------//
uint32_t period_calculate(uint32_t desired_u_sec) {
    uint32_t pclkd_freq_hz = (R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_PCLKD)>>g_timer0_cfg.source_div);
    uint64_t step_1 = ((uint64_t)pclkd_freq_hz*desired_u_sec);
    uint64_t step_2 = step_1 / gpt_usec_per_sec;
    uint32_t period_count_in = (uint32_t)step_2;
    return period_count_in;
}

fsp_err_t gpt0_init(void) {
    err_gpt = R_GPT_Open(&g_timer0_ctrl, &g_timer0_cfg);
    err_gpt = R_GPT_Start(&g_timer0_ctrl);
    return err_gpt;
}
fsp_err_t gpt1_init(void) {
    err_gpt = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
    err_gpt = R_GPT_Start(&g_timer1_ctrl);
    return err_gpt;
}

fsp_err_t gpt_update_period_for_q1(uint32_t period) {
    err_gpt = R_GPT_PeriodSet(&g_timer0_ctrl, period);
    return err_gpt;
}

fsp_err_t gpt_update_period_for_q2(uint32_t period) {
    err_gpt = R_GPT_PeriodSet(&g_timer1_ctrl, period);
    return err_gpt;
}

fsp_err_t gpt0_stop(void) {
    err_gpt = R_GPT_Stop(&g_timer0_ctrl);
    return err_gpt;
}

fsp_err_t gpt1_stop(void) {
    err_gpt = R_GPT_Stop(&g_timer1_ctrl);
    return err_gpt;
}

fsp_err_t gpt0_start(void) {
    err_gpt = R_GPT_Start(&g_timer0_ctrl);
    return err_gpt;
}
fsp_err_t gpt1_start(void) {
    err_gpt = R_GPT_Start(&g_timer1_ctrl);
    return err_gpt;
}
int gpt_timer0_state(void){
    // 0 --> stopped, 1 --> counting
    R_GPT_StatusGet(&g_timer0_ctrl, p_gpt_timer_0);
    return p_gpt_timer_0->state;
}

int gpt_timer1_state(void){
    // 0 --> stopped, 1 --> counting
    R_GPT_StatusGet(&g_timer1_ctrl, p_gpt_timer_1);
    return p_gpt_timer_1->state;
}

