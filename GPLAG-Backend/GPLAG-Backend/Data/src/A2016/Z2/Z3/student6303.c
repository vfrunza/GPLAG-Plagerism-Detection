#include <stdio.h>

int main() {
	
	int matricaljepotica[20][20]={{0}};
	int c, i, j, f, g;
	printf("Unesite broj tacaka: ");
	scanf("%d", &c); 
 if(c<=0 || c>10) {
		for(;;) {
			printf("Pogresan unos");
			printf("\nUnesite broj tacaka: ");
			scanf("%d", &c);
			if(c>0 && c<11) break;
		}
	} 
	for(i=0; i<c; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &g, &f);
		if(f<0 || f>19 || g<0 || g>19) {
			printf("Pogresan unos\n");
			i--;
		} else matricaljepotica[g][f]=1;
		/* 4, 1 1, 2 2, 3 1, 4 0 */
	}
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			f=i; g=j; 
			if(matricaljepotica[g][f]==1) printf("*");
			else if (matricaljepotica[g][f]==0) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
