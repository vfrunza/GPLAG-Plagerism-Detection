#include <stdio.h>

int main() {
	int r,k,s,i=0,j=0,z=0,c,p;
	do { 
	printf("Unesite broj redova: ");
	scanf("%d", &r);
	} while (r<=0 || r>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &k);
	} while (k<=0 || k>10);
	do { 
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &s);
	} while (s<=0 || s>10);
	 
		for (z=0;z<r;z++) {
			
			for (i=0;i<k;i++) {
				printf("+");
				for (j=0;j<s;j++) {
					printf("-");
				}
			}
			printf("+\n");
			for (c=0;c<k+1;c++) {
			printf("|");
			for (p=0;p<s;p++) {
				printf(" ");
			}
			}
			printf("\n");
			if (z==r-1) {
				for (i=0;i<k;i++) {
					printf("+");
					for (j=0;j<s;j++){
						printf("-");
					}
				
				}
				printf("+");
			}
			}
		
			


}
