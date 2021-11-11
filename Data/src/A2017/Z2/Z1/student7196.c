#include <stdio.h>
#include <math.h>

int main() {
	
	int N, i, j, a, b, brojac=0;
	
	do {
		if (brojac>0) {
			printf("Neispravno N!\n");
		}
		printf("Unesite broj N: ");
		scanf("%d", &N);
		brojac++;
	} while (N%4!=0 || N<8);
	
	printf("\n");
	
	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			if (i<=N/2 && j<=N/2) {
				if (i==j) {
					printf("\\");
				}
				else if (i+j==(N/2)+1) {
					printf("/");
				}
				else {
					printf(" ");
				}
			}
			else if (i<=N/2 && j>=N/2 || i>=N/2 && j<=N/2) {
				if ((i==1 && j==(N/2)+1) || (i==1 && j==N) || (i==N/2 && j==(N/2)+1) || (i==N/2 && j==N) || (j==1 && i==(N/2)+1) || (j==1 && i==N) || (j==N/2 && i==(N/2)+1) || (j==N/2 && i==N)) {
					printf("+");
				}
				else if (i==1 || i==N/2 || i==(N/2)+1 || i==N) {
					printf("-");
				}
				else if (j==1 || j==N/2 || j==(N/2)+1 || j==N) {
					printf("|");
				}
				else {
					printf(" ");
				}
			}
			else {
				if ((i==N/2+N/4 || i==N/2+N/4+1) && (j==N/2+N/4 || j==N/2+N/4+1)) {
					printf("+");
				}
				else if (i==N/2+N/4 || i==N/2+N/4+1) {
					printf("-");
				}
				else if (j==N/2+N/4 || j==N/2+N/4+1) {
					printf("|");
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	
	return 0;
}
