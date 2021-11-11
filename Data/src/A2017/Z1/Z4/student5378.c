#include <stdio.h>
#include <math.h>
int main() {
	int br,bk,sr,i,j,k;

	do { 
		printf("Unesite broj redova: ");
		scanf("%d", &br);
	} while (br<=0 || br>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &bk);
	} while (bk<=0 || bk>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sr);
	} while (sr<=0 || sr>10);
	
	for (i=0;i<br*2+1;i++) {
		
		for (j=0;j<bk;j++) {
			if (i%2==0) {
				printf("+");
				for (k=0;k<sr;k++) {
				printf("-");
				
				}
			} else {
				printf("|");
				for (k=0;k<sr;k++) {
				printf(" ");
				}
			}
		} if (i%2==0) {
		printf("+");
		} else { 
			printf("|");
		}
		printf("\n");
	}
	return 0;
}
