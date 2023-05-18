/*
 * smith_prothocol.c
 *
 *  Created on: 12 May 2023
 *      Author: ferdi.kurnaz
 */
///////////////////////////////////////////////
//----------------imports------------------//
#include "hal_data.h"
#include "smith_prothocol.h"
#include "stdbool.h"

///////////////////////////////////////////////
//----------------descriptions---------------//
unsigned char const STX = 0x02;
unsigned char const ETX = 0x03;
int counter_5 = 0;


unsigned char tmp[11]      = {0X02,'\0','\0','\0','\0','\0','\0','\0','\0',0X03};
unsigned char command[11]  = {0X02,'\0','\0','\0','\0','\0','\0','\0','\0',0X03};
uint8_t arr_uint8_base[11] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
uint8_t salt_data[8]       = {'\0','\0','\0','\0','\0','\0','\0','\0'};
uint8_t meaningful_data[8] = {'\0','\0','\0','\0','\0','\0','\0','\0'};
int transmitter_array_size = 0;

///////////////////////////////////////////////
//----------------methods--------------------//
unsigned char get_lrc(unsigned char * pbData,  int iCount) {
    unsigned char chLRC = 0;
    while (iCount > 0) {
        chLRC ^= *pbData++;
        iCount--;
    }
    return chLRC;
}

bool ıs_lrc_valid(const unsigned char chReceivedLRC, unsigned char * pbData, int etx_index) {
    if ((pbData != NULL) && (etx_index > 0) ){
        if ((pbData[etx_index-1] == ETX)) { // (*(pbData+8) == ETX) {
            if (chReceivedLRC == get_lrc(pbData,(etx_index)))//(1) working
              return true;
        }
      }
    return false;
}

/*unsigned char * create_command(unsigned char * val) {
    for (size_t i = 1; i < 9; ++i) {
        command[i] = *(val+(i-1));//val[j+0];
    }
    command[10] = get_lrc(&command[1],9);
    return &command[0];
}*/

unsigned char * create_command() {
    int k = 0;
    for (k = 1; k <= transmitter_array_size; ++k) {
        command[k] = salt_data[(k - 1)];//val[j+0];
    }
    command[(transmitter_array_size+1)] = ETX;
    command[(transmitter_array_size + 2)] = get_lrc(&command[1],(transmitter_array_size + 1));
    return &command[0];
}
unsigned char split_lrc(uint8_t * received_array, int etx_index) {
    if (received_array[etx_index] == ETX) {
        unsigned char var = (unsigned char)*(received_array + (etx_index + 1));
        return var;
    }
    return 1;
}

unsigned char * convert_unsigned_char(uint8_t * val) {
    for (size_t i = 1; i < 9; ++i) {
        tmp[i] = (unsigned char)*(val + i);
    }
    return &tmp[0];
}

uint8_t * convert_to_uint8(unsigned char * arr5) {
    for (counter_5 = 0; counter_5 < 12; ++counter_5) {
        arr_uint8_base[counter_5] = (uint8_t)*(arr5+counter_5);
    }
    return &arr_uint8_base[0];
}

uint8_t * get_salt_data(uint8_t * val) {
    set_array_to_null(salt_data);
    for (size_t i = 1; i < 11; ++i) {
        if(*(val + i) == ETX) {
            return &salt_data[0];    // STX X X X X X X X X ETX LRC
        }
        salt_data[i - 1] = *(val + i);
    }
    return &salt_data[0];
}

void insert_salt_data(void) {
    if (salt_data[0] != '\0') {
        for (size_t i = 0; i < 8; ++i) {
            // WRITE CODE HERE
        }
    }
}

int check_smith_format(uint8_t * array) {
    if (array == NULL || *(array) == '\0') {
        return -1;
    }
    if (*(array) != STX) {
        return -1;
    }
    for (size_t i = 0; i < 11; ++i) {
        if ((array[i]) == ETX) {
            return (int)i;   //return value is etx index
        }
    }
    return -1;
}

uint8_t * get_meaningful_data(void) {
    set_array_to_null(meaningful_data);
    for (size_t i = 0; i < sizeof(salt_data); ++i) {
        if (salt_data[(i + 2)] !='\0') {
            meaningful_data[i] = salt_data[(i + 2)];
        }
        else {
            return &meaningful_data[0];
        }
    }
    return &meaningful_data[0];
}

void set_array_to_null(uint8_t * array) {
    for (size_t i = 0; i < 8; ++i) {
        array[i]='\0';
    }
}

int q1_command_check(uint8_t * array) {
    if (*(array)=='Q' && *(array + 1)=='1') {
        return 0;
    }
    return -1;
}

void  set_command_size() {
    transmitter_array_size = 0;
    for (size_t j = 0; j < sizeof(salt_data); ++j) {
        if (salt_data[j] != '\0') {
            transmitter_array_size++;
        }
    }
}
