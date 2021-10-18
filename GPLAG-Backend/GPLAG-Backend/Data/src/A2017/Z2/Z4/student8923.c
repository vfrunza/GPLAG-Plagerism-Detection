#include <stdio.h>
#define VISINA 101
#define SIRINA 101
int main() {
	int mat_A[VISINA][SIRINA], mat_B[VISINA][SIRINA], mat_C[VISINA][SIRINA], visina, sirina, i, j;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &visina, &sirina);
	}while(visina < 0 || visina > 100 || sirina < 0 || sirina > 100);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visina; i++) 
		for(j=0; j<sirina; j++) 
			scanf("%d", &mat_A[i][j]);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visina; i++) 
		for(j=0; j<sirina; j++)
			scanf("%d",&mat_B[i][j]);
	printf("Unesite clanove matrice C: ");
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) 
			scanf("%d",&mat_C[i][j]);
	for(i = 0; i < visina; i++) {
		for(j = 0; j < sirina; j++) {
			
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	int matA[VISINA][SIRINA],matB[VISINA][SIRINA],matC[VISINA][SIRINA];
	int m,n,i,j,temp;
	int a=0,b=0,c=0;
	int nizmat_A[VISINA*SIRINA],nizmat_B[VISINA*SIRINA],nizmat_C[VISINA*SIRINA];
	// treba unijeti dimenzije MxN matrica A, B, C, i to prema uslovu iz zadatka
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}	while((m>100 || m<0) || (n>100 || n<0));
	// unos clanova matrica A, B, C redom

	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &matA[i][j]);
		}
	}

	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&matB[i][j]);
		}
	}

	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&matC[i][j]);
		}
	}

	//hajmo matricu pretvoriti u niz

	a = b = c = 0;
	// kazem petlji: "pretvori mi elemente matrice A u niz A sve dok mi ne dodjes do zadnjeg elementa matrice tj. dok ne prodjes kroz svaki element matrice"
	while(a < m) {
		nizmat_A[b]=matA[a][c];
		nizmat_B[b]=matB[a][c];
		nizmat_C[b]=matC[a][c];
		b++;
		c++;
		if(c>=n) {
			c=0;
			a++;
		}

	}
	//hajmo napraviti selection sort algoritam (predavanje: "Operacije i algoritmi sa nizovima")da sortiramo niz, a niz je nasa matrica koju smo pretvorili u niz u ovim gore koracima

	int najmanjiA,najmanjiB,najmanjiC;

	for(a=0; a<m*n; a++) {
		najmanjiA=a;
		for(b=a; b<m*n; b++) {
			if(nizmat_A[b]<nizmat_A[najmanjiA]) {
				najmanjiA=b;
			}
		}
		temp=nizmat_A[a];
		nizmat_A[a]=nizmat_A[najmanjiA];
		nizmat_A[najmanjiA]=temp;
	}
	for(a=0; a<m*n; a++) {
		najmanjiB=a;
		for(b=a; b<m*n; b++) {
			if(nizmat_B[b]<nizmat_B[najmanjiB]) {
				najmanjiB=b;
			}
		}
		temp=nizmat_B[a];
		nizmat_B[a]=nizmat_B[najmanjiB];
		nizmat_B[najmanjiB]=temp;
	}
	for(a=0; a<m*n; a++) {
		najmanjiC=a;
		for(b=a; b<m*n; b++) {
			if(nizmat_C[b]<nizmat_C[najmanjiC]) {
				najmanjiC=b;
			}
		}
		temp=nizmat_C[a];
		nizmat_C[a]=nizmat_C[najmanjiC];
		nizmat_C[najmanjiC]=temp;
	}
	// kao i u zadatku 2, postavljamo logicku promjenljivu na 1, tj da je ona tacna, ako nije tacna za bar jedno onda ona postaje 0 odnosno false
	int jednaki=1;
	for(a=0; a<m*n; a++) {
		if(nizmat_A[a]!=nizmat_B[a] || nizmat_A[a]!=nizmat_C[a]) {
			jednaki=0;
			break;
		}
	}
	if(jednaki==1)	printf("DA\n");
	else printf("NE\n");
*/
	return 0;
}
