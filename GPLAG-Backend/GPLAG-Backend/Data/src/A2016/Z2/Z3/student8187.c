#include <stdio.h>

int main() {
	int x,y,b,i,j,c;
	char mat[20][20];
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &b);
	while (b<1 || b>10)
	{
		printf ("Pogresan unos\n");
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &b);
	}
	for (i=0; i<20; i++)
	{
		for (j=0; j<20; j++)
		{
			mat[i][j]=' '; 
		}
	}
	
	for (c=1; c<=b; c++)
	{
		printf ("Unesite %d. tacku: ", c);
		scanf ("%d %d", &x, &y);
		while (x<0 || x>19 || y<0 || y>19)
		{
			printf ("Pogresan unos\n");
			printf ("Unesite %d. tacku: ", c);
			scanf ("%d %d", &x, &y);
		}
	
		mat[x][y]='*';
	}
	for (i=0; i<20; i++)
	{
		for (j=0; j<20; j++)
		{
			if (mat[j][i]=='*') {printf ("*");}
			else { printf (" ");}
		}
	
		printf ("\n");
	}

	return 0;
}
