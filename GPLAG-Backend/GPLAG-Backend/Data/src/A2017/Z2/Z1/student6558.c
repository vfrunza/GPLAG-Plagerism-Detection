#include <stdio.h>

int main() {
	int i,j,N;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N%4!=0 || N<8){
			printf("Neispravno N!\n");
		}
	}while(N%4!=0 || N<8);
	
	printf("\n");
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			if(i<=N/2 && j<=N/2){
				if(j==i){
					printf("\\");
				}
				else if(j==N/2-i+1){
					printf("/");
				}
				else{
					printf(" ");
				}
			}
			if(j>N/2 && i<=N/2){
				if(i==1 || i==N/2){
					if(j==(N/2)+1 || j==N){
						printf("+");
					}
					else if(j>(N/2)+1 || j<N){
						printf("-");
					}
				}
				else if(i>1 && i<=N/2) {
					if(j==(N/2)+1 || j==N){
						printf("|");
					}
					else if(j>(N/2)+1 || j<N){
						printf(" ");
					}
				}
			}
			if(i>N/2 && j<=N/2){
					if(i==(N/2)+1 || i==N){
					if(j==1 || j==N/2){
						printf("+");
					}
					else if(j>1 || j<N/2){
						printf("-");
					}
				}
				else if(i>N/2 && i<=N) {
					if(j==1 || j==N/2){
						printf("|");
					}
					else if(j>1 || j<N/2){
						printf(" ");
					}
				}
			}
			if(i>N/2 && j>N/2){
				if(i<3*N/4 || i>(3*N/4)+1){
					if(j<(3*N)/4 || j>((3*N)/4)+1){
						printf(" ");
					}
					else if(j==(3*N)/4 || j==((3*N)/4)+1){
						printf("|");
					}
				}
				else if(i==(3*N)/4 || i==((3*N)/4)+1){
					if(j<(3*N)/4 || j>((3*N)/4)+1){
						printf("-");
					}
					else if(j==(3*N)/4 || j==((3*N)/4)+1){
						printf("+");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
