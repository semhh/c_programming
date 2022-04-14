#include<stdio.h>
#include"stack_int.h"

void display(stack_t s);
int main(){
	
	stack_t st ; 
	initialize_s(&st);
	
	int array[6];
	int i ; 
	for(i=0; i<6;i++){
		printf("Enter an integer: ");
		scanf("%d",&array[i]);
		push(&st,array[i]);
	}
	
	printf("\nStack Content \n--------------------\n");
	display(st);
	
	int a = pop(&st);
	int b = pop(&st);
	
	push(&st,a);
	push(&st,b);
	
	printf("\n After Swap \n--------------------\n");
	display(st);
	
	return 0;
}
void display(stack_t s){
	while(!is_empty_s(&s))
		printf("%9d\n",pop(&s));
	
}


