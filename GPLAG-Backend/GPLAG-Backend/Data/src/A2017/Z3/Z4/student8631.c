#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int niz1[10000]; 
	int niz2[10000]={0}; 
	int i, j, k;
	int vel=0; 
	int maxi, min;
	/*
	printf("visina = %d, sirina = %d\n", visina, sirina);
	for(i=0; i<visina; i++) {
		 for(j=0; j<sirina; j++){
		 	printf("%d ", matrica[i][j]); 
		 }
		 printf("\n"); 
		 }*/
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++){
			for(k=0; k<vel; k++){
				if(matrica[i][j]==niz1[k]){
					niz2[k]++;
					break;
				} 
			}
			if(k==vel) {
				niz1[k]=matrica[i][j]; 
				niz2[k]++; 
				vel++; 
			}
			
		}
	}
	maxi=niz2[0]; 
	min=niz1[0];
	
	for(i=1; i<vel; i++) {
		if(niz2[i]>maxi){ maxi=niz2[i]; 
		min=niz1[i]; 
	}
	}
	for(i=0; i<vel; i++) {
		if(niz2[i]==maxi && niz1[i]<min)
		min=niz1[i]; 
	 
	}
	
	 return min; 
}
 int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n){
 	int i, j, l, k; 
 	for(i=0; i<visina; i++){
 		for(j=0; j<sirina; j++){
 			if(matrica[i][j]==n){
 				for(k=0; k<visina; k++){
 					for(l=j; l<sirina-1; l++) 
 					matrica[k][l]=matrica[k][l+1];
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
	int matrica[100][100], i, j, k, l, m,n;
	int pret;
	int rez=0;
	int maxi;
	do {
		printf("Unesite sirinu i visinu matrice: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || m>200 || n>200)
			printf("Brojevi nisu u zadanom opsegu");
	} while (m<=0 || n<=0 || m>200 || n>200);
	
	for(i=0; i<n; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		 for(j=0; j<m; j++)
				scanf("%d", &matrica[i][j]);
	}
	
	
	/*for(i=0; i<n; i++) {
		 for(j=0; j<m; j++){
		 	printf("%d ", matrica[i][j]); 
		 }
		 printf("\n"); 
		 }

	printf("%d\n", max(matrica, n, m)); */
	

	for(k=0;;k++) {
		
		maxi=max(matrica, n,m);
		m=izbaci_kolone(matrica, n,m, maxi);
		if(m==0){ 
			printf("\nNakon %d. prolaza matrica je prazna!", k+1);
			break;
		}
		printf("\nNakon %d. prolaza matrica glasi: \n", k+1);
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%5d", matrica[i][j]);
			}
			printf("\n"); 
		}
	
		  
	}
	
			return 0;
}
