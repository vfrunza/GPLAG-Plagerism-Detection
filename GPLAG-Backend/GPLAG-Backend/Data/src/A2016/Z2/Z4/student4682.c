#include <stdio.h>
#include <math.h>
#define epsilon 0.00001

int main() {
	int i,j,m,n,teplicova=1,cirkularna=0;
	double mat[100][100];
	
	do {
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m>100 || n>100 || m<1 || n<1) 
	printf("Pogresan unos!\n");
	} while(m>100 || n>100 || m<1 || n<1);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
		scanf("%lf",&mat[i][j]);
		}
	}
	
  if(m==1){
  printf("Matrica je cirkularna");
  return 0;
  }
  if(n==1) {
  printf("Matrica je Teplicova");
  return 0;
  }
	for(i=0; i<m-1; i++) {
		for(j=0; j<n-1; j++) {
			if (fabs(mat[i][j]-mat[i+1][j+1])>epsilon)
			teplicova=0;
		}
	}
	
	if (teplicova)
	{
		cirkularna=1;
		for(i=0; i<m-1; i++) {
		
	

			if (fabs(mat[i][n-1]-mat[i+1][0])>epsilon)
			{
			cirkularna=0;
			}
	
	}
	}
	
	if(cirkularna) 
	printf("Matrica je cirkularna");
	else if(teplicova) 
	printf("Matrica je Teplicova");
	else 
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	return 0;
}
