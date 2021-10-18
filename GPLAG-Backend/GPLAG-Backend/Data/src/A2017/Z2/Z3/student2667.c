#include <stdio.h>

int main() {
	int i,j,br=0,A[100][100],B[100][100],k,l,m,n;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
		printf("Unesite clanove matrice A: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&k,&l);
		printf("Unesite clanove matrice B: ");
	for(i=0;i<l;i++){
		for(j=0;j<k;j++){
		
			scanf("%d", &B[i][j]);
		}
	}
	     
 if(n!=k || m!=l) {printf("NE"); return 0; }
	for(i=0;i<n;i++){
		for(j=0;j<l;j++){
			 if(A[i][j]==B[j][n-1-i])
			 br++;
			else {printf("NE");
			return 0;
		}
		}
	}
	if(br==m*n) printf("DA");
	
	else printf("NE");
	
	
	return 0;
}
