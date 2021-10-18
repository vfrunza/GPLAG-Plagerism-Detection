#include <stdio.h>

int main ()
{
	int i, j, n;
	
	while(1)
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50)
		{
			printf("Pogresan unos\n");
		}
		else
		break;
	}
	if(n==1)
	{
		printf("**");
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<4*n-3; j++)
		{
			if(i==j || j==-i+(2*n-2) || j==i+(2*n-2) || j==-i+(4*n-4))
			printf("*");
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}