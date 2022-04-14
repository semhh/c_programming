#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    int choice, randNum;
    do{
        printf("          MENU             \n");
        printf("---------------------------\n");
        printf("1. Right Triangle\n");
        printf("2. Isoceles Triangle\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        srand(time(0)); 
        randNum = rand() % 6 + 3;
        
        
        int i,j;
        if(choice==1){
            printf("Random number is %d\n", randNum);
            for(i=1; i<=randNum; i++){
                for(j=randNum; j>i; j--){
                    printf(" ");
                }
                for(j=i; j>0; j--){
                    printf("%d",j);
                }
                printf("\n");
            }
            printf("Press any key to continue...\n");
        }
        else if(choice==2){
            printf("Random number is %d\n", randNum);
            for(i=1; i<=randNum; i++){
                for(j=randNum; j>i; j--){
                    printf(" ");
                }
                for(j=i; j>0; j--){
                    printf("%d",j);
                }
                for(j=2; j<=i; j++){
                    printf("%d",j);
                }
                printf("\n");
            }
            printf("Press any key to continue...\n");
        }
        else if(choice!=3){
            printf("Enter a valid choice\n");
        }
    }while(choice!=3);
    printf("Goodbye.\n");

    return 0;
}