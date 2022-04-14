#include<stdio.h>
#include<stdlib.h>
#include "stack_char_q3.h"


int main()

{
    FILE *myfile=fopen("input.txt","r");
    int max = 0;
    char array[30];
    char a='*';

	if (myfile == NULL)
		printf("\nFile cannot be opened!\n");
    else{
        stack_t st;
        initialize_s(&st);
        while(fscanf(myfile,"%s%c",array,&a)!=EOF)
        if(a=='\n')
        {
            push(&st,array,strlen(array));
            if(strlen(array)>max)
            {
                max = strlen(array);
            }
           while(is_empty_s(&st)==0)
                {
                    printf("%s ",pop(&st));

                }
                printf("\n");

        }
        else{
             push(&st,array,strlen(array));
            if(strlen(array)>max)
            {
                max = strlen(array);
            }
        }
    }

    printf("The maximum length is %d\n", max);
}

