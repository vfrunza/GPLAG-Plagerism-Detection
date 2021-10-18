#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina)
{
	int prethodni=0,trenutni=0,broj1=matrica[0][0],broj=0,najvise=0,i,j,k,l;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			broj=matrica[i][j];
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) {
					if(matrica[k][l]==broj) trenutni++;
				}
			}
			if(trenutni>prethodni) {
				najvise=broj;
				prethodni=trenutni;
				trenutni=0;
				broj1=broj;
			} else if(trenutni==prethodni && broj1!=broj) {
				if(broj1<broj) najvise=broj1;
				else {
					najvise=broj;
					trenutni=0;
					broj1=broj;
				}
			}
			trenutni=0;
		}
	}
	return najvise;
}
int izbaci_kolone(int matrica[100][100],int visina, int sirina,int n)
{
	int i,j,k,l;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==n) {
				if(j!=sirina-1) {
					for(k=0; k<visina; k++) {
						for(l=j; l<sirina-1; l++) {
							matrica[k][l]=matrica[k][l+1];
						}
					}
					sirina--;
					j--;
				} else sirina--;
			}
		}
	}
	return sirina;
}
int main()
{
	int mat[100][100],visina,sirina,broj_prolaza=1,i,j,broj,funkcija=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	broj=max(mat,visina,sirina);
	funkcija=izbaci_kolone(mat,visina,sirina,broj);
	for(broj_prolaza=1; broj_prolaza<=100; broj_prolaza++) {
		if(funkcija==0) break;
		printf("\nNakon %d. prolaza matrica glasi:\n",broj_prolaza);
		for(i=0; i<visina; i++) {
			for(j=0; j<funkcija; j++) {
				printf("%5d",mat[i][j]);
			}
			printf("\n");
		}
		broj=max(mat,visina,funkcija);
		funkcija=izbaci_kolone(mat,visina,funkcija,broj);
	}
	printf("\nNakon %d. prolaza matrica je prazna!",broj_prolaza);
	return 0;
}
