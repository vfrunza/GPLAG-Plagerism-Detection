#include <stdio.h>

int main() {
	int matrica[200][200]={{0}},m=0,n=0,i,j,x,k,a,b;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if((m<=0)||(m>200)||(n<=0)||(n>200))
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while((m<=0)||(m>200)||(n<=0)||(n>200));
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{

		for(j=0;j<n;j++)
		{
			scanf("%d",&matrica[i][j]);
		}
	}
	
	/*izbacivanje redova koji se ponavljaju*/
	for(k=0;k<m-1;k++)
	{
		x=0;
		for(i=k+1;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(matrica[k][j]==matrica[i][j])
				x=1;
				else
				{
					x=0;
					break;
				}
			}
			/*ako se poklapaju pomjeram redove*/
			if(x==1)
				{
					for(a=i;a<m-1;a++)
					{
						for(b=0;b<n;b++)
						{
							matrica[a][b]=matrica[a+1][b];
							
						}
					}
					m--;
					i=k;
				}
		}
	}
	/*izbacivanje kolona koje se ponavljaju*/
	for(k=0;k<n-1;k++)
	{
		x=0;
		for(i=k+1;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(matrica[j][k]==matrica[j][i])
				x=1;
				else
				{
					x=0;
					break;
				}
				
				
			}
		
			if(x==1)
			/*ako se poklapaju pomjeram kolone*/
				{
					for(a=0;a<m;a++)
					{
						for(b=i;b<n-1;b++)
						{
							matrica[a][b]=matrica[a][b+1];
							
						}
					}
					n--;
					i=k;
				}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
		
	}
	
	
	return 0;
}

