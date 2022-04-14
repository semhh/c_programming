
#include<stdio.h>
#include <string.h>
#define STACK_SIZE  100
#define SIZE 30

int STACK_EMPTY = -987654321;

typedef struct
{
	char word[40];
}pword;

typedef struct
{	int	top;
	pword data[100]; 
} stack_t;

void initialize_s (stack_t *s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int is_empty_s (stack_t *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int is_full_s (stack_t *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push (stack_t *s, char item[])
{
	int i;
	if (is_full_s (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		for(i=0; i<SIZE; i++)
		s->data[s->top].word[i] = item[i]; 
	}
}

//------------------------------------------------------------------------------

char *pop(stack_t *s, char *item)
{
 	int length;
	int i;
	if (is_empty_s(s))
	{	printf("Error: Stack is empty!\n");
		*(item+0) = STACK_EMPTY;	
	}
	else
	{
		for(i=0; i<SIZE; i++)
		*(item+i) = s->data[s->top].word[i]; 
		
		(s->top)--;
	}		
	length = strlen(item);
	item[length]='\0';
	
	return item;	    	
}
