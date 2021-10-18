#include <stdio.h>

int main() {
	
	int N, i, j;
	
	do { printf ("Unesite broj N: ");
	    scanf("%d", &N);
	    if (N%4!=0 || N<8) printf ("Neispravno N!");
	    printf("\n");
	} while (N%4==1 || N<8);
	
	for (i=0; i<N/2; i++){
		for(j=0; j<N/2; j++){
			if(i==j) printf("\\");
			else if (i+j==N/2-1) printf("/"); else printf(" ");
		}
		if(i==0 || i==N/2-1) printf("+"); else printf("|");
		for(j=0;j<N/2-2;j++){
			if(i==0 || i==N/2-1) printf("-"); else printf(" ");
		} if(i==0 || i==N/2-1) printf("+"); else printf("|"); printf("\n");
	}
	
	for(i=0;i<N/2;i++){
		if(i==0 || i==N/2-1) printf("+"); else printf("|");
		for(j=0;j<N/2-2;j++){
			if(i==0 || i==N/2-1) printf("-"); else printf(" ");
		} if(i==0 || i==N/2-1) printf("+"); else printf("|");
		
		if (i==N/4-1 || i==N/4) {
			for (j=0; j<(N-4)/4; j++) printf("-");
			 printf("++");
			for (j=0; j<(N-4)/4; j++) printf("-");
			 printf("\n"); }
			 
		
			 
		else {
			for (j=0; j<(N-4)/4; j++) printf(" ");
			 printf("||");
			for (j=0; j<(N-4)/4; j++) printf(" ");
			 printf("\n"); }
	
	}
	
	

	
	return 0;
}
