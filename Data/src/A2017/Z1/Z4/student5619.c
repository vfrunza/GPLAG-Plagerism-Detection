#include <stdio.h>

int main()
{
	int br,bk,sk,i,j,k,l,m;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&br);
	} while (br<=0 || br>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&bk);
	} while (bk<=0 || bk>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sk);
	} while (sk<=0 || sk>10);
	for (i=0; i<br; i++) {
		printf("+");
		for (j=0; j<bk; j++) {
			for (k=0; k<sk; k++) {
				printf("-");
			}
			printf("+");
		}
		printf("\n|");
		for (l=0; l<bk; l++) {
			for (m=0; m<sk; m++) {
				printf(" ");
			}
			printf("|");
		}
		printf("\n");
	}
	for (i=0; i<bk; i++) {
		printf("+");
		for (j=0; j<sk; j++) {
			printf("-");
		}
}
printf("+");
return 0;
}
