#include <stdio.h>

int main() {
	int red, kolona, sirina, i, j;
	printf("Unesite broj redova: ");
	scanf("%d", &red);
	printf("Unesite broj kolona: ");
	scanf("%d", &kolona);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	do {
		for(i=0; i<red+red+1; i++) {
			for(j=0; j<(kolona*sirina)+kolona+1; j++) {
				printf("-");
			}
			printf("\n");
		}
		break;
	} while((red>0 && red<=10) && (kolona>0 && kolona<=10) && (sirina>0 && sirina<=10));
	return 0;
}
