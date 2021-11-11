#include <stdio.h>
#define visina 100
#define sirina 100

int main() {
	
	int	M,N,i=0,j=0,teplicova,cirkularna;
	float mat[visina][sirina];
			do { 
			printf ("Unesite M i N: ");
			scanf ("%d %d",&M,&N); 
			if (M>100 || M<0 || N>100 || N<0) 
				printf("Pogresan unos!\n");
				else break; 
	 	 } while (1);
	 
	printf("Unesite elemente matrice: ");
	for (i=0;i<(M*N);i++) {
			scanf("%f ",&mat[i][j]);
		}
	
			teplicova=0;
	for (i=0;i<(M-1);i++) {
		for (j=0;j<(N-1);j++){
			if(mat[i][j]!=mat[i+1][j+1]) 
			teplicova=1;
		}
	}
		
		cirkularna=0;
	for (i=0;M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1])
			cirkularna=1;
			if(mat[i][N-1]!=mat[i+1][0])
			cirkularna=1;
		}
	}
	if (cirkularna=1) printf ("Matrica je cirkularna");
	else if (teplicova=1) printf("Matrica je Teplicova");
	else if(cirkularna!=1 && teplicova!=1)
	printf("Matrica nije ni cirkularna ni Teplicova");

	
	return 0; 

}


