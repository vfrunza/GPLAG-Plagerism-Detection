#include <stdio.h>

int main() {
	int m, n, p, i, j, brojac=0;
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &m);
	} while(m<=0 ||  m>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &n);
	} while(n<=0 || n>10);
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &p);
	} while(p<=0 || p>10);
	
	for(i=0; i<=m*2; i++) {
		for(j=0; j<p*n+n+1; j++) {
			if(i%2==0 && (j==0 || j==p*n+n || j-brojac==p+1)){
			printf("+");
			brojac=j;
			} 
			else if(i%2==0) printf("-");
			else if(i%2!=0 && (j==0 || j==p*n+n || j-brojac==p+1)){
			printf("|");
			brojac=j;
			} 
			else printf(" ");
		}
		printf("\n");
	}
	
	
	
	return 0;
}
