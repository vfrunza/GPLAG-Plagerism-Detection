#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 3");*/
	float a[20][20], b[20][20];
	int i, j, va, vb, sa, sb, vela, velb, bra=0, brb=0;
	float niza[400], nizb[400];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sa, &va);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<va; i++) {
		for(j=0; j<sa; j++) {
			scanf("%f", &a[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sb, &vb);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vb; i++) {
		for(j=0; j<sb; j++) {
			scanf("%f", &b[i][j]);
		}
	}
	vela=sa*va;
	velb=sb*vb;
	if(vela!=velb) {
		printf("NE\n");
		return 0;
	}
	for(j=0; j<sa; j++) {
		i=va-1;
		while(i>=0) {
			niza[bra]=a[i][j];
			bra++;
			i--;
		}
	}
	for(i=0; i<vb; i++) {
		for(j=0; j<sb; j++) {
			nizb[brb]=b[i][j];
			brb++;
		}
	}
	for(i=0; i<vela; i++) {
		if(niza[i]!=nizb[i]) {
			printf("NE\n");
			return 0;
		}
	}
	printf("DA\n");
	return 0;
}
