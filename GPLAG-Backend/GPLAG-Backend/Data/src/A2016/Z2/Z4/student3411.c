#include <stdio.h>
#include <math.h>
#define duzina 100
int main() {
	int m, n, i, j, t=1, c=1;
	double a[duzina][duzina], e=0.00000001;
	do{
		printf("Unesite M i N: ");
		scanf("%d", &m);
		scanf("%d", &n);
		if(m<1 || m>100 || n<1 || n>100) printf("Pogresan unos!\n");
	}while(m<1 || m>100 || n<1 || n>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf", &a[i][j]);
		}
	}
	if(n>=2){
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if(fabs(a[i][j]-a[i+1][j+1])>e || fabs(a[i][n-1]-a[i+1][0])>e){c=0;break;}
		}
		if(c==0) break;
	}	
	}
	if(n<2) {
		if(m==n) c=1;
		if(m!=n) c=0;
		
	}
		for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if(fabs(a[i][j]-a[i+1][j+1])>e ){t=0;break;}
		}
		if(t==0) break;
	}
	if(c==1) printf("Matrica je cirkularna");
	else if(t==1) printf("Matrica je Teplicova");
	else if(t==0) printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
