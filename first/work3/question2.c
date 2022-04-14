#include <stdio.h>
#include <math.h>

int factorial(int n){
    int res = 1, i;
    for(i = 2; i <=n;i++){
        res *= i;
    }
    return res;
}

int summation(int n){
    int res = 0;
    for(int i=n%2; i<=n; i+=2){
        res += i;
    }
    return res;
}

int f(int n){
    int result = 0;
    for(int i=-5; i<=n; i++){
        if(i<=0){
            result += pow(i,5) + factorial(abs(i));
        }
        else if(i<10){
            result += factorial(i) - 120;
        }
        else{
            result += summation(i);
        }
    }
    return result;
}

int main(){
    int n, result = 0;

    do{
        printf("Enter n (>= -5): ");
        scanf("%d", &n);
    }while(n<-5);

    printf("Result of the calculation: %d\n", f(n));
}