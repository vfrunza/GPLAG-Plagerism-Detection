#include <stdio.h>

int main()
{
	int n,m,i,j,k,l,t,red=1,kol=1;
	float mat[200][200];
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m>200||n>200||m<1||n<1)
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while(m>200||n>200||m<1||n<1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&mat[i][j]);
		}
	}
	do{
	//Provjeravanje duplih redova
		if(red)
		{
			red=0;
			for(i=0;i<m-1;i++)
			{
				for(k=i+1;k<m;k++)
				{
					t=1;
					for(j=0;j<n;j++)
					{
						if(mat[i][j]!=mat[k][j])
						{
							t=0;
							break;
						}
					}
					//Izbacivanje duplih redova
					if(t)
					{
						kol=1;
						for(l=k;l<m-1;l++)
						{
							for(j=0;j<n;j++)
							{
								mat[l][j]=mat[l+1][j];
							}
						}
						k--;
						m--;
					}
				}
			}
		}
		//Provjeravanje duplih kolona
		if(kol)
		{
			for(j=0;j<n-1;j++)
			{
				for(k=j+1;k<n;k++)
				{
					t=1;
					for(i=0;i<m;i++)
					{
						if(mat[i][j]!=mat[i][k])
						{
							t=0;
							break;
						}
					}
					//Izbacivanje duplih kolona
					if(t)
					{
						red=1;
						kol=1;
						for(l=k;l<n-1;l++)
						{
							for(i=0;i<m;i++)
							{
								mat[i][l]=mat[i][l+1];
							}
						}
						k--;
						n--;
					}
				}
			}
		}	
	}while(red);
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5g",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}