#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Semih KARACAOÐLU
//17050111008

int findFirst(char sent[100], char str[10]){
	
	int size1=strlen(sent);
	int size2=strlen(str);
	int nsent[100];
	
	for(int i=0; i<size1; i++){
		
		if(i==0 && strncmp(sent+i,str,size2)==0 && *(sent+(size2+i))==' '){
			return i;
		}
		else if(*(sent+i)==' ' && strncmp((sent+(i+1)),str,size2)==0 && *(sent+i+size2+1)==' '){
			return i+1;
		}
		else if(strcmp(sent+i,str)==0 && i+size2==size1){
			return i+1;
		}
	}
	
		printf("\nThere is no such a word!");
		exit(0);
		
}

void del(char sent[100], char str[10], int index){
	
	int size1=strlen(str);
	int size2=strlen(sent);
	char nsent[100];
	
	if (index!=0){
	
		strncpy(nsent,sent,index-1);
		strcat(nsent,(sent+index+size1));
	}
	
	else
		strcpy(nsent,(sent+index+size1));

	printf("\nThe new form of the sentence after deletion: %s",nsent);
	
}

int main(){
	
	char sent[100];
	printf("Enter a sentence: ");
	gets(sent);
	char str[10];
	printf("Enter a word: ");
	scanf("%s",str);
	int a=findFirst(sent,str); 
	del(sent,str,a);
	
	return 0;
}
