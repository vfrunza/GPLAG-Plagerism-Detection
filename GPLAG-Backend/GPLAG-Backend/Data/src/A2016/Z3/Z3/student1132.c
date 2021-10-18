#include <stdio.h>

int main()
{
int N,M,i,j,k,h,eq,tmp,matrica[205][205];

/*UNOS*/
do
{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&M,&N);
	
	if(M<1||N<1||M>200||N>200) printf("Brojevi nisu u trazenom opsegu.\n");
} while(M<1||N<1||M>200||N>200);

printf("Unesite elemente matrice: ");
for(i=0;i<M;i++)
{
	for(j=0;j<N;j++) scanf("%d",&matrica[i][j]);
}

/*IZBACIVANJE REDOVA*/
for(i=0;i<M;i++)
{
	for(j=0;j<i;j++)
	{
		eq=1;
		for(k=0;k<N;k++)
		{
			if(matrica[i][k]!=matrica[j][k]) 
			{
				eq=0;
				break;
			}
		}
		if(eq)
		{
			for(k=i;k<M-1;k++)
			{
				for(h=0;h<N;h++)
				{
					tmp = matrica[k+1][h];
					matrica[k+1][h] = matrica[k][h];
					matrica[k][h] = tmp;
				}
			}
			M--;
			i--;
		}
	}
}

/*IZBACIVANJE KOLONA*/
for(i=0;i<N;i++)
{
	for(j=0;j<i;j++)
	{
		eq=1;
		for(k=0;k<M;k++)
		{
			if(matrica[k][i]!=matrica[k][j]) 
			{
				eq=0;
				break;
			}
		}
		if(eq)
		{
			for(k=i;k<N-1;k++)
			{
				for(h=0;h<M;h++)
				{
					tmp = matrica[h][k+1];
					matrica[h][k+1] = matrica[h][k];
					matrica[h][k] = tmp;
				}
			}
			N--;
			i--;
		}
	}
}

printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i=0;i<M;i++)
{
	for(j=0;j<N;j++) printf("%5d",matrica[i][j]);
	printf("\n");
}

	return 0;
}
