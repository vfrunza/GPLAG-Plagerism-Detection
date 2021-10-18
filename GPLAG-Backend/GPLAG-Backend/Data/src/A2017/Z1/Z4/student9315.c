#include <stdio.h>

int main() {
	int a,b, w, i, j, k;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &a);
	} while (a<1 || a>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &b);
	} while (b<1 || b>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &w);
	} while (w<1 || w>10);
	
	for (i=0; i<a; i++) {
		for (j=0; j<b; j++) {
			printf("+");
			for (k=0; k<w; k++)
				printf("-");
		}
		printf("+\n");
		for (j=0; j<b; j++) {
			printf("|");
			for (k=0; k<w; k++)
				printf(" ");
		}
		printf("|\n");
	}
	for (j=0; j<b; j++) {
		printf("+");
		for (k=0; k<w; k++)
			printf("-");
	}
	printf("+\n");
	
	return 0;
}
