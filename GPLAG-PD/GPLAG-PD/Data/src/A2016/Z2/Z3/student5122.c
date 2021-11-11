#include <stdio.h>
int main() {
	int n, x, y, i, j;
	char mat[20][20];
	unos: printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>10 || n<=0)
	{ 
		printf("Pogresan unos\n"); goto unos;
	}
		for(i=0; i<20; i++)
		{
			for(j=0; j<20; j++)
			{
			mat[i][j]=' ';
			}
		}
	for(i=0; i<n; i++)
	{ 
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x,&y);
		if((x<0 || x>19)||(y<0 || y>19))
		{
			printf("Pogresan unos\n");
			i--;
		}
		else
		mat[y][x]='*';
	}
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}	
	return 0;
}
