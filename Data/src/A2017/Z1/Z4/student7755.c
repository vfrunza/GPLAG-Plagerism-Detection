#include <stdio.h>

int main()
{
	int redovi,kolone,sirina;
	int i,j;
	int A,B;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&redovi);
	} while (redovi>10 || redovi<=0);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&kolone);
	} while (kolone>10 || kolone<=0);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina);
	} while (sirina>10 || sirina<=0);
	A=(2*redovi) + 1;
	B=kolone+(sirina*kolone)+1;
	for (i=0; i<A; i++) {
		for (j=0; j<B; j++) {
			if (i%2==0 && j%(sirina+1)==0) {
				printf("+");
			} else if (i%2==1 && j%(sirina+1)==0) {
				printf("|");
			} else if (i%2==0 && j%(sirina+1)!=0) {
				printf("-");
			} else if (i%2==1 && j%(sirina+1)!=0) {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
