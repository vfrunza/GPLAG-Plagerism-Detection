#include <stdio.h>

int main()
{
	int M,N;
		double mat[200][200];
	do {
		printf("Unesite M i N: ");
		scanf("%d",&M);
		scanf("%d",&N);
		if(!((M<=100&&M>0)&&(N<=100&&N>0))) {
			printf("Pogresan unos!\n");
		}
	} while(!((M<=100&&M>0)&&(N<=100&&N>0)));

	int i,j;
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) { 
		for(j=0; j<N; j++) {
			scanf("%lf",&mat[i][j]);
		}
	}


int br=1;
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
if(mat[i][j]==mat[i+1][j+1]){
	br=1;
}
else{
	br=0;
	break;
}
		}
		if(br==0)break;
	}
int x;
	
	if(br==1){
		x=1;
			for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
			if(mat[i][N-1]==mat[i+1][0]){
				x=1;
			}
			else{
				x=0;
				break;
			}
			
		}
		if(x==0)break;
			}
		
	}
	
if(N==1&&M!=1){
	x=0;
}
	if(br==1&&x!=1){
		printf("Matrica je Teplicova");
	}
	else if(br==1&&x==1){
		printf("Matrica je cirkularna");
	}else{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}

	return 0;
}
