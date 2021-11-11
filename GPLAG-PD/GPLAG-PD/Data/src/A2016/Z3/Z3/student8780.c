#include <stdio.h>

int main()
{

	int red,kolona,i,j,k,isti_red,ista_kolona,brojac,brojac_1,izbaci;
	int matrica[200][200];

	printf ("Unesite brojeve M i N: ");
	scanf ("%d %d",&red,&kolona);

// Provjera da li su M i N u intervalu od 0 do 200 //

	do {

		if (red<=0 || red>200 || kolona<=0 || kolona>200) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
			printf ("Unesite brojeve M i N: ");
			scanf ("%d %d",&red,&kolona);

		}

	} while (red<=0 || red>200 || kolona<=0 || kolona>200);



	printf ("Unesite elemente matrice: ");

	for (i=0; i<red; i++) {

		for (j=0; j<kolona; j++) {


			scanf ("%d",&matrica[i][j]);
		}

	}

	/*Izbacivanje reda*/




	for (i=0; i<red-1; i++) {
		if (red==1)
			break;

		for (k=0; k<kolona-1; k++) {
			for (j=1+i; j<red; j++) {
				isti_red=1;
				if (matrica[i][k]!=matrica[j][k]) {
					isti_red=0;
				}

				else {
					for(k=0; k<=kolona-2; k++) {
						izbaci=1;
						if(matrica[i][k+1]!=matrica[j][k+1])

						{
							izbaci=0;
							if(izbaci==0)
								break;
						}
					}

					if (izbaci==1) {
						for (brojac=j; brojac<red-1; brojac++) {
							for (brojac_1=0; brojac_1<kolona; brojac_1++) {
								matrica[brojac][brojac_1]=matrica[brojac+1][brojac_1];
							}

						}
						red--;
						j--;
					}
				}
			}

		}
	}


	/*	Izbacivanje kolone */

	if (red==1) {
		for (i=0; i<red; i++) {
			for (j=0; j<kolona-1; j++) {
				for (k=j+1; k<kolona; k++) {
					ista_kolona=1;


					if (matrica [i][j]!=matrica[i][k]) {
						ista_kolona=0;
					}


					else {

						for (brojac=0; brojac<red; brojac++) {
							for (brojac_1=k; brojac_1<kolona-1; brojac_1++) {
								matrica [brojac][brojac_1]=matrica[brojac][(brojac_1)+1];
							}

						}
						kolona--;
						k--;
					}


				}
			}
		}

	} else {
		for (i=0; i<red-1; i++) {
			for (j=0; j<kolona-1; j++) {
				for (k=j+1; k<kolona; k++) {
					ista_kolona=1;

					if (matrica [i][j]!=matrica[i][k]) {
						ista_kolona=0;
					}


					else  {

						for (brojac=0; brojac<kolona-1; brojac++) {
							for (brojac_1=k;brojac_1<red-1; brojac_1++) {
								matrica [brojac][brojac_1]=matrica[brojac][brojac_1+1];
							}

						}
						kolona--;
						k--;
					}


				}
			}
		}
	}





	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");

	for (i=0; i<red; i++) {
		for (j=0; j<kolona; j++) {
			printf ("%5d",matrica[i][j]);
		}
		printf ("\n");


	}





	return 0;
}
