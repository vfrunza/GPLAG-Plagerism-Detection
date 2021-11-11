#include <stdio.h>
#include <math.h>
#define E 0.00001

int main() {
	int i=0,j=0,N=0,M=0,teplicova_mat=1,cirkularna_mat=1;
	double A[100][100]={{0}};
	do {
		printf("Unesite M i N: ");
		scanf("%d,%d",&M,&N);
		if(M>0 && M<=100 && N>0 && N<=100)
			break;
		printf("Pogresan unos!\n");
	} while(1);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++)
		scanf("%lf",&A[i][j]);
	}
	
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++)
			if(i+1<M && j+1<N && fabs(A[i][j]-A[i+1][j+1])>=E)
				teplicova_mat=0;
	}
	
	for(i=1;i<M;i++) {
		for(j=0;j<N;j++) {
			if(j==0 && fabs(A[i][j]!=A[i-1][j-1])>=E)
				cirkularna_mat=0;
			else if(j!=0 && fabs(A[i][j] != A[i-1][j-1])>=E)
				cirkularna_mat=0;
	}
	}
	if(cirkularna_mat)
		printf("Matrica je cirkularna");
	else if(teplicova_mat)
		printf("Matrica je Teplicova");
	else 
		printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
