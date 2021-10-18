#include <stdio.h>
#include <math.h>

int main() {
	int mat[100][100]={0}, m=0, n=0, i=0, j=0, a=0, b=1;
	do {
		printf("Unesite M i N: ");
		scanf("%d%d", &m, &n);
		if((m<1 || m>100) || (n<1 || n>100)){
			printf("Pogresan unos!\n");
		}
	} while((m<1 || m>100) || (n<1 || n>100));
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i!=0 && j!=0);{
				if(mat[i][j]==mat[i][j]-1){
					a++;
				}
			}
			if(i!=0 && j==0){
				if(mat[i][j]==mat[i][j]-1){
					a++;
				}
			}
		}
	}
	if(a==(m-1)*n){
		printf("Matrica je cirkularna");
		return 0;
	}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(mat[i][j] != mat[i][j]+1){
				b=0;
			}
		}
	}
	if(b==1){
		printf("Matrica je Teplicova");
	}
	if(b!=1){
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
