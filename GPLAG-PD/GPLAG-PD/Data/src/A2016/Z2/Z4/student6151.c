#include <stdio.h>

int main() {
	
		int m,n,i,j;
		int teplicova=1;
		
	do{
	printf("\nUnesite M i N: ");
	scanf("%d %d", &m, &n);
	if(m>100 || n>100 || m<=0 || n<=0) printf("Pogresan unos!");
	}
	while(m>100 || n>100 || m<=0 || n<=0);
	
	int niz[100][100];
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
	scanf("%d",&niz[i][j]);	
		}
		
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(niz[i][j]!=niz[i+1][j+1]){
			teplicova=0;
			 printf("Matrica nije ni cirkularna ni Teplicova");}
		}
	}
	
	
	
	/*	if(i==n-j)
		printf("\nMatrica je cirkularna");
		
		
		else printf("\nMatrica nije ni cirkularna ni Teplicova");
	}
	} */

	return 0;
}
