#include <stdio.h>
#include <math.h>
#define e 0.0001

int main() {
	int M,N,i,j,d=0,k=0;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || M>100 || N<1 || N>100)
		printf("Pogresan unos!\n");
	} while(M<1 || M>100 || N<1 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
	    scanf("%lf",&mat[i][j]);	
		}
	}
	if(M>1 && N>1){
	for(i=0;i<(M-1);i++){
		for(j=0;j<(N-1);j++){
			if(fabs(mat[i][j]-mat[i+1][j+1])>e || fabs(mat[i][N-1]-mat[i+1][0])>e){
			d++;
			i=M-1;
			j=N-1;
			}
		}
	}
	for(i=0;i<(M-1);i++){
		for(j=0;j<(N-1);j++){
			if(fabs(mat[i][j]-mat[i+1][j+1])>e){
			k++;
			i=M-1;
			j=M-1;
			}
		}
	}
	}
	else if(M==1 && N==1 || N>M)
	d=0;
	else if(M>N)
	d=1;
	if(d==0)
	printf("Matrica je cirkularna");
	else if(d==1 && k==0)
	printf("Matrica je Teplicova");
	else
	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
