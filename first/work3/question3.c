#include <stdio.h>
#include <math.h>

int convertToBase(int num, int base, int conv_base){
    int base10 = 0;
    int counter =0;
    while(num>0){
        int rem = num%10;
        base10 += (rem * pow(base,counter));
        num /= 10;
        counter++;
    }
    int res=0;
    counter = 1;
    while(base10>0){
        int rem = base10 % conv_base;
        res += rem * counter;
        counter *=10;
        base10 /= conv_base;
    }

    return res;
}

int main(){
    int base, num, conv_base;
    printf("Enter the base and the number:");
    scanf("%d %d", &base, &num);

    printf("Enter the base to be converted:");
    scanf("%d", &conv_base);

    printf("Number in base %d = %d",conv_base, convertToBase(num, base, conv_base));
   
    return 0;
}