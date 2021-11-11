#include <stdio.h>
#include <math.h>
#define epsilon 0.00000000000001
int main() {
	int m,n,teplicova=1,cirkularna=1,i,j;
	double matrica[100][100];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0||m>100 || n<=0 || n>100) printf("Pogresan unos!\n");
	}while(m<=0||m>100 || n<=0 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&matrica[i][j]);
		}
	}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n;j++){
			if(j==n-1){
				if(fabs(matrica[i][j]-matrica[i+1][0])>epsilon) cirkularna=0;
			}else{ 
			if(fabs(matrica[i][j]-matrica[i+1][j+1])>epsilon) teplicova=0;
			}
		}
	}
	
	if(cirkularna && teplicova) printf("Matrica je cirkularna");
		else if(teplicova) printf("Matrica je Teplicova");
			else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
