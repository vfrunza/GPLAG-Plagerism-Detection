#include <stdio.h>

int main()
{
	int r, n, s, i, j, k;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &r);
	} while(r<=0||r>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &n);
	} while(n<=0||n>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &s);
	} while(s<=0||s>10);
	for(i=0; i<2*r; i++) {
		if(i%2==0) {
			for(j=0; j<n*(s+1); j++) {
				if(j%(s+1)==0) {
					printf("+");
				} else {
					printf("-");
				}
			}
			printf("+\n");
		} else {
			for(k=0; k<(n*(s+1)); k++) {
				if(k%(s+1)==0) {
					printf("|");
				} else {
					printf(" ");
				}
			}
			printf("|\n");
		}
	}
	for(i=0; i<n*(s+1); i++) {
		if(i%(s+1)==0) {
			printf("+");
		} else {
			printf("-");
		}
	}
	printf("+\n");
	return 0;
}
