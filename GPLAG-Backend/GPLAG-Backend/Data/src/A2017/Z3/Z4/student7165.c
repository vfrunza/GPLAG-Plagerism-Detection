#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,k,l,element,maks_element,ponavljanja=0,maks_ponavljanja=0;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			element=matrica[i][j];
			for(l=0; l<visina; l++) {
				for(k=0; k<sirina; k++) {
					if(element==matrica[l][k]) ponavljanja++;
				}
			}
			if (ponavljanja>maks_ponavljanja) {
				maks_element=matrica[i][j];
				maks_ponavljanja=ponavljanja;
			}
			if(ponavljanja==maks_ponavljanja && matrica[i][j]<maks_element) {
				maks_element=matrica[i][j];
				maks_ponavljanja=ponavljanja;
			}
			ponavljanja=0;
		}
	}
	return maks_element;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i,j,k,l;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				for(k=0; k<visina; k++) {
					for(l=j; l<sirina; l++) matrica[k][l]=matrica[k][l+1];
				}
				sirina--;
			}
		}
	}
	for (i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(N==matrica[i][j]) {
				return 0;
			}
		}
	}
	return sirina;
}

int main()
{
	int visina=0,sirina=0,matrica[100][100],i,j,k,n,nova_sirina;
	while(sirina<=0 || visina<=0) {
		printf("Unesite sirinu i visinu matrice: ");
		scanf("%d%d",&sirina,&visina);
	}
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) scanf("%d",&matrica[i][j]);
	}
	i=1;
	n=max(matrica,visina,sirina);
	nova_sirina=izbaci_kolone(matrica,visina,sirina,n);
	while(nova_sirina!=0) {
		printf("\nNakon %d. prolaza matrica glasi:\n",i);
		for(j=0; j<visina; j++) {
			for(k=0; k<nova_sirina; k++) printf("%5d",matrica[j][k]);
			printf("\n");
		}
		n=max(matrica,visina,nova_sirina);
		nova_sirina=izbaci_kolone(matrica,visina,nova_sirina,n);
		i++;
	}
	printf("\nNakon %d. prolaza matrica je prazna!",i);
	return 0;
}
