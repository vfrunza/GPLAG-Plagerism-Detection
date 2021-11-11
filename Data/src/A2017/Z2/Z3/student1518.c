#include <stdio.h>
#define MAX 100

int main() {
	
	int a, b, c, d, i, j, jednake=1;
	float matricaA[MAX][MAX], matricaB[MAX][MAX];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d", &a);
	scanf("%d", &b);
	printf("Unesite clanove matrice A: ");
	for (i=0; i<b; i++) {
		for (j=0; j<a; j++) {
			scanf("%f", &matricaA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d", &c);
	scanf("%d", &d);
	printf("Unesite clanove matrice B: ");
	for (i=0; i<d; i++) {
		for (j=0; j<c; j++) {
			scanf("%f", &matricaB[i][j]);
		}
	}
	
	if (a==d && b==c) {
		for (i=0; i<b; i++) {
			for (j=0; j<a; j++) {
				if (matricaA[i][j]!=matricaB[j][b-i-1]) {
					jednake=0;
					i=b;
					j=a;
				}
			}
		}
		if (jednake) {
			printf("DA");
		}
		else {
			printf("NE");
		}
	}
	else {
		printf("NE");
	}
	
	
	
	return 0;
}