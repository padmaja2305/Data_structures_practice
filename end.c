#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 500 


void find(char m[], FILE *file, char *name)     // function to check whether the inputted string is present or not 
{
    if (file == NULL)       // if there are no elements, then print an appropriate error message 
    {
        printf("Could not open file %s\n", name);
        return;
    }

    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE - 1, file) != NULL)        //  iterate till we reach the end
    {
        
        if (strstr(line, m) != NULL)        //  if our string is present, then it will not return a null
        {
            printf("%s:%s", name, line);    
        }

        
        
    }
}
//DRIVER CODE
int main(int argc, char *argv[])
{


    int num = argc - 2;
    
    for (int i = 0; i < num; i++)
    {
        FILE *fptr;
        fptr = fopen(argv[i + 2], "r");

        find(argv[1], fptr, argv[i + 2]);
    }

    return 0;
}
