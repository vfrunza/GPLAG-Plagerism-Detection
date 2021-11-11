#include <stdio.h>

int main() {
	int M, N, mat[100][100]={0}, x, i, j, y;
	printf("Unesite M i N: ");
	do{
		scanf("%d %d", &M, &N);
		if(M>100 || M<1 || N>100 || N<1){
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");}
	} while(M>100 || M<1 || N>100 || N<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	x=1;
	y=1;
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
		if(mat[i+1][j+1]!=mat[i][j] || mat[i][N-1]!=mat[i+1][0]){
		x=0;
		break;}}}
		for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
		if(mat[i+1][j+1]!=mat[i][j]){
		y=0;
		break;}}}
		if(N==1 && M!=1)
		printf("Matrica je Teplicova");
		else if(x==1){
		printf("Matrica je cirkularna");}
		else if(y==1){
		printf("Matrica je Teplicova");}
		else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
