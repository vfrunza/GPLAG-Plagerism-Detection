#include <stdio.h>

int main() {
	int N,i,j;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&N);
		
		if(N%4!=0 || N<8) printf("Neispravno N!");
		printf("\n");
	}
	
    while(N%4!=0 || N<8);
    
    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
    	if(j==i && i<N/2) printf("\\");
    	else if( i+j==(N-1)/2 && i<N/2) printf("/");
    	else if((i==0 && j==N/2) || (i==0 && j==N-1) || (i==(N-1)/2 && j==N/2) || (i==(N-1)/2 && j==N-1)) printf("+");
    	else if((j==N/2 && i>0 && i<(N-1)/2) || (j==N-1 && i>0 && i<(N-1)/2)) printf("|");
    	else if((i==0 && j>N/2 && j<N-1) || (i==(N-1)/2 && j>N/2 && j<N-1)) printf("-");
    	else if((i==N/2 && j==(N-1)/2) || (i==N-1 && j==(N-1)/2) || (j==0 && i==N/2) || (j==0 && i==N-1)) printf("+");
    	else if((j==0 && i>N/2 && i<N-1) || (j==(N-1)/2 && i>N/2 && i<N-1)) printf("|");
    	else if((i==N/2 && j>0 && j<(N-1)/2) || (i==N-1 && j>0 && j<(N-1)/2)) printf("-");
    	else if((i==(3*N)/4 && (j==(3*N)/4 || j==(3*N)/4-1)) || (i==(3*N)/4-1 && (j==(3*N)/4 || j==(3*N)/4-1)))  printf("+");
    	else if((i>=N/2 && (j==(3*N)/4 || j==((3*N)/4)-1))) printf("|");
    	else if((i==(3*N)/4 && (j>=N/2 && j<(3*N)/4-1)) || (i==(3*N)/4-1) && (j>=N/2 && j<(3*N)/4-1)) printf("-");
    	else if(i==(3*N)/4 && (j>(3*N)/4 && j<N))  printf("-");
    	else if(i==((3*N)/4)-1 && (j>(3*N)/4) && j<N) printf("-");
    	else printf(" ");
    	}
    	
    	printf("\n");
    }
    
    		
    	
    	
  
	
	

		
		
		
	
	return 0;
}
