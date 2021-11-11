#include <stdio.h>
#define br 100

int main() {
	int m,n,A[br][br],i,j,T,C;
	T=0;
	C=0;
	for (i=0;i<br;i++){
		for(j=0;j<br;j++){
			A[i][j]=0;
		}
	}
	do {
		printf("Unesite M i N: ");
		scanf ("%d %d", &m,&n);
		if (n<=0 || n>100 || m<=0 || m>100){
			printf("Pogresan unos!\n");
		}
	}while (n<=0 || n>100 || m<=0 || m>100);
//------------------------------------------------------------------------------
	printf("Unesite elemente matrice: ");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			scanf("%d", &A[i][j]);
		}
	}
//------------------------------------------------------------------------------
	for(i=0;i<m;i++){
		for (j=0;j<n;j++){
			if((i+1)<m && (j+1)<n){
				if(A[i][j]==A[i+1][j+1]){
					T=1;
				}else{
				T=0;
				goto end;
				}
			}
		}
	}
//------------------------------------------------------------------------------
	if(T==1){
		for(i=0;i<m;i++){
			if(i+1<m){
				if(A[i][n-1]==A[i+1][0]){
					C=1;
				}else{
				C=0;
				goto end;
				}
			}
		}	
	}
//------------------------------------------------------------------------------
	end: 
	if(n==1){
		T=1;
	}
	if(m==1){
		C=1;
	}
	if(C==1){
		printf("Matrica je cirkularna");
	}
	if(T==1 && C!=1){
		printf("Matrica je Teplicova");
	}
	if(T!=1 && C!=1){
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
