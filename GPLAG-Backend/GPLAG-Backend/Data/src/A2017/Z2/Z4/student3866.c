#include <stdio.h>
#define leftB 0
#define rightB 100
#define f_SIZE 100

int A[f_SIZE][f_SIZE], B[f_SIZE][f_SIZE], C[f_SIZE][f_SIZE];
int MAT[f_SIZE][f_SIZE][3]; /* validity matrix */

/* scan matrix */
int scan_matrix(int M, int N, int type, int num) {
	int i, j;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			if(type == 0) {
				if(num == MAT[i][j][0] && MAT[i][j][1] == 0) {
					MAT[i][j][1] = 1;
					return 1;
				}
			}
			else {
				if(num == MAT[i][j][0] && MAT[i][j][2] == 0) {
					MAT[i][j][2] = 1;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	/* initial */
	int i, j, M, N, _SAME = 1;
	/* input */
	do {
		printf("Unesite brojeve M i N: "); scanf("%d %d", &M, &N);
	} while(M < leftB || M > rightB || N < leftB || N > rightB);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
			MAT[i][j][0] = A[i][j];
			MAT[i][j][1] = 0;
			MAT[i][j][2] = 0;
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%d", &B[i][j]); 
			/* check with matrix A */
			if(_SAME) _SAME = scan_matrix(M, N, 0, B[i][j]); 
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%d", &C[i][j]);
			/* check with matrix A */
			if(_SAME) _SAME = scan_matrix(M, N, 1, C[i][j]); 
		}
	}
	/* output */
	if(_SAME) {
		printf("DA\n");
	}
	else
		printf("NE\n");
	return 0;
}