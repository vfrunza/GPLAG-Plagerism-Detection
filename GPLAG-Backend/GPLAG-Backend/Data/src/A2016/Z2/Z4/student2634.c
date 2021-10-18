#include <stdio.h>
#include <math.h>
#define epsilon 0.00001

int main() {
	double matrica[100][100];
	int i=0,j=0,M,N,x,z,cirkularna=1,teplicova=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || M>=101 || N<1 || N>=101) printf("Pogresan unos!\n");
	}while(M<1 || M>=101 || N<1 || N>=101);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;) {
		for(j=0;j<N;) {
			scanf("%lf",&matrica[i][j]);
			j++;
		}
		i++;
	}
	
	if(M>=2 && N==1) {
		printf("Matrica je Teplicova");
		return 0;
	}
	
	for(x=0;x<M-1;x++) {
		for(z=0;z<N-1;z++) {
		if(fabs(matrica[x][z]-matrica[x+1][z+1])>epsilon) {
			printf("Matrica nije ni cirkularna ni Teplicova");
			return 0;
			}
		}
		if(fabs(matrica[x][N-1]-matrica[x+1][0])>epsilon) cirkularna=0;
	}
	
	if(cirkularna) printf("Matrica je cirkularna");
	else printf("Matrica je Teplicova");
	return 0;
}
