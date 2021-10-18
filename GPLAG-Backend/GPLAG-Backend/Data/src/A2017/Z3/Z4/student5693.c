#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int max(int matrica[100][100], int visina, int sirina) {
	int i,j,k,l,brojac[100][100],max=0,najmanji=10000;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			brojac[i][j]=0;
		}
	}
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			for(k=0;k<visina;k++){
				for(l=0;l<sirina;l++){
					if(matrica[i][j]==matrica[k][l]){
						brojac[i][j]++;
					}
				}
			}
		}
	}
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(brojac[i][j]>max) max=brojac[i][j];
		}
	}
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(brojac[i][j]==max){
				if(matrica[i][j]<najmanji) najmanji=matrica[i][j];
			}
		}
	}
	return najmanji;


}

int izbaci_kolone(int niz[100][100], int visina, int sirina, int N) {
	int j,i,k,l;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(niz[i][j]==N){
				for(l=0;l<visina;l++){
					for(k=j;k<sirina-1;k++){
						niz[l][k]=niz[l][k+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}


int main() {
    int matrica[100][100];
	int i,j,k,sirina=0,visina=0,niz,velicina=0,maksimalni;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	printf("\n");
	velicina=sirina;
	for(i=0; i<sirina; i++){
		maksimalni=max( matrica,visina,velicina);
		velicina=izbaci_kolone(matrica,visina,velicina,maksimalni);
		if(velicina!=0){
			printf("\nNakon %d. prolaza matrica glasi:\n", i+1);
			for(k=0;k<visina;k++){
				for(j=0;j<velicina;j++){
					printf("%5d",matrica[k][j]);
				}
				printf("\n");
			}
		}
		else{
			printf("Nakon %d. prolaza matrica je prazna!", i+1);
			break;
		}
	}
	return 0;
}