#include <stdio.h>
#include <math.h>

int main() {
	double M[100][100]={0};
	int m, n, tepl=1, cirk=1, i, j;
	do{
		printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
		if(m<1 || m>100 || n<1 || n>100) 
		printf("Pogresan unos!\n");
		
	}while(m<1 || m>100 || n<1 || n>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf", &M[i][j]);
		}
	}
		if(n==1 && m==1 ){
			cirk=1;
			tepl=1;}
		else if(n==1){
			cirk=0; 
			tepl=1;}
		else if(m==1){
			cirk=1; 
			tepl=0;}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			
			if(M[i][j]!=M[i-1][j-1]) tepl=0;
			
			if(M[i][0]!=M[i-1][n-1] || M[i][j]!=M[i-1][j-1]) cirk=0;
		}
	}
	if (cirk==1) printf("Matrica je cirkularna");
   	else if (tepl==1) printf("Matrica je Teplicova");
   	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
