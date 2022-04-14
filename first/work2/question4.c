#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    int num, numCpy, lastDigit;
    
    do{
        printf("Enter a positive number(0 to STOP): ");
        scanf("%d", &num);
        
        if(num<0){
            printf("Sorry! You didn't give a positive number!!!\n");
        }
        else{
            numCpy = num;
            while(numCpy!=0){
                lastDigit = numCpy %10;
                if(lastDigit==0){
                    printf("ZERO\t");
                }
                else if(lastDigit==1){
                    printf("ONE\t");
                }
                else if(lastDigit==2){
                    printf("TWO\t");
                }
                else if(lastDigit==3){
                    printf("THREE\t");
                }
                else if(lastDigit==4){
                    printf("FOUR\t");
                }
                else if(lastDigit==5){
                    printf("FIVE\t");
                }
                else if(lastDigit==6){
                    printf("SIX\t");
                }
                else if(lastDigit==7){
                    printf("SEVEN\t");
                }
                else if(lastDigit==8){
                    printf("EIGHT\t");
                }
                else if(lastDigit==9){
                    printf("NINE\t");
                }
                numCpy/=10;
            }
            printf("\n");
        }
    }while(num!=0);

    return 0;
}