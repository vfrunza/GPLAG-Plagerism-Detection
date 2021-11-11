#include <stdio.h>

int main() {
	int m,n,i,j,c=1,t=1;
	double matrica[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m<=0 || m>100 || n<=0 || n>100) printf("Pogresan unos!\n");
	}while((m<=0 || m>100) || (n>100 || n<=0));
	printf("Unesite elemente matrice: ");
	for(i=0; i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf", &matrica[i][j]);
		}
	}
	c=1;
	t=1;
	if(n==1 && m>1) c=0;
	else{
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(matrica[i][n-1]!=matrica[i+1][0]) {
				c=0;
			}
			if(matrica[i][j]!=matrica[i+1][j+1]){
				t=0;
				c=0;
			}
			if(m<=2 && n<=2 && matrica[i][1]!=matrica[i+1][0]) c=0; 
			}
		}
	}
	
	if(c==1 && t==1) printf("Matrica je cirkularna");
	else if(t==1 && c==0) printf("Matrica je Teplicova");
	else if(c==0 && t==0) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
