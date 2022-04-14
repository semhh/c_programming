#include <stdio.h>
#include <string.h>

void sumOfTwo(int* num1, int* num2, int* sumArr){
    int hold=0, sum=0;
    for(int i=10; i>=0;i--){
        sum = num1[i] + num2[i] + hold;
        sumArr[i] = sum % 2;
        hold = sum / 2;
        sum=0;
    }
}

int main(){
    int num1[11], num2[11], sum[11];
    
    FILE *file_ptr; /* pointer to file */
    
    // Open the file for input
    file_ptr = fopen("numbers.txt", "r");

    char temp[11];
    char temp2[11];

    // Check if not exists
    if (file_ptr == NULL)
        printf ("Cannot open numbers.txt for input!\n");
    else
    { 
        int sumCount = 1;
        while(fscanf(file_ptr, "%s%s", &temp, &temp2) != EOF){
            int counter=0;
            for(int i=0; i<11; i++){
                if(i<11-strlen(temp)){
                    num1[i] = 0;
                }
                else{
                    num1[i] = temp[counter++] - '0';
                }
            }
            counter=0;
            for(int i=0; i<11; i++){
                if(i<11-strlen(temp2)){
                    num2[i] = 0;
                }
                else{
                    num2[i] = temp2[counter++] - '0';
                }
            }
           
            sumOfTwo(num1,num2,sum);
            printf("%d. sum is ", sumCount++);
            for(int i=0; i<11;i++){
                printf("%d ",sum[i]);
            }
            printf("\n");
        }
        
    }

    return 0;
}