#include <stdio.h>

int main() {
	int s1, v1, s2, v2, i, j, svi_elementi_zadovoljavaju;
	svi_elementi_zadovoljavaju=1;
	float A[100][100]={0}; float pomocna[100][100]={0}; float B[100][100]={0};
	printf("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &s1, &v1);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<v1; i++) {
		for (j=0; j<s1; j++) {
			scanf("%f", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &s2, &v2);
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<v2; i++) {
		for (j=0; j<s2; j++) {
			scanf("%f", &B[i][j]);
		}
	}
	for (i=0; i < v1; i++) {
		for (j=0; j < s1; j++) {
			pomocna[j][i]=A[i][j];
		}
	}
	for (i = 0; i < s1; i++) {
		for (j=0; j < v1/2; j++) {
			float privremena = pomocna[i][j];
			pomocna[i][j] = pomocna[i][v1-1-j];
			pomocna[i][v1-1-j] = privremena;
		}
	}
	
	int red = v1;
	int kolona = s1;
	if (s2 > red || v2 > kolona || red > s2 || kolona > v2) 
	    svi_elementi_zadovoljavaju = 0;
	else {
	for (i=0; i < red; i++) {
		for (j = 0; j < kolona; j++) {
			if (pomocna[i][j] != B[i][j]) {
				svi_elementi_zadovoljavaju = 0;
				break;
			}
		}
	}
	} 
	if (svi_elementi_zadovoljavaju) printf("DA\n");
	else printf("NE\n");

	return 0;
}
