#include <stdio.h>

int main() {
	
	int i, j, k, brt=0;
	
	char smor[20][20];

	printf("Unesite broj tacaka: ");
	scanf("%d", &brt);
	
	
	while(brt<=0 || brt>10)
	{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &brt);
	}
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			smor[i][j] = ' ';
		}
	}
	for(k=0; k<brt; k++)
	{
		printf("Unesite %d. tacku: ", k+1);
		scanf("%d%d", &i, &j);
		
		while(i<0 || i>19 || j<0 || j>19)
		{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", k+1);
			scanf("%d%d", &i, &j);
			
		}
		smor[i][j] = '*';
		
	}
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			printf("%c", smor[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
