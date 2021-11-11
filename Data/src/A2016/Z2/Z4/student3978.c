#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	int M,N,i,j;
	int tep=1, cir=1;;
	double mat[100][100];
	do {
		printf("\nUnesite M i N: ");
		scanf ("%d %d", &M,&N);
		if (M<=0 || M>100 || N<=0 || N>100) printf ("Pogresan unos!");
	}
	while (M<=0 || M>100 || N<=0 || N>100 );
	
	printf ("Unesite elemente matrice: ");
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			
			scanf ("%lf", &mat [i][j]);
			
		}
	}
	
	
	for (i=0;i<M-1;i++){
		for (j=0;j<N-1;j++){
			
			if (fabs (mat[i][j]-mat[i+1][j+1])>epsilon )
                    tep=0;
		
		}
	}
	
		for (i=0;i<M-1;i++){
			if (fabs(mat[i][N-1]-mat[i+1][0]) ) 
					cir=0;
		
		
		}
	
	
		
	
	if (tep==1 && cir==0) printf ("Matrica je Teplicova");

	else if (cir==1 && tep==1) printf ("Matrica je cirkularna");
	else printf ("Matrica nije ni cirkularna ni Teplicova");
	return 0; 
}
