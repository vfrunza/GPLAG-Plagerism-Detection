#include <stdio.h>
#define mn  10000

int max(int matrica[100][100], int visina, int sirina) /* Prototip funkcije */
{
	int i,j,p,q,broj;
	int brojac=0;
	int max = 0; /* Najveci broj ponavljanja */
	int maxi = matrica[0][0]; /* Najveci broj od brojeva koji se najvise puta ponavljaju */
	int uporedi,temp;

	for(i=0; i<visina; i++) { /* "Prolazimo kroz matricu, od prvog reda do posljednjeg" */
		for(j=0; j<sirina; j++) {
			broj = matrica[i][j]; /* Ovo je broj do kojeg smo dosli tokom prolaza kroz matricu */
			for(p=0; p<visina; p++) { /* Sada nas Broj uporedjujemo tako sto opet "prolazimo" kroz matricu */
				for(q=0; q<sirina; q++) {
					uporedi = matrica[p][q]; /* Broj koji uporedjujemo sa nasim Brojem */
					if(broj==uporedi) { /* Ako su jednaki nasi brojevi, dodaje se vrijendost brojacu +1 */
						brojac++;
					}

				}
			}
			if(brojac >= max) { /* Ako je vrijednost u brojacu veca od max(najveci broj ponavljanja broja) */
				temp = maxi; /* Skladistimo u temp prijasnju vrijednost maxi da bi mogli kasnije uporediti */
				maxi = broj;
				if(brojac == max && broj>temp) /* Poredimo tako sto ako su brojevi ponavljanja isti, koji je manji od ta dva broja */
					maxi = temp;
				max = brojac;
			}
			brojac=0; /* Resetuje se brojac i ide dalje */
		}
	}
	return maxi;
}

int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N) /* Prototip funkcije */
{
	int i, j, p, q;
	int length;
	length=sirina; /* Stavljeno radi lakseg snalazenja, a i jer nam treba "stara" sirina kasnije */
	for (i=0; i<visina; i++)
		for (j=0; j<length; j++) {

			if (matrica[i][j]==N) {
				/* Odvojeno radi lakse preglednosti */ /* Ako je broj koji se nalazi na i-tom i j-om mjestu matrice jednak N: */
				for (p=j; p<sirina; p++)
					for (q=0; q<visina; q++)
						matrica[q][p]=matrica[q][p+1]; /* Kolone prebacuje */
				length--; /* Smanjuje se sirina jer se izbacuje kolona */
			}
		}
	return length;
}

int main()
{
	int  visina,sirina,i,j,matrix[100][100],c=0,d;
	printf ("Unesite sirinu i visinu matrice: "); /* KOPIRAO UNOS MATRICE IZ ZADATKA SA TUTORIJALA */
	scanf("%i %i", &sirina,&visina); /* Korisnik unosi sirunu i visinu matrice, a zatim i clanove matrice */
	for (i=0; i<visina; i++) {
		printf ("Unesite elemente %i. reda: ", i+1);
		for (j=0; j<sirina; j++)
			scanf ("%i", &matrix[i][j]);
	}

	int ponavljanje;
	ponavljanje = 1;
	int v=visina;
	int dd=sirina;
	int brojach=1;

	do {
		c=0;
		if(sirina>1) /* Dok je sirina veca od 1, tj. dok "ima" matrice prolazi kroz ovu while petlju */
			while(c<v) {
				for(d=1; d<sirina; d++) {
					if(matrix[c][0] == matrix[c][d]) {
						brojach++;
					}
				}
				if(brojach == dd) { /* Ispituje to da ako se u redu nalaze isti brojevi koji se najvise ponavljaju, da ispise da je matrica prazna jer ce se sve te kolone izbaciti */
					printf ("\nNakon 1. prolaza matrica je prazna!");
					return 0;
				} else {
					brojach=1;
					c++;
				}
			}

		int N=max(matrix,visina,sirina); /* Naci broj koji se najvise ponavlja */
		sirina = izbaci_kolone(matrix, visina, sirina, N); /* Kolika ce biti sirina nakon izbacivanja kolone koja sadrzi N */

		if (sirina!=0) {
			printf ("\nNakon %i. prolaza matrica glasi:\n", ponavljanje);
			for (i=0; i<visina; i++) {
				for (j=0; j<sirina; j++) {
					if(j==0 && matrix[i][0]<10) printf("    "); /* Poravnanje, da bude razmaka od pocetka do brojeva */
					else if(j==0 && matrix[i][0]>=10) printf("   ");
					else if(j==0 && matrix[i][0]>=100) printf("  ");
					if(j==sirina-1) printf ("%i",matrix[i][j]);
					if(j!=sirina-1)printf ("%-5i",matrix[i][j]); /* %-5i upisuje brojeve tako da uzima sirinu od 5 polja */
				}
				printf ("\n");
			}
		} else { /* Ako "nema" matrice, tj. kad smo izbacili sve kolone, onda ispisi da je nasa matrica prazna nakon nekog broja ponavljanja */
			printf ("\nNakon %i. prolaza matrica je prazna!", ponavljanje);
			return 0;
		}
		ponavljanje = ponavljanje + 1;
	} while (sirina != 0);

	return 0;
}