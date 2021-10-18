#include <stdio.h>

int main() {
	int N,i,j;
	do{
		printf("\nUnesite broj N:");
		scanf("%d", &N);
		if(N%4!=0 || N<8) printf(" Neispravno N!");
		else printf("\n");
	}
	while((N%4!=0) || (N<8));
	for(i=0; i<N/2; i++){
		for(j=0; j<N; j++){
			if(j<N/2){
				if(i==j) printf("\\");
				else if(i+j==N/2-1) printf("/");
				else printf(" ");
			}
			if((j>=N/2) && (j<N)){
				if(((j==N/2) || (j==N-1)) && ((i==0) || (i==N/2-1))) printf("+");
				else if(((j==N/2) || (j==N-1)) && ((i!=0) || (i!=N/2-1))) printf("|");
				else if(((j!=N/2) || (j!=N-1)) && ((i==0) || (i==N/2-1))) printf("-");
				else printf(" ");
			}
		}
		printf("\n");
	}
	for(i=0; i<N/2; i++){
		for(j=0; j<N; j++){
			if(j<N/2) {
				if(((j==0) || (j==N/2-1)) && ((i==0) || (i==N/2-1))) printf("+");
				else if(((j==0) || (j==N/2-1)) && ((i!=0) || (i!=N/2-1))) printf("|");
				else if(((j!=N/2-1) || (j!=0)) && ((i==0) || (i==N/2-1))) printf("-");
				else printf(" ");
			}
			if(j>=N/2 && j<N) {
				if(((j==3*N/4) || (j==3*N/4-1)) && ((i<N/4-1) || (i>N/4))) printf("|");
				else if(((j<3*N/4-1) || (j>3*N/4)) && ((i==N/4-1) || (i==N/4))) printf("-");
				else if(((j==3*N/4-1) || (j==3*N/4)) && ((i==N/4-1) || (i==N/4))) printf("+");
				else printf(" ");
			}
			
		}
		printf("\n");
	}
	
	return 0;
}
