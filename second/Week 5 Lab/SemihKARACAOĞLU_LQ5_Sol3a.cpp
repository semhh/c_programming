#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Semih KARACAOŠLU
//17050111008

int search(char plate[100][10],char temp[8],int size){
	
	int k=0;
	
	while(k<size&&strcmp(plate[k],temp)!=0){
		k++;
	}
	if(strcmp(plate[k],temp)==0){
		return k;
	}
	else{
		return -1;
	}
}

int main(){
	
	char name[100][10];
	char surname[100][10];
	char plate[100][10];
	
	FILE *inp=fopen("plates.txt","r");
	int i=0;
	
	while(fscanf(inp,"%s",(name+i))!=EOF){
		fscanf(inp,"%s",(surname+i));
		fscanf(inp,"%s",(plate+i));
		i++;
	}	
	
	int size=i;
	
	char end[]={"END"};
	char temp[9];
	printf("Enter plate of a car (END for exit) : ") ;
	gets(temp);

	while(strcmp(end,temp)!=0){
		
		int x = search(plate,temp,size);
		
		if(x!=-1){
			printf("%s ",name[x]);
			printf("%s ",surname[x]);
			printf("%s\n",plate[x]);
			printf("%d comparisons.\n",x+1);
		}
		else{
			printf("NOT FOUND\n");
			printf("%d comparisons\n",size); 
		}
		
		printf("\nEnter plate of a car (END for exit) : ") ;
		gets(temp);
	}
	
	return 0;
}




