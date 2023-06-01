/*
 * smith_prothocol.h
 *
 *  Created on: 12 May 2023
 *      Author: ferdi.kurnaz
 */

#ifndef SMITH_PROTHOCOL_H_
#define SMITH_PROTHOCOL_H_


bool ıs_lrc_valid(const unsigned char chReceivedLRC,unsigned char* pbData,int iCount);
unsigned char get_lrc(unsigned char* pbData,  int iCount);
unsigned char split_lrc(uint8_t * received_array, int etx_index);
//unsigned char * create_command(unsigned char * val);
unsigned char * create_command(void);
unsigned char * send_ek_response(uint8_t * array, int reset_state);
unsigned char * convert_unsigned_char(uint8_t *valu);
uint8_t * convert_to_uint8(unsigned char* arr5);
uint8_t * get_salt_data(uint8_t* val);
uint8_t * get_meaningful_data(void);
int check_smith_format(uint8_t * array);
void set_array_to_null(uint8_t * array);
void insert_salt_data(void);
int q1_command_check(uint8_t * array);
void set_command_size(void);
int command_router(uint8_t * array);
int get_etx_index(uint8_t * array, int size_arr);

#endif /* SMITH_PROTHOCOL_H_ */
