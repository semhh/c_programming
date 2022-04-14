#include <stdio.h>

void f1(){
    printf("****\n");
}

void f2(){
    printf("*\n");
}
void f3(){
    printf("   *\n");
}
void f4(){
    printf("*  *\n");
}

void zero(){
    f1();f4();f4();f4();f4();f4();f1();
}

void one(){
    for(int i=0; i<7;i++){
        f3();
    }
}

void two(){
    f1();f3();f3();f1();f2();f2();f1();
}

void three(){
    f1();f3();f3();f1();f3();f3();f1();
}

void four(){
    f4();f4();f4();f1();f3();f3();f3();
}

void five(){
    f1();f2();f2();f1();f3();f3();f1();
}

void six(){
    f1();f2();f2();f1();f4();f4();f1();
}

void seven(){
    f1();f3();f3();f3();f3();f3();f3();
}

void eight(){
    f1();f4();f4();f1();f4();f4();f1();
}

void nine(){
    f1();f4();f4();f1();f3();f3();f1();
}

int main(){
    FILE *file_ptr; /* pointer to file */
    
    // Open the file for input
    file_ptr = fopen("digits.txt", "r");
    

    int digit;

    // Check if not exists
    if (file_ptr == NULL)
        printf ("Cannot open digits.txt for input!\n");
    else
    { 
        while(fscanf(file_ptr, "%d", &digit) != EOF){
            switch (digit)
            {
            case 0:
                zero();
                break;
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                four();
                break;
            case 5:
                five();
                break;
            case 6:
                six();
                break;
            case 7:
                seven();
                break;
            case 8:
                eight();
                break;
            case 9:
                nine();
                break;
            default:
                printf("Wrong value\n");
                break;
            }
            printf("\n");
        }
    }
}