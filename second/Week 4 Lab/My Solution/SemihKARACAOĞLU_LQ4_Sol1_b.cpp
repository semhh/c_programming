#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Semih KARACAOÐLU
//17050111008

int findFirst(char sent[100],char str[10]){
	
	char *a=strstr(sent,str);
		if(a!=NULL)
			return a-sent;
			
		else{
			printf("There is no such a word");
			exit(0);
		}
}

void del(char sent [100],char str[10],int index){
	
	int size1=strlen(str);
	int size2=strlen(sent);
	char nsent[100];
	
	if (index!=0){
		strncpy(nsent,sent,index);
		strcat(nsent,(sent+index+size1));
	}
	else
		strcpy(nsent,(sent+index+size1));

	printf("The new form of the sentence after deletion: %s",nsent);
	
}

int main(){
	
	char sent[100];
	printf("Enter a sentence: ");
	gets(sent);
	char str[10];
	printf("\nEnter a string: ");
	scanf("%s",str);
	int a=findFirst(sent,str);
	 
	del(sent,str,a);
	
	return 0;
}
