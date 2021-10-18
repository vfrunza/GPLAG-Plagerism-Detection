#include <stdio.h>

int main() {
	int M,N,A[100][100]= {{0}, {0}},B[100][100]= {{0}, {0}},C[100][100]= {{0}, {0}},A1[10000]={0},B1[10000]={0},C1[10000]={0},p,temp,t,i,j,a;
	t = 1;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf ("%d",&M);
		scanf ("%d",&N);
	} while ((M<0 || M >100) || (N<0 || N > 100));
	printf("Unesite clanove matrice A: ");
	for (i=0;i<M;i++) {
		for(j=0;j<N;j++){
			scanf ("%d",&a);
			A[i][j] = a;
		}
	}
	printf("Unesite clanove matrice B: ");
	for (i=0;i<M;i++) {
		for(j=0;j<N;j++){
			scanf ("%d",&a);
			B[i][j] = a;
		}
	}
	printf("Unesite clanove matrice C: ");
	for (i=0;i<M;i++) {
		for(j=0;j<N;j++){
			scanf ("%d",&a);
			C[i][j] = a;
		}
	}
	for (i = 0; i<M;i++) {
		for (j=0;j<N;j++) {
			A1[i*N + j] = A[i][j];
			B1[i*N + j] = B[i][j];
			C1[i*N + j] = C[i][j];
		}
	}

	for (i = 0; i < M*N - 1; i++) {
		p = i;
		for (j = i + 1;j<M*N;j++){
			if (A1[p] > A1[j]) {
				p = j;
			}
		}
			if (p != i){
				temp = A1[i];
				A1[i] = A1[p];
				A1[p] = temp;
			}
		
	}

	for (i = 0; i < M*N - 1; i++) {
		p = i;
		for (j = i + 1;j<M*N;j++){
			if (B1[p] > B1[j]) {
				p = j;
			}
		}
			if (p != i){
				temp = B1[i];
				B1[i] = B1[p];
				B1[p] = temp;
			
		}
	}
	for (i = 0; i < M*N - 1; i++) {
		p = i;
		for (j = i + 1;j<M*N;j++){
			if (C1[p] > C1[j]) {
				p = j;
			}
		}
			if (p != i){
				temp = C1[i];
				C1[i] = C1[p];
				C1[p] = temp;
			}
		
	}
	for (i = 0;i<M*N;i++){
		if ((A1[i] != B1[i]) || (A1[i] != C1[i])){
			t = 0;
		}
	}
	if (t == 1) {
		printf("DA"); 
	} else {
		printf ("NE");
	}
	return 0;
}
