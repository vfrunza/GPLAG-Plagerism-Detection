#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i, j, num=1, array[10000];
	int counter=0, temp=0, min=0, maxi=0, count=1;

	/* 1. matricu prebacujemo u niz */

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			array[counter]=matrica[i][j];
			counter++;
		}
	}
	/* 1.1 sortiranje niza brojaca */
	for(i=0; i<counter-1; i++) {
		min=i;
		for(j=i+1; j<counter; j++) {
			if(array[j] < array[min])
				min=j;
		}
		temp=array[i];
		array[i]=array[min];
		array[min]=temp;
	}
	/* 1.3. trazenje clana koji se najvise ponavlja (num) */
	num = array[0];
	for(i=0; i<counter-1; i++) {
		if(array[i]==array[i+1])
			count++;
		else {
			if(maxi<count) {
				maxi=count;
				num=array[i];
			}

			count=1;
		}
	}
	if (maxi<count) {
		maxi=count;
		num=array[counter-1];
	}

	return num;
}


int izbaci_kolone(int matrica[100][100], int visina, int sirina, int num)
{
	/* izbacivanje kolone koja sadrzi clan koji se najvise ponavlja */
	int i, j, k, l;
	for (i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			if(matrica[j][i]==num) {
				for(k=0; k<visina; k++) {
					for(l=i; l< sirina - 1; l++) {
						matrica[k][l]=matrica[k][l+1];
					}
				}

				i--;
				sirina--;
				break;
			}
		}
	}
	return sirina;
}

int main()
{
	int i, j, visina, sirina, matrica[100][100], broj=0, prolaz;

	/* unos elemenata matrice */
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &sirina, &visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}

	prolaz=1;
	printf("\n");
	/* izbacivanje kolona matrice i ispis matrice nakon svakog izbacivanja */
	while(sirina!=0) {
		broj=max(matrica, visina, sirina);
		sirina=izbaci_kolone(matrica, visina, sirina, broj);

		if(sirina==0)
			printf("Nakon %d. prolaza matrica je prazna!", prolaz);
		else {
			printf("\nNakon %d. prolaza matrica glasi:\n", prolaz);
			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}
		}
		prolaz++;
	}

	return 0;
}
