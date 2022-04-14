#include<stdio.h>
#include <ctype.h>

typedef struct{
	int x,y,z,w;
	char c;
}adress_t;

int search_nick(adress_t adr[100], int i){
	int j;
	int a=0;
	for(j=0;j<i;j++){
		if(tolower(adr[j].c)!=tolower(adr[i].c))
			a++;
	}
	if(a!=i)
		return 1;
	else
		return 0;	
}

int main(){

	adress_t adr[100];
	int same[100];
	int c_same=0;
	int i=0;
	
	printf("Numeric addresses are specified in the form of xxx.yyy.zzz.www\n\n");	
	
	do{
		printf("Enter the numeric address and nickname: ");
		scanf("%d.%d.%d.%d %c",&(adr+i)->x,&(adr+i)->y,&(adr+i)->z,&(adr+i)->w,&(adr+i)->c);
		
		if((i>0) && ((adr+i)->x!=0,(adr+i)->y!=0,(adr+i)->z!=0,(adr+i)->w!=0)){
			while(search_nick(adr,i)){
				printf("Existing name!\nEnter another nickname: ");
				getchar();
				scanf("%c",&adr[i].c);				
			}	
		}
		i++;
			
	}while((adr-1+i)->x!=0,(adr-1+i)->y!=0,(adr-1+i)->z!=0,(adr-1+i)->w!=0);	

	int check[i-1][i-1];
	
	for(int e=0;e<i-1;e++){
		for(int w=0;w<i-1;w++)
			check[e][w]=0;
			
	}
	
	for(int a=0;a<i-1;a++){
		for(int b=a+1;b<i;b++){
			if((adr+a)->x==(adr+b)->x&&(adr+a)->y==(adr+b)->y){
				printf("\nComputers\n");
				printf("'%c' (%d.%d.%d.%d)\n",adr[a].c,adr[a].x,adr[a].y,adr[a].z,adr[a].w);
				printf("'%c' (%d.%d.%d.%d)\n",adr[b].c,adr[b].x,adr[b].y,adr[b].z,adr[b].w);
				printf("are from the same locality!\n");
			}
			else if((adr+a)->x!=(adr+b)->x&&(adr+a)->y==(adr+b)->y)
				printf("No computers are from the same locality!\n");
						
		}
	}
	
	int b=0;
	int  a=0;
	int counter=0;
	check[b][a]=(adr+b)->x;
	check[b][a+1]=(adr+b)->y;
	
	for(b=1;b<i-1;b++){	
		if((adr+b)->x!=(adr+b-1)->x&&(adr+b)->y==(adr+b-1)->y){
				a=0;
				check[b][a]=(adr+b)->x;
				check[b][a+1]=(adr+b)->y;
				counter++;
		}		
	}
	
	for(int z=0;z<counter;z++){
		printf("%d.%d",check[z][0],check[z][1]);
	}

}
