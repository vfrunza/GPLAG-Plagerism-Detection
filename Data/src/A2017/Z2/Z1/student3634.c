#include <stdio.h>

int main(){
	int i, j, N;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N % 4 != 0 || N < 8) printf("Neispravno N!\n");
	} while(!(N%4==0 && N >= 8));
	printf("\n");
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			//kvadrati
			if((i == 0 && (j == N/2 || j == N-1)) || (i == N/2-1 && (j == N/2 || j == N-1)) || (i == N/2 && (j == N/2-1 || j == 0)) || (i == N - 1 && (j == N/2-1 || j == 0))) printf("+");
			else if( (i == 0 && j >= N/2) || (i == N/2 - 1  && j >= N/2 ) || (i == N-1 && j < N/2 ) || (i == N/2  && j < N/2 )) printf("-");
			else if( (j == N-1  && i < N/2) || (j == N/2   && i < N/2) || (j == 0 && i > N/2 ) || (j == N/2 - 1  && i > N/2 )) printf("|");
			// donji desni ugao
			else if((i ==  N/2 + N/4 - 1 && j ==  N/2 + N/4 - 1) || (i ==  N/2 + N/4 - 1 && j ==  N/2 + N/4) || (i ==  N/2 + N/4 && j ==  N/2 + N/4 - 1) || (i ==  N/2 + N/4 && j ==  N/2 + N/4 )) printf("+");
			else if(i >= N/2 && (j == N/2 + N/4 - 1 || j == N/2 + N/4 )) printf("|");
			else if(j >= N/2 && (i == N/2 + N/4 - 1|| i == N/2 + N/4 )) printf("-");
			//X
			else if(i == j && i < N/2 && j < N/2) printf("\\");
			else if(j == N/2 - i - 1 && i < N/2 && j < N/2) printf("/");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}