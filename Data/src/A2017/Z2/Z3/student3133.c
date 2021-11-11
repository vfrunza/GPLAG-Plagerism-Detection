#include <stdio.h>
#include <math.h>


int main() {
	int i,j,m1=0,n1=0,m2=0,n2=0,x=0,A[100][100]={{0}},B[100][100]={{0}},k=0,l=0;
		printf("Unesite sirinu i visinu matrice A: ");
		scanf("%d %d",&m1,&n1);
		printf("Unesite clanove matrice A: ");
		for(i=0;i<m1;++i){
			for(j=0;j<n1;++j){
					scanf("%d",&A[i][j]);
			}
		}
		printf("Unesite sirinu i visinu matrice B: ");
		scanf("%d %d",&m2,&n2);
		printf("Unesite clanove matrice B: ");
				for(i=0;i<m2;++i){
			for(j=0;j<n2;++j){
					scanf("%d",&B[i][j]);
			}
		}
	if(m1==m2&&n1==n2){
	for(i=0;i<m2;++i){
		for(j=0;j<n2;++j){
			if(A[j][i]!=B[i][n2-j-1]){
				printf("NE\n");
				return 0;}
		}
	}
}
	else{
		for(i=0;i<n1;++i){
			for(j=0;j<m1;++j){
			if(A[j][i]!=B[i][m1-j]){
				printf("NE\n");
				return 0;}
		}
		
	}
}
	printf("DA\n");
	return 0;
}
