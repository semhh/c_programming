
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "stack_char_q3.h"


void reverse(char* mystring)
{
    char tempstring[30];
    int i=0, j=0;
    stack_t st;
    initialize_s(&st);
    char *fstring = (char*) malloc(strlen(tempstring));
     while(1)
    {
        if(mystring[i]!=' ' && mystring[i]!='\0')
        {
            tempstring[j]=mystring[i];
            j++;
        }
        else
        {
            tempstring[j++] = ' ';
            tempstring[j]='\0';
            push(&st,tempstring,strlen(tempstring));
            j=0;

        }
        if(mystring[i]=='\0')
        {
            free(tempstring);
            break;
        }
        char tempstring[30];
        i++;
    }

    while(is_empty_s(&st)==0)
    {
        strcat(fstring,pop(&st));
        strcat(fstring," ");
    }
    strcat(fstring,'\0');
    printf("%s", fstring);

}
int main()
{
    char str[200];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);
    reverse(str);


        return 0;
}
