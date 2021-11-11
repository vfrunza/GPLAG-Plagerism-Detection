#include <stdio.h>

int main() {
	int i, j, k, l, m, N;
	
	do{
		printf("Unesite broj N: ");
	    scanf("%d", &N);
	    if(N<8 || N % 4 != 0) printf("Neispravno N!\n");
	} while (N<8 || (N % 4 != 0));
	
	printf("\n");

	for(i=0; i<N/2; i++){
		for(j=0; j<N/2; j++){
			if(i==j) printf("\\");
			else if (j==(((N/2)- 1) - i)) printf("/");
			else printf (" ");
		}
		for(k=N/2; k<N; k++){
			if(i==0 && k==N/2 || i==0 && k==N-1) printf("+");
			else if(i==0) printf("-");
			}
		 
		 for(l=N/2; l<N; l++){
		 	if((i!=0 && i<(N/2 - 2) && l==N/2) || (i!=0 && i<(N/2 - 2) && l==N-1) || (i==(N/2 - 2) && l==N/2) || (i==(N/2 - 2) && l==N-1)) printf("|");
		 	else if (i!=0 && i<(N/2 - 1)) printf(" ");
		 }
		 
		 for(m=N/2; m<N; m++){
			if((i==(N/2 - 1) && m==N/2) || (i==(N/2 - 1) && m==N-1)) printf("+");
			else if(i==(N/2 - 1)) printf("-");
			}
	
		printf("\n");
	}

	
	
			
		
	for(i=0; i<N/2; i++){
		for(k=0; k<N/2; k++){
			if(i==0 && k==0 || i==0 && k==(N/2 - 1)) printf("+");
			else if(i==0) printf("-");
			}
		 
		 for(l=0; l<N/2; l++){
		 	if((i!=0 && i<(N/2 - 2) && l==0) || (i!=0 && i<(N/2 - 2) && l==(N/2 - 1)) || (i==(N/2 - 2) && l==0) || (i==(N/2 - 2) && l==(N/2 - 1))) printf("|");
		 	else if (i!=0 && i<(N/2 - 1)) printf(" ");
		 }
		 
		 for(m=0; m<N/2; m++){
			if((i==(N/2 - 1) && m==0) || (i==(N/2 - 1) && m==(N/2 - 1))) printf("+");
			else if(i==(N/2 - 1)) printf("-");
			}
	
		for(j=0; j<N/2; j++){
			if((i==(N/4 - 1) && j==N/4) || (i==(N/4 - 1) && j==(N/4 - 1)) || (i==(N/4) && j==N/4) || i==(N/4) && j==(N/4 - 1)) printf("+");
			else if(i==(N/4 - 1) || i==N/4) printf("-");
			else if(j==N/4 || j==(N/4 - 1) || j==N/4 || j==(N/4 - 1) ) printf("|");
			else printf(" ");
			
		}
	
		printf("\n");
	}
	    
	     
	
	return 0;
}
