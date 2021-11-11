#include <stdio.h>

int main() {
	int i,j,M=0,N=0,cirk=0,NE=0;
    float mat[100][100]={0.0},suma1[100]={0.0},prva=0.0;
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	if(M>100 || M<=0 || N>100 || N<=0){
	do{
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
    	scanf("%d %d",&M,&N);
	}while(M>100 || M<0 || N>100 || N<0);}
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		
		for(j=0;j<N;j++){
			scanf("%d",&mat[i][j]);
			suma1[i]=suma1[i]+mat[i][j];
		}
//	printf("%d\n",suma1[0]);
   
  // printf("%d",prva);
	}
	prva=suma1[0];
	for(i=0;i<M;i++){
		if(prva!=suma1[i]){
				NE++;
			
		}
	
	
		 if(prva==suma1[i] && mat[i][0]!=mat[i+1][0]){
	    cirk++;
	    }
        }
	
     if(cirk==M){
	 printf("Matrica je cirkularna");
     return 0;}
	 else if(NE>0){
	 	for(i=0;i<M-1;i++){
	    for(j=0;j<N-1;j++){
	 if(mat[i][j]!=mat[i+1][j+1]){
	 	printf("Matrica nije ni cirkularna ni Teplicova");
	 	return 0;}
	 }}}
	  else{
	    printf("Matrica je cirkularna");
	return 0;}
	    printf("Matrica je Teplicova");
	//    

	return 0;
}
 