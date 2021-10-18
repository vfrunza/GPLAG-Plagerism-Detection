#include <stdio.h>

int main() {
	int i,j,N;
	
		do{
		scanf("%d",&N);
		if(N<8 || N%4!=0)
		printf("Unesite broj N: Neispravno N!\n");
		else printf("Unesite broj N:\n");
	}
	while( N<8 || N%4!=0);

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			
			if(((i>=0 && i<N/2) && (j>=0 && j<N/2)) && i==j)
			printf("\\");
			else if(((i>=0 && i<N/2) && (j>=0 && j<N/2)) && i+j==N/2-1)
			printf("/");
			
			else if((j==(N/2) || j==(N-1)) && (i==0 || i==((N/2)-1)))
			printf("+");
			else if ((j>(N/2) && j<(N-1)) && (i==0 || i==((N/2)-1)))
			printf("-");
			else if(i<N/2 && (j==N/2 || j==N-1))
			printf("|");
			
			else if((j==0 || j==(N/2-1)) && (i==(N/2) || i==(N-1)))
			printf("+");
			else if((j>0 && j<(N/2)) && (i==(N/2) || i==(N-1)))
			printf("-");
			else if(i>=N/2 && (j==0 || j==N/2-1))
			printf("|");
			
			else if((i==N/2-1+N/4 || i==N/2+N/4) && (j==N/2-1+N/4 || j==N/2+N/4))
			printf("+");
			else if((i==N/2-1+N/4 || i==N/2+N/4) && j>=N/2)
			printf("-");
			else if(i>=N/2 && (j==N/2-1+N/4 || j==N/2+N/4))
			printf("|");

			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
