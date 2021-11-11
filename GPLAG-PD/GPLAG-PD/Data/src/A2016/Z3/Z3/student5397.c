#include <stdio.h>

int main() 
{
	int a, b, n, m, k ,countr, countk, i, j, e, l, niz[200][200], x, y, s, d, v, o, p, z, u;
	
	k=0;

	/*Unos dimenzija matrice koji se ponavlja sve dok nisu zadovoljeni uslovi da 
	su dimenzije brojevi izmedju 0 i 200 ukljucujuci 200*/
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf ("%d %d", &a,&b);
		
		if ((a>0 && a<=200) && (b>0 && b<=200))
		{
			m=a;
			n=b;
			k=1;
		}
		
		else
		{
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	}while (k==0);
	
	/*Unos elemenata matrice*/
	printf ("Unesite elemente matrice: ");
	
    for (e=0; e<m; e++)
	{
		for (l=0; l<n; l++)
		{
			scanf ("%d", &niz[e][l]);
		}
	}
	
	/*Izbacivanje redova koji se ponavljaju vise puta, tako da 
	ostane samo prvi takav red koji se prvi odozgo pojavljuje u matrici*/
	for (i=0; i<m; i++)
	{
		/*Varijable s predstavlja redove sa kojima se poredi jedan red*/
		s=i+1;
		while (s<m)
		{
			/*Brojac countr broji da li redovi koji se porede imaju isti broj elemenata,
			tako sto poredi broj jednakih elemenata sa varijablom n koja predstavlja broj elemenata u svakom redu*/
		   countr=0;
		   for (j=0; j<n; j++)
		   {
			  if (i!=(m-1))
			  {
				 if (niz[i][j]==niz[s][j])
				 {
					countr++;
					if (countr==n)
					{
						/*Ukoliko jesu jednaki redovi, onda se drugi po redu red izbacuje iz matrice*/
						for (x=s; x<m; x++)
						{
							for (y=0; y<n; y++)
							{
								niz[x][y]=niz[x+1][y];
								s=i;
							}
						}
						m--;
					}
				 }
			   }
		    }
		    s++;
	    }
	}

    /*Izbacivanje kolona koje se ponavljaju vise puta, tako da 
	ostane samo prva lijeva takva kolona u matrici*/
    for (o=0; o<m; o++)
	{
		for (p=0; p<n; p++)
		{
			
			if (p!=(n-1))
			{
			   /*Varijabla z predstavlja kolone sa kojima se poredi jedna kolona*/
			   z=p+1;
			   while(z<n)
			   {
				 if (niz[o][p]==niz[o][z])
				 {
				 	/*Brojac countk broji da li kolone koje se porede imaju isti broj elemenata,
			        tako sto poredi broj jednakih elemenata sa varijablom m koja predstavlja broj 
			        elemenata u svakoj koloni, odnosno broj redova u matrici*/
				 	countk=0;
					for (u=0; u<m; u++)
					{
						if (niz[u][p]==niz[u][z])
						{
							countk++;
							if (countk==m)
							{
								/*Ukoliko jesu jednake kolone, onda se druga po redu kolona izbacuje iz matrice*/
								for (x=0; x<m; x++)
						        {
							       for (y=z; y<n; y++)
							       {
							          niz[x][y]=niz[x][y+1];
							          if (m==1)
							          {z=p;}
							       }
						        }
						        n--;
							}
						}
					}
				 }
				 z++;
			   }
			}
		}
		o=m;
	}
	
   /*Printanje matrice nakon sto su otklonjeni odgovarajuci redovi i kolone*/
   printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (d=0; d<m; d++)
	{
		for (v=0; v<n; v++)
		{
			printf ("%5.d", niz[d][v]);
		}
		printf ("\n");
	}
	
	
	return 0;
}
