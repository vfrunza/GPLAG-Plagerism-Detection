#include <stdio.h>

int main() {
	/* Unos broja redova, broja kolona i sirine kolone */
	int m, n, p; 
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &n);
	} while (n<=0|| n>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &m);
	} while (m<=0 || m>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &p);
	} while (p<=0 || p>10);
	/* Obrada i ispis: imat cemo 2n redova i m*(p+1) kolona */
	int i, j;
	for(i=0; i<=2*n; i++){
		for(j=0; j<=m*(p+1); j++){
			/* Ispis + */
			if(i%2==0 && j%(p+1)==0) printf("+");
			/* Ispis | */
			else if (i%2==1 && j%(p+1)==0) printf("|");
			/* Ispis - */
			else if(i%2==0 && j%(p+1)!=0) printf("-");
			/* Ispis razmaka */
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
