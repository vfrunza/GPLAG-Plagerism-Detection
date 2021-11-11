#include <stdio.h>
#define BROJ_EL 100

int main() {
	int M,N,i,j,Teplicova_matrica,Cirkularna_matrica;
	double mat[BROJ_EL][BROJ_EL];
	do {
		printf ("Unesite M i N: ");
		scanf ("%d %d",&M,&N);
		if (M>100 || N>100 || M<=0 || N<=0)  { 
			printf ("Pogresan unos!\n"); 
				}
		} while (M>100 || N>100 || M<=0 || N<=0);
		
		printf ("Unesite elemente matrice: ");
		for (i=0;i<M;i++) {
			for (j=0;j<N;j++) {
				scanf ("%lf",&mat[i][j]);
			}
		}
		
		Teplicova_matrica = 1;
		for (i=0;i<M-1;i++) {
			for (j=0;j<N-1;j++) {
				if (mat[i][j]!=mat[i+1][j+1]) { 
					Teplicova_matrica=0; 
					break; 
					
				}
			}
		}
		
		if (Teplicova_matrica) {
		
			Cirkularna_matrica = 1;
			for (i=0;i<M-1;i++) {
				for (j=N-1;j<N;j++) {
					if (mat[i][N-1]!=mat[i+1][0]) { 
						Cirkularna_matrica=0; 
						break; 
						
					}
				}
			}
			if (Cirkularna_matrica) printf ("Matrica je cirkularna");
			else printf ("Matrica je Teplicova");
		}
	else printf ("Matrica nije ni cirkularna ni Teplicova");
	
		return 0;
		}