#include <stdio.h>

int main() {
	int N, i, j;
	
	printf("Unesite broj N: ");
	scanf("%d", &N);
	
	if(N%4!=0 || N<8) {
		do {
			printf("Neispravno N!\n");
			printf("Unesite broj N: ");
			scanf("%d", &N);
		} while(N%4!=0 || N<8);
	}
	printf("\n");
	
	
	for(i=1; i<=N/2; i++){
		for(j=1; j<=N; j++){
			if(j<=N/2){
				if(i==j) printf("\\");
				else if(i+j==(N/2)+1) printf("/");
				else printf(" ");
			}
			
			else{
				if((i==1 || i==N/2) && (j==(N/2)+1 || j==N)) printf("+");
				else if((i==1 || i==N/2) && j>(N/2)+1 && j<=N) printf("-");
				else if(i>1 && i<N/2 && (j==(N/2)+1 || j==N)) printf("|");
				else printf(" ");
			}
		}
		printf("\n");
	}
	
	
		for(i=N/2 +1; i<=N; i++){
		for(j=1; j<=N; j++){
			if(j<=N/2){
				if((i==(N/2)+1 || i==N) && (j==1 || j==N/2) ) printf("+");
				else if((i==(N/2)+1 || i==N) && j>1 && j<N/2)  printf("-");
				else if(i>(N/2)+1 && i<N && (j==1 || j==N/2))  printf("|");
				else printf(" ");
			}
			
			else{
				if((i==N/2+(N/2)/2 || i==N/2+(N/2)/2+1) && (j==N/2+(N-N/2)/2 || j==N/2+(N-N/2)/2+1 )) printf("+");
				else if((i==N/2+(N/2)/2 || i==N/2+(N/2)/2+1) && j!=N/2+(N/2)/2 && j!=N/2+(N/2)/2+1) printf("-");
				else if((j==N/2+(N/2)/2 || j==N/2+(N/2)/2+1 ) && i!=N/2+(N/2)/2 && i!=N/2+(N/2)/2+1) printf("|");
				else printf(" ");
			}
		}
		printf("\n");
	}
	
	
	
	return 0;
}
