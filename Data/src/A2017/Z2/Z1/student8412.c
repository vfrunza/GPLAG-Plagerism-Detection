#include <stdio.h>

int main()
{
	int i,j,N;
	do {
		printf("Unesite broj N: ");
		scanf("%d",&N);
		if(N%4!=0 || N<8) printf("Neispravno N!");
		printf("\n");
	} while(N%4!=0 || N<8);
	for(i=0; i<N/2; i++) {
		for(j=0; j<N; j++) {
			if(j<N/2) {
				if(i==j) printf("\\");
				else {
					if(i+j==(N/2)-1) printf("/");
					else printf(" ");
				}
			} else {
				if(i==0 || i==(N/2)-1) {
					if(j==N/2 || j==N-1) printf("+");
					else printf("-");
				} else {
					if(j==N/2 || j==N-1) printf("|");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}
	for(i=0; i<N/2; i++) {
		for(j=0; j<N; j++) {
			if(j<N/2) {

				if(i==0 || i==(N/2)-1) {
					if(j==0 || j==N/2-1) printf("+");
					else printf("-");
				} else {
					if(j==0 || j==N/2-1) printf("|");
					else printf(" ");
				}
			} else {
				if(i==N/4 || i==(N/4)-1) {
					if(j==N-N/4-1 || j==N-N/4) printf("+");
					else printf("-");
				} else {
					if(j==N-N/4-1 || j==N-N/4) printf("|");
					else printf(" ");
				}
			}

		}




		printf("\n");
	}


	return 0;
}
