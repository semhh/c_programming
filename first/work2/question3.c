#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    int choice, num;
    do{
        printf("          MENU             \n");
        printf("---------------------------\n");
        printf("1. Triangular?\n");
        printf("2. Prime?\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(choice!=1 && choice!=2 && choice!=3){
            printf("Wrong choice! Enter your choice again: ");
            scanf("%d", &choice);
        }
        
        
        if(choice==1){
            printf("Enter a number: ");
            scanf("%d", &num);
            int i, flag=0;
            int sum=0;
            for(i=1; i<=num/2; i++){
                sum += i;
                if(sum == num){
                    flag=1;
                    printf("%d is a triangular number\n",num);
                    break;
                }
            }
            if(flag == 0){
                printf("%d is NOT a triangular number\n",num);
            }
        }
        else if(choice==2){
            printf("Enter a number: ");
            scanf("%d", &num);

            int i, flag=0;
            for(i=2; i<=num/2; i++){
                if(num%i == 0){
                    flag=1;
                    printf("%d is NOT a prime number\n",num);
                    break;
                }
            }
            if(flag == 0){
                printf("%d is a prime number\n",num);
            }

        }
    }while(choice!=3);
    printf("Goodbye.\n");

    return 0;
}