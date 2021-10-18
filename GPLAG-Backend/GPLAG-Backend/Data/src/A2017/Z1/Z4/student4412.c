#include <stdio.h>

int main() {
	int r, k, sk, i, j, l;
//	printf("Zadaća 1, Zadatak 4");
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &r);
		printf("Unesite broj kolona: ");
		scanf("%d", &k);
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);
	}
	while(r<0 || r>10 || k>10 || k<0 || sk>10 || sk<0);
	for(i=0; i<r; i++){
		for(j=0; j<k; j++){
			for(l=1; l<=sk; l++){
				
				
			}
		}
		printf("\n");
	}
	return 0;
}
