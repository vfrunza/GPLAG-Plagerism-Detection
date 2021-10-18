#include <stdio.h>

int max(int matrica[100][100],int visina,int sirina)
{
	int poz_brojac[10000]= {0},neg_brojac[10000]= {0},i,j,maks_poz,maks_neg,broj=0,negativnost=1;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[i][j]>=0)
				poz_brojac[matrica[i][j]]++;
			else
				neg_brojac[-matrica[i][j]]++;
		}
	}
	for (i=0; i<10000; i++) {
		if(neg_brojac[i]!=0) {
			negativnost=1;
			break;
		} else
			negativnost=0;
	}
	maks_poz=poz_brojac[0];
	maks_neg=neg_brojac[0];
	j=9999;
	for (i=0; i<10000; i++) {
		if(j<0)
			break;
		if(negativnost) {
			if (neg_brojac[j]>maks_neg) {
				maks_neg=neg_brojac[j];
				broj=-j;
			}
			j--;
			continue;
		}
		if (poz_brojac[i]>maks_poz) {
			maks_poz=poz_brojac[i];
			broj=i;
		}
	}
	return broj;
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N)
{
	int i,j,kol_za_izbaciti[100]= {0},nova_sirina,k=0,copy_sirina,p=0;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[i][j]==N) {
				kol_za_izbaciti[j]=j+1;
			}
		}
	}
	nova_sirina=sirina;
	copy_sirina=sirina;
	for(j=0; j<sirina; j++) {
		if (kol_za_izbaciti[j])
			nova_sirina--;
	}
	for (j=0; j<copy_sirina; j++) {
		if (kol_za_izbaciti[j]) {
			for (i=0; i<visina; i++) {
				for (k=j-p; k<sirina; k++) {
					if ((k+1)==sirina)
						break;
					matrica[i][k]=matrica[i][k+1];
				}
			}
			p++;
		}
	}
	return nova_sirina;
}

int main()
{
	int mat[100][100],sirina,visina,i,j,k=1,N;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &sirina, &visina);
	for (i=0; i<visina; i++) {
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++) {
			scanf ("%d", &mat[i][j]);
		}
	}
	N=izbaci_kolone(mat,visina,sirina,max(mat,visina,sirina));
	printf ("\n");
	while (N>0) {
		printf ("Nakon %d. prolaza matrica glasi:\n", k);
		k++;
		for (i=0; i<visina; i++) {
			for (j=0; j<N; j++)
				printf ("%5d", mat[i][j]);
			printf ("\n");
		}
		N=izbaci_kolone(mat,visina,N,max(mat,visina, N));
	}
	printf ("\nNakon %d. prolaza matrica je prazna!", k);
	return 0;
}