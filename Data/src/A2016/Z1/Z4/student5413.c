#include <stdio.h>

int main() 
{
	int n;
	printf("Unesite broj n: ");
	while(1 == 1)
	{
		scanf("%d", &n);
		if(n < 1 || n > 50)
		{
			printf("Pogresan unos\n");
			printf("Unesite broj n: ");
			continue;
		}
		else
			break;
	}
	
	if(n == 1)
	{
		printf("***");
		return 0;
	}
	
	int i, k;
	for(i = 0; i < n; i++)
	{
		for(k = 0; k < n * 4 - 3; k++)
		{
			if(i == 0)
			{
				if(k == 0)
				  	printf("*");
				else if(k == n * 4 - 4)
				  	printf("*");
				else if(k == (n * 4 - 3) / 2)
				  	printf("*");
				else
				  printf(" ");
			}
			else if(i != 0 && i != n - 1)
			{
				if(k == i || k == ((n * 4 - 3) / 2) - i || k == ((n * 4 - 3) / 2) + i || k == ((n * 4 - 4)) - i)
				{
				  printf("*");	
				}
				else 
				  printf(" ");
			}
			else if(i == n - 1)
			{
				if(k == n - 1 || k == n * 4 - 4 - i)
				  	  printf("*");
					else 
				      printf(" ");	
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
