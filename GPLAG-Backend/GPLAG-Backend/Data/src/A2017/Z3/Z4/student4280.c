#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	
	int clanovi[10000];
	int ponavljanja[10000];
	int i, j, k;
	int brojac = 0;
	int provjera;
	int broj;
	int najveci;
	int najmanji;
	
	for (i = 0; i < 10000; i++)
		{
			clanovi[i] = 0;
			ponavljanja[i] = 0;
		}
	
	for (i = 0; i < visina; i++)
		{
			
			for (j = 0; j < sirina; j++)
				{
					
					provjera = 0;	
					for (k = 0; k<brojac;k++)
						{
							if (matrica[i][j] == clanovi[k])
								provjera = 1;
						}
						
					if (provjera == 0)
						clanovi[brojac++] = matrica[i][j];
					
				}
		}
	
	for (k = 0; k < brojac; k++)
		{
			broj = 0;
			for (i = 0; i < visina; i++)
				{
					for (j = 0; j < sirina; j++)
						{
							if (clanovi[k] == matrica[i][j])
								broj++;
						}
				}
				
			ponavljanja[k] = broj;
		}
	
	provjera = 0;
	najveci = ponavljanja[0];
	for (i = 0; i < brojac; i++)
		{
			if (ponavljanja[i] == najveci)
				provjera = 1;
				
			if (ponavljanja[i]>najveci)
				{
					najveci = ponavljanja[i];
					provjera = 0;
					najmanji = clanovi[i];
				}
		}
	
	if (provjera == 0)
		return najmanji;
		
		
	for (i = 0; i < brojac; i++)
		{
			if (ponavljanja[i] == najveci)
				najmanji = clanovi[i];
		}
		
	for (i = 0; i < brojac; i++)
		{
			if (clanovi[i] < najmanji && ponavljanja[i] == najveci)
				najmanji = clanovi[i];
		}
	
	return najmanji;
}


int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N)
{
	int broj_kolona = 0;
	int pomocna[100][100];
	int i, j;
	int provjera;
	
	for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++)
				pomocna[i][j] = 0;
		}
	
	for (i = 0; i < sirina; i++)
		{
			provjera = 0;
			for (j = 0; j < visina; j++)
				{
					if (matrica[j][i] == N)
						provjera = 1;
				}
				
			if (provjera == 0)
				{
					for (j = 0; j < visina; j++)
						pomocna[j][broj_kolona] = matrica[j][i];
					
					broj_kolona++;
				}
		}
	
	for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++)
				matrica[i][j] = 0;
		}
		
	for (i = 0; i < visina; i++)
		{
			for (j = 0; j < broj_kolona; j++)
				matrica[i][j] = pomocna[i][j];
		}
	
	
	
	
	return broj_kolona;
}






int main() {
	
	int visina, sirina;
	int matrica[100][100];
	int i,j;
	int N;
	int brojac;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	
	for (i = 0; i < visina; i++)
		{
			printf("Unesite elemente %d. reda: ", i+1);
			for (j = 0; j < sirina; j++)
				scanf("%d", &matrica[i][j]);
		}
	
	brojac = 1;	
	while(1)
		{
			N = max(matrica,visina,sirina);
			sirina = izbaci_kolone(matrica,visina,sirina,N);
			
			printf("\n");
			if (sirina == 0)
				{
					printf("Nakon %d. prolaza matrica je prazna!", brojac);
					break;
				}
				
			printf("Nakon %d. prolaza matrica glasi:\n", brojac);
			
			for (i = 0; i < visina; i++)
				{
					for (j = 0; j < sirina; j++)
						printf("%5d", matrica[i][j]);
						
					printf("\n");
				}
			
			
			
			
			brojac++;
		}
	
	
	
	
	
	
	return 0;
}
