#include <stdio.h>
#define NIZ 100

int main() {
	
	int M, N, i, j, tip_matrice=2;
	double el[NIZ][NIZ];
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M,&N);
		
		if (M<1 || M>100) {
			printf("Pogresan unos!\n");
		} else if (N<1 || N>100) {
			printf("Pogresan unos!\n");
		}
	} while (M<1 || M>100 || N<1 || N>100);
	
	printf("Unesite elemente matrice: ");
	
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%lf", &el[i][j]);
		}
	}
	
	for (i=0; i<M-1; i++) {
		for (j=0; j<N-1; j++) {
			
			if ((el[i][j]!=el[i+1][j+1]) || (el[i][N-1]!=el[i+1][0])) {
				tip_matrice--;
				i=M;
				break;
			}
		}		
	}		
	
	for (i=0; i<M-1; i++) {
		for (j=0; j<N-1; j++){		
			if (el[i][j]!=el[i+1][j+1]) {
				tip_matrice--;
				i=M;
				break;
			}
		}
	}
	
	switch (tip_matrice) {
		case 2:
		printf("Matrica je cirkularna");
		break;
		
		case 1:
		printf("Matrica je Teplicova");
		break;
		
		case 0:
		printf("Matrica nije ni cirkularna ni Teplicova");
		break;
	
	}
	
	return 0;
}
