#include <stdio.h>

int main() {
	int niz[20][20];
	int i,j;
	for (i=0; i<20; i++)
		for (j=0; j<20; j++)
			niz[i][j]=0;
	
	int broj_Tacaka = 0;
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &broj_Tacaka);
	
	while (broj_Tacaka <= 0 || broj_Tacaka > 10)
	{
		printf ("Pogresan unos\n");
		printf ("Unesite broj tacaka: ");
		scanf ("%d", &broj_Tacaka);
	}
	
	for (i=0; i<broj_Tacaka; i++)
	{
		int x,y;
		printf ("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &x, &y);
		if (x<0 || x>=20 || y<0 || y>=20)
		{
			printf ("Pogresan unos\n");
			i--;
		}
		else 
		{
			niz[x][y]=1;
		}
		
	}
	for (i=0; i<20; i++)
	{
		for (j=0; j<20; j++)
		{
			if (niz[j][i] == 0)
			{
				printf (" ");
			}
			else 
			{
				printf ("*");
			}
		}
		printf ("\n");
	}
		return 0;
}
