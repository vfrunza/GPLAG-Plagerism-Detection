#include <stdio.h>

int izbaci_kolone (int matrica [100][100], int velicina, int sirina, int N)
{
	int i, j, k, l;

	for(i=0; i<velicina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				for(k=0; k<velicina; k++) {
					for(l=j; l<sirina-1; l++) {
						matrica[k][l]=matrica[k][l+1];              /**/
					}
				}
				i=0;
				j=0;

				sirina--;                      
			}
		}
	}

	return sirina;
}

int max (int matrica [100][100], int velicina, int sirina)
{
	int i, j, maxx=0, max_ponavljanja,max2,max2pon;
	int M[10000];

	for(i=0; i<velicina; i++) {
		for(j=0; j<sirina; j++) {
			M[i*sirina+j]=matrica[i][j];           /*Petlje uz pomoc kojih vrijednosti iz matrice "matrica" redamo u niz "M".*/
		}
	}

	maxx=M[0];
	max_ponavljanja=0;
	for(i=0; i<velicina*sirina; i++) {
		if(M[i]==M[0])
			max_ponavljanja++;
	}

	for(i=0; i<velicina*sirina; i++) {
		max2=M[i];
		max2pon=0;
		for (j = 0; j < velicina*sirina; j++) {
			if(max2==M[j])
				max2pon++;
		}
		if(max2pon==max_ponavljanja && max2<maxx) {
			max_ponavljanja=max2pon;
			maxx=max2;
		}

		if(max2pon>max_ponavljanja) {
			max_ponavljanja=max2pon;
			maxx=max2;
		}

	}


	return maxx;                   /**/

}

int main()
{
	int matrica[100][100], velicina, sirina, N, i, j, br=0;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &velicina);


	for(i=0; i<velicina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d ", &matrica[i][j]);
		}
	}





	while(sirina>0) {



		N=max(matrica, velicina, sirina);
		sirina=izbaci_kolone(matrica, velicina, sirina, N);
		if(sirina==0) break;
		printf("\nNakon %d. prolaza matrica glasi:\n", br+1);

		for(i=0; i<velicina; i++) {
			for(j=0; j<sirina; j++)
				printf("%5d", matrica[i][j]);                 /*Ispis matrice nakon izbacivanja*/

			printf("\n");
		}


		br++;
	}
	printf("\nNakon %d. prolaza matrica je prazna!",br+1);
	return 0;
}
