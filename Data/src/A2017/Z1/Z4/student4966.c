#include <stdio.h>

int main() {
	int red, kolona, sirina, i, j; 
	
	do { 
	printf("Unesite broj redova: ");
	scanf("%d", &red);
	} while (red<=0 || red>10);
	
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &kolona);
	} while (kolona<=0 || kolona>10);
	
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	} while (sirina<=0 || sirina>10);
	
	for (i = 2*red; i >= 0; i--) {
		if (i%2==0) {
		printf("+");	
		}
		else {
		printf("|");	
		}
		
		/*redovi*/
		
	for(j=1;j<(kolona*sirina + kolona+1);j++){
		/*brisanje za i neparno*/
		
			if (i%2!=0) {
				 if (j%(sirina+1)==0) {
					printf("|");
				}
				else{
					printf(" ");
				}
			}
			
		/*razdvoji polja*/
		else if (j%(sirina+1)==0) {
			printf("+");
		}
		/*dodavanje za i parno*/
			else
		{
				printf("-");
		}
		
		
		}
		printf("\n");
	}
	return 0;
}
	
