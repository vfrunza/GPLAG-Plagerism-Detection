#include <stdio.h>

int main() {
	int N, i, j;
	
	do{
		printf("Unesite broj N:");
		scanf("%d", &N);
		if(N<8 || N%4!=0){
			printf(" Neispravno N!\n");
		}
	} while (N%4!=0 || N<8);
	printf("\n");
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if((i==(N/2)+1 && j==1) || (i==N && j==1) || (i==1 && j==(N/2)+1) || (i==1 && j==N) || (i==N/2 && j==(N/2)+1) || (i==N/2 && j==N ) || (i==(N/2)+1 && j==N/2) || (i==N && j==N/2)){
				printf("+");
			}   else if((i>N/2 && j==1) || (i>N/2 && j==N/2) || (i<N/2 && j==N/2+1) ||  (i<N/2 && j==N)){
				printf("|");
			}   else if((i==1 && j>N/2) || (i==N/2 && j>N/2) || (i==(N/2)+1 && j<N/2) || (i==N && j<N/2)){
				printf("-");
			}   else if(i==j && i<=N/2 && j<=N/2){
				printf("\\");
			}   else if(i<=N/2 && j<=N/2 && (i+j)==(N/2)+1){
				printf("/");
			}   else if((i==(3*N)/4 && j==(3*N)/4) || (i==(3*N)/4 && j==(3*N)/4+1) || (i==(3*N)/4+1 && j==(3*N)/4) || (i==(3*N)/4+1 && j==(3*N)/4+1)){
				printf("+");
			}   else if((i==(3*N)/4 && j>N/2) || (i==(3*N)/4+1 && j>N/2)){
				printf("-");
			}   else if((i>N/2 && j==(3*N)/4) || (i>N/2 && j==((3*N)/4)+1)){
				printf("|");
			} else {
				printf(" ");
			}}
		 printf("\n");
	}
	
	return 0;
}
