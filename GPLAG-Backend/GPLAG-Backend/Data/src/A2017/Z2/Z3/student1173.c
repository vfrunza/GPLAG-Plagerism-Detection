#include <stdio.h>

int main() {
	double A[100][100],B[100][100];
	int i,j,d1,d2,h1,h2;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&d1,&h1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<h1;i++){
		for(j=0;j<d1;j++){
			scanf("%lf",&A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&d2,&h2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<h2;i++){
		for(j=0;j<d2;j++){
			scanf("%lf",&B[i][j]);
		}
	}
	for(i=0;i<d1;i++){
		for(j=0;j<h1;j++){
		 if(B[i][j]!=A[h1-j-1][i]) {printf("NE\n");return 0;
		}
		else if(h1!=d2 || h2!=d1){printf("NE\n"); return 0;
	}

		}}
		printf("DA\n");
	return 0;
}
