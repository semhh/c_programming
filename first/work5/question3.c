#include <stdio.h>

int main(){
    
    FILE *file_ptr; /* pointer to sentence file */
    FILE *output_file;
    // Open the file for input
    file_ptr = fopen("mytext.txt", "r");
    output_file = fopen("reversed.txt", "w");
   
    char word[50];
    char current;
    int counter=0;
    
    // Check if not exists
    if (file_ptr == NULL)
        printf ("Cannot open mytext.txt for input!\n");
    else
    { 
        while(fscanf(file_ptr, "%c", &current) != EOF){
            if(current!=' ' && current!='\n'){
                word[counter++]=current;
            }
            else{
                if(counter%2==0){
                    for(int i=counter-1; i>=0; i--){
                        fprintf(output_file,"%c",word[i]);
                    }
                }
                else{
                    for(int i=0; i<counter; i++){
                        fprintf(output_file,"%c",word[i]);
                    }
                }
                counter=0;
                fprintf(output_file,"%c",current);
            }
        }
        if(counter%2==0){
            for(int i=counter-1; i>=0; i--){
                fprintf(output_file,"%c",word[i]);
            }
        }
        else{
            for(int i=0; i<counter; i++){
                fprintf(output_file,"%c",word[i]);
            }
        }
    }

    return 0;
}