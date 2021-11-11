#include <stdio.h>
#define m 200
#define n 200

int main() {
	int A[m][n];
	int M, N, i, j, k, x, y;
do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<0||N<0||M>200||N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<0||N<0||M>200||N>200);
		printf("Unesite elemente matrice: ");
		for(i=0;i<M;i++) {
			for(j=0;j<N;j++) {
					scanf("%d",&A[i][j]);
				
			}
		}
	/*petlja za provjeru*/
	for(i=0; i<M; i++){
		for(j=i+1; j<M; j++){
			int t=1;
			for(k=0; k<N; k++){
				if((A[i][k]) != (A[j][k])){
		t=0;
		break;}
	}
	if (t==1){
		for(x=j+1; x<M; x++){
			for(y=0; y<N; y++){
				A[x-1][y]=A[x][y];
				M--;
				j--;
	}}}}}
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
		int	t=1;
			for(k=0; k<M; k++){
				if(A[k][i]!=A[k][j]){
			t=0;
			break;
		}
	}
	if(t==1){
		for(x=j+1; x<N; x++){
			for(y=0; y<M; y++){
				A[y][x-1]=A[y][x];
				N--;
				j--;
}}}}}
	/*petlja za ispis*/
printf("Nakon izbacivanja kolona/redova matrica glasi: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d", A[i][j]);
		}
			printf("\n");
	}
	return 0;
}