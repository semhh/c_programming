#define STACK_SIZE  100

typedef  int  STypep;

STypep  stack_empty = -987654321;

typedef struct
{	int	top;
	STypep data[STACK_SIZE];
} stack_p;


void initialize_s_pn (stack_p *s);
int is_empty_s_pn (stack_p *s);
int is_full_s_pn (stack_p *s);
void push_pn (stack_p *s, STypep item);
STypep pop_pn (stack_p *s);

//------------------------------------------------------------------------------

void initialize_s_pn (stack_p *s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int is_empty_s_pn (stack_p *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int is_full_s_pn (stack_p *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push_pn (stack_p *s, STypep item)
{
	if (is_full_s_pn (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

//------------------------------------------------------------------------------

STypep pop_pn (stack_p *s)
{
	STypep item;
	if (is_empty_s_pn(s))
	{	printf("Error: Stack is empty!\n");
		item = stack_empty;	
	}
	else
	{	item = s->data[s->top];
		(s->top)--;
	}		    	
	return (item);
}

//------------------------------------------------------------------------------


