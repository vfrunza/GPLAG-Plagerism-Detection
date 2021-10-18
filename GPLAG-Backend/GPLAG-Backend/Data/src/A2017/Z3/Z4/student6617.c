#include <stdio.h>
#include <math.h>
#define duzina_brojaca 10000

int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,k=0,brojac_poz[duzina_brojaca]= {0},broj,max_poz,max_neg,niz[1000],brojac_neg[duzina_brojaca]= {0},broj1=0,broj2=-1;

	for(i = 0; i < visina; i++) {
		for(j = 0; j < sirina; j++) {
			niz[k]=matrica[i][j];
			k++;

		}
	}

	for(i = 0; i < k; i++) {
		if(niz[i] >= 0)
			brojac_poz[niz[i]]++;
		else if(niz[i] < 0)
			brojac_neg[(int)fabs(niz[i])]++;
	}
	max_poz=brojac_poz[0];
	max_neg=brojac_neg[0];
	for(i = 0; i < duzina_brojaca; i++) {

		if(brojac_poz[i] > max_poz) {
			max_poz=brojac_poz[i];
			broj1=i;
		}

		if(brojac_neg[i] >= max_neg) {
			max_neg=brojac_neg[i];
			broj2=-i;
		}
	}

	if(max_poz > max_neg)
		broj=broj1;
	else
		broj=broj2;

	return broj;
}

int izbaci_kolone(int mat[100][100], int visina, int sirina, int N)
{
	int i,j,k,m;
	for(i = 0; i < visina; i++) {
		for(j = 0; j < sirina; j++) {
			if(mat[i][j] == N) {
				for(k = j; k < sirina-1; k++) {
					for(m = 0; m < visina; m++) {
						mat[m][k]=mat[m][k+1];
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
	int mat[100][100],sirina,visina,x,i,j,k,maxi;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina, &visina);

	for(i = 0; i < visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j = 0; j < sirina; j++) {
			scanf("%d",&mat[i][j]);
		}
	}


	for(k = 0; sirina >= 0; k++) {
		maxi=max(mat,visina,sirina);
		x=izbaci_kolone(mat,visina,sirina,maxi);
		if(x == 0 ) {
			printf("\nNakon %d. prolaza matrica je prazna!",k+1);
			break;
			return 0;
		}
		printf("\nNakon %d. prolaza matrica glasi:\n",k+1);
		for(i = 0; i < visina; i++) {
			for(j = 0; j < x; j++) {
				printf("%5d",mat[i][j]);
			}
			printf("\n");
		}
		sirina=x;
	}
	return 0;
}
