#include <stdio.h>

int main() {
    float mat[100][100]; 
    int M,N,i,j,br1=0,br2=0;
    
  printf("Unesite M i N: ");
         scanf("%d %d",&M,&N); 
         if(M<1 || M>100 || N<1 || N>100) {
    do {
         printf("Pogresan unos!\n") ;   
    	 printf("Unesite M i N: ");
         scanf("%d %d",&M,&N); 
    	} while(M<1 || M>100 || N<1 || N>100); }
    	 
    
    printf("Unesite elemente matrice: ");	
    for(i=0;i<M;i++) { 
        for(j=0;j<N;j++){ 
            scanf("%f",&mat[i][j]);
    } }
         
         if(M==2 && N==2) { 
             printf("Matrica nije ni cirkularna ni Teplicova");
             return 0; 
         }
         for(i=0;i<M-1;i++){
              if(mat[i][N-1]==mat[i+1][0]) br2++;
         	for(j=0;j<N-1;j++) {
         		if(mat[i][j]==mat[i+1][j+1]) br1++; 
         	    } }
         	    
         
         	
         	if(br1==(M-1)*(N-1) && br2==M-1) printf("Matrica je cirkularna");
         	else if(M==1 && N==1) printf("Matrica je cirkularna");
         	else if(M>1 && N==1) printf("Matrica je Teplicova");
         	else if(br1==(M-1)*(N-1)) printf("Matrica je Teplicova");
         	else printf("Matrica nije ni cirkularna ni Teplicova");
         
         
	return 0;
}
