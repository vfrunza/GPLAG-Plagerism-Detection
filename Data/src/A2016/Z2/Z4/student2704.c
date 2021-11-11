#include <stdio.h>

int main() {
	
	int m, n, a, b;
	double matrica[100][100];
	int tep=1, cirk=1;
	
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if((m<=0 || m>100) || (n<=0 || n>100)) {printf("Pogresan unos!\n");}
	}
	while(m<=0 || m>100 || n<=0 || n>100);
	
	printf("Unesite elemente matrice: "); 
	
	for(a=0; a<m; a++) {
		for(b=0; b<n; b++) {
			scanf("%lf",&matrica[a][b]);}}
	
	for(a=0; a<m-1;a++){
		for(b=0; b<n-1; b++){
			
			if(matrica[a][b]!=matrica[a+1][b+1]) {tep=0;}
			}
		}
	
	for(a=0;a<m-1;a++) {
		if(matrica[a][n-1]!=matrica[a+1][0]) cirk=0;
	}
	
	
	if(cirk && tep) {printf("Matrica je cirkularna");}
	else if(tep) {printf("Matrica je Teplicova");}
	else  {printf("Matrica nije ni cirkularna ni Teplicova");}
		
	return 0;
}
