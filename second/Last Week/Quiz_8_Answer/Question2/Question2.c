//inserting each character into a queue 
//display the new queue content

#include <stdio.h>
#define SIZE 1000

int front=0, rear=-1;

void displayQueue(char queue[SIZE], int front, int rear){   //display the queue content 
	int k;
    printf("\nThe content of the queue is: ");
    
	for(k=front; k<= rear; k++){
        printf("%c ", queue[k]);
    }
    printf("\n");
}

int main(){
    
    printf("*\t Erase the first character (remove it from thr queue)\n");
    printf("+\t Kill the entire line (Empty the queue)\n");
    printf(": or !\t Display the queue content\n");
    printf("Enter\t Terminate the string entry and display the queue content\n");

    printf("Enter characters to be inserted to the queue (press enter to stop)..\n");

    char input[SIZE];
    scanf("%s", input);  

    
    char queue[SIZE]; // create a queue 
    int i = 0;
    
    while (input[i] != '\0')  // iterate until null
    {
        
        if(input[i] == '*'){   // remove first character from the queue
              printf("The character <%c> is removed from the queue\n", input[front]);
              front++;
           
        } 
		else if(input[i] == '+'){
            // remove the whole characters from the queue
            printf("All the characters are removed from the queue\n");
            front = 0;    
            rear = -1;
        } 
		else if(input[i] == ':' || input[i] == '!'){
            // display the queue
            displayQueue(queue, front, rear);
        }
        else {
            // insert into the queue
            rear++;
            queue[rear] = input[i];
        }
        i++;
    }

    displayQueue(queue, front, rear);

    return 0;
}
