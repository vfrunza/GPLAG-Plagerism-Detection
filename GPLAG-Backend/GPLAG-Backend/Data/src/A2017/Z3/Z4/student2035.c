#include <stdio.h>


void sortiraj(int niz[], int velicina)
{
	int i=0, j=0, temp=0, min=0;
	for(i=0; i<velicina; i++) {
		min=i;
		for(j=i+1; j<velicina; j++) {
			if(niz[j]<niz[min])
				min=j;
		}
		temp=niz[i];
		niz[i]=niz[min];
		niz[min]=temp;
	}
}

int max(int mat[100][100], int visina, int sirina )
{
	
	int niz[10000]= {0};
	int i,j,k=0, popular, brojac=0, brojacpopularnog=0;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			niz[k]=mat[i][j];
			k++;
		}
	}

	sortiraj(niz, k);
	popular=niz[0];
	for(i=1; i<k; i++) {
		if(niz[i-1]!=niz[i]) {
			brojac=0;
			continue;
		}
		brojac++;
		if(brojac>brojacpopularnog) {
			brojacpopularnog=brojac;
			popular=niz[i];
		}
		if(brojacpopularnog==brojac && niz[i]<popular) popular=niz[i]; // provjeri ovo jel radi sta hoces
	}
	return popular;

}


int izbaci_kolone(int mat[100][100], int visina, int sirina, int N)
{
	int i, j, k, l;
	for(i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			if(mat[j][i]==N) {

				for(l=i+1; l<sirina; l++) {
					for(k=0; k<visina; k++) {
						mat[k][l-1]=mat[k][l];
					}
				}
				sirina--;
				i=-1;
				break;
			}
		}
	}

	return sirina;
}

int main()
{
	int mat[100][100];
	int sirina, i, j, novasirina;
	int visina, maxel, k=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &mat[i][j]);

		}
	}
	printf("\n");
	novasirina=sirina;
	while(1) {

		k++;
		maxel=max(mat,visina, novasirina);
		novasirina=izbaci_kolone(mat, visina, novasirina, maxel);
		if(novasirina==0) {
			printf("Nakon %d. prolaza matrica je prazna!", k);
			break;
		}
		printf("Nakon %d. prolaza matrica glasi:\n", k);

		for(i=0; i<visina; i++) {
			for(j=0; j<novasirina; j++)
				printf("%5d", mat[i][j]);
			printf("\n");
		}



	}
	return 0;
}
