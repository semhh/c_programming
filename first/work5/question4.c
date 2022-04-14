#include <stdio.h>
#include <math.h>

int isPrime(int num){
    for(int i=2;i<=(int)sqrt(num);i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int isPerfect(int num){
    int sum=0;
    for(int i=1; i<=(num/2);i++){
        if(num%i==0){
            sum+=i;
        }
    }
    if(sum==num){
        return 1;
    }
    else{
        return 0;
    }
}



int main(){
    int primes[100], perfects[100];
    int primeCount=0, perfectCount=0, count=0,temp;
    
    printf("Enter the integer numbers: ");
    scanf("%d",&temp);
    while(temp!=-1)
    {
        count++;
        if(isPrime(temp)){
            primes[primeCount++] = temp;
        }
        if(isPerfect(temp)){
            perfects[perfectCount++] = temp;
        }
        scanf("%d",&temp);
    }

    printf("There are %d numbers, %d of them are perfect and %d of them are prime\n", count, perfectCount, primeCount);
    printf("Prime numbers are: ");
    for(int i=0; i<primeCount; i++){
        printf("%d ", primes[i]);
    }
    printf("\n");
    printf("Perfect numbers are: ");
    for(int i=0; i<perfectCount; i++){
        printf("%d ", perfects[i]);
    }

    return 0;
}