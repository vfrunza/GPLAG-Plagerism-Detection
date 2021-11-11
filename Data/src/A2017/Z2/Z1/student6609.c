#include <stdio.h>

int main() {
	int i,j,N,br=0;
	do {
		if(br>0) printf("Neispravno N!\n");
		printf("Unesite broj N: ");
		scanf("%d", &N);
		br++;
	} while(N%4!=0 || N<8);
	
	printf("\n");
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(i>=0 && i<N/2) {
				if(j>=0 && j<N/2) {
					if(i==j) printf("\\");
					else if(i+j==(N/2)-1) printf("/");
					else printf(" ");
				}
				if(j>=N/2 && j<N) {
					if(i==0 || i==(N/2)-1) {
						if(j==N/2 || j==N-1) printf("+");
					    else printf("-");
					}
					else {
				    	if(j==N/2 || j==N-1) printf("|");
				    	else printf(" ");
				    }
				}
			}
			
			if(i>=N/2 && i<N) {
				if(j>=0 && j<N/2) {
					if(i==N/2 || i==N-1) {
						if(j==0 || j==(N/2)-1) printf("+");
						else printf("-");
					}
					else {
						if(j==0 || j==(N/2)-1) printf("|");
						else printf(" ");
					}
				}
				if(j>=N/2 && j<N) {
					if((i>=N/2 && i<N-(N/4)-1) || (i>N-(N/4) && i<=N-1)) {
						if(j==N-1-(N/4) || j==N-(N/4)) printf("|");
						else printf(" ");
					}
					else {
						if(j==N-1-(N/4) || j==N-(N/4)) printf("+");
						else printf("-");
					}
				}
			}
		}
		printf("\n");
	}
	
	return 0;
}
