#include <stdio.h>

int main() {
	double mat [100][100];
	int m,n,i,j;
	double x;
	int pomocna1=1;
	int pomocna2=1;
	printf("Unesite M i N: ");
	scanf("%d" "%d" ,&m,&n);
	while(m<1||m>100||n<1||n>100){
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d" "%d" ,&m,&n);
	}

	printf("Unesite elemente matrice: ");
		for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&x);
			mat[i][j]=x;
		}
	}
		for (i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
		if(mat[i][n-1]!=mat[i+1][0]){
    		pomocna1=0;
    		break;
		}
		if(pomocna1==0)break;
		}
	}
		for (i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
		if(mat[i][j]!=mat[i+1][j+1]){
    		pomocna2=0;
    		break;
		}
		if(pomocna2==0)break;
		}
	}
	
	if(pomocna1==0&&pomocna2==1)printf("Matrica je Teplicova");
	if(pomocna2==0&&pomocna1==0)printf("Matrica nije ni cirkularna ni Teplicova");
	if(pomocna2==1&&pomocna1==1)printf("Matrica je cirkularna");
    
	
	return 0;
}
