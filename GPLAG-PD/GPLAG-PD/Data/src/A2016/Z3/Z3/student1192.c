#include <stdio.h>


int main() {
	int m, n, i ,j, k,l, isti;
	int niz[200][200], red[200];
	/*ulaz i program provjera da li M i N pripadaju zadanom intervalu*/
	do {
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	if((m<=0)||(n<=0)||(m>200)||(n>200))
	printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while((m<=0)||(n<=0)||(m>200)||(n>200));
	
	/*Unos elemenata matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &niz[i][j]);
		}
	}
	
   /*izbacivanje istih redova*/
	for(i=0; i<(m-1); i++)
	{
			if(m==1)
			break;
				for(k=1; k<(m-i); k++)
				{
				isti=1;
					for(j=0; j<n; j++)
					{
				    if(niz[i][j]!=niz[i+k][j])
					isti=0;
					}
   /*niz r pamti koji su redovi isti kao red koji ispitujemo*/
					if(isti==1)
				 	red[k]=1;
			    	else 
			    	red[k]=0;
				}
		
		
 /*Izbacivanje svih redova koji su isti kao red koji ispitujemo */
		for(k=1; k<(m-i); k++)
		{
			/*Program provjerava koji je red isti i onda ga izbacuje iz matrice*/
			if(red[k]==1)
			{
				
				for(l=(i+k); l<(m-1); l++)
				{
					for(j=0; j<n; j++)
					niz[l][j]=niz[l+1][j];
				}
				i--; m--;
				
			}
		}
		
	}
	
	
	/*Izbacivanje istih kolona iz matrice*/
	for(j=0; j<(n-1); j++)
	{
		
		
				for(k=1; k<(n-j); k++)
				{
				isti=1;
					for(i=0; i<m; i++)
					{
				    if(niz[i][j]!=niz[i][j+k])
					isti=0;
					}
					if(isti==1)
				 	red[k]=1;
			    	else 
			    	red[k]=0;
				}
		
		
			
			for(k=1; k<(n-j); k++)
		{
			if(red[k]==1)
			{
				for(l=(j+k); l<(n-1); l++)
				{
					for(i=0; i<m; i++)
					niz[i][l]=niz[i][l+1];
				}
				j--; n--;
				
			}
		}
		
	}
	
	
	
	/*Izlaz*/
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
		for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%5d", niz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
