#include <stdio.h>

int main() {
	int Ax, Ay, Bx, By, i, j;
	double nizA[100][100], nizB[100][100];
	
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &Ay, &Ax);
	
	if (Ax<1 || Ay<1){
		printf ("Dimenzije matrice moraju biti pozitivne!\n");
		return 1;
	}
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<Ax; i++){
		for (j=0; j<Ay; j++){
			scanf("%lf", &nizA[i][j]);
		}
	}
	
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &By, &Bx);
	
	if (Bx<1 || By<1){
		printf ("Dimenzije matrice moraju biti pozitivne!\n");
		return 1;
	}
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<Bx; i++){
		for (j=0; j<By; j++){
		scanf ("%lf", &nizB[i][j]);	
		}
	}
	
	
	if (Ax!=By || Ay!=Bx){
		printf ("NE\n");
		return 1;
	}
	
	
	for (i=0; i<Ax; i++){
		for (j=0; j<Ay; j++){
			if (nizA[i][j] != nizB[j][By-i-1]){
				printf ("NE\n");
				return 1;
			}
		}
	}
	
	printf ("DA\n");
	
	return 0;
}
