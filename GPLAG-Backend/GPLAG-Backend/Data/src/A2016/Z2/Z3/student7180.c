#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j, a, b;
	int mat[20][20];
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			mat[i][j]=0;
		}
	}
	
	while(1==1)
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10) printf ("Pogresan unos\n");
		else break;
	}
	for(i=0; i<n; i++)
	{
		
		while(1)
		{
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &a, &b);
			if(a<0 || a>19 || b<0 || b>19) printf("Pogresan unos\n");
			else break;
		}
		mat[b][a]=1;
	}
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			if(mat[i][j]==1) printf ("*");
			else printf (" ");
		}
		printf("\n");
	}
	return 0;
}
