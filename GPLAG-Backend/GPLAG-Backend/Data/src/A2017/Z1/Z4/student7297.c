#include <stdio.h>

int main() {
	int i, j, a, b, c, n, m, k, p, q;
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &a);
	} while (a<=0 || a>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &b);
	} while (b<=0 || b>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &c);
	} while (c<=0 || c>10);
	for(n=0; n<a; n++){
	for(i=0; i<b; i++){
		if(i==0){
			printf("+");
		}
		for(j=0; j<c; j++){
			printf("-");
		} printf("+"); } 
		printf("\n");
		for (k=0; k<b; k++){
			if(k==0){
				printf("|");
			} for(m=0; m<c; m++){
				printf(" ");
			} printf("|");
		} printf("\n");
	}
	for(p=0; p<b; p++){
		if(p==0){
			printf("+");
		}
		for(q=0; q<c; q++){
			printf("-");
		} printf("+");
	}
 return 0;
}
