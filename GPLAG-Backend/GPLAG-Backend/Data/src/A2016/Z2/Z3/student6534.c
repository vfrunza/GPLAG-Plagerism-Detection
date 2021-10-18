#include <stdio.h>

int main() {
	int brojt,k,z,x,y;
	int mat[20][20];
	for (k=0;k<20;k++)
	for (z=0;z<20;z++)
	mat[k][z]=0;
printf("Unesite broj tacaka: ");
scanf ("%d",&brojt);
while (brojt<=0 || brojt>10) 
	{
		printf ("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf ("%d",&brojt); 
		}
	for (k=0;k<brojt;k++)
{
			printf ("Unesite %d. tacku: ",k+1);
			scanf ("%d%d",&x, &y);
			if (x>=0 && x<20 && y>=0 && y<20)mat[y][x]=1;
			else {
			printf ("Pogresan unos\n");
			k--;
			}
		}
		for (k=0;k<20;k++)
		{
		for (z=0;z<20;z++) 
			if (mat[k][z]==1) 
			printf ("*");
			else 
			printf (" ");
			printf ("\n");
	
		}
			return 0;
}