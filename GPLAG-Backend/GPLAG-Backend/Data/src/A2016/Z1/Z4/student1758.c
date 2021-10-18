#include <stdio.h>

int main() {
	int i, j, k, n;
	for(k=0;;k++) {
		printf("Unesite broj n: ");
		scanf("%d", &n);
		
		if(n<=0 || n>50) {
			printf("Pogresan unos\n");
			continue;
		} 
		else if(n==1) {
			printf("***");
		}
		else {
				for(i=0; i<n; i++) {
			for(j=0; j<=(n*4)-4; j++) {
				if(i==j) printf("*");
				else if((i+j)==(n*2)-2) printf("*");
				else if((j-i)==(n*2)-2) printf("*");
				else if((i+j)==((n*2)-2)*2) printf("*");
				else printf(" ");
			}
			printf("\n");
		} 
		} break;
	}
	
	return 0;
}
