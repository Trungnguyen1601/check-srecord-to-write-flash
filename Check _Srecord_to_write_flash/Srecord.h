#ifndef _SRECORD_H_
#define _SRECORD_H_


/* Define file'name to read */
#define SREC_FILE "Srec.txt"
/* Define file'name to read */
#define SREC_FILE_1 "Srec1.txt"
/* Define file'name to write */
#define OUTPUT_FILE "Output.txt"

/* Convert 2 Hexa characters to decimal */
uint8_t Convert_2_Hexa(char*str);

/* Number of bits address for each S_type */
uint8_t address_S(uint8_t S_type);

/* Value power to base 16 */
uint32_t Pow16(uint8_t coso);

/* Convert Hexa to decimal (1-9) (A-F) */
uint8_t hexa_to_dec(uint8_t char_hexa );

/* Convert Hexa to decimal value */
uint32_t Convert_to_dec(uint8_t *string);

/* Check S of srecord string */
uint8_t check_S(char* str);

/* Check S_Type of srecord string */
uint8_t check_Type(char* str);

/* Calculate Byte Count value of Srecord string */
uint8_t Byte_Count(uint8_t string[]);

/* Calculate S_type value of Srecord string */
uint8_t S_Type(uint8_t* str);

/* Check Byte Count of srecord string */
uint8_t check_Byte_Count(char*str);

/* Check Sum of srecord string */
uint8_t check_Sum(uint8_t*str);

/* Check Hexa  of srecord string, Characters in srecord string in (1,9) or (A,F) */
uint8_t check_Hexa ( uint8_t *string );

/* Free string */
void free_char(char*str_free,uint8_t size);

/* Find max in 2 number */
uint8_t max(uint8_t number1, uint8_t number2);

/* Max_S(uint32_t S1,uint32_t S2, uint32_t S3 */
uint8_t Max_S(uint8_t S1,uint8_t S2, uint8_t S3 );

/* Check ternimal of Srecord file */
uint8_t checkS19_S28_S37(uint8_t check_max, uint8_t number2,uint8_t number3,uint32_t count_Srec_Data) ;
/* */
void Read_address_data(int8_t*str , int8_t *address, int8_t *data);

#endif /* _SRECORD_H_ */

