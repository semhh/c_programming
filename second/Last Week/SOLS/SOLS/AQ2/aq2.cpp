#include <stdio.h>
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

/*alternative solution
node_t *reverse2 (node_t *headp)
{	node_t *newp;
	if (headp->next == NULL)
	{	newp = NULL;
		newp = add_beginning (newp, headp->data);
	}
	else
	{
		newp = reverse2 (headp->next);
		add_after (newp, headp->data);
	}
	return (newp);
}*/

node_t *reverse3 (node_t *headp, node_t *newp)
{	
	if (headp != NULL)
	{	newp = add_beginning (newp, headp->data);
		newp = reverse3 (headp->next, newp);
	}
	return (newp);
}


int
main(void)
{
	FILE *inp;
	node_t *list,*p;

	inp = fopen("students.bin","rb");
	if(inp == NULL)
		printf("File can not be opened!");
	else
	{
		list = CreateList(inp);
		fclose(inp);
		printf("Content of the file\n");
		display_list(list);
		list = deleteList(list,2.00);
		printf("After the elimination of CGPAs :\n");
		display_list(list);
		printf("Reverse of the list\n");
		list = reverse3(list, NULL);
		display_list(list);
	}
	return 0;
}