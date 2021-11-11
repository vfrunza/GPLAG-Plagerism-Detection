#include <stdio.h>
#include <math.h>
#define DUZINA 20	

int main() {
	int mat[DUZINA][DUZINA] = {0}, i, j, k, m, d=0, a, b;
	printf("Unesite broj tacaka: ");
	scanf("%d", &d);
	if (d > 10 || d < 0) {
	    for (m=0;m<1000;m++) {
	    	printf("Pogresan unos\n");
	    	printf("Unesite broj tacaka: ");
	    	scanf("%d", &d);
	    	if (d>0 && d<11){
	    		break;
	    	}
	    }
	} 
		for (k=0;k<d;k++) {
		printf("Unesite %d. tacku: ", k+1);
		scanf("%d %d", &a, &b);
		if ((a <= -1  || a >= 20) || (b <= -1 || b >= 20)) {
			printf("Pogresan unos\n");
		k--;
		}
		for (i=0;i<20;i++) {
			for (j=0;j<20;j++) {
				if (b == i && a == j) {
				  mat[i][j] = 1;
				} 
			}
		}
	}
	    for (i=0;i<20;i++) {
	    	for (j=0;j<20;j++) {
	    		if (mat[i][j] != 0) {
	    			printf("*");
	    		} else {
	    			printf(" ");
	    		}
	    	}	
	    printf("\n");
	}
	return 0;
}