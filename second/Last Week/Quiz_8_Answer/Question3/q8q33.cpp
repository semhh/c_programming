#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_char.h"
#include "stack_char.h"

void printIfSubstr(queue_str_t q ,char str[])
{
	int len = strlen(str), i;
	char temp[20], hold[20];
	
	printf("Strings that contain the substring \"%s\" are:\n", str);
	while(!is_empty_str_q(&q))
	{
		remove_str_q(&q, hold); 
		int wordlen = strlen(hold);
	
		for(i=0; i<=wordlen-len; i++)
		{
			temp[0] = '\0';
			memmove(temp, hold + i, len);
			
			if(strcmp(temp, str) == 0)
			{
				printf("%s\n",hold);
				break; 
			}
		}
	}

}


int main()
{
	stack_t stack;
	queue_str_t queue[5];
	char strings[20], item[20], srch[20];
	int i, sCount, k=0;
	
	printf("Enter strings (end to stop):\n");
	do
	{
		initialize_s(&stack);
		initialize_str_q(&queue[k]);
		scanf("%s", strings);
		while(strcmp(strings, "return")!=0 && strcmp(strings, "end")!=0) 
		{
			push(&stack, strings);
			scanf("%s", strings);
		}
		
		while(is_empty_s(&stack)!=1)
			insert_str_q(&queue[k], pop(&stack, item));
		
		printf("Stack %d has been pushed.\n\n", k+1);
		
		k++;
	
	}while(strcmp(strings, "end")!=0); 
	
	printf("Enter the string to be searched: ");
	scanf("%s", srch);
	printf("Enter the number of the stack: ");
	scanf("%d", &sCount);
	
	printIfSubstr(queue[sCount-1], srch);
	
	
	return 0;
}
