#include <stdio.h>
#include <math.h>
#define vel 101
#define eps 0.000000001

int main(){
	int M,N,i,j,l=1,k;
	float mat[vel][vel];
	do{
		printf("Unesite M i N: ");
		scanf("%d%d",&M,&N);
		if(M>100 || M<=0 || N>100 || N<=0)
			printf("Pogresan unos!\n");
	}while(M>100 || M<=0 || N>100 || N<=0);
	
	/* unos matrice */
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%f",&mat[i][j]);
		}
	}
    if(M<N || M==N){
    	for(i=0;i<=N-M;i++){
    		for(k=1;k<M;k++){
    			if(!(fabs(mat[0][i]-mat[k][k+i])<eps))
    				l=0;
    		}
    	}
    	if(l==1){
    		for(i=1;i<M;i++){
    			for(k=1;k<M-i;k++){
    				if(!(fabs(mat[i][0]-mat[i+k][k])<eps))
    					l=0;
    			}
    		}
    	}
    	if(l==1){
    		for(i=N-M+1;i<N;i++){
    			for(k=1;k<N-i;k++){
    				if(!(fabs(mat[0][i]-mat[k][k+i])<eps))
    					l=0;
    			}
    		}
    	}
    	if(l==0){
    		printf("Matrica nije ni cirkularna ni Teplicova");
    		return 0;
    	}
    	for(i=1;i<M;i++){
    		if(!(fabs(mat[i][0]-mat[0][N-i])<eps))
    			l=2;
    	}
    	if(l==2)
    		printf("Matrica je Teplicova");
    	else
    		printf("Matrica je cirkularna");
    }
    
    if(M>N){
    	for(i=0;i<M-N+1;i++){
    		for(k=1;k<N;k++){
    			if(!(fabs(mat[i][0]-mat[k+i][k])<eps))
    				l=0;
    		}
    	}
    	if(l==1){
    		for(i=M-N+1;i<M;i++){
    			for(k=1;k<M-i;k++){
    				if(!(fabs(mat[i][0]-mat[k+i][k])<eps))
    					l=0;
    			}
    		}
    	}
    	if(l==1){
    		for(i=1;i<N;i++){
    			for(k=1;k<N-i;k++){
    				if(!(fabs(mat[0][i]-mat[k][k+i])<eps))
    					l=0;
    			}
    		}
    	}
    	if(l==0){
    		printf("Matrica nije ni cirkularna ni Teplicova");
    		return 0;
    	}
    	for(i=1;i<M;i++){
    		if(i<=N){
    			if(!(fabs(mat[i][0]-mat[0][N-i])<eps))
    				l=2;
    		}
    		else if(l==1 && i>N){
    			if(!(fabs(mat[i][0]-mat[i-N][0])<eps))
    				l=2;
    		}
    	}
    	if(l==2)
    		printf("Matrica je Teplicova");
    	else
    		printf("Matrica je cirkularna");
    }
	
	return 0;
}