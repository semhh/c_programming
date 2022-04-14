#include <stdio.h>
#include "linked_list.h"

node_t *reverse (node_t *headp)
{	node_t *pre, *cur, *temp;
	pre = headp; 
	if (pre != NULL)
	{	cur = pre->next; 
		pre->next = NULL;
		while (cur != NULL) 
		{	temp = cur->next; 
			cur->next = pre; 
			pre = cur; 
			cur = temp;
		}
	}
	return (pre);
}

int main(void)
{
	FILE *inp;
	node_t *list;

	inp = fopen("student.txt","r");
	if(inp == NULL)
		printf("File can not be opened!");
	else
	{
		list = CreateList(inp);
		fclose(inp);
		printf("Content of the LIST\n");
		display_list(list);
		printf("\nReverse of the LIST\n");
		list = reverse(list);
		display_list(list);
	}
	return 0;
}