#include <stdio.h>
int i,j,n;
int main() {
	
	do{
	printf("Unesite broj n: ");
	scanf("%d", &n);
    if (n<=0 || n>50)
       printf("Pogresan unos\n");
    
    if(n==1)
    {
    printf("***");
    return 0;
    }
  }
  while (n<=0 || n>50);
     for (i=1; i<=n; i++){
    	for (j=1; j<4*n; j++){
    	    if ((i==j) || (j==2*n-i) || (j==2*n-2+i) || (j==4*n-2-i))
    	        printf("*");
    	        else 
    	            printf(" ");
    	        
    	    }
    		printf("\n");
     }
    		return 0;
    
}
    