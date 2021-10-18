#include <stdio.h>
#include <math.h>
#define BROJ_EL 101
#define epsilon 0.000001
int main() {
	int M,N,i,j,tepl=0,cirk=0;
	double mat[BROJ_EL][BROJ_EL]={{0}};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M<=0 || M>100 || N<=0 || N>100)
		printf("Pogresan unos!\n");
	}while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++)
		scanf("%lf",&mat[i][j]);
	}
	tepl=1;
	for(i = 0; i < (M-1); i++){
		for(j = 0; j < (N-1); j++){
			if(fabs(mat[i][j]-mat[i+1][j+1])>epsilon)
				tepl=0;
		}
	}
	
	if(tepl==1){
		cirk=1;
		for(i = 0; i < (M-1); i++){
			for(j = 0; j <N; j++){
				if(fabs(mat[i][N-1]-mat[i+1][0])>epsilon)
				cirk=0;
			}
		}
	}
	if(cirk==1 && tepl==1)
	printf("Matrica je cirkularna");
	else if(tepl==1 && cirk==0)
	printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
