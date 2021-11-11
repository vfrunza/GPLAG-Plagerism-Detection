#include <stdio.h>

int main() {
	int matricaA[100][100], matricaB[100][100], matricaC[100][100];
	int nizA[1000], nizB[1000], nizC[1000];
	int M, N, i, j, max, zamjena;
	
	/*unos dimenzija matrice*/
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}while(M>100 || N>100);
	
	/*Unos matrica*/
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matricaA[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matricaB[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matricaC[i][j]);
		}
	}
	
	/*pretvaranje matrica u niz*/
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			nizA[i*N + j]=matricaA[i][j];
		}
	}
	
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			nizB[i*N + j]=matricaB[i][j];
		}
	}
	
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			nizC[i*N + j]=matricaC[i][j];
		}
	}
	
	/*sortiram od najveceg ka najmanjem*/
	for(i=0; i<M*N; i++)
	{
	  max=i;
		for(j=i+1; j<M*N; j++)
		{
			if( nizA[max]<nizA[j])
			max=j;
		}

       zamjena=nizA[i];
       nizA[i]=nizA[max];
       nizA[max]=zamjena;
	}
	
	for(i=0; i<M*N; i++)
	{
		max=i;
		for(j=i+1; j<M*N; j++)
		{
			if(nizB[max]<nizB[j])
			max=j;
		}
		
		zamjena=nizB[i];
		nizB[i]=nizB[max];
		nizB[max]=zamjena;
	}
	
	for(i=0; i<M*N; i++)
	{
		max=i;
		for(j=i+1; j<M*N; j++)
		{
			if(nizC[max]<nizC[j])
			max=j;
		}
		
		zamjena=nizC[i];
		nizC[i]=nizC[max];
		nizC[max]=zamjena;
	}
	
	for(i=0; i<M*N; i++)
	{
		if(nizA[i]!=nizB[i] || nizA[i]!=nizC[i])
		{
		printf("NE");
		return 0;
		}
	}
	
	printf("DA");
	
	return 0;
}
