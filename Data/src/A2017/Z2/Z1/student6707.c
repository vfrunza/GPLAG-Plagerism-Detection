#include <stdio.h>

int main() {
	int x,y,N;
		
		/*	printf("Unesite broj N: ");
		scanf("%d", &N);*/
	
	do { 
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N%4!=0 || N<8) printf("Neispravno N!\n");
		
	} while(N%4!=0 || N<8); 
		
	printf("\n");
	
	
	for(x=1; x<=N; x++) {
		for(y=1; y<=N; y++) {
			if(x>=1 && x<=N/2 && y>=1 && y<=N/2) {
				if(x==y) printf("\\");
				else if(x+y==N/2+1) printf("/");
				else printf(" ");
			}
			else if(x>=1 && x<=N/2 && y>N/2 && y<=N) {
				if((x==1 || x==N/2) && (y==N/2+1 || y==N)) printf("+");
				else if(x>1 && x<N/2 && (y==N/2+1 || y==N)) printf("|");
				else if((x==1 || x==N/2) && y>N/2+1 && y<N) printf("-");
				else printf(" ");
			}
			else if(x>=N/2+1 && x<=N && y>=1 && y<=N/2) {
				if((y==1 || y==N/2) && (x==N/2+1 || x==N)) printf("+");
				else if(y>1 && y<N/2 && (x==N/2+1 || x==N)) printf("-");
				else if((y==1 || y==N/2) && x>N/2+1 && x<N) printf("|"); 
				else printf(" ");
			}
			else {
				if((x==N/2+N/4 || x==N/2+N/4+1) && (y==N/2+N/4 || y==N/2+N/4+1)) printf("+");
				else if(y==N/2+N/4 || y==N/2+N/4+1) printf("|");
				else if(x==N/2+N/4 || x==N/2+N/4+1) printf("-");
				else printf(" ");
			}
			
	}
	printf("\n");
	} 
	
	return 0;
}
