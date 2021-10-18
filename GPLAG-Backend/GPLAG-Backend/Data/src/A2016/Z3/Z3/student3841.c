#include <stdio.h>

int main() 
{
	/*printf("Zadaća 3, Zadatak 3");*/
	
	int mat[200][200], M = 0, N = 0, i = 0, j = 0, k = 0, s = 0, m = 0;
	/*U N O S    D I M E N Z I J A     M A T R I C E*/
	do
	{
		printf("Unesite brojeve M i N: "); /*Unos dimenzija matrice*/
		scanf("%d %d", &M, &N);	
		
		if(N <= 0 || N > 200 || M <= 0 || M > 200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}
	
	while(N <= 0 || N > 200 || M <= 0 || M > 200);
	/*U N O S   E L E M E N A T A    M A T R I C E*/
	printf("Unesite elemente matrice: "); /*Unos elemenata matrice*/
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
			scanf("%d", &mat[i][j]);
	}
	/*I Z B A C I V A NJ E    R E D A*/
	for(i = 0; i < M; i++)  /*''fiksiranje'' na prvi red matrice*/
	{
		for(j = i + 1; j < M; j++) /*Poređenje ostalih redova sa prvim, traženje da li su isti*/
		{
			int e = 1; /*pretpostavka da su dva reda ista*/
			
			for(k = 0; k < N; k++)
				if(mat[i][k] != mat[j][k])
					e = 0;  /*Ukoliko nisu pronađena dva ista reda istinitosna vrijednost je nula*/
					
			if(e == 1)  /*ukoliko su pronađena dva ista reda, izbacuje se drugi po redu od njih*/
			{
				for(s = j; s < M - 1; s++)
					for(m = 0; m < N; m++)
						mat[s][m] = mat[s + 1][m];
				j--;
				M--;
			}
		}
	}
	/*I Z B A C I V A NJ E    K O L O N E (princip je isti kao za izbacivanje redova, samo se kolona fiksira na prvu i ostale se porede s njom)*/
	for(i = 0; i < N; i++)
	{
		for(j = i + 1; j < N; j++)
		{
			int a = 1;
			
			for(k = 0; k < M; k++)
				if(mat[k][i] != mat[k][j])
					a = 0;
			
			if(a == 1)
			{
				for(s = j; s < N - 1; s++)
					for(m = 0; m < M; m++)
						mat[m][s] = mat[m][s + 1];
				j--;
				N--;
			}
		}
	}
	/*I S P I S    M A T R I C E*/
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
			printf("%5d", mat[i][j]);
			
		printf("\n");
	}
	return 0;
}
