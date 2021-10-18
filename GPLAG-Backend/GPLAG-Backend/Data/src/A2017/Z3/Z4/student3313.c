#include <stdio.h>

/* funkcija za trazenje elementa koji se ponavlja najvise puta prema uslovima zadatka */
int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,k,l,naj,a;
	int najbr=0, brojac=0;

	/* postavljanje prvog elementa za max, njegovo prebrojavanje*/
	naj= matrica[0][0];
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if(matrica[i][j]==naj) najbr++;
		}
	}

	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (i==0 && j==0) continue;

			/* poredjenje  broja ponavljanja svakog narednog elementa */
			a=matrica[i][j];
			/* petlja koja broji koliko se posmatrani element ponavlja u matrici */
			for (k=0; k<visina; k++) {
				for (l=0; l<sirina; l++) {
					if(matrica[k][l]==a) brojac++;
				}
			}
			/* ako je njegov brojac veci njega stavljamo za brmax a dati element za naj*/
			if(brojac>najbr || (brojac==najbr && a<naj)) {
				naj=a;
				najbr=brojac;
			}
			brojac=0;
		}
	}
	return naj;
}

/* funkcija za izbacivanje kolona u kojima se javlja uneseni element */
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{
	int i, j,kolona,k,m;
	for (i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {

			/* ukoliko se pojavi element, datu kolonu izbaciti uz ocuvanje redoslijeda*/
			if(matrica[i][j]==n) {
				kolona=j;
				for (m=0; m<visina; m++) {
					for(k=kolona; k<sirina; k++) {
						matrica[m][k]=matrica[m][k+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}

int main()
{
	int matrica[100][100];
	int i, j, visina, sirina,novi_brkolona,clan,prolaz;
	/*unos dimenzija i elemenata matrice*/
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &sirina, &visina);
	for (i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for (j=0; j<sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	prolaz=1;
	do {
		clan=max(matrica,visina,sirina);
		novi_brkolona=izbaci_kolone(matrica,visina,sirina,clan);
		sirina=novi_brkolona;
		if(novi_brkolona==0) {
			printf("\nNakon %d. prolaza matrica je prazna!",prolaz);
			break;
		}
		printf("\nNakon %d. prolaza matrica glasi:\n", prolaz);
		for (i=0; i<visina; i++) {
			for (j=0; j<sirina; j++) {
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}
		prolaz++;
	} while(sirina>0);


	return 0;
}
