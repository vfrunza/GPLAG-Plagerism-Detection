#include <stdio.h>

int main() {
	int j,i,k,o,n,m,p,l;
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&n);
	}
	while ((n<=0) || (n>10));
	do {
	printf("Unesite broj kolona: ");
	scanf("%d",&o);
	}
	while ((o<=0) || (o>10));
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&m);
	}
	while((m<=0) || (m>10));
	for (j=0;j<n+1;j++) {
		for (k=0;k<o;k++){
			printf("+");
		for (i=0;i<m;i++) {
			printf("-");
		}
		}
		printf("+");
			if (j<n) {
				printf("\n");
				for (l=0;l<o+1;l++){
					printf("|");
				for (p=0;p<m;p++) {
			printf(" ");
				}
				}
		}
			printf("\n");
	}
	return 0;
}
