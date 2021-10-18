#include <stdio.h>
#include <stdlib.h>


int max(int matrica[100][100], int visina, int sirina){
	int i, j, p, q, broj, maxbroj=matrica[0][0], brojac=0, maxbrojac=0;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			broj=matrica[i][j];
			for(p=0; p<visina; p++){
				for(q=0; q<sirina; q++){
					if(matrica[p][q]==broj) brojac++;
				}
			}
			if(brojac==maxbrojac){
				if(broj<maxbroj) maxbroj=broj;
				brojac=0;
			}
			if(brojac>maxbrojac){
				maxbrojac=brojac;
				maxbroj=broj;
				brojac=0;
			}
			brojac=0;
		}
	}
	return maxbroj;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n){
	int i, j, p, q;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(matrica[i][j]==n){
				for(p=0; p<visina; p++){
					for(q=j; q<sirina-1; q++){
						matrica[p][q]=matrica[p][q+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}

int main(){
	int sirina, visina, matrica[100][100], i, j, k, tmp=1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	
	for(i=0; i<visina; i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	printf("\n");
	
	while(sirina!=0){
		k=max(matrica, visina, sirina);
		sirina=izbaci_kolone(matrica, visina, sirina, k);
		if(sirina==0){
			printf("Nakon %d. prolaza matrica je prazna!", tmp);
			return 0;
		}
		printf("Nakon %d. prolaza matrica glasi:\n", tmp++);
		for(i=0; i<visina; i++){
			for(j=0; j<sirina; j++){
				printf("%5d", matrica[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
