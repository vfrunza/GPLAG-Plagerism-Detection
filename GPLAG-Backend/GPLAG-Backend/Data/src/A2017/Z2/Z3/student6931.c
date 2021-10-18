#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	int i=0, j=0, rot=1, sirina1, sirina2, visina1, visina2;
	float a[100][100], b[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina1, &visina1);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visina1; i++) {
		for(j=0; j<sirina1; j++){
			scanf("%f", &a[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina2, &visina2);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visina2; i++) {
		for(j=0; j<sirina2; j++) {
			scanf("%f", &b[i][j]);
		}
	}
	if(visina1!=sirina2 || visina2!=sirina1) {
		printf("NE"); 
		return 0;
	} else {
		for(i=0; i<sirina1; i++) {
			for(j=0; j<visina1; j++) {
				if(b[i][j]==a[visina1-1-j][i]) {
					rot=1;
				} else {
					rot=0;
					break;
				}
			}
		}
		if(rot==0) printf("NE");
		else printf("DA");
	}
	return 0;
}
