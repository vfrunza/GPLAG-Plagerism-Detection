#include <stdio.h>

int main()
{

	int N,i,j;

	do {
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N<8 || N%4!=0) printf("Neispravno N!\n");
		else break;
	} while(1);


	printf("\n");
	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {



			//prvi dio
			if(i==j && i<=N/2 && j<=N/2 ) printf("\\");
			else if(i==(N/2)-j+1) printf("/");


			//drugi dio
			else if((i==1 && j==(N/2)+1) || (i==N/2 && j==(N/2)+1) || (i==1 && j==N) || (i==N/2 && j==N))
				printf("+");
			else if((i==1 && j>(N/2)+1 && j!=N) || (i==N/2 && j>(N/2)+1 && j!=N))
				printf("-");
			else if((i>1 && i<N/2 && j==(N/2)+1) || (i>1 && i<N/2 && j==N))
				printf("|");

			//treci dio
			else if((i==(N/2)+1 && j==1) || (i==(N/2)+1 && j==N/2) || (i==N && j==1) || (i==N && j==N/2))
				printf("+");
			else if((i==(N/2)+1 && j>1 && j<(N/2)) || (i==N && j>1 && j<(N/2)))
				printf("-");
			else if((i>(N/2)+1 && i!=N && j==1) || (i>(N/2)+1 && i!=N && j==N/2))
				printf("|");



			//cetvrti dio
			else if((i==N-(N/4) && j==N-(N/4)) || (i==N-(N/4) && j==N-(N/4)+1) || (i==N-(N/4)+1 && j==N-(N/4)) || (i==N-(N/4)+1 && j==N-(N/4)+1))
				printf("+");
			else if(i>=(N/2)+1 && (j==N-(N/4) || j==N-(N/4)+1))
				printf("|");
			else if(j>=(N/2)+1 && (i==N-(N/4) || i==N-(N/4)+1))
				printf("-");
			else printf(" ");


		}
		printf("\n");
	}


	return 0;
}