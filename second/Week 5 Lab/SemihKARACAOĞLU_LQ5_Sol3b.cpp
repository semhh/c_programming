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

int binarySeach(char plate[100][10],char temp[8],int top,int bottom,int *comp){
	
	int middle;
	
	while (top <= bottom) {
			
		*comp=*comp+1;
		middle = (top + bottom) / 2;
		
		if (strcmp(plate[middle],temp)==0){
			return (middle);
		}
		else{			
			
			if(strcmp(plate[middle],temp)==1){
				bottom = middle-1;
			}
			else{
				top = middle+1;	
			}
		}	
	}
	
	return (-1);
}

int main(){
	
	char name[100][10];
	int surname[100][10];
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
		
		int comp=0;
		int x=binarySeach(plate,temp,0,size-1,&comp);
				
		if(x!=-1){
			printf("%s ",name[x]);
			printf("%s ",surname[x]);
			printf("%s\n",plate[x]);
			printf("%d comparisons.\n",comp);
		}
		else{
			printf("NOT FOUND\n");
			printf("%d comparisons\n",comp); 
		}
		
		printf("\nEnter plate of a car (END for exit) : ") ;
		gets(temp);	
	}
	
	return 0;
}




