#include <stdio.h>

int main() {
	int i,j,n;
	do
	{
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50)
	printf("Pogresan unos\n");
	}while(n<=0 || n>50);
	if(n==1)
	{
		printf("***");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<(4*n-3);j++)
		{
			if(i==j || 2*n-2+i==j || 2*n-2-i==j || 4*n-4-i==j)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
