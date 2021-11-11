#include <stdio.h>

int main() {

float mat[100][100];
int M, N, i, j, tep=1, cirk=1;


do {
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<1 || N<1 || M>100 || N>100)
	printf("Pogresan unos!\n");
} while(M<1 || N<1 || M>100 || N>100);
	

printf("Unesite elemente matrice: ");

for(i=0; i<M; i++) {
	for(j=0; j<N; j++) {
		scanf("%f", &mat[i][j]);
	}
}

	for(i=1; i<M; i++) {
		for(j=0; j<N; j++) {
			if(mat[i][0]!=mat[i-1][N-1])
				cirk=0;
		}
	}

for(i=0; i<M; i++) {
	for(j=0; j<N; j++) {
		if(j>=i) {
		if(mat[i][j]!=mat[0][j-i])
			tep=0;
		}
		else if(j<i) {
			if(mat[i][j]!=mat[i-j][0])
				tep=0;
		}
	}
}

if(!tep) cirk=0; /*Potreban uslov da bi matrica bila cirkularna je da je Teplicova*/


if(cirk==1 && tep==1) printf("Matrica je cirkularna");
else if(tep) printf("Matrica je Teplicova");
else  printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
