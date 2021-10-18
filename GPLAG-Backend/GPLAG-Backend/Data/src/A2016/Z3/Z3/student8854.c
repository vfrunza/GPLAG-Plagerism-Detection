#include <stdio.h>

/*Funkcija za izbacivanje ponavljajucih redova iz matrice*/
int izbacired(int M, int N,int niz[][200])
{int i,j,k,b,v,br_istih=0;
	for(i=2;i<=M;i++)
	{
		for(j=1;j<i;j++)
		{
			/*Uporedjivanje redova*/
			br_istih=0;
			for(k=1;k<=N;k++)
			{
				if(niz[i][k]==niz[j][k])
				br_istih++;
				else
				{
					br_istih=0;
					break;}
			}
			if(br_istih==N)
			{
			/*Izbacivanje reda iz matrice*/
			for(b=i;b<M;b++)
			{
				for(v=1;v<=N;v++)
				{
					niz[b][v]=niz[b+1][v];
					
				}
				
			}
			M--;
			i--;
				
				
				
			}
		}
		
	}
	
	
	
	
	
	
	
	
	/*Vracamo broj redova nove matrice*/
	return M;
}

/*Funkcija za izbacivanje ponavljajucih kolona iz matrice */
int izbacikolonu(int M, int N,int niz[][200])
{int i,j,k,b,v,br_istih=0;
	for(i=2;i<=N;i++)
	{
		for(j=1;j<i;j++)
		{
			/*Uporedjivanje kolona*/
			br_istih=0;
			for(k=1;k<=M;k++)
			{
				if(niz[k][i]==niz[k][j])
				br_istih++;
				else
				{
					br_istih=0;
					break;}
			}
			if(br_istih==M)
			{
			/*Izbacivanje kolone iz matrice*/	
			for(b=i;b<N;b++)
			{
				for(v=1;v<=M;v++)
				{
					niz[v][b]=niz[v][b+1];
					
				}
					
			}
			N--;
			i--;
				
				
				
				
			}
		}
		
	}
	
	
	
	
	
	/*Vracamo broj kolona nove matrice*/
	return N;
}



int main() {
	int niz[200][200],M,N,i,j;
/*Unos dimenzija matrice*/
	do
	{
		printf("\nUnesite brojeve M i N: ");
		scanf("%d %d",&M,&N);

		if(M>200 || N>200 || M<=0 || N<=0)
		printf("Brojevi nisu u trazenom opsegu. ");
	}
	while(M>200 || N>200 || M<=0 || N<=0);
	
	printf("Unesite elemente matrice: ");
	/*Unos elemenata matrice*/
	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		scanf("%d",&niz[i][j]);
	}

/*Izbacivanje redova i kolona*/
M=izbacired(M,N,niz);
N=izbacikolonu(M,N,niz);

/*Ispis*/

printf("Nakon izbacivanja redova/kolona matrica glasi: \n");

for(i=1;i<=M;i++)
{
	for(j=1;j<=N;j++)
	printf("%5d",niz[i][j]);
	printf("\n");
}

	return 0;
}
