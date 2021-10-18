#include <stdio.h>

int main() {
	
	 int A[101][101]={0},m=0,n=0,i=0,j=0,k=0,br=0,br1=0,B[200]={0};
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		
		if(m<=0 || m>100 || n<=0 || n>100){
			printf("Pogresan unos!\n");
			continue;
		} else break;
	}while(1);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		B[i]=A[0][i];
	}
	k=i-1;
	for(i=1;i<m;i++){
		B[k+i]=A[i][0];
	}
	
	for(k=0;k<m+n-1;k++){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(j-k-i==0 && k<n && A[i][j]!=B[k]){
					br=1;
				}
				if(k-i+j==n-1 && k>=n && A[i][j]!=B[k]){
					br=1;
				}
			}
		}
	}
	if(br==0){
		for(i=0;i<m-1;i++){
			if(A[i][n-1]!=A[i+1][0]){
				br1=1;
			}
		}
	}
	
	if(br==0 && br1==0){
		printf("Matrica je cirkularna");
	}
	if(br==0 && br1==1){
		printf("Matrica je Teplicova");
	}
	if(br==1) printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
