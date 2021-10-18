#include <stdio.h>

int main() {
	int red, kol, sirina;
	int kraj1, kraj2;
	int i, j;
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &red);
	}while(red<=0 || red>10);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &kol);
	}while(kol<=0 || kol>10);
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	}while(sirina<=0 || sirina>10);
	
	kraj1=(red*2)+1;
	kraj2=(kol*sirina)+kol+1;
	
	for(i=0; i<kraj1; i++) {
		for(j=0; j<kraj2; j++) {
			if(i%2==0 && (j==0 || j==kraj2-1 || j%(sirina+1)==0)) {
						printf("+");
			} else {
				if(i%2!=0 && (j==0 || j==kraj2-1 || j%(sirina+1)==0)) { 
					printf("|");
				} else {
					if(i%2==0 && (j==0 || j==kraj2-1)) {
						printf("+");
					} else {
						if(i%2==0) {
							printf("-");
						} else {
							printf(" ");
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
