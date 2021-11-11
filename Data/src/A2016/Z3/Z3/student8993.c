#include <stdio.h>
#define dimenzija 200

int main() {
	int matrica[dimenzija][dimenzija];
	int m,n,i,j,k;
	int nred, nkolona;
	int ima;
	int x=0;
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&m,&n);
		if(n<=0 || n>200 || m<=0 || m>200)
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
			
		}
		else break;
		
	}while(1);
	nred=m;
	nkolona=n;
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n;j++)
		{
			scanf("%d", &matrica[i][j]);
		}
	}
	/*izbacivanje redova*/
	for(x=0;x<nred-1;x++)
	{
		
		for(i=x+1; i<nred;i++)
		{ 
			ima=1;
			for(j=0; j<n; j++)
				{	
					if(matrica[x][j]!=matrica[i][j])
						{
							ima =0;
							break;
						}
				}
			if(ima==1)
				{
					for(k=i; k<nred-1;k++)
						{
							for(j=0; j<n; j++)
								{
									matrica[k][j]=matrica[k+1][j];
								}
						}
					i--;
					nred--;
					
				}
		}
		
		
		
	}
	/*Izbacivanje kolona*/
	if(n>1)
	{
	x=0;
	while(x<n)
	{
		for(i=x+1; i<nkolona; i++)
		{
			ima=1;
			for(j=0;j<nred; j++)
			{
				if(matrica[j][x]!=matrica[j][i])
				{
					ima=0;
					break;
				}
			}
			if(ima==1)
			{
				for(j=i; j<nkolona-1; j++)
				{
					for(k=0; k<nred; k++)
					{
						matrica[k][j]=matrica[k][j+1];
					}
				}
				i--;
				nkolona--;
			}
		}
		x++;
	}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<nred;i++)
	{
		for(j=0; j<nkolona;j++)
		printf("%5d", matrica[i][j]);
		printf("\n");
	}
	
	
	return 0;
}
