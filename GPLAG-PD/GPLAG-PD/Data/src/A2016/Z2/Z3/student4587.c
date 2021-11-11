#include <stdio.h>
#define X 20
#define Y 20

int main() {
	char niz[X] [Y]={'m'};
	int k, i, m, n, j;
	printf("Unesite broj tacaka: ");
	scanf("%d", &k);
	while (k>10 || k<=0) {
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &k);
	}
	    for(i=0; i<k; i++) {
	    	printf("Unesite %d. tacku: ", i+1);
	    	scanf("%d %d", &m, &n);
	    	while (m>19 || n>19 || m<0 || n<0) {
	    		printf("Pogresan unos\n");
	    		printf("Unesite %d. tacku: ", i+1);
	    		scanf("%d %d", &m, &n);
	    	}
	    	   niz [m] [n] = '*';
	    }  
           for(j=0; j<X; j++) {
           	for(i=0; i<Y; i++) {
           		if(niz [i] [j] != '*')
           		printf(" ");
           		else printf("*");
        }
        printf("\n");
    }
	   
	
	return 0;
}