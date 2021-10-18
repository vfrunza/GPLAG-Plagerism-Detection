#include <stdio.h>


int main() {
	int A[100][100], B[100][100], C[100][100],sirina, visina,i,j;
	
	printf ("Unesite sirinu i visinu matrice A: ");
			scanf ("%d %d", &sirina, &visina);
		
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<sirina; i++){
		for (j=0; j<visina; j++){
			scanf ("%d ", &A[i][j]);
		}
	}
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &sirina, &visina);
	
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<sirina; i++){
		for (j=0; j<visina; j++){
			scanf ("%d ", &B[i][j]);
		}
	}
	
	for (i=0; i<sirina; i++){
		for (j=0; j<visina; j++){
			B[i][j]=C[j][i];}}
		if (C[j][i]==A[i][j]){
		printf ("DA");
	}
	else{
		printf ("NE");
	}
	
	return 0;
}
