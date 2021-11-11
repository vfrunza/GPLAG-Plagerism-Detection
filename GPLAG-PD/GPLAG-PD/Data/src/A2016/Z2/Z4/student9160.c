#include <stdio.h>

int main() {
	int M,N,i,j,teplicova=1,cirkularna=1;
	double mat[100][100];
	double suma[100]={0};
	/*format matrice*/
	do{
		printf("Unesite M i N: ");
		scanf("%d",&M);
		scanf("%d",&N);
		if(M<1 || N<1 || M>100 || N>100)printf("Pogresan unos!\n");
	}while(M<1 || N<1 || M>100 || N>100);
	/*unos elemenaa matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<M;i++){for(j=0;j<N;j++){scanf("%lf", &mat[i][j]);}}
	/*provjera vrste matrice matrice*/
	/*teplicova*/
	for(i=0; i<M-1;i++){for(j=0;j<N-1;j++){
	if(mat[i][j]!=mat[i+1][j+1])teplicova=0;}}
	/*cirkularna*/
	if(teplicova){for(i=0;i<M-1;i++){for(j=0;j<N-1;j++)suma[i]+=mat[i][j];}
	for(i=0;i<M-1;i++){if(suma[i]!=suma[i+1])cirkularna=0;}}
	
	if(cirkularna==1 && teplicova==1)printf("Matrica je cirkularna");
	else if(teplicova==1 && cirkularna==0)printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}