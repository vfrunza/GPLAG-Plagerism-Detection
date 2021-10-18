#include <stdio.h>

int visina, sirina;

//Funkcija trazi element koji se najvise puta ponavlja, ako ih ima vise od jednog vraca manji broj
int max (int matrica[100][100], int visina, int sirina)
{
	int i,j;
	int maxi = matrica[0][0];
	int number=0;
	int temp, count=0, z, k, var=0, compare=0;

	for (i=0; i<visina; i++)
		for(j=0; j<sirina; j++)

		{
			number=matrica[i][j];
			for (z=0; z<visina; z++)
				for(k=0; k<sirina; k++)

				{
					compare=matrica[z][k];
					if(number == compare) count++;
				}


			if(count >= var) {
				temp=maxi;
				maxi=number;

				if(count == var && number>temp)
					maxi=temp;

				var=count;

			}
			count=0;
		}


	return maxi;
}

//Funkcija za izbacivanje kolona, koja vraca broj kolona nakon izbacivanja
int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, m, n;
	int sirina_=sirina;
	for (i=0; i<visina; i++)
		for (j=0; j<sirina_; j++) {
			if (matrica[i][j]==N) {

				for (m=j; m<sirina; m++)
					for (n=0; n<visina; n++)
						matrica[n][m]=matrica[n][m+1];
				sirina_--;

			}
		}
	return sirina_;
}


int main()
{
	int  visina=0, sirina=0, i=0, j=0, matrica[100][100], N=0, f=0, br=1, ponavljanje_e=1;

	printf ("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina,&visina);
	for (i=0; i<visina; i++) {
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++)
			scanf ("%d", &matrica[i][j]);
	}

	do {
		if (sirina>1) {       //Prvo provjeravamo da li se neki red sastoji od istih clanova
			for (i=0; i<visina; i++) {
				for (j=0; j<sirina; j++) {
					if (matrica[i][0] == matrica [i][j]) ponavljanje_e++;
				}
				if (ponavljanje_e==sirina) {
					printf ("\nNakon 1. prolaza matrica je prazna!");
					return 0;
				}
				ponavljanje_e=0;
			}


		}

		//Pozivanje funkcija

		N=max(matrica, visina, sirina);

		f=izbaci_kolone(matrica, visina, sirina, N);

		sirina = f;

		if (sirina!=0) {
			printf ("\nNakon %d. prolaza matrica glasi:\n", br);
			for (i=0; i<visina; i++) {
				for (j=0; j<sirina; j++) {
					printf ("%5d",matrica[i][j]);

				}

				printf ("\n");
			}
		}

		else {
			printf ("\nNakon %d. prolaza matrica je prazna!", br);
			return 0;
		}
		br++;


	} while (sirina != 0);

	return 0;
}
