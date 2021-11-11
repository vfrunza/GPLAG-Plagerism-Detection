#include <stdio.h>


int main(){
	
	double A[10][10],B[10][10],C[10][10];
	int i,j,n,m,p,r,pom,k,l,br=0;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%lf",&A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&p,&r);
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<r;i++){
		for(j=0;j<p;j++){
			scanf("%lf",&B[i][j]);
		}
	}
	
	
	if(n==p && m==r){
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			C[i][j]=A[j][i];
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n/2;j++){
			pom=C[i][j];
			C[i][j]=C[i][n-j-1];
			C[i][n-j-1]=pom;
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(C[i][j]==B[i][j]) br++;
		}
	}
	
	if(br==(m*n) && br==(r*p))printf("DA\n");
	else printf("NE\n");
	
	}
	else printf("NE\n");
	
	return 0;
}