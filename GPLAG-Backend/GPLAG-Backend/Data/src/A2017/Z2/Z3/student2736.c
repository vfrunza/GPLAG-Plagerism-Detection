#include <stdio.h>

int main() {
	int m,n,p,q;
	int A[100][100],B[100][100],temp[100][100],temp2[100][100];
	int i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&q,&p);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<p;i++){                                           
		for(j=0;j<q;j++){                                       
			scanf("%d",&A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d",&m,&n);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&B[i][j]);
		}
	}
	for(i=0;i<q;i++){
		for(j=0;j<p;j++){
			temp[i][j]=A[j][i];
		}
	}
	
    	for(i=0;i<q;i++){
		for(j=0;j<p;j++){
		temp2[i][j]=temp[i][p-1-j];
		}
	}
	
	if(q!=n || p!=m){printf("NE\n"); return 0;}
	
	for(i=0;i<q;i++){
		for(j=0;j<p;j++){
			if(temp2[i][j]!=B[i][j]) {printf("NE\n"); return 0; }
		}
	}
	printf("DA\n");



	return 0;
}
