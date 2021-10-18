#include <stdio.h>

int main() 
{
	int i, j, n;
	
	for(i=0; i<50; i++)
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		
		if(n<=0 || n>50) printf("Pogresan unos\n");
		else break;
	}
	
	if(n==1) printf("***");
	else{
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n*4-3; j++)
		{
			if(i==j) printf("*");
			else if((i+j)/2.==n-1) printf("*");
			else if((j-i)/2.+1==n) printf("*");
			else if(((i+j+2)/2.+1)/2.==n) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
		}
	
	return 0;
}