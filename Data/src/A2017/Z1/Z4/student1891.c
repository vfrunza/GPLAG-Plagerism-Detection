#include <stdio.h>

int main() {
	int i,j,k,l,m,a,b,s;
	
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&a);
	} while (a <= 0 || a > 10);

	do{
		printf("Unesite broj kolona: ");
		scanf("%d",&b);
	} while (b <= 0 || b > 10);
	
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&s);
	} while (s <= 0 || s > 10);
	
	
	for(i=0;i<=a;i++) {
		for(j=0;j<=b;j++) {
			printf("+");
			if (j<b) {
				for (k=0;k<s;k++){
					printf("-");
				}
			}
		}
		printf("\n");
		if (i<a) {
			for(l=0;l<=b;l++) {
					printf("|");
				if (l<b) {
					for (m=0;m<s;m++){
						printf(" ");
					}		
				}
			}
		
			printf("\n");
		}
	}
	return 0;
}
