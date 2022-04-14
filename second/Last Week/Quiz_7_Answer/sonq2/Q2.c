
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include "stack_char.h"

#define MAX 100
bool palindrome(char *mystring)
{

    //char mychar;
	int stringlength = strlen(mystring);
	stack_t st;
	initialize_s(&st);
	int i = 0;
	for(i=0;i<stringlength;i++)
    {
        push(&st,mystring[i]);
    }
    i = 0;
    while(!is_empty_s(&st))
    {
        //araba -- fonksiyon stringi
        //abara -- Stack'in içindeki string
        if(mystring[i++]!=pop(&st))
            return false;

    }
    return true;

}

int main()

{
    char myline[100];
    FILE *myfile = fopen("palindrome.txt", "r");

	if (myfile == NULL)
		printf("\nFile cannot be opened!\n");
    else{
        while (fscanf(myfile, " %[^\n]s", myline) != EOF)
		{
               if(palindrome(myline))
                    printf("%s\n", myline);
		}
    }


    return 0;
}
