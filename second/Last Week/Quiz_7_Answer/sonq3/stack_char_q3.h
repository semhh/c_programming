#define STACK_SIZE  100
#include <string.h>

typedef struct
{
	char* fdata;
	int length;
} mydata;

//typedef  mydata  SType;

char  STACK_EMPTY = '*';

typedef struct
{	int	top;
	mydata data[50];
} stack_t;

//Functions in this file...
void initialize_s (stack_t *s);
int is_empty_s (stack_t *s);
int is_full_s (stack_t *s);
void push (stack_t *s, char* item,int len);
char* pop (stack_t *s);

//------------------------------------------------------------------------------

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


char *copyString(char *str)
{
  char *tmp = malloc(strlen(str) + 1);//'\0'
  if (tmp)
    strcpy(tmp, str);
  return tmp;
}

//------------------------------------------------------------------------------

void push (stack_t *s, char* item, int len)
{
	if (is_full_s (s))
		printf("Error: Stack is full!\n");
	else
	{
        //s->data[0].fdata okuduğumuz kelimeyi koyuyoruz
        //s->data[0].length okuduğumuz kelimenin uzunluğunu koyuyoruz.
        //s->top 1 arttırmamız lazım.

        //s->data[1].fdata okuduğumuz kelimeyi koyuyoruz
        //s->data[1].length okuduğumuz kelimenin uzunluğunu koyuyoruz.
        //s->top 1 arttırmamız lazım.


		s->data[++(s->top)].fdata = copyString(item);
		s->data[s->top].length = len;

	}
}

//------------------------------------------------------------------------------

char* pop (stack_t *s)
{
	mydata item;

	if (is_empty_s(s))
	{	printf("Error: Stack is empty!\n");
		//item.fdata = STACK_EMPTY;
	}
	else
	{
	    //item.fdata = s -> data[s->top--].fdata;
		//item.fdata,s -> )

		//(s -> top) = (s->top)  -1;
	}
	return s->data[s->top--].fdata;
}
