#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int readFromFile(FILE *inp,char num[10][15]){
	
	inp=fopen("phones.txt","r");
	int i=0;
	
	while(fscanf(inp,"%s,",(num+i))!=EOF){
		i++;
	}
	
	return i;
}

void updateDirectory(char num[10][15],int size){

	for(int i=0;i<size;i++){
		
		char code[20]={"(312)  "};
	
		if(strlen(*(num+i))<10){
			strcat(code,*(num+i));
			strcpy(*(num+i),code);
		}
		else{
			strcat(code,(*(num+i)+3));
			strcpy(*(num+i),code);
		}
	}
}

void printDirectory(char num[10][15],int size){
	
	for(int i=0;i<size;i++)
		printf("%s\n",*(num+i));
		
}

int main(){
	
	FILE *inp;
	char num[10][15];
	char code[]={"(312)"};
	int size=readFromFile(inp,num);
	
	printf("There are %d phone numbers in directory\n",size);
	
	updateDirectory(num,size);
	printDirectory(num,size);

	return 0;
}







