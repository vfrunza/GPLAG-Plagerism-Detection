#include <stdio.h>

int main()
{
	int i=0, j=0, m=0, n=0, s=0;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &m);
	} while (m<=0 || m>10);

	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &n);
	} while (n<=0 || n>10);

	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &s);
	} while(s<=0 || s>10);

	for(i=0; i<m*2+1; i++) {
		for(j=0; j<n*s+n+1; j++) {
			if(j%(s+1)==0 && i%2==0) {
				printf("+");
			} else if (i%2==0 && j%(s+1)!=0) {
				printf("-");
			} else if(i%2!=0 && j%(s+1)==0) {
				printf("|");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}