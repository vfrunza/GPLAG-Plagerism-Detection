#include <stdio.h>
#define vel 100

int main() {
	int m, n, i,j, t, d;
	double a[vel][vel];
		do {
	printf("Unesite M i N: ");
	scanf("%d %d",&m, &n);
	if(m<=0 || n<=0  || m>vel || n>vel) printf("Pogresan unos!\n");}
	while(m<=0 || n<=0  || m>vel || n>vel);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf", &a[i][j]);
				}}
	t=1;
		for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if(a[i][j]!=a[i+1][j+1]) {t=0;}
					}}
	d=1;
			if(t==0) printf ("Matrica nije ni cirkularna ni Teplicova");
			else{
				for(i=0;i<m-1;i++){
					
			if(a[i+1][0]!=a[i][n-1]) d=0;
			
				}
			
			if(d==0) printf("Matrica je Teplicova");
			else printf ("Matrica je cirkularna");}
			
	
	return 0;
}