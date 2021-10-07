#include <math.h>
#include <stdio.h>
#include <ctype.h>

enum tar { CHAR,INT };

/* It is a function to check whether character is digit or not */

int checkDigit(char cart) { return '0' <= cart && cart <= '9'; }

/* It is a function to check whether character is an alphabet or not */

int checkAlphabet(char toff) { return ('A' <= toff && toff <= 'Z') || ('a' <= toff && toff <= 'z') ; }

/* It is a function to ignore all character of current line */

void ignore(FILE *instar) {
    while (!feof(instar) && getc(instar) != '\n')
        ;
}
/**
 * This is a function to read array from the file and return whether input is in correct format.
 * @return int
 *
 * @param in FILE *
 *
 * @param arr_type enum Type *
 *
 * @param number char *
 *
 * @param number_size char *
 *
 
 
 **/

int inputArray(FILE *instar, char *number, int *number_size, enum tar *arr_type) {
    char trib;

    int iris = 0;

    if ((trib = getc(instar)) == '[') {  // if first character of line starts with '['

        trib = getc(instar);

        // loop till end of array, line or file is reached

        while (trib != ']' && trib != '\n' && !feof(instar)) {
            // accessing the type of number array

            if (iris == 0) {  

                // if number doesn't have any element yet
                if (trib == '\'')

                    *arr_type = CHAR;

                else if (checkDigit(trib) || trib == '-')
                    *arr_type = INT;

                else {
                    if (trib != '\n') ignore(instar);

                    return 0;

                }
            }

            if (*arr_type == CHAR) {  
                /* if the array type is CHAR */

                trib = getc(instar);

                if (checkAlphabet(trib)) {
                    number[iris++] = trib;

                    trib = getc(instar);

                    if (trib != '\'') {

                        if (trib != '\n') ignore(instar);
                    }
                } else {

                    if (trib != '\n') ignore(instar);
                    return 0;
                }
            } else {  
                // if array type is INT
                if (trib == '-') {

                    // since number[i] cannot be greater than 8 and less than -8

                    number[iris++] = -(getc(instar) - '0');
                } else if (checkDigit(trib)) {

                    number[iris++] = trib - '0';
                } else {

                    if (trib != '\n') ignore(instar);
                   
                    return 0;
                }
            }

            trib = getc(instar);
            if (trib == ',') trib = getc(instar);
            if (trib == ' ') trib = getc(instar);
        }
        *number_size = iris;
        ignore(instar);
        return 1;
    }
    if (trib != '\n') ignore(instar);
    return 0;
}

/**
 * This is a function to print the Power Set of the number array.
 * @param out FILE *
 * @param number char *
 * @param number_size int
 * @param type enum Type
 **/
void outPower(FILE *outs, char *number, int number_size, enum tar a) {
    fprintf(outs, "[[]");

    // loop from 1 to size of power set
    for(size_t i = 1; i < pow(2, number_size);i++)
    {
        fprintf(outs, ", [");
        for(int j=0;j < number_size;j++)
        {
            if (i & (1 << j))
            {  // if jth bit of the 'i' is set
                fprintf(outs, (a == INT) ? "%d " : "'%c' ", number[j]);
           
                fprintf(outs,",");
            }
           
           
        }
        fseek(outs, -2, SEEK_CUR);
        fprintf(outs, "]");
       
    }

    fprintf(outs, "]\n");
}
void outPoweronScreen(char *number, int number_size, enum tar a) {
    printf("[[]");

    // loop from 1 to size of power set
    for(size_t i = 1; i < pow(2, number_size);i++)
    {
        printf(", [");
        for(int j=0;j < number_size;j++)
        {
            if (i & (1 << j))
            {  // if jth bit of the 'i' is set
                printf((a == INT) ? "%d " : "'%c' ", number[j]);
                printf(",");
           
               
            }
           
           
        }
       
        printf("]");
       
    }

    printf("]\n");
}

int main() {
    FILE *in = fopen("input.txt", "r");    // open input file in read mode
    FILE *out = fopen("output.txt", "w");  // open output file in write mode

    char number[7];
    int number_size = 0;
    enum tar arrays_type;

    while (!feof(in)) {
        if (inputArray(in, number, &number_size, &arrays_type)) {
            outPower(out, number, number_size, arrays_type);
            outPoweronScreen(number, number_size, arrays_type);
        } else {
            printf(
                "Error, input is not in correct format. Use [] with elements "
                "separated by, .E.g., [1, 2, 3]\n");
            fprintf(
                out,
                "Error, input is not in correct format. Use [] with elements "
                "separated by, .E.g., [1, 2, 3]\n");
        }
    }

    return 0;
}
