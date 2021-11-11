#include <stdio.h>

int main()
{
	int i,j,k,n,m,r;


	
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &n);
	} while((n<=0 || n>10));


	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &m);
	} while((m<=0 || m>10));

	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &r);
	} while((r<=0 || r>10));



	for(i=0; i<=n*2; i++) {
		if(i%2==0) {
			for(j=0; j<m; j++) {
				printf("+");
				for(k=0; k<r; k++) {
					printf("-");
				}

			}
			printf("+");

			printf("\n");
		}

		else {
			for(j=0; j<m; j++) {
				printf("|");
				for(k=0; k<r; k++) {
					printf(" ");
				}
			}
			printf("|");
			printf("\n");

		}
	}

	return 0;
}
