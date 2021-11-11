#include <stdio.h>

int main() {
	int N,i,j;
	
	do {
		scanf ("%d", &N);
	}while (N%4!=0 || N!=8);
	
	printf ("\\");
	for (i=0; i<N-N/2; i++){
		printf (" ");
		for (j=0; j<N-N/2; j++){
			printf (" ");
			
		printf ("/");
		
		}
		printf ("\n");
	
		
	}
	/*for (i=0; i<N/2; i++){
		printf ("+");
		for (j=0; j<(N/2)-2){
			printf ("-");
		}
		printf ("+");*/
	
	
	return 0;
}
