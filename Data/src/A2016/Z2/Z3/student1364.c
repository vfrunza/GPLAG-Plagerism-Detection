#include <stdio.h>

int main() {
	int broj_tacaka, i, j, x[10]={0}, y[10]={0}, br=0;
	char rezultat[20][20];
	for (i=0; i<20; i++)
	{
		for (j=0; j<20; j++)
		rezultat[i][j]=' ';
	}
	do {
		printf("Unesite broj tacaka: ");
	    scanf ("%d", &broj_tacaka);
		if (broj_tacaka<1 || broj_tacaka>10)
		printf ("Pogresan unos\n");
	}
	while (broj_tacaka<1 || broj_tacaka>10);
	
	for (i=0; i<broj_tacaka; i++)
	{
		do
		{
			printf ("Unesite %d. tacku: ", i+1);
		    scanf ("%d %d", &x[i], &y[i]);
		    if ((x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19) && i!=0)
		    {i--; printf ("Pogresan unos\n");}
		    else if ((x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19) && i==0)
		    {i=0; printf("Pogresan unos\n");}
		}
	    while (x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19
	    );
	}
	
	for (br=0; br<broj_tacaka; br++)
	{
  	for (i=0; i<20; i++)
  	{
  		for (j=0; j<20; j++)
  		{
  			if (x[br]==j && y[br]==i)
  				rezultat[i][j]='*'; 
  			
  		 }
  		}
	}
	
	for (i=0; i<20; i++)
	{
		for (j=0; j<20; j++)
		printf ("%c", rezultat[i][j]);
		printf ("\n");
		
	}
	
	return 0;
}
