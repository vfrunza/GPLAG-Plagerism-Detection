#include <stdio.h>

int main()
{
	int i,j,N;
	do{
		printf("Unesite broj N:");
			scanf("%d",&N);
			if(N<8 || N%4!=0){
				 printf(" Neispravno N!");
				 printf("\n");
			}
	}while(N<8 || N%4!=0);
	printf("\n");
	for(i=1; i<=N; i++) {
		for(j=1; j<=N; j++) {
			if(i<=N/2) {
				if(j<=N/2) {
					if(i==j) printf("\\");
					else if(i+j==(N/2)+1) printf("/");
					else printf(" ");

				} else if( j>N/2) {
					if(i==N/N || i==N/2) {
						if(j==(N/2)+1 || j==N) printf("+");
							else printf("-");
							
					} else {
						if(j==(N/2)+1 || j==N) printf("|");
						else printf(" ");
					}
					
					}

			}
			else if(i>N/2){
				if(j<=N/2){
					if(i==N/2+1 || i==N){
					
					if(j==N/N || j==N/2) printf("+");
					else printf("-");
					}
					
					else if(i>N/2+1 && i<N){
						
							if(j==N/N || j==N/2) printf("|");
							else printf(" ");
					}	
					}
					else if(j>N/2){
						if(i==(3*N)/4 || i==3*N/4+1){
							if(j==3*N/4 || j==3*N/4+1) printf("+");
							else printf("-");
						}
						else{
							if(j==3*N/4 || j==3*N/4+1) printf("|");
							else printf(" ");
						}
						
							
						
					}
				}
			}
	printf("\n");
		
	}
		
	



	return 0;
}
