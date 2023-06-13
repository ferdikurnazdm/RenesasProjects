/*
 * timer_code.h
 *
 *  Created on: 5 Haz 2023
 *      Author: ferdi.kurnaz
 */

#ifndef TIMER_CODE_H_
#define TIMER_CODE_H_
#define gpt_usec_per_sec (1000000);

uint32_t period_calculate(uint32_t desired_u_sec);
fsp_err_t gpt0_init(void);
fsp_err_t gpt1_init(void);
fsp_err_t gpt_update_period_for_q1(uint32_t per_count);
fsp_err_t gpt_update_period_for_q2(uint32_t per_count);
fsp_err_t gpt0_stop(void);
fsp_err_t gpt0_start(void);
fsp_err_t gpt1_stop(void);
fsp_err_t gpt1_start(void);
int gpt_timer0_state(void);
int gpt_timer1_state(void);

#endif /* TIMER_CODE_H_ */
