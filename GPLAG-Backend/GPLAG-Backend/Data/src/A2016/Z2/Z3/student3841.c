#include <stdio.h>

int main() 
{
	/*printf("Zadaća 2, Zadatak 3");*/
	
	char fluks[20][20];
	int x = 0, y = 0, n = 0, i = 0, j = 0;

	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
			fluks[i][j] = ' ';
	}
	
	idk:
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	
	if(n <= 0 || n > 10)
	{
		printf("Pogresan unos\n");
		goto idk;
	}
	
	for(i = 0; i < n; i++)
	{
		semra:
		printf("Unesite %d. tacku: ", i + 1);
		scanf("%d %d", &y, &x);
		
		if(x < 0 || y < 0 || x > 19 || y > 19)
		{
			printf("Pogresan unos\n");
			goto semra;
		}
			
		
		fluks[x][y] = '*';
	}
	
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			printf("%c", fluks[i][j]);
		}
		
		printf("\n");
	}
	return 0;
}
