#include <stdio.h>

int main() {
	int M,N,i,j,k=0, min, temp;
	int A[100][100], B[100][100], C[100][100];
	int niz[10000], niz2[10000], niz3[10000];
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}while(M > 100 || N> 100 || N < 0 || M < 0);
	
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < M; i++) {
		for( j =0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%d", &C[i][j]);
		}
	}
	if( M == 0 && N == 0) {
		printf("DA\n");
		return 0;
	}
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			niz[k] = A[i][j];
			niz2[k] = B[i][j];
			niz3[k] = C[i][j];
			k++;
		}
	}

	for(i = 0; i < k; i++) {
		min = i;
		for(j = i+1; j < k; j++) {
			if(niz[j] < niz[min])  min = j;
		}
		temp = niz[i];
		niz[i] = niz[min];
		niz[min] = temp;
	}
	for(i = 0; i < k; i++) {
		min = i;
		for(j = i+1; j <k; j++) {
			if(niz2[j] < niz2[min]) min = j;
		}
		temp = niz2[i];
		niz2[i] = niz2[min];
		niz2[min] = temp;
	}
	for(i = 0; i < k; i++) {
		min = i;
		for(j = i+1; j < k; j++) {
			if(niz3[j] < niz3[min]) min = j;
		}
		temp = niz3[i];
		niz3[i] = niz3[min];
		niz3[min] = temp;
	}
	int test1 = 0, test2 =0;
	for(i = 0;i <k; i++) {
		if(niz[i] != niz2[i]) { 
			test1 = 0;
			break;
		}
			else test1 = 1;
	}
	for(i = 0; i < k; i++) {
		if(niz[i] != niz3[i]) {
			test2 = 0;
			break;
		}
		else test2 = 1;
	}
	if(test1 == 1 && test2 ==1) printf("DA\n");
	else printf("NE\n");
	
	
	return 0;
}
