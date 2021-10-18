#include <stdio.h>
int main()
{
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<=0 || n>50)
	{
		printf("Pogresan unos \n");
		printf("Unesite broj n: ");
		scanf("%d",&n);
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n+3*(n-1); j++)
		{
			if(n==1) 
		{
			for(i=0;j<3;j++)
		{
			printf("*");
		}
		}
			else if(i==j || i+j== 2*(n-1) || j-i==2*(n-1) || i+j==4*(n-1))
			printf("*");
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}