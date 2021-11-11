#include <stdio.h>
#include <math.h>
#define RED 101
#define KOL 101

int main() {
	int  m,n, greska=0, i, j, c=1, t=1;
	double matrica[RED][KOL];
	
	do{
		if(greska != 0) printf ("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		
		greska++;
		
	}
	while (m<1 || m>100 || n<1 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
		scanf("%lf", &matrica[i][j]);
		}
	}

	
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
		if(matrica[i][n-1] != matrica [i+1][0]){
		 c=0;
		}
		}}
		
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
		if(matrica [i][j] != matrica[i+1][j+1]){
		 t=0;
		}
		}}
	
	if(m==1&&n==1)printf("Matrica je cirkularna");
	else if(n==1)printf ("Matrica je Teplicova");
	
	else{
	
	if (t==0) printf("Matrica nije ni cirkularna ni Teplicova");
	else if (c==1 && t==1) printf ("Matrica je cirkularna");
	else printf("Matrica je Teplicova");
	}
	
	
	return 0;
}
