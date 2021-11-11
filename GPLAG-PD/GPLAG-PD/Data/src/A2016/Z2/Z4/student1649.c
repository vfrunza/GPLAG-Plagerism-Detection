#include <stdio.h>

int main() {
	int M=0, N=0, i, j, C=1, T=1;
	double a[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if((M<1)||(M>100)||(N<1)||(N>100)){
			printf("Pogresan unos!\n");
			M=0;
			N=0;
		}
	}while(M==0 && N==0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			scanf("%lf", &a[i][j]);
	for(i=0;i<(M-1);i++)
		for(j=0;j<(N-1);j++)
			if(a[i][j]!=a[i+1][j+1] || a[i][N-1]!=a[i+1][0]){
				C=0;
				i=j=101;
			}
	if(C==0)
		for(i=0;i<(M-1);i++)
			for(j=0;j<(N-1);j++)
				if(a[i][j]!=a[i+1][j+1]){
							T=0;
							i=j=101;
						}
	if(N==1 && M!=1){
		T=1;
		C=0;
	}
	if(M==1 && N!=1){
		C=1;
		T=1;
	}
	if(C) printf("Matrica je cirkularna");
		else if(T) printf("Matrica je Teplicova");
			else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}