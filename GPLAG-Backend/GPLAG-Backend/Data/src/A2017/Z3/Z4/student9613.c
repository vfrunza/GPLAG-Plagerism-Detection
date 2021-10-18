#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{
	int i, j, k, l;

	/* Ako nadjemo element matrice koji je jednak trazenom preko te kolone prepisemo sljedecu, pa sirinu smanjimo za jedan i ponovo posmatramo tu kolonu */
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==n) {
				for(k=0; k<visina; k++) {
					for(l=j; l<sirina-1; l++)
						matrica[k][l]=matrica[k][l+1];
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}

int max(int matrica[100][100], int visina, int sirina);


int main()
{

	int i, j, k, sirina, visina, matrica[100][100], maximum;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);

	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++)
			scanf("%d", &matrica[i][j]);
	}

	i=1;
	while(sirina>1) {
		maximum=max(matrica, visina, sirina);
		sirina=izbaci_kolone(matrica, visina, sirina, maximum);

		if(sirina!=0) {
			printf("\n");
			printf("Nakon %d. prolaza matrica glasi: ", i);

			for(j=0; j<visina; j++) {
				printf("\n");

				for(k=0; k<sirina; k++)
					printf("%5d", matrica[j][k]);
			}
			i++;
		}
	}
	printf("\n");
	printf("Nakon %d. prolaza matrica je prazna!", i);

	return 0;
}

int max(int matrica[100][100], int visina, int sirina)
{
	int i, j, k, maxi, brojaci[10101]= {0};

	/* Koristimo pomocni niz brojaci kako bismo izbrojali koliko kojih brojeva ima */
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			for(k=-10000; k<=100; k++)
				if(matrica[i][j]==k)
					brojaci[k+10000]++;
		}
	}
	/* Stavljamo maxi na nulu kako bi poredili sa ostalim clanovima */
	maxi=0;

	for(i=0; i<=10100; i++) {
		if(brojaci[i]>brojaci[maxi])
			maxi=i;
	}

	for(i=0; i<=10100; i++)
		if(brojaci[i]==brojaci[maxi])
			if(i<maxi)
				maxi=i;

	return (maxi-10000);
}
