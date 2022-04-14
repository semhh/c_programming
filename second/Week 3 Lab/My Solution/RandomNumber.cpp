#include <stdio.h>
#include <stdlib.h> //for srand funtion
#include <time.h> //for time function

int main(void){
	
	int num;
	srand(time(0)); //we use srand function to be able to get a random number
	
//but we can not use the srand function on its own we also
//use time function in it to give a start point to the srand function.
//because time is different every time you run the program,
//the random number will be different also
	
	num=rand()%100; //because time returns a very big number because
	
//it returns the milisecond value of the hour, so we want to get a random number
//between 0 and 99, we get the modulus 100 of the rand function
	
	printf("The random number is: %d", num);
return(0);
}
