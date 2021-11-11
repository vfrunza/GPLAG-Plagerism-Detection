#include <stdio.h>

int main() {
	int i,j,n;
	do {
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if((n<=0)||(n>50))
	printf("Pogresan unos\n");
	} while ((n<=0)||(n>50));
		if (n==1)
		printf("***");
		else	
		
    	for (i=1; i<=n; i++) {
	      for (j=1; j<=(2*(2*n-3)+3); j++) {
	 
	  	if ((i==j)||(i+j==2*n))
	  		printf("*");
	  		
	   	else if (i+j==2*n+2*(i-1))	
	  		printf("*");
	  		
	  	else if (i+j==4*n-2)
	  		printf("*");

	      
	else 
	printf(" ");
	      }
	printf("\n");
   
    	}

	return 0;
}
