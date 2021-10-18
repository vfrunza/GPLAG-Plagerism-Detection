#include <stdio.h>

int main() {
	int i,j,n=1;
	CP:	 printf("\nUnesite broj n: ");
		scanf("%d", &n);
		if(n <= 0 || n > 50)
			{
				printf("Pogresan unos ");
				goto CP;
				}
		
	else if (n>0 && n <= 50 && n!= 1)
			{
				for(i=0; i<n; i++)
			{
				for(j=0; j<4*n; j++)
				{
					if(i==j || j==2*n-i-2 || (j == 2*n + i-2) || (j==4*n-i-4))
						printf("*");
					else
						printf(" ");
				}
				
				printf("\n");
			}
			}

		
	else if (n == 1)
	printf("***");
	
	
	
	return 0;
}
