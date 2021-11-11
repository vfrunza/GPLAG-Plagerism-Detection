#include <stdio.h>
#include <math.h>
int main() {
	double mat[100][100];
	int i,j,M,N,cirk,tep;
	printf("Unesite M i N: ");
	do{
	
		scanf("%d %d",&M,&N);
		if(M<=0||N<=0||N>100||M>100){
			printf("Pogresan unos!");
		    printf("\nUnesite M i N: ");
		}
	}
	while(M<0||N<0||N>100||M>100);
	printf("Unesite elemente matrice:");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	tep=1;
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]){
				tep=0;
				break;
			}
		}}
	cirk=1;
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]||mat[i][N-1]!=mat[i+1][0]){
				cirk=0;
				break;
			}
		}
	}
	if(tep==1&&cirk==0) printf(" Matrica je Teplicova");
	else if(tep==1&&cirk==1) printf(" Matrica je cirkularna");
	else printf(" Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
