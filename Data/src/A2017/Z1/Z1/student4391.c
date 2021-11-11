#include <stdio.h>

int main() {
	printf("Zadaća 1, Zadatak 1");
	return 0;
}
	do{
	    printf("Unesite broj redova: ");
	scanf("%d", &r);
	} while (r<=0 || r>10);
	do{
		printf("Unesite broj kolona: ");
	scanf("%d", &k);
	} while (k<=0 || k>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &jk);
	}while (jk<=0 || jk>10);