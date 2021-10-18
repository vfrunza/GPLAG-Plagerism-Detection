#include <stdio.h>

int main() {
	int i, j, n;
	
	printf("Unesite broj n: ");
	scanf("%d",&n);
	
	 if (n<=0 || n>50 ) do { printf ("Pogresan unos\nUnesite broj n: "); scanf ("%d", &n); }
	while (n<=0 || n>50);
	
	if (n==1) printf ("***");
		else {
		for(i=0; i<n; ++i) 
		{
			 
			 for(j=0; j<4*n-3; ++j) 
			{if (j==i+2*n-2 || j==-i+2*n-2 || j==-i+4*n-4 || i==j  )
			
	
			 	printf("*");
			 	
			
			 	
			else printf (" ");
			}
			printf("\n");
		}}
	return 0;
}
