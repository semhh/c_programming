//AHMET FATIH YILMAZ   16050111007 
//I write example program for header files
#include <stdio.h>
#include "last.h"


int main()
{	
	doublestack s;
	initialize_s1(&s); 
	initialize_s2(&s);
	
	for(int i=0;i<50;i++)
		push1(&s,i);
	
	for(int i=50;i<110;i++)
		push2(&s,i);
		
	while(!is_empty_s2(&s))
		printf("%d ",pop2(&s));
		
	while(!is_empty_s1(&s))
		printf("%d ",pop1(&s));
			
		
	return 0;
}
