#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {
	int m,n,M,N,i,j;
	float A[10][10], B[10][10], C[10][10];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &n, &m);
	printf("Unesite clanove matrice A: ");
	for(i =0; i < m; i++) {
		for(j =0; j < n; j++) {
			scanf("%f", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &N, &M);
	printf("Unesite clanove matrice B: ");
	for(i =0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%f", &B[i][j]);
		}
	}
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			C[j][m-i-1] = A[i][j];
		}
	}
	
	if(m != N || n != M)
	{
		printf("NE");
		return 0;
	}
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			if(fabs(B[i][j] - C[i][j]) > eps)
			{
				printf("NE");
				return 0;
			}
	printf("DA");
	return 0;
}
