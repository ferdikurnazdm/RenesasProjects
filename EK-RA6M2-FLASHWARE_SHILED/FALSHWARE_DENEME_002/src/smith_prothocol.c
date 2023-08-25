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

unsigned char ek_response_arr[12] = {0X02,'\0','\0','0','0','0','0','0','0','\0',0x03};
unsigned char tmp[11]             = {0X02,'\0','\0','\0','\0','\0','\0','\0','\0','\0'};
unsigned char command[11]         = {0X02,'\0','\0','\0','\0','\0','\0','\0','\0',0X03};
uint8_t arr_uint8_base[11]        = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
uint8_t salt_data[8]              = {'\0','\0','\0','\0','\0','\0','\0','\0'};
uint8_t meaningful_data[8]        = {'\0','\0','\0','\0','\0','\0','\0','\0'};
int transmitter_array_size        = 0;
int index_etx = 0;

///////////////////////////////////////////////
//----------------methods--------------------//


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
    command[(transmitter_array_size + 1)] = ETX;
    command[(transmitter_array_size + 2)] = get_lrc(&command[1],(transmitter_array_size + 1));
    return &command[0];
}

unsigned char * convert_unsigned_char(uint8_t * val) {
    int i =0;
    for (i = 1; i < index_etx; ++i) {
        tmp[i] = (unsigned char)*(val + i);
    }
    tmp[index_etx] = ETX;
    return &tmp[0];
}

unsigned char split_lrc(uint8_t * received_array, int etx_index) {
    if (received_array[etx_index] == ETX) {
        unsigned char var = (unsigned char)*(received_array + (etx_index + 1));
        return var;
    }
    return 1;
}

unsigned char get_lrc(unsigned char * pbData,  int iCount) {
    unsigned char chLRC = 0;
    while (iCount > 0) {
        chLRC ^= *pbData++;
        iCount--;
    }
    return chLRC;
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

uint8_t * get_meaningful_data(void) {
    set_array_to_null(meaningful_data);
    for (size_t i = 4; i < sizeof(salt_data); ++i) {
        if (salt_data[(i)] != '\0') {
            meaningful_data[(i - 4)] = salt_data[i];
        }
        else {
            return &meaningful_data[0];
        }
    }
    return &meaningful_data[0];
}

void insert_salt_data(void) {
    if (salt_data[0] != '\0') {
        for (size_t i = 0; i < 8; ++i) {
            // WRITE CODE HERE
        }
    }
}

void set_array_to_null(uint8_t * array) {
    for (size_t i = 0; i < 8; ++i) {
        array[i]='\0';
    }
}

void set_command_size() {
    transmitter_array_size = 0;
    for (size_t j = 0; j < sizeof(salt_data); ++j) {
        if (salt_data[j] != '\0') {
            transmitter_array_size++;
        }
    }
}

int command_router(uint8_t * array) {
    int route = -1;
    if (*(array + 2) == 'Q' && *(array + 3) == '1') {
        route = 0;
    }
    if (*(array + 2) == 'R' && *(array + 3) == 'Q') {
        route = 1;
    }
    if (*(array + 2) == 'E' && *(array + 3) == 'K') {
        route = 2;
    }
    return route;
}

int q1_command_check(uint8_t * array) {
    if (*(array + 2) == 'Q' && *(array + 3) == '1') {
        return 0;
    }
    return -1;
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

int get_etx_index(uint8_t * array, int size_arr) {
    index_etx = 0;
    int o = 0;
    for (o = 0; o < size_arr; ++o) {
        if (*(array + o) != ETX) {
            index_etx++;
        }
        else {
            return index_etx;
        }
    }
    return -1;
}

unsigned char * send_ek_response(uint8_t * array, int reset_state){
    uint8_t A1 = *(array);
    uint8_t A2 = *(array + 1);
    ek_response_arr[1] = (unsigned char) A1;
    ek_response_arr[2] = (unsigned char) A2;

    if (reset_state == 0) {
        ek_response_arr[9] = '0';
    }
    else {
        ek_response_arr[9] = '1';
    }
    ek_response_arr[11] = get_lrc(&ek_response_arr[1], 10);
    return &ek_response_arr[0];

}
