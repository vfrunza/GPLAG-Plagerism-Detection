#include <stdio.h>
int main() {
	int n1,m1,n2,m2,mat1[100][100],mat2[100][100],gr=0,i,j;
	
	printf("Unesite sirinu i visinu matrice A: ");
	do {
	scanf("%d%d",&n1,&m1);
	} while ((n1<0 || n1>100) || (m1<0 || m1>100));
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m1;i++){
		for(j=0;j<n1;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	do {
	scanf("%d%d",&n2,&m2);
	} while ((n2<0 || n2>100) || (m2<0 || m2>100));
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m2;i++){
		for(j=0;j<n2;j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	for(i=0;i<n1;i++){
		for(j=m1-1;j>=0;j--){
			if(mat1[j][i]!=mat2[i][n2-1-j]){
				gr++;
			}
		}
	}
	if(gr==0){
		printf("DA");
	}
	else {
		printf("NE");
	}
	return 0;
}
