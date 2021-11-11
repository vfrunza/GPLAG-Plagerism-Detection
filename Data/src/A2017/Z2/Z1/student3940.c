#include <stdio.h>

int main(){
	
	int N, i, j;
	// unosenje broja N dok ne bude zadovoljavao uslove zadatka
	do {
		printf ("Unesite broj N: ");
		scanf ("%d", &N );
		
		if (N < 8 || N % 4 != 0 ){
			printf("Neispravno N!\n");
			
		}
	}while (N < 8 || N % 4 != 0);
	printf("\n");
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			// prvo, unosenje znaka X
			if (i < N/2 && j < N/2){
				if(i == j){
					printf("\\");
				}
				
				else if ((i + j == (N/2 - 1))) printf("/");
				else printf(" ");
			}
			// drugo, unosenje kvadrata u gornjem desnom uglu
			
			 else if (j >= N/2 && i < N/2){
				if ( (j == N/2 || j == N - 1) && (i == 0 || i == N/2 -1))printf("+");
				else if((j < N - 1) && (i == 0 || i == N/2 - 1)) printf ("-");
				else if(((j == N/2 || j == (N-1)) && (i < N/2 - 1))) printf ("|");
				else printf(" ");
			}
			
			// zatim unosimo kvadrat u donjem lijevom cosku
			else if ( i >= N/2 && j < N/2 ){
				if (( i == N/2 || i == N - 1) && ( j == 0 || j == N/2 -1)) printf ("+");
				else if( (i == N / 2 || i == N - 1) && (j < N/2 - 1))printf("-");
				else if (( i <= N - 1) && (j == 0 || j == N/2 - 1)) printf ("|");
				else printf (" ");
			}
			// na kraju se unosi plus u donjem desnom cosku
			else {
				if(j >= (N/2 + ((N/2 - 2)/2)) && j < (N -(N/2 - 2)/2)){
					if(i >= (N/2 + ((N/2 - 2)/2)) && i < (N -(N/2 - 2)/2))printf("+");
					else printf("|");
				}
			else if (i >=  (N/2 + ((N/2 - 2)/2)) && i < (N -(N/2 - 2)/2))printf ("-");
				else printf(" ");
			}
			
		}
			printf("\n");
	}
	

	return 0;
}