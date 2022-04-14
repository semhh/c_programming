#include <stdio.h>
#include <conio.h> 

int main(){
    int upperCount = 0;
    int lowerCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int otherCount = 0;
    printf("Enter characters ending with '.':");
    char ch;
    ch = getche();
    while(ch!='.'){
        if(ch >= 'a' && ch<= 'z'){
            lowerCount++;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u'){
                vowelCount++;
            }
            else{
                consonantCount++;
            }
        }
        else if(ch>='A' && ch <='Z'){
            upperCount++;
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch =='U'){
                vowelCount++;
            }
            else{
                consonantCount++;
            }
        }
        else if(ch == ' '){

        }
        else{
            otherCount++;
        }
        ch = getche();
    }
    printf("\n\n");
    printf("Number of uppercase letters %d\n", upperCount);
    printf("Number of lowercase letters %d\n", lowerCount);
    printf("Number of vowels %d\n", vowelCount);
    printf("Number of consonants %d\n", consonantCount);
    printf("Number of other characters %d\n", otherCount);


    return 0;
}