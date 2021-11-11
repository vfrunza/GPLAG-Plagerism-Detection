#include <stdio.h>

int main() {
	
	int n; 
    int i,j; 
    
	for (;;) { 
		
		printf ("Unesite broj n: "); 
		scanf ("%d", &n); 
	
	if (n<1 || n>50) {
		printf ("Pogresan unos\n"); 
	}
	
	else { 
		
		if (n!=1)
		for (i=0; i<n; i++) { 
			
		    for (j=0; j<(4*n-3); j++) {
				
			if (i==j || (i+j-(n-1)==(n-1)) || (i==j-2*(n-1)) || ((i+j-3*(n-1))==(n-1)))
			printf ("*");  
		
			else 
				printf (" ");
		}
         
	      printf (" ");
	      printf ("\n");
		}
		
		else printf ("***"); 
	
		break;
	}
	}
	return 0;
}
