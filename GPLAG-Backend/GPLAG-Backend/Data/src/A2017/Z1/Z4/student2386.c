#include <stdio.h>

int main() {
	int m,n,p,i,j,k,l;
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &m);
	} while(m<0 || m>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &n);
	} while(n<0 || n>10);
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &p);
	} while(p<0 || p>10);
	
	k=0;
	l=0;
	for(i=0; i<(2*m+1); i++) {
		for(j=0; j<(n*(p+1)+1); j++) {
			if(i==0 && (j=k++*((n*(p+1)+1)/n) +1)) printf("+");
			else if(i==0) printf("-");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
