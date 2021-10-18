#include <stdio.h>

int main() {
	int matA[100][100],matB[100][100],m,m1,n,n1;
	int i,j,rotirana_za_90;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&m1,&n1);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m1;i++){
		for(j=0;j<n1;j++){
			scanf("%d",&matB[i][j]);
		}
	}
	
	rotirana_za_90=1;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(matA[i][j] != matB[j][n1-i-1]){
				rotirana_za_90=0;
			}
		}
	}
	if(rotirana_za_90){
		printf("DA\n");
	}else{
		printf("NE\n");
	}
	return 0;
}
