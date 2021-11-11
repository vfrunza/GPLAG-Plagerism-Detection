#include <stdio.h>

int main() {
	double mat[100][100];
	int i,j,m,n,c=1,t=1;
	do{
	printf("Unesite M i N: ");
	scanf("%d%d",&m,&n);
	if((n>100 || n<=0)||(m>100 || m<=0)){
		printf("Pogresan unos!\n");
	}
	}while(n>100 || n<=0 || m>100 || m<=0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
       for(i=0;i<m-1;i++){
       	for(j=0;j<n-1;j++){
       		if(mat[i][n-1]!=mat[i+1][0]){
       			c=0;
       			break;
       		}
       	}
       }
    	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]){
				t=0;
				break;
			}
		}
	}
	if(m>1 && n==1){
		printf("Matrica je Teplicova");
		return 0;
	}
	
	if(t==1){
		if(c==1){
			printf("Matrica je cirkularna");
		}
		else printf("Matrica je Teplicova");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
