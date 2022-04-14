#include <stdio.h>
#include "queue_struct.h"
#include "stack_struct.h"

void displayQ(queue_t q)
{
	product_t p;	
	while(!is_empty_q(&q))
	{
		p = remove(&q);
		printf("%-5d%-7.2f%-5d\n",p.id, p.price,p.amount);
	}
}


void display_stack(stack_t s)
{
	product_t p;
	while(!is_empty_s(&s))
	{
		p = pop(&s);
		printf("%-5d%-7.2f%-5d\n",p.id, p.price,p.amount);
	}
}


int main(void)
{
	stack_t stack;
	initialize_s(&stack);
	queue_t q;
	initialize_q(&q);

	product_t pr;
	FILE *inp = fopen("items.txt","r");

	if(inp!=NULL)
	{
		int status= fscanf(inp,"%d %lf %d",&pr.id, &pr.price, &pr.amount);
		while(status!=EOF)
		{
			if(pr.amount < 100)
				insert(&q,pr);
			else
				push(&stack,pr);

			status= fscanf(inp,"%d %lf %d",&pr.id, &pr.price, &pr.amount);
		}
		
		printf("Queue contents: \n");
		displayQ(q);
		
		printf("\n\nStack contents: \n");
		display_stack(stack);

		printf("\n");
		int amount;
		while(!is_empty_q(&q))
		{
			pr = remove(&q);
			printf("Enter the purchase amount for Item %d (min %d): ", pr.id, 100 - pr.amount);
			scanf("%d",&amount);
			while(amount + pr.amount < 100)
			{
				printf("Wrong Input!\nEnter the purchase amount for Item %d (min %d): ", pr.id, 100 - pr.amount);
				scanf("%d",&amount);
			}
			pr.amount += amount;
			push(&stack,pr);
		} 


		printf("\n\nStack contents after purchases: \n");
		display_stack(stack);
	
	}else printf("cannot open file");
	
	return (0);
}