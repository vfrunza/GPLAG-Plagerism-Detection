#include <stdio.h>

int main()
{
	int BR,BK,SK,i,j,k;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&BR);
	} while (BR<=0 || BR>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&BK);
	} while (BK<=0 || BK>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&SK);
	} while (SK<=0 || SK>10);

	for(i=0; i<=BR; i++) {
		for(j=0; j<=BK; j++) {
			printf("+");
			if(j==BK)
				continue;
			for(k=1; k<=SK; k++) {
				printf("-");
			}
		}
		printf("\n");
		if(i==BR)
			break;
		for(j=0; j<=BK; j++) {
			printf("|");
			if(j==BK)
				break;
			for(k=1; k<=SK; k++) {
				printf(" ");
			}
		}
		printf("\n");
	}
		return 0;
}
