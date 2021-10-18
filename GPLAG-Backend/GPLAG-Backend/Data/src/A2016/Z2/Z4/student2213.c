#include <stdio.h>
#include <stdlib.h>
#define EPSILON 0.000001
int main() {
	int M,N,i,j,br=0;
	double mat[100][100];
do{
	printf("Unesite M i N: ");
	scanf("%d",&M);
	scanf("%d",&N);
	if(M>100 || M<1 || N<1 || N>100) 
		printf("Pogresan unos!\n");
}     while(M>100 || M<1 || N<1 || N>100);

printf("Unesite elemente matrice: ");
for(i=0;i<M;i++)
	for(j=0;j<N;j++)
     	scanf("%lf", &mat[i][j]);
for(i=0;i<M-1;i++){
for(j=0;j<N-1;j++){
		if(abs(mat[i][j]-mat[i+1][j+1])>EPSILON){
			br++;    
			break; 
		}
	}
	if(br!=0)
	break;                      
		}
		if(br==0){	
			for(i=0;i<M-1;i++)  {
					if(abs(mat[i][N-1]-mat[i+1][0])>EPSILON){
						br++;
						break;              
					}
			} 
    	if(br==0)
			printf("Matrica je cirkularna");
    	else
			printf("Matrica je Teplicova");
		}
 else 
		printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
