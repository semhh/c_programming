//Ahmet Fatih YILMAZ 16050111007
#define STACK_SIZE  100

typedef  int  SType;

typedef struct{
	SType ar[STACK_SIZE];
	int	top1,top2;
	
}doublestack;

SType  STACK_EMPTY = -987654321;

void initialize_s1 (doublestack *s);
int is_empty_s1 (doublestack *s);
int is_full_s1 (doublestack *s);
void push1 (doublestack *s, SType item);
SType pop1 (doublestack *s);
void initialize_s2 (doublestack *s);
int is_empty_s2 (doublestack *s);
int is_full_s2 (doublestack *s);
void push2 (doublestack *s, SType item);
SType pop2 (doublestack *s);

void initialize_s1 (doublestack *s)
{
	s->top1 = -1;
}
int is_empty_s1 (doublestack *s)
{
	if (s->top1 == -1)
		return 1;
	return 0;
}

int is_full_s1 (doublestack *s)
{
	if (s->top1 == (s->top2)-1)
		return 1;
	return 0;
}
void push1 (doublestack *s, SType item)
{
	if (is_full_s1 (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top1)++;
		s->ar[s->top1] = item;
	}
}
SType pop1 (doublestack *s)
{
	SType item;
	if (is_empty_s1(s))
	{	printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;	
	}
	else
	{	item = s->ar[s->top1];
		(s->top1)--;
	}		    	
	return (item);
}
void initialize_s2 (doublestack *s)
{
	s->top2 = STACK_SIZE;
}
int is_empty_s2 (doublestack *s)
{
	if (s->top2 == STACK_SIZE)
		return 1;
	return 0;
}
int is_full_s2 (doublestack *s)
{
	if (s->top2 == (s->top1)+1)
		return 1;
	return 0;
}
void push2 (doublestack *s, SType item)
{
	if (is_full_s2 (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top2)--;
		s->ar[s->top2] = item;
	}
}
SType pop2 (doublestack *s)
{
	SType item;
	if (is_empty_s2(s))
	{	printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;	
	}
	else
	{	item = s->ar[s->top2];
		(s->top2)++;
	}		    	
	return (item);
}
