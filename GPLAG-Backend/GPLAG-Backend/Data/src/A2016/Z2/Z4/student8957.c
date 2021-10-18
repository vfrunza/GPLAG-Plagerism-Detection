#include <stdio.h>

int main() {
	double m[100][100];
	int i,j,tm=1,cm=1,M,N,k;
	
	do{
		printf ("Unesite M i N: ");
		scanf ("%d%d",&M,&N);
		if (M>100 || N>100 || M<=0 || N<=0) printf ("Pogresan unos!\n");
	} while(M>100 || N>100 || M<=0 || N<=0);
	
	printf ("Unesite elemente matrice: ");
	
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			scanf ("%lf",&m[i][j]);
		}
	}
	
	if (N==1 && M!=1) { tm=1; cm=0; }
	
	for (i=0;i<M-1;i++){
		for (j=0;j<N-1;j++){
			if (m[i][j]!=m[i+1][j+1]) { tm=0; break; }	
		}
	}
	
	for (i=0;i<M-1;i++){
		for (j=0;j<N-1;j++){
			if (m[i][N-1] != m[i+1][0]) {
				cm=0; 
				break;
			}
		}
	} 
	
	if (tm==1 && cm==0)  
		printf ("Matrica je Teplicova");
	else if (cm==1 && tm==1) 
		printf ("Matrica je cirkularna");
	else 
		printf ("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
