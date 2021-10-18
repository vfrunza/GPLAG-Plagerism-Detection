#include <stdio.h>

int main() {
	int red, kolona, sirina, i, j, k;
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &red); 
	} while(!(red>0 && red<=10));
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &kolona);
	} while(!(kolona>0 && kolona <=10));
	do{printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	} while(!(sirina>0 && sirina<=10));
	for (i = 0; i < red; i++) {
		if (i==0) {
			for(j = 0;j<kolona;j++){
				printf("+");
				for (k = 0; k < sirina; k++) {
					printf("-");
				}
			}
			printf("+\n");
		} 
			for(j=0;j<kolona; j++){
				printf("|");
				for(k=0;k<sirina;k++){
					printf(" ");
				}
			}
			printf("|\n");
		
			for(j=0;j<kolona;j++){
				printf("+");
				for (k=0;k<sirina;k++) {
					printf("-");
				}
			}
			printf("+\n");
	}
	return 0;
}
