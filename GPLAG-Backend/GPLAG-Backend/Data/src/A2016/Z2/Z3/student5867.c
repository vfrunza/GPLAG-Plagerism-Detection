#include <stdio.h>

int main() 
{
	int i, j, n, x, y, k, niz_x[400], niz_y[400];
	char mat[20][20];
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	
	for(i=0; i<1; i++)
	{
		if(n>10 || n<=0)
		{
			printf("Pogresan unos");
			printf("\nUnesite broj tacaka: ");
			scanf("%d", &n);
			i--;
		}
		else break;
	}
	
	for(i=0; i<n; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		for(j=0; j<1; j++)
		{
		if(x<0 || y<0 || x>=20 || y>=20)
		{
			printf("Pogresan unos");
			printf("\nUnesite %d. tacku: ", i+1);
			scanf("%d %d", &x, &y);
			j--;
		}
		}
		
		niz_x[i]=x;
		niz_y[i]=y;
	
	}
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			mat[i][j]=' ';
		}
	}
	
	for(k=0; k<n; k++)
	{
		for(i=0; i<20; i++)
		{
			for(j=0; j<20; j++)
			{
				if(i==niz_y[k] && j==niz_x[k])
				mat[i][j]='*';
			}
		}
	}
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	
		
		
	
	
	return 0;
}
