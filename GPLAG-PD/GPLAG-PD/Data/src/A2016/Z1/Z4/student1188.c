#include <stdio.h>

int main() {
  	int n,i,j;
    do{
        printf("Unesite broj n: ");
        scanf("%d",&n);
        if(n<1||n>50){
        printf("Pogresan unos\n");
            
        }
    }
    while(n<1||n>50);
  	if(n==1){
  	    printf("***");
  	    return 0;
  	}
  	
  	for(i=0;i<n;i++){
  	    for(j=0;j<=n*n;j++){
  	        if(i==j){
  	            printf("*");
  	            
  	        }
  	        else if(j+i==n*2-2){
  	            printf("*");
  	        }
  	        else if(i+j==n*4-4){
  	            printf("*");
  	        }
  	        else if(j-i==n*2-2){
  	            printf("*");
  	        }
  	        else {
  	            printf(" ");
  	        }
  	    }
  	    printf("\n");
  	}
  	
	return 0;
}
