#include <stdio.h>

int main() {
	int count=0, i, j, m, n;
	double a[100][100];
	do {
	    printf("Unesite M i N: ");
	    scanf("%d %d", &m, &n);
	    if(m>100||n>100||m<1||n<1) {
	        printf("Pogresan unos!\n");
	    }
	} while(m>100||n>100||m<1||n<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
	    for(j=0; j<n; j++) {
	        scanf("%lf", &a[i][j]);
	    }
	}
	if(m==1) {
		printf("Matrica je cirkularna");
		return 0;
	}
	for(i=0; i<m-1; i++) {
	    for(j=0; j<n-1; j++) {
	        if(a[i][j]!=a[i+1][j+1]) {
	            count=1;
	            break;
	        }
	    }
	    if(count) {
	        printf("Matrica nije ni cirkularna ni Teplicova");
	        return 0;
	    }
	}
	for(i=0; i<m-1; i++) {
	    if(a[i][n-1]!=a[i+1][0]) {
	        printf("Matrica je Teplicova");
	        return 0;
	    }
	}
	printf("Matrica je cirkularna");
	return 0;
}
