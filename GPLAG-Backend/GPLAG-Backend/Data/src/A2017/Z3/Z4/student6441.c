#include <stdio.h>
#define BROJ_EL 100

int max(int M[100][100], int visina, int sirina){
	int i, j, brojac_poz[BROJ_EL], brojac_neg[BROJ_EL], max_brojac=0, index=0;
	
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(M[i][j]>=0) brojac_poz[M[i][j]]++;
			else brojac_neg[((-1)*M[i][j])]++;
		}
	}
	
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(M[i][j]>=0 && brojac_poz[M[i][j]]>max_brojac){
				max_brojac=brojac_poz[M[i][j]];
				index=M[i][j];
			} else if(brojac_neg[((-1)*M[i][j])] > max_brojac){
				max_brojac=brojac_neg[((-1)*M[i][j])];
				index=M[i][j];
			}
		}
	}
	
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++){
			if(M[i][j]>=0 && max_brojac==brojac_poz[M[i][j]] && M[i][j]<index){
				index=M[i][j];
			}else if(max_brojac==brojac_neg[((-1)*M[i][j])] && M[i][j]<index) {
				index=M[i][j];
			}
		}
		
	}
	return index;
}
int izbaci_kolone(int M[100][100], int visina, int sirina, int N){
	int i,j,k,l;
	 for(i=0; i<visina; i++){
	 	for(j=0; j<sirina; j++){
	 		if(M[i][j]==N){
	 			for(k=0; k<visina; k++){
	 				for(l=j; l<sirina; l++){
	 					M[k][l]=M[k][l+1];
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
	int M[100][100], visina, sirina, i, j, brojac=0, max_pon, kolone;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	
	for(i=0; i<visina; i++){
	
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++){
			scanf("%d", &M[i][j]);
		}
	}
	kolone=sirina;
	do{
		max_pon=max(M, visina, kolone);
		kolone=izbaci_kolone(M,visina,kolone,max_pon);
		brojac++;
		if (kolone==0) printf("\nNakon %d. prolaza matrica je prazna!", brojac);
		else {
			printf("\nNakon %d. prolaza matrica glasi:\n", brojac);
			for(i=0; i<visina; i++){
				for (j=0; j<kolone; j++){
					printf("%5d", M[i][j]);
				}printf("\n");
			}
		}
	} while (kolone>0);
	return 0;
}
