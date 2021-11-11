#include <stdio.h>

int main() {
	
	char matrica[20][20];
	
	int i, j, n, p, q;
	
	
	for(i=0; i<20; i++) {
		
		for(j=0; j<20; j++) {
			
			matrica[i][j]=' ';
		}
		
    }
    
	
	do {
	
	printf("Unesite broj tacaka: ");
	
	scanf("%d", &n);
	
	if(n<=0 || n>10) printf("Pogresan unos\n");
	
	} while (n<=0 || n>10);
	
    
	i=0;
	
	do {
		
		printf("Unesite %d. tacku: ", i+1);
		
		scanf("%d %d", &p, &q);
		
		if(p<0 || p>19 || q<0 || q>19) {
			printf("Pogresan unos\n");
		}
		
		else {
		matrica[q][p]='*'; i++; }
		
	} while(i<n || p<0 || p>19 || q<0 || q>19);
	
	for(i=0; i<20; i++) {
		
		for(j=0; j<20; j++) {
			
			printf("%c", matrica[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
