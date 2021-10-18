#include <stdio.h>

int main() {
	int M=0, N=0, P=0, R=0, A[100][100], B[100][100],a[100][100], i=0, j=0, tacno=0;
	if (M<100 && N<100){
	printf("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &N, &M);
	}
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++){
		for(j=0; j<N; j++){
		scanf ("%d", &A[i][j]);
	}
	}
	
	if (P<100 && R<100){
		printf ("Unesite sirinu i visinu matrice B: ");
		scanf ("%d %d", &P, &R);
	}
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<R; i++){
		for (j=0; j<P; j++){
			scanf ("%d", &B[i][j]);
		}
	}
	
for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			a[j][M-1-i]=A[i][j];

	
	if (R==N && P==M)
	{
		for (i=0; i<R; i++){
			for (j=0; j<P; j++){
				if(a[i][j]!=B[i][j])
				{
					tacno=0;
					break;
				}
				else {
					tacno=1;
				}
			}
		}
	
	if(tacno==1)
	{
		printf ("DA\n");
	}
	else 
	{
		printf ("NE\n");
	}
	}
	else {
		printf("NE\n");
	}

	
	return 0;
}
