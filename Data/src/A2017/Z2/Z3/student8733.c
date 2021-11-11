#include <stdio.h>

int main() {
	int i,j,AS,AV,BS,BV;
	int B[10][10];
	int A[10][10];
		int GD[10],SD[10];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&AS,&AV);

	printf("Unesite clanove matrice A: ");
	for(i=0;i<AV;i++){
		for(j=0;j<AS;j++){
			scanf("%d ",&A[i][j]);
	}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&BS,&BV);

	printf("Unesite clanove matrice B: ");
	for(i=0;i<BV;i++){
		for(j=0;j<BS;j++){
			scanf("%d ",&B[i][j]);
	}
	}
	for(i=0;i<AV;i++){
		for(j=0;j<AS;j++){
			if (i==j) GD[i]=A[i][j];
			if (i+j==AS-1) SD[i]=B[i][j]; 
		}
	}
	int suma=AS,suma1=0;
	for (i=0;i<AS;i++){
		if (GD[i]==SD[i]) suma1++;
	}
	if (suma==suma1) printf ("DA\n");
	else printf("NE\n");
	return 0;
}
