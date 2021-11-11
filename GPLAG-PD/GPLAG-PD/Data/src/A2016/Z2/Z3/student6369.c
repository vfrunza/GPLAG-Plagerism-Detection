#include <stdio.h>


int main() {
	int X[20],Y[20],i,j,br_tacaka,k;
	char mat[20][20];
	printf("Unesite broj tacaka: ");
	scanf("%d",&br_tacaka);
	for(i = 0 ; i < br_tacaka ; i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&X[i],&Y[i]);
		while(X[i] < 0 || X[i] > 19 || Y[i] < 0 || Y[i] > 19 || br_tacaka > 10 || br_tacaka < 0 )
		{
			printf("Pogresan unos\nUnesite %d. tacku: ",i+1);
			scanf("%d %d",&X[i],&Y[i]);
		}

	}
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			mat[i][j] =' ';
		}
	}
	
	for(i = 0; i < 20 ;i++)
	{
		for(j = 0; j < 20; j++)
		{
			for(k = 0; k < br_tacaka; k++)
			{
				if(i == Y[k] && j == X[k])
				{
					mat[i][j]='*';
				}
			}
		}
	}
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
