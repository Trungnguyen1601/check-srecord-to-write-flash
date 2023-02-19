/*******************************************************************************
* Include
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

/*******************************************************************************
* Function
*******************************************************************************/

/**
 * @brief           Convert Hexa to decimal (1-9) (A-F)
 *
 * @param[in]       Char Hexa
 * @param[out]      Number after converted
 * @param[inout]    None
 * @returns         Decimal value of Hexa 
 */
uint8_t hexa_to_dec(uint8_t char_hexa )
{
    uint8_t data;
    uint8_t i;
    /* If char_hexa>='0' & char_hexa<='9' , value in (0,9) */
        if (char_hexa>='0' & char_hexa<='9') 
        {
            data = char_hexa - '0';
        }
    /* If char_hexa>='A' & char_hexa<='F' , value in (10,15) */
        if (char_hexa >='A' & char_hexa <='F')
        {
            data = char_hexa -'A'+10;
        }
    return data;

}

/**
 * @brief           Convert 2 Hexa characters to decimal 
 *
 * @param[in]       String
 * @param[out]      None
 * @param[inout]    None
 * @returns         Decimal of Hexa 
 */

uint8_t Convert_2_Hexa(char*str)
{
    uint8_t decimal;
    /* Value decimal of hexa = hexa_to_dec(string[0]) *16 + hexa_to_dec(string[1] */
    decimal= hexa_to_dec(str[0])*16 + hexa_to_dec(str[1]);
    return decimal;
    
}
/**
 * @brief           Free string
 *
 * @param[in]       String , number of characters
 * @param[out]      None
 * @param[inout]    None
 * @returns         Node 
 */

void free_char(char*str_free,uint8_t size)
{
    uint8_t index;
    for (index=0;index<size;index++)
        str_free[index] ='\0';
        
}

/**
 * @brief           Number of bits address for each S_type
 *
 * @param[in]       S_type
 * @param[out]      Number of bits address for S_type
 * @param[inout]    None
 * @returns         Number of Address 
 */
 
uint8_t address_S(uint8_t S_type)
{
    uint8_t hexa_add;
    switch(S_type){
        /* If S_type = 0 : Number of bits address is 4 */
        case 0 :
            {
                hexa_add = 4;
                break;
            }
        /* If S_type = 1 : Number of bits address is 4 */
        case 1 :
            {
                hexa_add = 4;
                break;
            }
        /* If S_type = 2 : Number of bits address is 6 */
        case 2 :
            {
                hexa_add = 6;
                break;
            }
        /* If S_type = 3 : Number of bits address is 8 */
        case 3 :
            {
                hexa_add = 8;
                break;
            }
        /* If S_type = 5 : Number of bits address is 4 */
        case 5 :
            {
                hexa_add = 4;
                break;
            }
        /* If S_type = 6 : Number of bits address is 6 */
        case 6 :
            {
                hexa_add = 6;
                break;
            }
        /* If S_type = 7 : Number of bits address is 8 */
        case 7 :
            {
                hexa_add = 8;
                break;
            }
        /* If S_type = 8 : Number of bits address is 6 */
        case 8 :
            {
                hexa_add = 6;
                break;
            }
        /* If S_type = 9 : Number of bits address is 4 */
        case 9 :
            {
                hexa_add = 4;
                break;
            }


    }
    return hexa_add;
}

/**
 * @brief           Value power to base 16
 *
 * @param[in]       Radix base
 * @param[out]      Value power of base 16
 * @param[inout]    None
 * @returns         Value total 
 */
 
uint32_t Pow16(uint8_t coso)
{
    uint8_t count=0;
    uint32_t total =1;
    while (count<coso)
    {
        total =total*16;
        count++;
    }
    return total;
}

/**
 * @brief           Convert Hexa to decimal value
 *
 * @param[in]       String hexa
 * @param[out]      Value decimal of hexa
 * @param[inout]    None
 * @returns         Value decimal of hexa 
 */
 
uint32_t Convert_to_dec(uint8_t *string)
{
    uint8_t index;
    uint32_t total;
    uint32_t sum =0;
    uint8_t size;
    size = strlen(string);
    /* Convert Hexa to decimal value */
    for (index=0;index<size;index++)
    {
        total = hexa_to_dec(string[index]) * Pow16(size-1-index);
        sum = sum + total;
    }
    return sum;
}

/**
 * @brief           Check S of srecord string
 *
 * @param[in]       Srecord string
 * @param[out]      None
 * @param[inout]    None
 * @returns         Check 
 */

uint8_t check_S(int8_t* str)
{
    uint8_t check = 0;
    /* Check Str srecord in index 0 == 'S' */
    if (str[0]=='S')
    {
        check =1;
    }
    return check;
}

/**
 * @brief           Check S_Type of srecord string
 *
 * @param[in]       Srecord string
 * @param[out]      None
 * @param[inout]    None
 * @returns         Check 
 */
 
uint8_t check_Type(int8_t * str)
{
    uint8_t check = 0;
    /* If S_type in (1,9) diffence 4 , is true */
    if ((str[1] >= 48 & str[1] <= 57) & str[1]!=52)
    {
        check =1;
            
    } 
    return check;

}

/**
 * @brief           Calculate Byte Count value of Srecord string
 *
 * @param[in]       Srecord string
 * @param[out]      None
 * @param[inout]    None
 * @returns         Byte Count 
 */
 
uint8_t Byte_Count(int8_t  string[])
{
    
    uint8_t Byte_Count = 0;
    /* Byte Count = hexa_to_dec(string[2]) *16 + hexa_to_dec(string[3] */
    Byte_Count = hexa_to_dec(string[2]) *16 + hexa_to_dec(string[3]);
    return Byte_Count;
}

/**
 * @brief           Calculate S_type value of Srecord string
 *
 * @param[in]       Srecord string
 * @param[out]      None
 * @param[inout]    None
 * @returns         S_Type
 */
 
uint8_t S_Type(int8_t* str)
{
    uint8_t string[1];
    uint8_t Type;
    string[0] = str[1];
    /* Calculate Decimal value of string[0] */
    Type = atoi(string);
    return Type;
}

/**
 * @brief           Check Byte Count of srecord string
 *
 * @param[in]       Srecord string
 * @param[out]      None
 * @param[inout]    None
 * @returns         Check 
 */
 
uint8_t check_Byte_Count(int8_t *str)
{
    uint8_t check = 0;
    uint8_t count = 0;
    uint8_t index;
    uint8_t byte_count=0;
    byte_count = Byte_Count( str);
    /* Count characters from index=4 to string length of srecord */
    for (index = 4;index<strlen(str);index=index+1 )
    {
        count ++;
    }
    /* If Count characters = 2* byte count , true*/
        if ((count) == (2*byte_count) )
                
        {
            check =1;
        }


    return check;
}

/**
 * @brief           Check Sum of srecord string
 *
 * @param[in]       Srecord string
 * @param[out]      None
 * @param[inout]    None
 * @returns         Check 
 */
 
uint8_t check_Sum(int8_t*str)
{
    uint8_t check = 0;
    uint8_t index;
    uint8_t size;
    uint8_t sum = 0;
    uint8_t str1[2];
    /* Calculate decimal of hexa one by two from index 2 to string length of srecord string is called 'sum'  */
    for (index = 2;index<strlen(str)-2;index=index+2 )
            {
                str1[0] = str[index];
                str1[1] = str[index+1];
                size = Convert_2_Hexa(str1);
                sum = sum + size;
            }
    /* (Calculate decimal of hexa of index strlen -2 and strlen -1) is called 'size'  */
    str1[0] = str[strlen(str)-2 ];
    str1[1] = str[strlen(str)-1];
    size = Convert_2_Hexa(str1);
    /* sum + size = 255, is true */
    if ((sum+size) == 255)
    {

        check = 1;
    }
    else
    {

        check = 0;
    }
    return check;
}

/**
 * @brief           Check Hexa  of srecord string, Characters in srecord string in (1,9) or (A,F)
 *
 * @param[in]       Srecord string
 * @param[out]      None
 * @param[inout]    None
 * @returns         Check 
 */
 
uint8_t check_Hexa ( int8_t *string )
{
    uint8_t count = 0;
    uint8_t index;
    uint8_t check =1;
    /* Count Hexa  of srecord string, Characters in srecord string is not in (1,9) or (A,F) */
    for (index=0;index<strlen(string);index++)
    {
        if ( (string[index] <48 || string[index]>57) & (string[index] <65 || string[index]>70) )
        {    
            count ++;
        }
    }
    /* If count hexa > 1, check =0 */
    if (count >1)
    {
        check =0;
    }
    return check;
}

/**
 * @brief           Find max in 2 number
 *
 * @param[in]       Number1, number2
 * @param[out]      None
 * @param[inout]    None
 * @returns         Max of 2 number 
 */

uint8_t max(uint32_t number1, uint32_t number2)
{
    uint8_t max = number1;
    /* Find max in 2 number */
    if(number1>number2)
        max = number1;
    else 
        max = number2;
    return max;     
}

/**
 * @brief           Find max in 3 number
 *
 * @param[in]       Number S1, number S2, number S3
 * @param[out]      None
 * @param[inout]    None
 * @returns         Max of 3 number 
 */
 
uint8_t Max_S(uint32_t S1,uint32_t S2, uint32_t S3 )
{
    uint8_t check_max;
    /* Find max in (S1,S2) , after find max in Max(S1,S2) and S3 */
    if (max(  max(S1,S2),S3)  == S1 )
    {
        check_max = 1;    
    }
    if (max(  max(S1,S2),S3)  == S2 )
    {
        check_max = 2;    
    }
    if (max(  max(S1,S2),S3)  == S3 )
    {
        check_max = 3;    
    }
    return check_max;
}

/**
 * @brief           Check ternimal of Srecord file
 *
 * @param[in]       S_type of srecord data, S_type of count, S_type of address start, Count of Srecord data
 * @param[out]      None
 * @param[inout]    None
 * @returns         Check 
 */
 
uint8_t checkS19_S28_S37(uint8_t check_max, uint8_t number2,uint8_t number3,uint32_t count_Srec_Data)
{
    uint8_t check = 0;
    /* if  Count of Srecord Data < 65535
     S_type of srecord data = 1, S_type of count = 5, S_type of address start = 9
     S_type of srecord data = 2, S_type of count = 5, S_type of address start =8
     S_type of srecord data = 3, S_type of count = 5, S_type of address start =7 
     check =1, true*/
    if (count_Srec_Data < 65535)
    {
    
        if ( ( (check_max==1)& (number2==5) & (number3==9) ) == 1 ) 
        {
            check =1;
        }
        if ( ( (check_max==2)& (number2==5) & (number3==8) ) == 1 ) 
        {
            check =1;
        }
        if ( ( (check_max==3)& (number2==5) & (number3==7) ) == 1 ) 
        {
            check =1;
        }
        
        
    }
     /* if  65535< Count of Srecord Data < 16777215 
     S_type of srecord data = 1, S_type of count = 6, S_type of address start = 9
     S_type of srecord data = 2, S_type of count = 6, S_type of address start =8
     S_type of srecord data = 3, S_type of count = 6, S_type of address start =7 
     check =1, true*/
    else if (65535 < count_Srec_Data < 16777215)
    {
        if ( ( (check_max==1)& (number2==6) & (number3==9) ) == 1 ) 
        {
            check =1;
        }
        if ( ( (check_max==2)& (number2==6) & (number3==8) ) == 1 ) 
        {
            check =1;
        }
        if ( ( (check_max==3)& (number2==6) & (number3==7) ) == 1 ) 
        {
            check =1;
        }
         
    }
    
    return check;
}

void Read_address_data(int8_t*str , int8_t *address, int8_t *data)
{
    uint8_t type = 0;
    uint8_t add;
    uint8_t index1;
    type = S_Type(str);
    add = address_S(type);
    /* Find address character hexa according to S_type */
    for (index1=0;index1<add;index1++)
                 
    {
        address[index1]=str[index1+4];
    }
    /* Find data character hexa according to S_type */
    for (index1=0;index1<strlen( str )-2-add-4;index1++)
                   
    {
        data[index1]=str[index1+4+add];
    }



}
/*******************************************************************************
* End of file
*******************************************************************************/
