/*******************************************************************************
* Include
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "Srecord.h"

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
    FILE*Output_file = NULL;
    FILE*Myfile = NULL;
    uint8_t string[80];
    uint8_t address[9];
    uint8_t data[65];
    uint32_t count=0;
    uint32_t index =0;
    uint8_t index1=0;
    uint8_t type = 0;
    uint8_t countS0=0;
    uint32_t countS1=0;
    uint32_t countS2=0;
    uint32_t countS3=0;
    uint8_t countS5=0;
    uint8_t countS7=0;
    uint8_t countS8=0;
    uint8_t countS9=0;
    uint8_t check_max;
    uint8_t add;
    uint32_t count_record;
    uint32_t count_srec=0;
    uint8_t number1;
    uint8_t number2;
    uint8_t check = 0;
    Myfile = fopen(SREC_FILE,"r");
    if (Myfile==NULL)
    {
        printf("Don't open file to read\n");
    }
    else 
    {
        while (fscanf(Myfile, "%s", string) != EOF)
        {
    
            count++;
            free_char(string,80);
        }
        rewind(Myfile);
        uint8_t Srec[count][80];
        free_char(address,9);
        free_char(data,65);
        for (index= 0;index<count;index++)
        {
            fscanf(Myfile, "%s", string);
            add = S_Type(string);
            
            if (add==0) 
            { 
                countS0++; 
            }
            if (add==1) 
            {
                countS1++;  
            }
            if (add==2) 
            { 
                countS2++; 
            }
            if (add==3) 
            {
                countS3++;  
            }
            if (add==5) 
            { 
                countS5++; 
            }
            if (add==7) 
            { 
                countS7++; 
            }
            if (add==8)
            { 
                countS8++; 
            }
            if (add==9) 
            { 
                countS9++; 
            }
            strcpy(Srec[index],string); 
            if(index==count-2)
            {
                number1 = S_Type(string);
            }
            if (index==count-1)
            {
                number2 = S_Type(string);
            }
            
            

            
        }
        count_srec = countS1 +countS2+ countS3;
        check_max = Max_S(countS1,countS2,countS3);
        Output_file = fopen(OUTPUT_FILE,"w");
        if (Output_file == NULL)
        {
            printf("Don't open file to write\n");
        }
        else
        {
            printf(" Line Address\tData\n");
            fprintf(Output_file," Line Address\tData\n ");
            for (index=0;index<count;index++)
        
            {
                if ((check_S(Srec[index]) & check_Type(Srec[index]) & check_Byte_Count(Srec[index]) & check_Sum(Srec[index]) 
                     & check_Hexa (Srec[index])  )==1 )  
                {
                    type = S_Type(Srec[index]);
                    uint8_t add = address_S(type);
              
                    for (index1=0;index1<add;index1++)
                 
                    {
                        address[index1]=Srec[index][index1+4];
                    }
                    for (index1=0;index1<strlen( Srec[index] )-2-add-4;index1++)
                   
                    {
                        data[index1]=Srec[index][index1+4+add];
                    }
                    if (index==count-2)  
                    {
                        count_record = Convert_to_dec(address);
               
                    }
                    if (index== count -2 || index == count -1)
                    {
                    
                        if (index==count-2 & count_record !=count_srec)
                        {
                            printf(" %-3d  %s ",index,Srec[index]);
                            printf(" Un_true count in srecord count");
                            fprintf(Output_file," %-3d  %s ",index,Srec[index]);
                            fprintf(Output_file," Un_true count in srecord count");
                            check=1;
                        }
                        if ( check==0 & ( ( (index==count-2) || (index ==count-1) ) 
                            &  (checkS19_S28_S37( check_max, number1, number2,count_srec) == 0 )   ))
                        {
                            printf(" %-3d  %s ",index,Srec[index]);
                            printf(" Un_true TERNIMAL");
                            fprintf(Output_file," %-3d %s ",index,Srec[index]);
                            fprintf(Output_file," Un_true TERNIMAL");
                        }
                        if ( check == 1 &  (checkS19_S28_S37(check_max,  number1, number2, count_srec) == 0 )   )
                        {
                            printf(" Un_true TERNIMAL");
                            fprintf(Output_file," Un_true TERNIMAL");
                        }
                        if ( check == 0 & (checkS19_S28_S37( check_max, number1, number2,count_srec) == 1 ) )
                        {
                            printf(" %-3d  %-8s  %-64s",index,address,data);
                            fprintf(Output_file," %-3d  %-8s  %-64s",index,address,data);
                        }
                    }
                    else 
                    {
                        if ( (type !=check_max) &( (type ==1)||(type ==2)||(type ==3)))
                        {
                            printf(" %-3d  %s ",index,Srec[index]);
                            printf("Un_true check srecord data type");
                            fprintf(Output_file," %-3d  %s ",index,Srec[index]);
                            fprintf(Output_file,"Un_true check srecord data type");
                        }
                        else 
                        {
                            printf(" %-3d  %-8s  %-64s",index,address,data);
                            fprintf(Output_file," %-3d  %-8s  %-64s",index,address,data);
                        }
                    }
                    free_char(address,8);
                    free_char(data,64);
                    check = 0;
                    printf("\n");
                    fprintf(Output_file,"\n");
                } 
                else 
                {
                    printf(" %-3d  %s ",index,Srec[index]);
                    fprintf(Output_file," %-3d  %s ",index,Srec[index]);
            
                    if (   ( ( (index==count-2) || (index ==count-1) ) 
                       &  (checkS19_S28_S37( check_max, number1, number2,count_srec) == 0 )   ))
                    {
                        printf(" Un_true TERNIMAL");
                        fprintf(Output_file," Un_true TERNIMAL");
                    }
                
                
                    if (check_Hexa(Srec[index]) == 0)
                    { 
                        printf("Un_true syntax Hexa");
                        fprintf(Output_file," Un_true syntax Hexa");
                        printf("\n");
                        fprintf(Output_file,"\n");
                    }
                    else
                    {
                        if (index==count-2 & Convert_to_dec(address)!=(countS1+countS2+countS3))
                        {
                            printf(" Un_true count");
                            fprintf(Output_file," Un_true count");
                        }
                        if (check_Type(Srec[index])==0)
                        {
                            printf(" Un_true check Type");
                            fprintf(Output_file," Un_true check Type");
                        }
                        if (check_S(Srec[index])==0)
                        {
                            printf(" Un_true S character");
                            fprintf(Output_file," Un_true S character");
                 
                        }
                        if (check_Byte_Count(Srec[index])==0)
                        { 
                            printf(" Un_true Byte Count");
                            fprintf(Output_file," Un_true Byte Count");
                 
                        }
                        if (check_Sum(Srec[index])==0) 
                        {
                            printf(" Un_true Check Sum");
                            fprintf(Output_file," Un_true Check Sum");
                        }
                        printf("\n");
                        fprintf(Output_file,"\n");
                    }
                }
            }
        }
    }
    fclose(Myfile);
    fclose(Output_file);
    return 0;
}

/*******************************************************************************
* End of file
*******************************************************************************/
