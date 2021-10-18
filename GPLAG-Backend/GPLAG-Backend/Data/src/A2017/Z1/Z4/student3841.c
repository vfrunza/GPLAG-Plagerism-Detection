#include <stdio.h>

int main() {
	int n,i,j;
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	while(n<=0 || n>50) {
		printf ("Pogresan unos\n");
		
		printf("Unesite broj n: ");
		scanf("%d", &n);
		}
        for(i=0;i<n;i++) {
        	for(j=0;j<i;j++) {
        		printf(" ");
        		
        	}
        	printf("*");
        	 
      
      for(j=0;j<(n-2)+(n-1)-(2*i); j++)     {
      	printf(" ");
      }
      if(i==0) {
      	printf("*");
      }
      if(i>0 && i<n-1) {
      	printf("*");
      	for(j=0;j<(2*i-1); j++)  {
      		printf(" ");
      		}
      		printf("*");
      }
      	
       for(j=0;j<(n-2)+(n-1)-(2*i); j++) {
      	printf(" ");
      	
      }
      if(i==n-1) {
      	
      	for(j=0; j<(2*i-1); j++)  {      
      		printf(" ");
      	}
      }
      printf("*\n");

        }
      return 0;
      }
      
      
      
      
      
      
      
      
      
      
      
      
      
      