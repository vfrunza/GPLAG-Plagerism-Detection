#include <stdio.h>

int main() {
	int a, b, c, i, j, k;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &a);
	} while(a<=0 || a>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &b);
	} while(b<=0 || b>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &c);
	} while(c<=0 || c>10);
	
	for(i=0; i<=a; i++) {
		printf("+");
		
		for(j=0; j<b; j++) {
			for(k=0; k<c; k++) {
				printf("-");	
			}
			printf("+");
		}
		printf("\n");
		if(i<a) {
			for(j=0; j<b; j++) {
				printf("|");
				for(k=0; k<c; k++) {
					printf(" ");
				}
			}
			printf("|");
			printf("\n");
		} else {
			printf("\n");
		}
	}
	return 0;
}
