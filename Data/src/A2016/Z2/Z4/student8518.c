#include<stdio.h>
int main(){
	int M,N,i,j;
	double mat[101][101];
	

    do{
    	printf("Unesite M i N:");
    	scanf("%d %d",&M,&N);
    	if((M<=0 || M>100) || (N<=0 || N>100) ){
	printf(" Pogresan unos!\n");}
    } while((M<=0 || M>100) || (N<=0 || N>100));
    printf(" Unesite elemente matrice:");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%lf",&mat[i][j]);}}
            
              for(i=0;i<=M-2;i++){
                for(j=0;j<=N-2;j++){
                  if(mat[i][j]!=mat[i+1][j+1]){ 
                    printf(" Matrica nije ni cirkularna ni Teplicova");return 0; }}}
                        for(i=0;i<=M-2;i++){
                             
                                if(mat[i][N-1]!=mat[i+1][0]){
                                    printf(" Matrica je Teplicova");return 0;}}
                            
                                        printf(" Matrica je cirkularna");
                    return 0;}
        
    
            
                        
                          
	
