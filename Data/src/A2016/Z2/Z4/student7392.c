#include <stdio.h>
#include <math.h>

#define eps 0.000001

int main() {
	int x, y;
	double a[110][110];
	int i, j;
	int g;
	do{
	    printf("Unesite M i N: ");
	    scanf("%d %d", &x, &y);
	    if(x<1 || x>100 || y<1 || y>100){
	        printf("Pogresan unos!\n");
	    }
	}while(x<1 || x>100 || y<1 || y>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<x;i++){
	    for(j=0;j<y;j++){
	        scanf("%lf", &a[i][j]);
	    }
	}
	for(i=0;i<x-1;i++){
	    for(j=0;j<y-1;j++){
	        if(fabs(a[i][j]-a[i+1][j+1])>eps){
	            printf("Matrica nije ni cirkularna ni Teplicova");
	            return 0;
	        }
	    }
	}
	for(j=0;j<y;j++){
	    g=j;
	    for(i=0;i<x;i++){
	        if(fabs(a[i][g]-a[0][j])>eps){
	            printf("Matrica je Teplicova");
	            return 0;
	        }
	        g++;
	        if(g==y)g=0;
	    }
	}
	printf("Matrica je cirkularna");
	return 0;
}
