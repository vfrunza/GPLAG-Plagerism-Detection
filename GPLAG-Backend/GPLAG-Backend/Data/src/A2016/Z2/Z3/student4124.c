#include <stdio.h>

int main() {
	int brojTacaka, i,j,k=1, x,y;
	int matrica[20][20];
	for(i=0; i<20; i++)
		for(j=0; j<20; j++)
			matrica[i][j]=0;
	while(1)
	{
		printf("Unesite broj tacaka: ");
		scanf("%d",&brojTacaka);
		if(brojTacaka>10 || brojTacaka<=0)
		{
			printf("Pogresan unos\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("Unesite %d. tacku: ", k);
		scanf("%d %d",&x,&y);
		if(x>=20 || x<0 || y<0 || y>=20)
		{
			printf("Pogresan unos\n");
			continue;
		}
		k++;
		matrica[y][x] = 1;
		if((k-1)==brojTacaka)
			break;
		
	}
	for(i=0; i<20; i++)
	{
		for(j=0; j<20;j++)
		{
			if(matrica[i][j]==1)
				printf("*");
			else 
				printf(" ");
		}
	printf("\n");
	}
	return 0;
}
