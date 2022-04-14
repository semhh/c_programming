#include <stdio.h>
#include "linked_list.h"

node_t* deleteList(node_t *headp,double grade)
{
	node_t *p;
	if(headp->data.cgpa < grade)
	{
			headp = delete_first(headp);
			return headp;
	}
	p = headp;
	while(p->next != NULL)
	{
			if(p->next->data.cgpa < grade)
			{
				delete_after(p);
				return headp;
			}
			else
				p =  p->next;
	}
	return headp;
}
int
main(void)
{
	FILE *inp;
	students_t temp;
	node_t *list,*p;

	
	inp = fopen("student.txt","r");
	if(inp == NULL)
		printf("File can not be opened!");
	else
	{
		list = CreateList(inp);
		fclose(inp);
		printf("Content of the LIST\n");
		display_list(list);
		list = deleteList(list,2.00);
		printf("After the elimination of the first student with cgpa < 2.00 :\n");
		display_list(list);
	}
	return 0;
}