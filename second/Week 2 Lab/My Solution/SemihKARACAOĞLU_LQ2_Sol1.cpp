#include <stdio.h>

//Semih KARACAOÐLU
//17050111008
//This program reads product.txt file and stores the informations in a structures. After writes to the console.

#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 50

typedef struct{
	char prod_name[20];
	double price;
	int warranty;
}product_t;

product_t product[MAX_ARRAY_SIZE];

void ReadFile(char *fileName);

int main(int argc, char *argv[]){
    
	char *fileName = "product.txt";

    ReadFile(fileName);
	
    int i = 0;
	
    for (i = 0; i < 3; i++){
    	printf("************************\n");
        printf("Name : %s\n", product[i].prod_name);
        printf("Price : %0.1lf\n", product[i].price);
        printf("Years Of Warranty : %d\n", product[i].warranty);
    }

    exit(EXIT_SUCCESS);
}

void ReadFile(char *fileName){
    
	FILE *filePtr = NULL;
    int  i = 0;
	int prod_num;
    
	if ((filePtr = fopen(fileName, "r")) == NULL){
        printf("Error : Unable to open %s for reading\n");
        exit(EXIT_FAILURE);
    }
    
	fscanf(filePtr, "%d", &prod_num) != EOF;
    while (fscanf(filePtr, "%s%lf%d", &product[i].prod_name, &product[i].price, &product[i].warranty) != EOF){
        i++;
    }
    
	printf("There are %d products\n\n",prod_num);
	printf("The Product Information:\n");
    fclose(filePtr);
}
