#include <stdio.h>
#define NIZ 20
int main() {
	
	int n, i, j, k, X[NIZ], Y[NIZ], treba_li_ispisati;
	
	
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		
		if (n<1 || n>10)
			printf("Pogresan unos\n");
			
	} while (n<1 || n>10);
	
	for (i=0; i<n; i++) {
		
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &X[i],&Y[i]);
		
		
		if (X[i]<0 || X[i]>19 || Y[i]<0 || Y[i]>19) {
			printf("Pogresan unos\n");
			i--;
		}
	}
	
	for (i=0; i<20; i++) { 
		for(j=0; j<20; j++) {
			
	     	treba_li_ispisati=0;
		
			for (k=0; k<n; k++) {
				
				
				
				if (X[k]==j && Y[k]==i)
					treba_li_ispisati=1;
				
			}
			
			if (treba_li_ispisati)
				printf("*");
		    else 
		    	printf(" ");
				
		}
		printf("\n");
	}
	
	 return 0;
}
