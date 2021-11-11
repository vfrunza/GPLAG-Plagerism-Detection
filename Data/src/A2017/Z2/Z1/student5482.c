#include <stdio.h>

int main() {
	int N, i, j, t=0;
	while(t==0){
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N%4==0 && N>=8) break;
		printf("Neispravno N!\n");
		}
		
	printf("\n");
	
	for(i=0; i<N; i++){
		for(j=0; j<N ; j++){
			if(i<N/2 && j<N/2){
				if(i==j) printf("\\");
				else if(i==N/2-1-j) printf("/");
				else printf(" ");
			}
			if((i>=N/2 && i<N && j<N/2) || (j>=N/2 && j<N && i<N/2)){
				if(i%(N/2-1)==0 && (j==N/2 || j==N-1)) printf("+");
				else if(j%(N/2-1)==0 && (i==N/2 || i==N-1)) printf("+");
				else if(i%(N/2-1)==0 && i<N/2) printf("-");
				else if(j<N/2 && (i==N/2 || i==N-1)) printf("-");
				else if(j%(N/2-1)==0 && i>N/2) printf("|");
				else if(i<N/2 && (j==N/2 || j==N-1)) printf("|");
				else printf(" ");
			}
			if(j>=N/2 && i>=N/2){
				if((i==(3*N)/4-1 || i==(3*N)/4) && (j==(3*N)/4-1 || j==(3*N)/4)) printf("+");
				else if(i==(3*N)/4-1 || i==(3*N)/4) printf("-");
				else if(j==(3*N)/4-1 || j==(3*N)/4) printf("|");
				 else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
