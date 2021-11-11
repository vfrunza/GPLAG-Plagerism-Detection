#include <stdio.h>

int main()
{
	int N, i, j, n1;

	printf("Unesite broj N: ");
	scanf("%d", &N);

	if (N%4 != 0 || N==4 || N <= 0) {
		do {
			printf("Neispravno N!\n");
			printf("Unesite broj N: ");
			scanf("%d", &N);
		} while (N%4 != 0 || N==4 || N <= 0);
	}
	printf("\n");

	for(i= 0; i <N; i++) {
		for(j= 0; j <=N; j++) {
			//	prva vrsta
			if ( ( i == 0 && j == 0 ) || ( i==j && i <= (N /2)-1 ) ) printf("\\");

			else if ((i == 0 && j == (N/2)-1) || ( i !=0 && j == (N/2)-1-i)  ) printf ("/");
			else if ((i == 0 && (j == N/2 || j == N-1 )) || (i == (N/2)-1 && (j == N/2 || j == N-1 )) ) printf("+");
			else if ((j == 0 && (i == N/2 || i == N-1 )) || (j == (N/2)-1 && (i == N/2 || i == N-1 )) ) printf("+");
			else if (j == (N/2 + N/4)-1 && i == (N/2 + N/4)-1 || j == N/2 + N/4 && i == N/2 + N/4 || j == (N/2 + N/4)-1 && i == N/2 + N/4 || i == (N/2 + N/4)-1 && j == N/2 + N/4)printf("+");
			else if (j == N) printf("\n");
			else if ((i == 0 && (j == (N/2)+1 || j < N-1) && j> N/2)  || (i == (N/2)-1 && (j == (N/2)+1  || j < N-1) && j> N/2) || (j != 0 && i == N/2 && j< N/2) ||  (j != 0 && i == N-1 && j< N/2)  ) printf("-");
			else if (i == (N/2 + N/4)-1 && (j >=N/2 && j <N/2 + N/4 || j >N/2 + N/4) || i == (N/2 + N/4) && (j >=N/2 && j <N/2 + N/4 || j >N/2 + N/4))printf("-");
			else if ((i != 0 && j == N /2  && i < N/2)||(j == 0 && i > N/2)  || (j == (N/2)-1 && i > N/2 && i != N-1) || (j == N-1 && i < (N/2)-1) ) printf ("|");
			else if (  i>= N/2 && j == (N/2 + N/4)-1 || i >= N/2 && j == N/2 + N/4) printf("|");
			else if (
			    (i == 0 && j<(N/2)-1)
			    ||(j < i && j !=(N/2)-1-i)
			    ||(j >(N/2)-1-i && i!=0 && j<N/2)
			    ||(j > i && j <(N/2)-1-i)
			    ||(j !=0 && i >N/2 && i !=N)
			)printf (" ");
			else if ((i !=0 && i < (N/2)-1) && (j > N/2 && j<N-1) ||
			         (j !=0 && j < (N/2)-1) && (i > N/2 && i <N-1) || ( i == N/2 &&(j >=N/2 &&  j < (N/2 + N/4)-1) ) || ( i == N/2 &&(j <=N-1 &&  j > (N/2 + N/4)-1) ) ) printf (" ");

		}
	}
	return 0;
}
