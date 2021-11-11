#include <stdio.h>
#define SIRINA 20

int main()
{
	int n,i,j,k, A[10], B[10];
	char mat[SIRINA][SIRINA];
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n>10 || n<=0) {
			printf("Pogresan unos\n");
		}
	} while(n>10 || n<=0);


	for(i=0; i<n; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &A[i], &B[i]);
		if(A[i]<0 || A[i]>19 || B[i]<0 || B[i]>19) {
			printf("Pogresan unos\n");
			i--;
		}
	}

	for(i=0; i<SIRINA; i++) {
		for(j=0; j<SIRINA; j++) {
			mat[i][j]=' ';
		}
	}


	for(i=0; i<n; i++) {
		for(j=0; j<SIRINA; j++) {
			for(k=0; k<SIRINA; k++) {
				if(j==B[i] && k==A[i])
					mat[j][k]='*';

			}
		}
	}

	for(i=0; i<SIRINA; i++) {
		for(j=0; j<SIRINA; j++) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}


	return 0;
}
