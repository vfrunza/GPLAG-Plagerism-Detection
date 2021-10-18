#include <stdio.h>
#define br_el 100

int main() {
	int matA[br_el][br_el], matB[br_el][br_el], matC[br_el][br_el];
	int  i, j, m, n, a, b;
	
	
	printf("Unesite sirinu i visinu matrice A: Unesite clanove matrice A: ");
	scanf("%d %d", &b, &a);
	
	for(i=0; i<a; i++){
			for(j=0; j<b; j++){
			scanf("%d", &matA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: Unesite clanove matrice B: ");
	scanf("%d %d", &n, &m);
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
		scanf("%d", &matB[i][j]);
		} 
		
}

/*ispis matrice A
for(i=0; i<a; i++){
	for(j=0; j<b; j++){
		printf("%2d", A[i][j]);
	}
}*/
/*Ispis matrice B
for(i=0; i<m; i++){
	for(j=0; j<n; j++){
		printf("%2d", B[i][j];}}*/
		
for(i=0; i<b; i++){
	for(j=0; j<a; j++){
		matC[i][j]=matA[a-1-j][i];
	}
}
if((b!=m) || (a!=n)){
	printf("NE\n");
	return 0;
}

for(i=0; i<m; i++){
	for(j=0; j<n; j++){
    if(matB[i][j]!=matC[i][j]) {
			printf("NE\n");
			return 0;
	}
	}
	} printf("DA\n");
	return 0;
}
