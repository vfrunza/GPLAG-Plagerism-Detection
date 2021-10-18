#include <stdio.h>

int max (int matrica[100][100], int visina , int sirina)
{
	int kljucevi[10000];
	int vrijednosti[10000]= {0};
	int i,j,k, max=0;
	int duzina= 0;
	int temp=1;
	/*Unesi vrijednosti matrice u kljuceve, ako se one ponavljaju nemoj ih unositi u kljuc, ovaj kod radi na principu "mape"*/
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			for (k=0; k<duzina; k++)
				if (kljucevi[k]==matrica[i][j])
					temp = 0;
			if (temp==1) {
				kljucevi[duzina]= matrica[i][j];
				duzina++;
			}
			temp=1;

		}
	}
	/*Prebroji koliko se puta vrijednosti u kljucevima ponavljaju u matrici*/
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			for (k=0; k<duzina; k++) {
				if (kljucevi[k]==matrica[i][j]) {
					vrijednosti[k]++;
				}
			}
		}
	}
	/*Vrati vrijednost koja se najvise ponavlja ili ako se vise vrijednosti ponavlja jednak broj puta, pronadji najmanju te je vrati*/
	for (i=0; i<duzina; i++) {

		if (vrijednosti[i]>vrijednosti[max]) {
			max=i;
		}


		else if (vrijednosti[i]==vrijednosti[max]) {
			if (kljucevi[i]<kljucevi[max])
				max=i;
		}

	}

	return kljucevi[max];
}

int izbaci_kolone (int matrica[100][100], int visina , int sirina, int N)
{
	int i,j,m,n;

	/*Prodji kroz matricu i nadji max (N) vrijednost te izbaci kolonu koja sadrzi N*/
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[i][j]==N) {
				for (m=j; m<sirina; m++)
					for (n=0; n<visina ; n++)
						matrica [n][m]= matrica [n][m+1];
				sirina--;
				i=0;
				j=0;

			}
		}
	}
	return sirina;

}

int main()
{

	int i,j;
	int matrica[100][100], visina, sirina;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d",&sirina, &visina);

	for (i=0; i<visina; i++) {
		printf ("Unesite elemente %i. reda: ", i+1);
		for (j=0; j<sirina; j++) {
			scanf ("%d", &matrica[i][j]);
		}

	}
	printf ("\n");
	int novasirina=sirina;
	int N=0;
	int temp=1;
	/*Ispisuj matricu nakon svakog poziva max, potom funkcije izbaci_kolone sve dok sirina matrice ne bude 0*/
	for(;;) {
		N=max(matrica,visina, novasirina);
		novasirina= izbaci_kolone (matrica,visina, novasirina, N);
		if (novasirina==0) {
			break;
		}
		printf ("Nakon %d. prolaza matrica glasi:\n", temp);
		temp++;
		/*Ispisi matricu s novom sirinom*/
		for (i=0; i<visina; i++) {
			for (j=0; j<novasirina; j++) {
				printf ("%5d", matrica[i][j]);
			}
			printf ("\n");
		}
		printf ("\n");
	}
	printf ("Nakon %d. prolaza matrica je prazna!", temp);
	return 0;
}
