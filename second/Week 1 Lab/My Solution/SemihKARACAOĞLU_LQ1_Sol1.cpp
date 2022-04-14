#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Semih KARACAOÐLU
//17050111008
//This program finds given words are palindrome or not

int findSize(char a[]){
	
		int size = strlen(a)-1;
	
	return size;
}


int isPalindrome(char str[]){ 
    
    int l = 0; 
    int h = findSize(str)-1; 
  
    while (h > l) { 

		if (str[l++] != str[h--]){ //Not Palindrome
		printf("Not Palindrome\n"); 
            return 0; 
        } 
    } 
    
	//palindrome
	printf("Palindrome\n");
	return 1; 
}


int readFile(char fileName[]){
	
	char ch;
	FILE *fp;
	char text[25][25];
	int row=0;
	
	fp = fopen(fileName, "r"); // read mode
	
	if(fp == NULL){
	      perror("Error while opening the file.\n");
	      exit(EXIT_FAILURE);
	}

	printf("All Words\n");
	printf("*********\n");
	while(row<25 && fgets(text[row], sizeof(text[0]), fp) != NULL)
        ++row;
    for (int i= 0; i != row; ++i){
        //puts(text[i]);
        printf("%s",text[i]);
        isPalindrome(text[i]);
        printf("\n");
	}
	fclose(fp);
}


int main(){
	
		char fileName[20] =	"Palindrome.txt";
		readFile(fileName);
	
	return 0;
}










