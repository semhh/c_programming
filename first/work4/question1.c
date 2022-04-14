#include <stdio.h>


int main(){
    
    int num;
    do{
        do{
            printf("Enter a number (1-9 or non-positive to stop): ");
            scanf("%d",&num);
        }while(num>9);

        if(num<1){
            break;
        }

        int i,j;

        for(i=1; i<=num; i++){
            for(j=1; j<=num; j++){
                if(j<=i){
                    printf("%d",j);
                }
                else{
                    printf("*");
                }
            }
            printf("\n");
        }
    }while(num>0);

    return 0;
}