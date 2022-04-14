#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Semih KARACAOÐLU
//17050111008

int *disp_one(){
	
	printf("\n\nVector is\n");
	printf("*************\n");
	int arr1[4];
  	FILE* file = fopen ("OneDimArray.txt", "r");
  	int i = 0;

  	fscanf (file, "%d", &i);    
  
  	while (!feof (file)){
    	
		  	
		for(int m=0;m<4;m++){
				arr1[m] = i;
				fscanf(file, "%d", &i);	
		}
		fscanf(file, "%d", &i);
	}
	
	for(int x=0;x<4;x++){
				printf("%d ",arr1[x]);
		}

  fclose (file);
  return arr1;
}

int *disp_two(){
	
	printf("Matrix is\n");
	printf("*********\n");

	int arr2[4][4];
  	FILE* file = fopen ("TwoDimArray.txt", "r");
  	int i = 0;

  	fscanf (file, "%d", &i);    
  
  	while (!feof (file)){
    	  	
		for(int m=0;m<4;m++){
			for(int n=0;n<4;n++){
				
				arr2[m][n] = i;
				fscanf(file, "%d", &i);	
			}
		}
		fscanf(file, "%d", &i);
	}
	
	for(int x=0;x<4;x++){
			for(int y=0;y<4;y++){
				printf("%d ",arr2[x][y]);
				if(y==3)
				printf("\n");
			}
		}

  fclose (file);

	int *p,arr[4];
	p=disp_one();
	
	for(int a=0;a<4;a++)
	arr[a] = *(p+a);
	
	
	printf("\n\nThe product is\n");
	printf("**************\n");
	
	int f,h,result=0;
	
	for (f = 0; f < 4; f++){
		result=0;
		for(h=0;h<4;h++){
		result += arr2[f][h]*arr[h];
		}
		printf("%d\n",result);
	}

}

int main(){
	
	
	disp_two();

	return 0;
}
