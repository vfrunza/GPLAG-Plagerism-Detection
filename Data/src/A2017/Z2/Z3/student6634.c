#include <stdio.h>

int main() {
	double A[100][100],B[100][100],C[100][100],temp,n=0;
	int i,j,a,b,c,d;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a,&b);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<b; i++) {
		for(j=0; j<a; j++) {
			scanf("%lf", &A[i][j]);
			C[i][j]=A[i][j];
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &c,&d);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<d; i++) {
		for(j=0; j<c; j++) {
			scanf("%lf", &B[i][j]);
		}
	}
	for(i=0; i<b; i++) {
		for(j=i+1; j<a; j++) {
			temp=C[i][j];
			C[i][j]=C[j][i];
			C[j][i]=temp;
		}
	}
	for(i=0; i<b; i++) {
		for(j=0; j<(a/2); j++) {
			temp=C[i][j];
			C[i][j]=C[i][a-1-j];
			C[i][a-1-j]=temp;
		}
	}
	for(i=0; i<b; i++) {
		for(j=0; j<a; j++) {
			if(C[i][j]!=B[i][j]) {
				printf("NE");
				return 0;
			} else n=1;
		}
	}
	if(n==1) {
		printf("DA");
	}

	return 0;
}
