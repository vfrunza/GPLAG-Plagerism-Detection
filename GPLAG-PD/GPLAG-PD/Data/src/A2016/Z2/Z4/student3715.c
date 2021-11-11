#include <stdio.h>
#include <math.h>
#define eps 0.00000001

int main() {
	int M=0,N=0,i=0,j=0,teplicova=1,cirkularna=1;
	double mat[100][100];
	do{
		greska1:
		printf("Unesite M i N: ");
	    scanf("%d %d", &M, &N);
	    if(M<1 || M>100 || N<1 || N>100){
	    	printf("Pogresan unos!\n");
	    	goto greska1;
		}else{
			goto nastavak;
		}
	}while((M<=100 && M>0) || (N<=100 && N>0));
	nastavak:
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}

    for(i=0; i < M-1; i++){
    	for(j=0;j< N-1; j++){
	        if(fabs(mat[i][j] - mat[i+1][j+1]) > eps)
	        {
		      teplicova=0;
		      break;
				
	        }
    	}
    }
    if(teplicova==1){
    	for(i=0; i < M-1; i++){
    	for(j=0;j< N-1; j++){
    		if(fabs(mat[i][N-1] - mat[i+1][0])> eps){
    			cirkularna=0;
    			break;
    		}
    	  }
    	  if(j<0){
    	  	cirkularna=0;
    	  	break;
    	  }
       }
       if(cirkularna==1){
       	printf("Matrica je cirkularna\n");
       }else{
       	printf("Matrica je Teplicova\n");
       }
    }else{
	     printf("Matrica nije ni cirkularna ni Teplicova");
    }
	return 0;
}
