#include <stdio.h>
#define duzina 100
int main() {
	int M, N, i, j, provjera, provjera2;
	double mat[duzina][duzina];
	do{
		printf("Unesite M i N: ");
		scanf ("%d %d", &M, &N);
		if (M<=0 || M>100 || N<=0 || N>100)
		printf ("Pogresan unos!\n");
		
	}while (M<=0 || M>100|| N<=0 || N>100);
	
	printf ("Unesite elemente matrice: ");
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			scanf ("%lf", &mat[i][j]);
		}
	}
	if (M==1) {printf("Matrica je cirkularna");return 0;}
	if (N==1) {printf("Matrica je Teplicova");return 0;}
	
	provjera=0; provjera2=0;
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if (mat[i][j]!=mat[i+1][j+1]){
			provjera2=1; break;
			}
			if (mat[i][j]!=mat[i+1][j+1] || mat[i][N-1]!=mat[i+1][0])
			provjera=1;

		}
	}
	if (provjera==0 && provjera2==0)printf("Matrica je cirkularna");
	if (provjera2==0 && provjera==1)printf("Matrica je Teplicova");
	if (provjera2==1)printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
