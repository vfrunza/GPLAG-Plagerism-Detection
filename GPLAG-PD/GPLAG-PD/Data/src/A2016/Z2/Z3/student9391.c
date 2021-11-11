#include <stdio.h>
#include <math.h>
int main() {
	int broj, i, j, k;
	int koordinataX[10], koordinataY[10];
	for(i=0;i<10;i++){
		koordinataX[i]=-10;
		koordinataY[i]=-10;
	}
	while(1) {
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj);
		if(broj<=0 || broj>10) printf("Pogresan unos\n");
		else break;
	}
	for(i=0;i<broj;i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &koordinataX[i], &koordinataY[i]);
		if(koordinataX[i]<0 || koordinataX[i]>19 || koordinataY[i]<0 || koordinataY[i]>19) {
			printf("Pogresan unos\n");
		}
	}
	
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			for(k=0;k<10;k++) {
				if(j==koordinataX[k] && i==koordinataY[k]) {
					printf("*");
					break;
				} else {
					if(k==9) printf(" ");
				}
			}
		}
		printf("\n");
	}
	
	//printf("Zadaća 2, Zadatak 3");
	return 0;
}
