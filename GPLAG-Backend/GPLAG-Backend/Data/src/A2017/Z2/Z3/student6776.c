#include <stdio.h>
#include <math.h>
#define MAX 10

int main() {
	int a1, a2, b1, b2, i, j, t=1;
	double A[MAX][MAX], B[MAX][MAX], At[MAX][MAX], Atz[MAX][MAX];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a1, &a2);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<a2; i++){
		for(j=0; j<a1; j++){
			scanf("%lf", &A[i][j]);
		}
	}
	for(i=0; i<a1; i++){
		for(j=0; j<a2; j++){
			At[i][j]=A[j][i];
		}
	}
	for(i=0; i<a1; i++){
		for(j=0; j<a2; j++){
			Atz[i][j]=At[i][a2-1-j];
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &b1, &b2);
	printf("Unesite clanove matrice B: ");
	
	for(i=0; i<b2; i++){
		for(j=0; j<b1; j++){
			scanf("%lf", &B[i][j]);
		}
	}
	
	if(a1!=b2 || a2!=b1) printf("NE\n");
	else{
		for(i=0; i<a1; i++){
			for(j=0; j<a2; j++){
				if(fabs(Atz[i][j]-B[i][j])>0.000001) t=0;
			}
		}
		if(t==0) printf("NE\n");
		else printf("DA\n");
	}
	
	return 0;
}
