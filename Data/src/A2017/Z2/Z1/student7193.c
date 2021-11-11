#include <stdio.h>


int main() {
	int N;
	int i,j;
	
	do{
		printf("Unesite broj N: ");
		scanf("%d",&N);
		if(N<8 || N%4!=0) printf("Neispravno N!\n");
	}while(N<8 || N%4!=0);
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i<N/2) {
				
				if(j<N/2){
					if(i==j) printf("\\");
					else if(i+j==N/2-1) printf("/");
					else printf(" ");
				}
			
			
				if(j>=N/2){
					if(i==0 || i==N/2-1){
						if(j==N/2 || j==N-1) printf("+");
						else printf("-");
						}
					else {
						if(j==N/2 || j==N-1) printf("|");
						else printf(" ");
					}	
					
				}
			}
		
			if(i>=N/2){
				
				if(j<N/2){
					
					if(i==N/2 || i==N-1) {
						if(j==0 || j==N/2-1) printf("+");
						else printf("-");
					}
					else {
						if(j==0 || j==N/2-1) printf("|");
						else printf(" ");
					}
					
				}
			
				if(j>=N/2){
					
					if(i==N/2+N/4-1 || i==N/2+N/4)
						if(j==N/2+N/4-1 || j==N/2+N/4) printf("+");
						else printf("-");
					else{
						if(j==N/2+N/4-1 || j==N/2+N/4) printf("|");
						else printf(" ");
					}	
					
				}
				
			}
		}
		
		printf("\n");
	}
	
    
    
    
	return 0;
}
