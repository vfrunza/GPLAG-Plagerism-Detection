#include <stdio.h>

int main() {
	int i,j,AS,AV,BS,BV;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&AS,&AV);
	int A[10][10];
	printf("Unesite clanove matrice A: ");
	for(i=0;i<AV;i++){
		for(j=0;j<AS;j++){
			scanf("%d ",&A[i][j]);
	}
	printf("\n");
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&BS,&BV);
	int B[10][10];
	printf("Unesite clanove matrice B: ");
	for(i=0;i<BV;i++){
		for(j=0;j<BS;j++){
			scanf("%d ",&B[i][j]);
	}
	printf("\n");
	}
	int GD[10],SD[10];
	for(i=0;i<AS;i++){
		for(j=0;j<AV;j++){
			if (i==j) GD[i]=A[i][j];
			if (i+j==AS-1) SD[i]=B[i][j]; 
		}
	}
	for (i=0;i<AS;i++){
		if (GD[i]==SD[i]) printf ("DA");
		else printf ("NE");
	}
	return 0;
}
