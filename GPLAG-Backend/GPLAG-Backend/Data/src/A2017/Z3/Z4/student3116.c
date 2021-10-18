#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,niz[1000],x;
	int ponavljanje=0,maks=0,element;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			niz [i*sirina+j]=matrica[i][j];
		}
	}
	x=niz[0];
	for (i=0; i<=(visina-1)*sirina+sirina-1; i++) {
		ponavljanje=0;
		element=niz[i];
		for (j=i; j<=(visina-1)*sirina+sirina-1; j++) {
			if (element==niz[j]) {
				ponavljanje++;
			}
		}
		if(ponavljanje>maks) {
			maks=ponavljanje;
			x=element;
		} else if (ponavljanje==maks) {
			if (element<x)
				x=element;
			else continue;
		}
	}
	return x;

}

int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N)
{
	int i,j,k;
	int pom=0;
	for (i = 0; i<sirina; i++) {
		pom=0;
		for (j=0; j<visina; j++) {
			if (matrica[j][i]==N) {
				pom=1;
				break;
			}
		}
		if (pom==1) {
			for (j = 0; j <visina; j++) {
				for (k=i; k <sirina-1; k++) {
					matrica[j][k] = matrica[j][k+1];
				}
			}
			i--;
			sirina--;
		}
	}
	return sirina;
}

int main ()
{
	int i,j,X[100][100],vis,sir,clan,k=1;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &sir, &vis);
	for (i=0; i<vis; i++) {
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sir; j++) {
			scanf ("%d", &X[i][j]);
		}
	}

	while (sir>0) {
		clan=max(X,vis,sir);
		sir=izbaci_kolone(X,vis,sir,clan);
		if (sir==0) break;
		printf ("\nNakon %d. prolaza matrica glasi: \n",k++);
		for (i=0; i<vis; i++) {
			for (j=0; j<sir; j++) {
				printf ("%5d", X[i][j]);
			}
			printf ("\n");
		}
	}
	printf ("\nNakon %d. prolaza matrica je prazna!", k);

	return 0;
}