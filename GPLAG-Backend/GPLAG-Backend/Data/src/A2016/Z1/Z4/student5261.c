#include <stdio.h>

int main()
{
	int n, i, j, k;
	while(1)
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<1 || n>50)
		{
			printf("Pogresan unos\n");
			continue;
		}
		break;
		
	}
	if(n==1)
	{
		printf("***");
	}
	else
	{
	for(i=0;i<n;i++) 
	{
		for(j=0;j<2*n-1;j++)
		{
			if((i==j && i<n) || (i+j==2*n-2 && i<n))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for(k=1;k<2*n-1;k++)
		{
			if(i==k || i+k==2*n-2)
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	}

	return 0;
}
