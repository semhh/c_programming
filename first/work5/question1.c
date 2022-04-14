#include <stdio.h>

int main(){
    
    FILE *file_ptr; /* pointer to sentence file */
    
    // Open the file for input
    file_ptr = fopen("sentence.txt", "r");
    char previous=' ', current;
    char user_choice;

    int counter = 0, lineNum = 1;

    printf("Enter a character:");
    scanf("%c", &user_choice);

    printf("User choice: %c\n", user_choice);
    // Check if not exists
    if (file_ptr == NULL)
        printf ("Cannot open sentence.txt for input!\n");
    else
    { 
        while(fscanf(file_ptr, "%c", &current) != EOF){
            if(current==' ' && (previous == user_choice)){
                counter++;
            }
            else if(current=='\n' || current=='\0'){
                if(previous == user_choice){
                    counter++;
                }
                printf("There are %d words ending with '%c' in the %d. Line\n", counter, user_choice, lineNum++);
                counter=0;
            }
            previous=current;    
        }
        if(previous==user_choice){
            counter++;
        }
        printf("There are %d words ending with '%c' in the %d. Line\n", counter, user_choice, lineNum++);
    }

    return 0;
}