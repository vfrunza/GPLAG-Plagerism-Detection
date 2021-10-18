#include <stdio.h>

int main() {
	int i,j,n;
	do
	{
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if (n<=0 || n>50)
		printf("Pogresan unos\n");
	} while (n<=0 || n>50);
	
	if (n==1)
	{
		printf("***");
		return 0;
	}
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<4*n-3;j++)
		{
			if (i==j)
			printf("*");
			else if (i+j==(4*n-3)/2)
			printf("*");
			else if (j-i==(4*n-3)/2)
			printf("*");
			else if (j+i==(4*n-3)-1)
			printf("*");
			else
			printf(" ");
		}
	printf("\n");
	}
	return 0;
}
