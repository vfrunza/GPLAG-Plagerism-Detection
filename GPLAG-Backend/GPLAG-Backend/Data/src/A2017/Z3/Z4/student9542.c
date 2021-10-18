#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina){
	int brojac=0;
	int pomocna;
	int maximalni;
	int maximalni1;
	int najvise_ponavljanja=0;
	int i,j,k,l;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			pomocna=matrica[i][j];
		maximalni1=pomocna;
			for(k=i; k<visina; k++){
		for(l=0; l<sirina; l++){
			if(pomocna==matrica[k][l]) brojac++;
			
		}
			}

			if(brojac>najvise_ponavljanja) najvise_ponavljanja=brojac;
			else if(brojac==najvise_ponavljanja) {
				if(pomocna>maximalni1) maximalni=maximalni1;
		else	maximalni=pomocna;} 
		brojac=0;
		}  
	}
 	return maximalni;
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int i,j,k,l;
	
	int pozicija_sirine;
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(matrica[i][j]==N)
			{ 
			pozicija_sirine=j;
				for(k=0; k<visina; k++){
					for(l=pozicija_sirine; l<sirina-1; l++){
							matrica[k][l]=matrica[k][l+1];
						
					}
					
				} 
				sirina--; 
		} 
		}
		
	} 
	return sirina;
}

int main() {
	int sirina, visina;
	int i,j;
	int mat[100][100];
	int N;
	int vrati=0;
	int brojac=0;
	int k;
	int l;
	int pozicija_sirine;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d", &sirina);
	scanf("%d", &visina);
	for(i=0; i<visina; i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
			scanf("%d", &N);
			vrati=izbaci_kolone(mat,visina,sirina,N);
	for(i=0; i<visina; i++){
		for(j=0; j<sirina; j++){
			if(mat[i][j]==N)
			{ 
			pozicija_sirine=j;
				for(k=0; k<visina; k++){
					for(l=pozicija_sirine; l<sirina-1; l++){
							mat[k][l]=mat[k][l+1];
						
					}
					
				} 
				sirina--; 
		} 
		}
		
	} brojac++; 
			
	for(k=0; k<brojac; k++){ 	printf("Nakon %d. prolaza matrica glasi: \n", k+1);
		if(vrati==0) printf("Nakon %d. prolaza matrica je prazna!", k+1);
		vrati=izbaci_kolone(mat,visina,sirina,N);
		for(i=0; i<visina; i++){ 	
		for(j=0; j<sirina; j++){
			printf("%5d", mat[i][j]);
		
		}
		printf("\n");
		}}
	return 0;
}
