#include <stdio.h>

int main() {
	int N,i,j;
	
	/* Unos broja*/
	do{
		
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N>=8 && N%4==0) break;
		else printf("Neispravno N!\n");
		
	} while(N<8 || N%4!=0);
    printf("\n");
    
    /* Ispis lika */
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i<N/2 && i==j){
				printf("\\");
			} else if(i<N/2 && j<N/2 && j==N/2-i-1){
				printf("/");
			} else if((i==0 || i==N/2-1) && (j==N/2 || j==N-1)){
				printf("+");
			} else if((i==N/2 || i==N-1) && (j==0 || j==N/2-1)){
				printf("+");
			} else if((i==0 || i==N/2-1) && (j>N/2 && j<N-1)){
				printf("-");
			} else if((i==N/2 || i==N-1) && (j>0 && j<N/2-1)){
				printf("-");
			} else if((i>0 && i<N/2-1) && (j==N/2 || j==N-1)){
				printf("|");
			} else if((i>N/2 && i<N-1) && (j==0 || j==N/2-1)){
				printf("|");
			} else if((i==N-N/4 || i==N-N/4-1) && (j>=N/2 && j<N-N/4-1)){
				printf("-");
			} else if((i==N-N/4 || i==N-N/4-1) && (j>=N-N/4-1 && j<=N-N/4)){
				printf("+");
			} else if((i==N-N/4 || i==N-N/4-1) && (j>N-N/4 && j<=N-1)){
				printf("-");
			} else if((j==N-N/4 || j==N-N/4-1) && (i>N-N/4 && j<=N-1)){
		     	printf("|");
		    } else if((j==N-N/4 || j==N-N/4-1) && (i>=N/2 && i<N-N/4-1)){
		    	printf("|");
		    } else printf(" ");
		} printf("\n");
	}
	
	return 0;
}
