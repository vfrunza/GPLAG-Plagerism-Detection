#include <stdio.h>

int main() {
	int i,j,N;
	do {
	printf("Unesite broj N: ");
	scanf("%d",&N);
	if (N < 8 || N % 4 !=0 ) 
		printf("Neispravno N! \n");
		else printf("\n");
	}
	while (N < 8 || N % 4 != 0);
	for	(i = 0; i < N/2; i++) {
		for (j = 0; j< N; j++) {
			if (i == j) 
				printf("\\");
			else if (i+j == N/2-1)
				printf ("/");
			else if(j<N/2)
				printf(" ");
				else if((i==0 || i==N/2-1)&&(j==N/2|| j==N-1))
			printf("+");
			else if(i==0||	i==N/2-1 )/**/
			printf("-");
			else if(j==N/2||j==N-1)
			printf("|");
			else
			printf(" ");
			
		}
		printf("\n");
	}
	
	for(i=N/2;i<N;i++) {
		for(j=0;j<N;j++) {
		
		if(((i==N/2 || i==N-1)&&(j==N/2-1 || j==0 ))||((i==3*N/4-1|| i==3*N/4)&&(j==3*N/4-1|| j==3*N/4)))
		printf("+");
		else if(((i==N/2 || i==N-1)&&(j<N/2))||((i==3*N/4-1|| i==3*N/4)&&(j>N/2-1)))
		printf("-");
		else if(((i>N/2 && i<N-1)&&(j==0 || j==N/2-1))||(j==3*N/4-1)||(j==3*N/4))
		printf("|");
		else 
		printf(" ");}
		printf("\n");}
		
	return 0;
}