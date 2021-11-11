#include <stdio.h>

int main()
{
	int N,i,j;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if (N%4!=0 || N<8) {
			printf("Neispravno N!\n");
		}
	} while (N%4!=0 || N<8); printf("\n");

	for(i=0; i<N/2; i++) {
		for(j=0; j<N; j++) {

			if (j<N/2) {
				if(j==i) {
					printf("\\");
				}
				else if(j==N/2-(i+1)) {
					printf("/");
				} else {
					printf(" ");
				}
			}
			if(j>=N/2) {
				if(i==0 || i==N/2-1) {
					if(j==N/2 || j==N-1) {
						printf("+");
					} else {
						printf("-");
					}
				} else if(j==N/2 || j==N-1) {
					printf("|");
				} else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}

	for(i=N/2; i<N; i++) {
		for(j=0; j<N; j++) {
			if(j<N/2) {
				if(i==N/2 || i==N-1) {
					if(j==0 || j==N/2-1) {
						printf("+");
					} else {
						printf("-");
					}
				} else if(j==0 || j==N/2-1) {
					printf("|");
				} else {
					printf(" ");
				}
			}
			if(j>=N/2) {
				if(i==(3*N)/4 || i==(3*N)/4-1) {
					if(j==(3*N)/4 || j==(3*N)/4-1) {
						printf("+");
					} else {
						printf("-");
					}
				} else if(j==(3*N)/4 || j==(3*N)/4-1) {
					printf("|");
				} else {
					printf(" ");
				}

			}
		}
		printf("\n");

	}
	return 0;
}