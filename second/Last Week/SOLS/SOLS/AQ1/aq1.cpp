#include <stdio.h>
#include "stack_struct.h"
#include "linked_list.h"

node_t* deleteList(node_t *headp,double grade)
{
	node_t *p;
	if(headp->data.cgpa < grade)
			headp = delete_first(headp);
	p = headp;
	while(p->next != NULL)
	{
			if(p->next->data.cgpa < grade)
				delete_after(p);
			else
				p =  p->next;
	}
	return headp;
}

void reverse(node_t *headp)
{
	node_t *p;
	stack_t s;

	initialize_s(&s);

	p = headp;

	while(p != NULL)
	{
		push(&s,p->data);
		p = p->next;
	}

	p = headp;
	
	while(!is_empty_s(s))
	{
		p->data = pop(&s);
		p = p->next;
	}
}

void write_to_bin(char *fname,node_t *list)
{
	node_t *p;
	FILE *out;
	out = fopen(fname,"wb");
	p = list;

	while(p != NULL)
	{
		fwrite(&(p->data),sizeof(students_t),1,out);
		p = p->next;
	}
	fclose(out);
}

int
main(void)
{
	FILE *inp,*out;
	node_t *list,*p;

	inp = fopen("students.bin","rb");
	if(inp == NULL)
		printf("File can not be opened!");
	else
	{
		list = CreateList(inp);
		fclose(inp);
		printf("Content of the LIST\n");
		display_list(list);
		list = deleteList(list,2.00);
		printf("After elimination\n");
		display_list(list);
		printf("Reverse of the list\n");
		reverse(list);
		display_list(list);
		write_to_bin("students.bin",list);
	}
	return 0;
}