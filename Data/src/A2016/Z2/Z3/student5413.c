#include <stdio.h>

int main() 
{
	int n = 0, x = 0, y = 0;
	int i, k;
	char matrix[20][20];
	
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n < 1 || n > 10)
		  printf("Pogresan unos\n");
		  
	}while(n < 1 || n > 10);
	
	for(i = 0; i < 20; i++)
	{
		for(k = 0; k < 20; k++)
		  matrix[i][k] = ' ';
	}
	
	i = 0;
	while(i < n)
	{
		printf("Unesite %d. tacku: ", i + 1);
		scanf("%d %d", &y, &x);
		if(x < 0 || x > 19 || y < 0 || y > 19)
		{
			printf("Pogresan unos\n");
			continue;
		}
		matrix[x][y] = '*';
		i++;
	}
	
	for(i = 0; i < 20; i++)
	{
		for(k = 0; k < 20; k++)
		{
			printf("%c", matrix[i][k]);
		}
		printf("\n");
	}
	return 0;
}
