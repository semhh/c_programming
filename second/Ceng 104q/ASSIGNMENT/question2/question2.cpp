#include <stdio.h>
#include "customer_queue.h"
#include "person_info.h"
#include "phone_num.h"
#define STACK_SIZE  100
void menu();//for menu which is help for customer
void waiting_process(queue_t *q,int *count);//put the customer in a queue 
void mov_q_to_s(stack_t *s,queue_t *q,stack_p *p,int numb,int *count);//move information in a queue to stack
void kill(stack_t *s,int num);//deleting customer's phone number
void menu()
{
	printf("1)application form for telephone installations\n2)number waiting for process\n3)completing the application\n4)delete record\n5)menu\n6)exit\nenter a choice:");
}

void waiting_process(queue_t *q,int *count)
{		customer_t cus;
	
		printf("\nEnter a name:");scanf("%s",cus.nameq);
		printf("\nEnter a surname:");scanf("%s",cus.snameq);
		printf("\nEnter an adress:");scanf("%s",cus.adressq);
		printf("\nEnter a birthday(like->day month year):");scanf("%d %d %d",&(cus.adateq.dayq ),&(cus.adateq.monthq ),&(cus.adateq.yearq ));
		printf("\nSecurity Question\nWhat is your lucky count:");scanf("%d",&cus.squenq);
		insert(q,cus);
		(*count)++;
	
}

void mov_q_to_s(stack_t *s,queue_t *q,stack_p *p,int numb,int *count)
{	
	stack_t temp1;
	customer_t cus;
	stack_p phone;
	initialize_s_pn(&phone);
	initialize_s(&temp1);
	int temp;
	for(int i=0;i<STACK_SIZE;i++)
{
	numb+=2;
	push_pn(&phone,numb);
}
	while(!is_empty_q(q))
	{	
		cus=remove(q);
		cus.phone_num=pop_pn(&phone);
		push(s,cus);
	}

	while(!is_empty_s(s))
	{
		cus=pop(s);
		printf("%s\n%s\n%s\n%d %d %d\nphone number:%d\n\n",cus.nameq,cus.snameq,cus.adressq,cus.adateq.dayq,cus.adateq.monthq,cus.adateq.yearq,cus.phone_num);
		push(&temp1,cus);
	}
	(*s)=temp1;
	(*count)=0;
}
void kill(stack_t *s,int num)
{	stack_t temp3;
	initialize_s(&temp3);
	
	customer_t kil;
	int luck;
	
	while(!is_empty_s(s) )
	{	kil=pop(s);
		if(kil.phone_num==num)
		{
			printf("\nSecurity Question!!\nWhat is your lucky count?:");scanf("%d",&luck);
				if(luck==kil.squenq)
				{
					printf("%s %s 's acoount was deleting completed!!!",kil.nameq,kil.snameq);
				}
				else
				{
					printf("\nLUCKY COUNT IS WRONG!!!!\n\nPlease come to our office near you!");
				}
			
		}
		else
		{
			push(&temp3,kil);
		}
		
	}
	(*s)=temp3;
	
}

int main()
{	queue_t q;
	stack_t s;
	stack_p p;
	customer_t cus;
	initialize_q(&q); 
	initialize_s(&s);
	initialize_s_pn(&p);
	int b;//for choice 
	int coun=0,numb=2717171;// the company's own phone number and this number is starting point.Also the company was set up in Kýrýkkale :)
	int num; 
	printf("Welcome Our TT Telecommunication Company\nPlease enter the number of the process you want to do\n\n\n\n");
	menu();
	scanf("%d",&b);

	
do
{

	switch (b)
	{
	case 1:
		waiting_process(&q,&coun);
		printf("\nThe application has been successfully completed.\n Please enter 5 for menu or enter 6 for exit!");
		scanf("%d",&b);
		break;	
	case 2:
		printf("number of waiting process:%d",coun);
		printf("\nThe process has been successfully completed.\n Please enter 5 for menu or enter 6 for exit!");
		scanf("%d",&b);
		break;
	case 3:
		mov_q_to_s(&s,&q,&p,numb,&coun);
		printf("\nThe process has been successfully completed.\n Please enter 5 for menu or enter 6 for exit!");
		scanf("%d",&b);
		break;
	case 4:
		printf("\nplease enter the phone number:");scanf("%d",&num);
		kill(&s,num);
		printf("\n\n Please enter enter 6 for exit!");
		scanf("%d",&b);
		break;
	case 5:
			menu();
			scanf("%d",&b);
		break;
	}
}while(b!=6);	
		
	return 0;
	}
