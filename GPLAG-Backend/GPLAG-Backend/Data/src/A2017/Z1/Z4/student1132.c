#include <stdio.h>

int main() {
	int red, kolona, sirina, i, j, k;
	
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &red); }
	while (red<=0 || red>10);
	
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &kolona); }
	while (kolona<=0 || kolona>10);
	
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina); }
	while (sirina<=0 || sirina>10);
	
	for (k=0; k<=red;k++) {
		for (i=0;i<=kolona;i++) {
			printf("+");
		if (i==kolona)
			continue;
		for (j=0;j<sirina;j++) 
			printf("-");
		}
		printf("\n");
		if (k==red)
			continue;
		for (i=0;i<=kolona;i++) {
			printf("|");
			if (i==kolona)
				continue;
			for (j=0;j<sirina;j++)
				printf(" ");
			}
		printf("\n");
	}
	
	return 0;
}
