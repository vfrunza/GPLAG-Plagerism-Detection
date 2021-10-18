#include <stdio.h>

int main()
{
	int red,kolona,sirinakolone,i,j,k;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&red);
	} while(red<=0 || red>10);

	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&kolona);
	} while(kolona<=0 || kolona>10);

	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirinakolone);
	} while(sirinakolone<=0 || sirinakolone>10);

	for(i=1; i<=red*2+1; i++) {
		for(j=1; j<=kolona; j++) {
			if(i%2!=0) {
				printf("+");
				for(k=1; k<=sirinakolone; k++)
					printf("-");
				if(j==kolona+2)
					printf("+");
			} else  {
				printf("|");
				for(k=1; k<=sirinakolone; k++)
					printf(" ");
				if(j==kolona+2)
					printf("|");
			}
		}
		if(i%2!=0) {
			printf("+");
		} else printf("|");
		printf("\n");
	}

	return 0;
}