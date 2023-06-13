/*
 * calculate.c
 *
 *  Created on: 5 Haz 2023
 *      Author: ferdi.kurnaz
 */

/////////////////////////////////////////
//---------------imports---------------//
#include <math.h>
#include "common_data.h"
#include "r_ioport_cfg.h"
#include "r_ioport.h"
#include "r_ioport_api.h"
#include "hal_data.h"
#include "calculate.h"

/////////////////////////////////////////
//---------------moethods--------------//
int array_to_int(uint8_t array[]) {
    int array_size = 0;
    int array_index;
    int array_coef;
    int result = 0;
    int i;
    int mover;
    for (array_index = 0; array_index < 8; ++array_index) {
        if ((array[array_index] != '\n') && (array[array_index] != '\0')) {
            array_size = array_size+1;
        }
    }
    array_coef=array_size;
    for (i = 0; i < array_size; ++i) {
        char str = (char)array[i];
        mover = str-'0';
        int product = (int)(pow(10,(array_coef-1)));
        result = result + (mover*product);
        array_coef--;
    }
    return result;
}

uint64_t hz_to_usec(uint64_t freq) {
    if (freq > 1000000) {
        return (uint64_t)120000;
    }
    uint64_t u_sec = ((uint64_t)1000000/freq);
    return u_sec;
}

uint64_t debi_to_hertz(int debi) {
    if (debi < 50) {
        return (uint64_t)-1;
    }
    if (debi >= 999 ) {
        debi = 999;
    }
    return (uint64_t)(debi*debi_coef);
}

