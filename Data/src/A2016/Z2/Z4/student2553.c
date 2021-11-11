#include <stdio.h>

int main() {
	int m,n,i,j,cirkularna=1,teplicova=1;
	double mat[100][100]={0};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || n<1 || m>100 || n>100){
			printf("Pogresan unos!\n");
		}
	}while(m<1 || n<1 || m>100 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	if(n==1 && m==1 ){cirkularna=1;teplicova=1;}
	else if(n==1){cirkularna=0; teplicova=1;}
	else if(m==1){cirkularna=1; teplicova=0;}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(mat[i][0]!=mat[i-1][n-1] || mat[i][j]!=mat[i-1][j-1]){
				cirkularna=0;
			}
			
			if(mat[i][j]!=mat[i-1][j-1] || mat[i][j]!=mat[i-1][j-1]){
				teplicova=0;
			}
		}
	}
	if(cirkularna==1){printf("Matrica je cirkularna");}
	else if(teplicova==1){printf("Matrica je Teplicova");}
	else {printf("Matrica nije ni cirkularna ni Teplicova");}
	
	return 0;
}
