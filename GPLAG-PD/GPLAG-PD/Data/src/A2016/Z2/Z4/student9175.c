#include <stdio.h>

int main() {
	int M,N,i,j;
	int mat[100][100];
	int t=1;
	int c=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M>100 || N>100 || M<0 || N<0)printf("Pogresan unos!\n");
	}while(M>100 || N>100 || M<0 || N<0);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1])t=0;
		}
	}
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][N-1-j]!=mat[i+1][0])c=0;
		}}
		
		if(t==1 && c==1){printf("Matrica je cirkularna");}
		else if(c==0 && t==1){printf("Matrica je Teplicova");}
		else{
			printf("Matrica nije ni cirkularna ni Teplicova");
			
		}
return 0;	}
	

