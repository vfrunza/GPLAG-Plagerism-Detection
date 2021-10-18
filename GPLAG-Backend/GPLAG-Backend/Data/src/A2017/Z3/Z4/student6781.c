#include <stdio.h>
int max (int matrica[100][100],int visina,int sirina)
{
	int niz[10000],brojac[10000];
	int i,j;
	int brojacI,maxi,maxm;
	/*Pretvaranje 2-d niza u 1-d niz.*/
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++)
			niz[i*sirina+j]=matrica[i][j];
	}
	/*Formiranje novog niza,koji sadrzi broj ponavljanja svakog elementa 1-d niza.*/
	for (i=0; i<visina*sirina; i++) {
		brojacI=1;
		for (j=i+1; j<visina*sirina; j++) {
			if( niz[i]==niz[j])
				brojacI++;
		}
		brojac[i]=brojacI;
	}
	maxm=brojac[0];
	maxi=0;
	/*Trazanje indeksa elementa koji se najvise puta ponavlja.*/
	for (i=0; i<visina*sirina; i++) {
		if (brojac[i]==maxm) {
			if (niz[i]<niz[maxi]) {
				maxm=brojac[i];
				maxi=i;
			}
		}
		if (brojac[i]>maxm) {
			maxi=i;
			maxm=brojac[i];
		}
	}
	return niz[maxi];
}
int izbaci_kolone (int matrica[100][100],int visina,int sirina,int N)
{
	int i,j,k,l;
	/*Trostrukom petljom trazi kolonu u kojoj se nalazi odgovarajuci element N,koju izbacujemo*/
	for (i=0; i<sirina; i++) {
		for (j=0; j<visina; j++) {
			if (matrica[j][i]==N) {
				for (k=0; k<visina; k++) {
					for (l=i; l<sirina-1; l++)
						matrica[k][l]=matrica[k][l+1];
				}
				sirina--;
				i--;
				break;
			}

		}

	}
	return sirina;
}

int main()
{
	int matrica[100][100];
	int i,j,N,x=1;
	int vis,sir;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d",&sir,&vis);
	for (i=0; i<vis; i++) {
		printf ("Unesite elemente %d. reda: ",i+1);
		for (j=0; j<sir; j++)
			scanf ("%d",&matrica[i][j]);
	}
	printf ("\n");
	while (sir>0) {

		N=max(matrica,vis,sir);
		sir=izbaci_kolone(matrica,vis,sir,N);
		if (sir>0) {
			printf ("Nakon %d. prolaza matrica glasi:\n",x);
			printf ("\n");
		} else if (sir==0)
			printf ("Nakon %d. prolaza matrica je prazna!\n",x);
		x++;
		for (i=0; i<vis; i++) {
			for (j=0; j<sir; j++)
				printf ("%5d",matrica[i][j]);
			printf ("\n");
		}

	}
	return 0;
}
