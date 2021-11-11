#include <stdio.h>

int main()
{

	int i,j,k;
	int q,p,r;

	do {
		printf("Unesite broj redova: ");
		scanf("%d",&q);
	} while(q<=0 || q>10);

	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&p);
	} while(p<=0 || p>10);

	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&r);
	} while(r<=0 || r>10);

	for(i=0; i<=q*2; i++) {
		if(i%2==0) {
			for(j=0; j<=p; j++) {
				printf("+");
				if(j<p) {
					for(k=0; k<r; k++)
						printf("-");
				}
			}
			printf("\n");
		}

		else {
			for(j=0; j<=p; j++) {
				printf("|");
				if(j<p) {
					for(k=0; k<r; k++)
						printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}