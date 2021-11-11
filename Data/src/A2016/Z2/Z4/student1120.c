#include <stdio.h>
#define v 100

int main() {
	int i,j,M,N,pretT,cirk;
	double mat[v][v];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M,&N);
	if(M<=0 || N<=0 || M>v|| N>v)
		printf("Pogresan unos!\n");
		
	}
		while(M<=0 || N<=0 || M>v || N>v);
		printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&mat[i][j]);
		}}
	pretT=1;
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]){
			pretT=0;}
			}}
			cirk=1;
		if(pretT==0)
			printf("Matrica nije ni cirkularna ni Teplicova");
		else{
			for(i=0;i<M-1;i++){
			if(mat[i+1][0]!=mat[i][N-1])
				cirk=0;
			}
			if(cirk==0)
				printf("Matrica je Teplicova");
				else printf("Matrica je cirkularna");
			}
	return 0;
		}
