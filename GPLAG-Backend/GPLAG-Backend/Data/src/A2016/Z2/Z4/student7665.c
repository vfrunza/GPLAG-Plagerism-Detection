#include <stdio.h>
#define BROJ 100
int main() {
	int m,n,i,j, Teplicova_matrica, Cirkularna_matrica;
	double niz[BROJ][BROJ];
   
	do{
		printf("Unesite M i N: "); scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || m>BROJ || n>BROJ){
		printf("Pogresan unos!\n");
		}
		
	}while(m<=0 || n<=0 || m>BROJ || n>BROJ);
	
	printf("Unesite elemente matrice: ");
	
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf", &niz[i][j]);
		}
	}
			Teplicova_matrica=1;
			for(i=1; i<m; i++){
				for(j=1; j<n; j++){
					
					if(niz[i][j]!=niz[i-1][j-1]){
					Teplicova_matrica=0;
					Cirkularna_matrica=0;
					}
				}
			}
			
			if(Teplicova_matrica==1){
				Cirkularna_matrica=1;
				for(i=1; i<m; i++){
					
						if(niz[i][0]!=niz[i-1][n-1])
						Cirkularna_matrica=0;
					
					
				}
			}
			
				if(Teplicova_matrica==1 && Cirkularna_matrica==0){
					 printf("Matrica je Teplicova\n");
				}
				else if(Cirkularna_matrica==1 && Teplicova_matrica==1) {
					printf("Matrica je cirkularna\n");
				}
				else if(Teplicova_matrica==0 && Cirkularna_matrica==0){
					printf("Matrica nije ni cirkularna ni Teplicova\n");
				}
				return 0;
			}



