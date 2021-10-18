#include <stdio.h>

int main() {
	int a,b,i,j,k,q, z[200][200], r;
	/* osiguravamo da se brojevi nalaze u opsegu*/
	do 
	{
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &a, &b);
		if (a<=0 || a>200 || b<=0 || b>200)
		{
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	}

	while (a<=0 || a>200 || b<=0 || b>200);
	
	/*unos elemenata matrice*/
	printf ("Unesite elemente matrice: ");
	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++)
		{
			scanf ("%d", &z[i][j]);
		}
	}
	
	/*ispitivanje jednakosti redova uz pomoc logicke varijable*/
	r=0;
	for (i=1; i<a; i++)
	{
		for (j=0; j<i; j++)
		{
			r=0;
			for (k=0; k<b; k++)
			{
				if (z[i][k]!=z[j][k])
				{
					r=1; 
					break;
				}
			}
		/*izbacivanje identicnih redova*/
			if (r==0)
			{
			for (q=i; q<a-1; q++)
			
			{
				for (k=0; k<b; k++)
				
				{
					z[q][k]=z[q+1][k];
				}
			}
			a--;
			i--;
			
			}
		}
		
	}
	
	/*ispitivanje jednakosti kolona uz pomoc logicke varijable*/
	for (k=1; k<b; k++)
	{
		for (j=0; j<k; j++)
		{
			r=0;
			for (i=0; i<a; i++)
			{
				if (z[i][k]!=z[i][j])
				{
					r=1;
					break;
				}
			}
		/*izbacivanje identicnih kolona*/
			if (r==0)
			{
				for (q=k; q<b-1; q++)
				{
					for (i=0; i<a; i++)
					{
						z[i][q]=z[i][q+1];
						
					}
				}
				k--;
				b--;
			}
		}
	}
	
/* ispis novonastale matrice*/	
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0; i<a; i++)
	{
		printf (" ");
		for (j=0; j<b; j++)
		{
			printf ("%4d ", z[i][j]);
		}
		
		printf ("\n");
	}
	return 0;
}
