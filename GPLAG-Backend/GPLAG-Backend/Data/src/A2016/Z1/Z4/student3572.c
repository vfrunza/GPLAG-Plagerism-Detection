#include <stdio.h>

int main() {
	int i,n,j,a;
	
	do
	{
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50)
	printf("Pogresan unos\n");
	}
	while (n<=0 || n>50);
    a=(2*n-3)*2+3;
	if (n==1) 
	printf("***");
	else
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<a; j++)
		{
			if( j==i )
			printf("*");
			else 
			
			if(i==2*n-2-j)
			printf("*");
			else
			
			if(j-i==2*n-2)
			printf("*");
			else 
		    if(i==(n-1)*4-j)
			printf("*");
			else 
			printf (" ");
		}
		printf("\n");
	}
	
	
	return 0;
}
