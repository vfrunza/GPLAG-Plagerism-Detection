#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina){
	int i, j, i1, j1, max_broj, br, max_puta=0;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
	br=0;	
	for(i1=0; i1<visina; i1++){
		for(j1=0; j1<sirina; j1++){
			if(matrica[i][j]==matrica[i1][j1]) br++;
		}
	}
	
	if(max_puta<br){
		max_puta=br;
		max_broj=matrica[i][j];
	}
	if(max_puta==br && max_broj>matrica[i][j]) max_broj=matrica[i][j];
	}
	}
	
	return max_broj;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int i, j, i1, j1;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(matrica[i][j]==N){
	
	for(i1=0; i1<visina; i1++){
		for(j1=j; j1<sirina-1; j1++){
			matrica[i1][j1]=matrica[i1][j1+1];
			}
		}
			j--;
			sirina--;
			}
		}
	}
	return sirina;
}

int main() {
	int sirina, visina, i, j, matrica[100][100], N,br=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina, &visina);
	for(i=0; i<visina; i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	do{
		N=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,N);
		if(sirina==0){
			printf("\nNakon %d. prolaza matrica je prazna!",br+1);
		}
		else printf("\nNakon %d. prolaza matrica glasi:\n",br+1);
		for(i=0; i<visina; i++){
			for(j=0; j<sirina; j++){
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}
		br++;
	} while(sirina!=0);
	
	return 0;
}
