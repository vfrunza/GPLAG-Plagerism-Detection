#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i, j, k ,l;
	int a, b, brojac;
	a=matrica[0][0];
	b=1;

	for(i=0; i<visina; i++) {
		brojac=0;
		for(j=0; j<sirina; j++) {
			brojac=0;
			for(k=0; k<visina; k++)
				for(l=0; l<sirina; l++)
					if(matrica[i][j]==matrica[k][l])
						brojac++;

			if(brojac>b || (brojac==b && matrica[i][j]<=a)) {
				a=matrica[i][j];
				b=brojac;
			}
		}
	}
	return a;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, p=0, q=0;
	int mat[100][100]= {{0,0,0}};
	int brojac;

	for(j=0; j<sirina; j++) {
		brojac=0;
		for(i=0; i<visina; i++) {
			if(matrica[i][j]!=N)
				brojac++;
		}
		if(brojac==visina) {
			for(p=0; p<visina; p++)
				mat[p][q]=matrica[p][j];
			q++;
		}
	}

	for(i=0; i<visina; i++)
		for(j=0; j<q; j++)
			matrica[i][j]=mat[i][j];
	return q;

}

int main()
{
	int matrica[100][100];
	int i, j,l, sirina, visina;
	int k;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);

	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	l=1;
	k=sirina;
	while(1) {
		k=izbaci_kolone(matrica, visina, k, max(matrica, visina, k));
		if(k==0) {
			printf("\nNakon %d. prolaza matrica je prazna!",l);
			break;
		}
		printf("\nNakon %d. prolaza matrica glasi: \n",l);
		for(i=0; i<visina; i++) {
			for(j=0; j<k; j++)
				printf("%5d",matrica[i][j]);
			printf("\n");
		}
		l++;
	}

	return 0;
}
