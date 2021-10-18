#include <stdio.h>

int main() {
	int A[100][100],B[100][100],At[100][100];
	int V1,S1,V2,S2,i,j;
	
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &S1, &V1);
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<V1; i++) {
		for (j=0; j<S1; j++) {
			scanf ("%d", &A[i][j]); } }
			
			
	for (i=0; i<V1; i++) {
		for (j=0; j<S1; j++) {
			At[j][V1-i-1]=A[i][j]; } }
			
			
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &S2, &V2);
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<V2; i++) {
		for (j=0; j<S2; j++) {
			scanf ("%d", &B[i][j]); } }
			
			
	if (V1!=S2 || S1!=V2) {
		printf ("NE\n");
		return 0; }		
			
			
	for (i=0; i<V2; i++) {
		for (j=0; j<S2; j++) {
			if (At[i][j]!=B[i][j]) {
				printf ("NE\n");
				return 0; } } }
	
				
	printf ("DA\n");
	
	return 0;
}
