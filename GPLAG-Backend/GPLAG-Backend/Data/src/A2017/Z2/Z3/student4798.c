#include <stdio.h>

int main() {
	double A[100][100], B[100][100];
	int i,j,m,n,p,r;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &n,&m);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf", &A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&r,&p);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			scanf("%lf",&B[i][j]);
		}
	}
	
	if (m==r && n==p){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if (A[i][j]!=B[j][m-i-1]){
					printf("NE\n");
					return 0;
				}
			}
		}
	}
	else {
		printf("NE\n");
		return 0;
	}
		
	printf("DA\n");
	return 0;
}
