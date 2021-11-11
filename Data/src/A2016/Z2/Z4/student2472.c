#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100
#define granica 0.00000001

int main() {
	int i, j, u=0, m, n, provjera=0, T=0;
	double mat[max][max];
	do{
	if(u>0){printf(" Pogresan unos!\n");}
	printf("Unesite M i N:");
	scanf("%d %d", &m, &n);
	u++;
	}while(m>100 || m<=0 || n>100 || n<=0);
	
	printf(" Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(fabs(mat[i][j]-mat[i+1][j+1])>granica){provjera++;}
		}
	}
	if(provjera>0){printf("Matrica nije ni cirkularna ni Teplicova"); return 0;}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n;j++){
			if(m==1)break;
			if(fabs(mat[i][n-1]-mat[i+1][0])>granica){T++; printf("Matrica je Teplicova"); return 0;}
			
			
		}
	}

	if(T==0 || m==1){printf("Matrica je cirkularna");}

	return 0;
}
