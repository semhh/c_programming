#include <stdlib.h>
typedef struct
{
	int id;
	double cgpa;
}students_t;

typedef struct node_s
{	students_t data;
	struct node_s *next; 
} node_t;

node_t *Getnode (void)
{
	node_t *node;
	node = (node_t *) malloc (sizeof(node_t));
	node->next = NULL;
	return (node);
}

//function that displays the list
void display_list (node_t *headp)
{	
	node_t *p;
	
	if (headp == NULL)
		printf("\nThe List is EMPTY !!!\n\n");
	else 
	{	
		p = headp;
		
		while (p != NULL)
		{	
			printf ("%d %.2f \n",p->data.id,p->data.cgpa);
			p = p->next;
		}
	}
}

void add_after (node_t *p, students_t item)
{
	node_t *newp;
	newp = Getnode();	
	newp->data = item;
	newp->next = p->next;
	p->next = newp;
}

node_t *add_beginning (node_t *headp, students_t item)
{	
	node_t *newp;
	newp = Getnode();	
	newp->data = item;
	newp->next = headp;
	return (newp);
}

//function that creates the list by using the file elements
node_t* CreateList(FILE *inp)
{
	node_t *headp, *p;
	students_t stu;
	double y;
	int x,status;

	headp = NULL; 

	status=fscanf(inp,"%d %lf",&stu.id,&stu.cgpa);
	if (status != EOF)
	{	
		headp = add_beginning (headp, stu);

		status=fscanf(inp,"%d %lf",&stu.id,&stu.cgpa);
		p = headp;
    	
		while (status != EOF)
		{	
			add_after (p, stu);
			p = p->next;
			status=fscanf(inp,"%d %lf",&stu.id,&stu.cgpa);
		} 
	}
	return headp;
}

node_t *delete_first (node_t *headp)
{	
	node_t *del;
	del = headp;
	headp = del->next;
	free (del);
	return (headp);
}

void delete_after (node_t *p)
{	
	node_t *del;
	del = p->next;
	p->next = del->next;
	free (del);
}