/*
 * calculate.h
 *
 *  Created on: 5 Haz 2023
 *      Author: ferdi.kurnaz
 */

#ifndef CALCULATE_H_
#define CALCULATE_H_
#define debi_coef (2.777660695468915) //2.777660695468915 //0.00462708

int array_to_int(uint8_t array[]);
uint64_t hz_to_usec(uint64_t freq);
uint64_t debi_to_hertz(int debi);


#endif /* CALCULATE_H_ */
