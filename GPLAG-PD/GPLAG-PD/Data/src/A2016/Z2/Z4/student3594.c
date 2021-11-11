#include <stdio.h>

int main() {
	
	int M, N, i, j;
	double matrica[100][100];
	
	int a=1,b=1;
	
	for(i=0; ; i++){
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		
		if((M<=0 || M>100) || (N<=0 || N>100)) {
			printf("Pogresan unos!\n");
			i--;
		}
		else break;
	}
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++){
		
		for(j=0; j<N; j++){
			scanf("%lf", &matrica[i][j]);
	    }
		
	}
	
    if(M==1){
     printf("Matrica je cirkularna");
    return 0;
    }
    
	else if (N==1){ 
	printf("Matrica je Teplicova"); 
	return 0;
	}
	
	
	else {
	
	for(i=0; i<M-1; i++){
		
		for(j=0; j<N-1; j++){
			
			  if(matrica[i][j]!=matrica[i+1][j+1]) a=0;
			  
		      if((matrica[i][j]!=matrica[i+1][j+1]) || (matrica[i][N-1]!=matrica[i+1][0])) b=0;
		    
     	}
    }
}


if(a==1 && b==0){
	printf("Matrica je Teplicova");
}

else if(a==0 && b==0) {
	printf("Matrica nije ni cirkularna ni Teplicova");
}

else if(b==1 && (a==0 || a==1)) {
	printf("Matrica je cirkularna");
}

	return 0;
}
