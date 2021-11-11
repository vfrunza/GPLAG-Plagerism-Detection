/*#include <stdio.h>

int main() {

	int r,k,sk,i,j,n,m,o,p,s;
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &r);
	}while(r<=0 || r>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &k);
	}while(k<=0 || k>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);
	} while (sk<=0 || sk>10);

	for(o=0; o<r; o++){
	for(i=0; i<k; i++){
		printf("+");
		for(j=0; j<sk; j++){
			printf("-");
		}
	}
	printf("+");
	printf("\n");

	for(n=0; n<k; n++){
		printf("|");
		for(m=0; m<sk; m++){
			printf(" ");
		}
	}
	printf("|");
	printf("\n");
	}
	for(p=0; p<k; p++){
		printf("+");
		for(s=0; s<sk; s++){
			printf("-");
		}
	}
	printf("+");
	printf("\n");
		return 0;
}*/
#include <stdio.h>

int main()
{
	int n, m, sirina, i, j, k;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &m);
	} while(m <= 0 || m > 10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&n);
	} while(n <= 0 || n > 10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	} while(sirina <= 0 || sirina> 10);

	for(i = 0; i < m * 2 + 1; i++) {
		for(j = 0; j < n; j++) {
			if(i % 2 == 0) {
				printf("+");
				for( k = 0; k < sirina; k++) {
					printf("-");
				}
			} else {
				printf("|");
				for(k = 0; k < sirina; k++) {
					printf(" ");
				}
			}
		}
		if(i % 2 == 0) printf("+");
		else printf("|");
		printf("\n");
	}
	return 0;
}