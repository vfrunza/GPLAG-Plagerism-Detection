#include <stdio.h>
#include <stdlib.h>
#define NULAA 0
#define DO 100
int main() {
double mat[DO][DO];
int M,N,m,n;

do{
	
	printf("Unesite M i N: ");
	scanf("%d %d", &M,&N);
	if(M>DO || M<=NULAA || N>DO || N<=NULAA) printf("Pogresan unos!\n");
}
	while (M>100 ||   M<=0 ||  N>100 ||  N<=0);
	
printf("Unesite elemente matrice: ");
for(m=NULAA;m<M;m++)
	{
		for(n=NULAA;n<N;n++)
		{			scanf("%lf", &mat[m][n]);}	}
		
	if(M==1) {printf("Matrica je cirkularna"); return 0;}	
		
	for(m=1;m<M;m++)
	{
		for(n=1;n<N;n++)
		{
			if(mat[m][n]!=mat[m-1][n-1]) {printf("Matrica nije ni cirkularna ni Teplicova"); return 0;}
		}
		
	}
		
		if(mat[NULAA][N-1]==mat[1][NULAA] && mat[M-1][NULAA]==mat[M-2][N-1]) printf("Matrica je cirkularna"); 
	else printf("Matrica je Teplicova");
	
		return 0;
}
