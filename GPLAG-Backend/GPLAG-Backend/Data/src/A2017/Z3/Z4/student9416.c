#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int duzina, i, j, pomocni_niz[10000]= {0}, brojaci[10000]= {0};
	int najveci;
	int *p, *q, *r, *s, *t;

	p=pomocni_niz;
	duzina=sirina*visina;

	/*Sve elemente matrice smijestamo u pomocni niz cija je duzina jednaka broju elemenata matrice.*/
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			*p=matrica[i][j];
			p++;
		}
	}
	/*Ovom petljom pronalazimo broj ponavljanja svih elemenata niza, koje spremamo u niz brojaca iste duzine.*/
	for(i=0; i<duzina; i++) {
		r=pomocni_niz+i;
		q=pomocni_niz;
		while(q<pomocni_niz+duzina) {
			if(*q==*r) {
				brojaci[i]++;
			}
			q++;
		}
	}

	s=brojaci;
	t=pomocni_niz;
	/*Ovom petljom pronalazimo najveci element niza brojaca*/
	for(i=1; i<duzina; i++) {
		if(*(brojaci+i)>*s) {
			s=(brojaci+i);
			t=(pomocni_niz+i);
			/*Ukoliko su dva elementa niza brojaca jednaka, uporedjujemo odgovarajuce elemente pomocnog niza*/
		} else if(*(brojaci+i)==*s) {
			/*Vraca manji od odgovarajucih clanova pomocnog niza*/
			if(*(pomocni_niz+i)<=*t) t=(pomocni_niz+i);
		}
	}
	najveci= *t;

	return najveci;


}
/*Funkcija "izbaci kolone" iz matrice izbacuje sve one kolone koje sadrze broj N*/
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i,j,k,l;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				for(k=0; k<visina; k++) {
					for(l=j; l<sirina-1; l++) {
						matrica[k][l]=matrica[k][l+1];
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
	int matrica[100][100], i, j, k, visina, sirina,N;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);

	for (i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d ", &matrica[i][j]);
		}
	}
	k=1;
	while(sirina>=0) {
		N=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica, visina, sirina, N);
		if(sirina==0) {
			printf ("\nNakon %d. prolaza matrica je prazna!", k);
			break;
		} else {
			printf("\nNakon %d. prolaza matrica glasi:\n", k);
			for (i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}
			k++;
		}
	}

	return 0;
}
