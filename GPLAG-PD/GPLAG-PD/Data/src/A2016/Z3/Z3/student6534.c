#include <stdio.h>

int main() {
	int m,n,mat[200][200],i,j,brojac,k,z,s,p;
	printf("Unesite brojeve M i N: ");
	scanf ("%d%d",&m,&n);
	while (m>200 || n>200 || m<1 || n<1)
	{printf("Brojevi nisu u trazenom opsegu.\n");
	printf("Unesite brojeve M i N: ");
	scanf ("%d%d",&m,&n);}
	printf ("Unesite elemente matrice: ");
	
	/*Unos elemenata matrice*/
	for (i=0;i<m;i++)
	{	for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);	}
			
/*poredjenje redova*/
for (s=0;s<m;s++)		
{	for (i=s+1;i<m;i++)
	{	brojac=1;
		for(j=0;j<n;j++)
		{	if (mat[s][j]!=mat[i][j]) 
			{brojac=0;break;}
		}
			if (brojac)
			{	/*izbaciti citav red*/
				for (z=i+1;z<m;z++)
				{	for(k=0;k<n;k++)
					mat[z-1][k]=mat[z][k];
				} 
				i--;m--;
			}
	}
}

/*poredjenje kolona*/
for (s=0;s<n;s++)
{	for (i=s+1;i<n;i++)
	{	brojac=1;
		for(j=0;j<m;j++)
		 {	if ( mat[j][s]!=mat[j][i]) 
		 	{brojac=0;break;}
		 }
			if (brojac)
			{ 	/*izbaciti citavu kolonu*/
				for (z=i+1;z<n;z++)
				{	for(k=0;k<m;k++)
					mat[k][z-1]=mat[k][z];
				} 
				i--;n--;
			}
	}
}
printf("Nakon izbacivanja redova/kolona matrica glasi: \n ");
for (i=0;i<m;i++)
{ for (j=0;j<n;j++)
	printf("%4d ",mat[i][j]);
	printf("\n");
	printf(" ");
}
	return 0;
}