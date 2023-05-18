/*
 * calculate.h
 *
 *  Created on: 9 May 2023
 *      Author: ferdi.kurnaz
 */

#ifndef CALCULATE_H_
#define CALCULATE_H_
#define debi_coef (2.77766606954)

int array_to_int(uint8_t array[]);
uint64_t hz_to_usec(uint64_t freq);
uint64_t debi_to_hertz(int debi);



#endif /* CALCULATE_H_ */
