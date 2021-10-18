#include <stdio.h>
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, a, b;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				for(a=j; a<sirina; a++)
					for(b=0; b<visina; b++)
						matrica[b][a]=matrica[b][a+1];
				sirina--;
			}
		}
	}
	return sirina;
}


int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,a,b;
	int max = 0, brojac = 0, poredi, temp, broj=0, ponoviti=1;
	int maks=matrica[0][0];

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			broj=matrica[i][j];
			for(a=0; a<visina; a++) {
				for(b=0; b<sirina; b++) {

					poredi=matrica[a][b];
					if(broj==poredi) {
						brojac++;
					}
				}
			}
			if(brojac>=max) {
				temp=maks;
				maks=broj;
				if(brojac==max && broj>temp)
					maks=temp;
				max=brojac;
			}
			brojac=0;
		}
	}
	return maks;
}

int main()
{
	int i, j, a=0, b, brojac=1;
	int mat[100][100];
	int sirina, visina;
	printf("Unesite sirinu i visinu matrice: "); /*Unos elemenata matrice*/
	scanf("%d %d", &sirina, &visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	int ponoviti=1;
	do {
		if(sirina>1)
			while(a<visina) {
				for(b=1; b<sirina; b++) {
					if(mat[a][0]==mat[a][b]) brojac++;
				}
				if(brojac==sirina) {
					printf("\nNakon 1. prolaza matrica je prazna!");
					return 0;
				} else {
					brojac=1;
					a++;
				}
			}
		int N=max(mat,visina,sirina);
		sirina=izbaci_kolone(mat,visina,sirina,N);

		if(sirina!=0) {
			printf("\nNakon %d. prolaza matrica glasi:\n", ponoviti);
			for(i=0; i<visina; i++) {      
				for(j=0; j<sirina; j++) {
					if(j==0 && mat[i][0]>=100) printf("  ");
					else if(j==0 && mat[i][0]>=10) printf ("   ");
					else if(j==0 && mat[i][0]<10) printf("    ");
					if(j==sirina-1) printf("%d", mat[i][j]);
					if(j!=sirina-1) printf("%-5d", mat[i][j]);

				}
				printf("\n");
			}
		} else {
			printf("\nNakon %d. prolaza matrica je prazna!", ponoviti); /*Ispisuje da je matrica prazna nakon nekog broja ponavljanja*/
			return 0;
		}
		ponoviti=ponoviti+1;
	} while (sirina!=0);

	
	return 0;
}
