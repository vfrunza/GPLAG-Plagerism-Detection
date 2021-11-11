#include <stdio.h>

int main() {
	int n,i,j;
	printf ("Unesite broj n: ");
	scanf ("%d", &n);

	while (n<=0 || n>50)
	{
		printf ("Pogresan unos");
		printf ("\nUnesite broj n: ");
		scanf ("%d", &n);
	
	}
		
	
	for (i=0; i<n; i++)
	{
		
		if (n==1) 
			{
			printf("***"); 
			return 0;
			
			}
		
		for (j=0; j<4*n-3; j++)
		{
			if (j==i || i+j==2*n-2 || i+j==4*n-4 || j-i==2*n-2)
			{
				printf ("*");
			}
		
			else 
			{
				printf (" ");
			}
			
		}
			printf ("\n");
		
	}
			
	
	return 0;
	
	
}
