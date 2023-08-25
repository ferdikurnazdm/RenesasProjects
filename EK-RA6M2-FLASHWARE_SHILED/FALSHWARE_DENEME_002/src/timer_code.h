/*
 * timer_code.h
 *
 *  Created on: 9 May 2023
 *      Author: ferdi.kurnaz
 */

#ifndef TIMER_CODE_H_
#define TIMER_CODE_H_
#define gpt_usec_per_sec (1000000);

uint32_t period_calculate(uint32_t desired_u_sec);
fsp_err_t gpt_init(void);
fsp_err_t gpt_update_period(uint32_t per_count);

#endif /* TIMER_CODE_H_ */
