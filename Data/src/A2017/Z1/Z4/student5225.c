#include <stdio.h>

int main() {
	int i, j, n, br_red, br_kol, sirina_kol;
	do {printf("Unesite broj redova: ");
		scanf("%d", &br_red); }
	while (br_red <= 0 || br_red > 10);
	
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &br_kol); 
	}
	while (br_kol <= 0 || br_kol > 10);
		
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina_kol); }
	while (sirina_kol <= 0 || sirina_kol > 10);
	
	
	for(i = 0; i < br_red*2+1; i++){
	
		for(j = 0; j < br_kol; j++){
			
			if(i%2==0) {
			
				printf("+"); 
				
				for(n = 0; n < sirina_kol; n++){
				
					printf("-");
				}
			
			if( j == br_kol - 1) printf("+");
			
			}
	
		else {
			printf("|");
			
			for (n=0; n < sirina_kol; n++) {
				printf(" ");
			}
			if(j == br_kol - 1) printf("|");
		}
		
		}
				printf("\n");
		}
	
	
	return 0;
}
