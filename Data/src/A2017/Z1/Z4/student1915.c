#include <stdio.h>

int main()
{
	int n,m,p,j,k,i;

	printf("Unesite broj redova: ");
	scanf("%d",&n);
	if(n>10 || n<=0) {
		do {
			printf("Unesite broj redova: ");
			scanf("%d",&n);
		} while(n>10 || n<=0);
	}
	printf("Unesite broj kolona: ");
	scanf("%d",&m);
	if(m>10 || m<=0) {
		do {
			printf("Unesite broj kolona: ");
			scanf("%d",&m);
		} while(m>10 || m<=0);
	}
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&p);
	if(p>10 || p<=0) {
		do {
			printf("Unesite sirinu jedne kolone: ");
			scanf("%d",&p);
		} while(p>10 || p<=0);
	}
	for(i=1; i<=n+1; i++) {

		for(j=1; j<=m+1; j++) {
			printf("+");

			for(k=1; k<=p; k++) {
				if(j==m+1)continue;
				printf("-");
			}
		}
		printf("\n");
		for(j=1; j<m+2 && i!=n+1; j++) {
			printf("|");
			for(k=1; k<=p; k++) {
				if(j==m+1)continue;
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
