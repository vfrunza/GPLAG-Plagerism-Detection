#include <stdio.h>
#include <math.h>
#define epsilon 0.0005
int provjeriDijagonalu(double matrica[100][100], int M, int N, int X, int Y){
	int i,j;
	for(i=X, j=Y; i<M && j<N; i++, j++) {
		if(fabs(matrica[i][j]-matrica[X][Y])> epsilon)
			return 0;
	}
	return 1;
}
int provjeriCirkularnu(double matrica[100][100], int M, int N){
	int i, j, k;
	double a;
	for(i=0; i<M; i++) {
		for(j=0; j<i; j++) {
			for(k=0; k<N-1; k++) {
				a= matrica[i][k];
				matrica[i][k]=matrica[i][k+1];
				matrica[i][k+1]=a;
			}
		}
	}
	for(j=0; j<N; j++) {
		for(i=0; i<M; i++) {
			if(fabs(matrica[i][j]-matrica[0][j])>epsilon)
				return 1;
		}
	}
	return 2;
}
int provjeriTeplicovu(double matrica[100][100], int M, int N){
	int i, j=0;
	for(i=0; i<M; i++) {
		if(provjeriDijagonalu(matrica, M, N, i, j)==0)
			return 0;
	}
	for(i=0; i<N; i++) {
		if(provjeriDijagonalu(matrica, M, N, j, i)==0)
			return 0;
	}
	return provjeriCirkularnu(matrica, M, N);
}
int main(){
//	printf("Zadaća 2, Zadatak 4");
	int i,j,M,N;
	double matrica[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d%d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100)
			printf("Pogresan unos!\n");
	} while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &matrica[i][j]);
		}
	}
	switch(provjeriTeplicovu(matrica, M, N)) {
	case 0:
		printf("Matrica nije ni cirkularna ni Teplicova");
		break;
	case 1:
		printf("Matrica je Teplicova");
		break;
	case 2:
		printf("Matrica je cirkularna");
		break;
	}
	return 0;
}
