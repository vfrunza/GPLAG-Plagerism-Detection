#include <stdio.h>
int visina, sirina;
/*Funkcija provjerava koji clan matrice se najvise puta ponavlja*/
int max (int matrica[100][100], int visina, int sirina)
{
	int i, j, k, l, broj=0;
	int matrix=matrica[0][0];
	int temp, var=0, uporedi=0, brojac=0;


	for(i=0; i<visina; i++)
		for(j=0; j<sirina; j++) {

			broj=matrica[i][j];

			for(k=0; k<visina; k++)
				for(l=0; l<sirina; l++) {
					uporedi=matrica[k][l];
					if (broj==uporedi)
						brojac++;
				}


			if(brojac>=var) {
				temp=matrix;
				matrix=broj;

				if(brojac==var && broj>temp)
					matrix=temp;
				var=brojac;
			}


			brojac=0;
		}

	return matrix;
}

/*Izbacuje kolone u kojima se javlja broj N*/
int izbaci_kolone(int matrica [100][100], int visina, int sirina, int N)
{
	int i=0, j=0, k, l, sirina1=0;
	sirina1=sirina;
	for(i=0; i<visina; i++)
		for(j=0; j<sirina; j++) {

			if (matrica[i][j]==N) {

				for(k=j; k<sirina; k++)
					for (l=0; l<visina; l++)
						matrica[l][k]=matrica[l][k+1];

				sirina1--;
			}

		}


	return sirina1;
}


int main()
{
	int visina=0, sirina=0, i=0, j=0, matrica[100][100]= {}, N=0, funkcija=0, brojac=1;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);


	for (i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++)
			scanf("%d", &matrica[i][j]);
	}

	do {

		N=max(matrica, visina, sirina);
		funkcija=izbaci_kolone(matrica, visina, sirina, N);
		sirina=funkcija;

		if(funkcija!=0) {

			printf("\nNakon %d. prolaza matrica glasi:\n", brojac);
			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					printf("%5d", matrica[i][j]);

				}
				printf("\n");

			}

		} else
			printf("\nNakon %d. prolaza matrica je prazna!", brojac);
		brojac++;
	}

	while(funkcija!=0);

	return 0;
}
