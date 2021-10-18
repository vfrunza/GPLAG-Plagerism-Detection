#include <stdio.h>

int main() {
	int i, j, N;
	char backslash=92;
	
	do{
		printf("Unesite broj N: ");
		scanf("%d", &N);
		if(N%4!=0 || N<8){
			printf("Neispravno N!");
		}
		printf("\n");
	} while (N%4!=0 || N<8);
	
	for(i=1;i<N+1;i++){
		for(j=1;j<N+1; j++){
			if(i==j && j>=1 && i>=1 && i<N/2+1 && j<N/2+1) printf("%c", backslash);
			else if(i==N/2+1-j && j>=1 && i>=1 && j<N/2+1) printf("/");
			else if(i==1 && (j==N/2+1 || j==N)) printf("+");
			else if(i==N/2 && (j==N/2+1 || j==N)) printf("+");
			else if(i==N/2+1 && (j==1 || j==N/2)) printf("+");
			else if(i==N && (j==1 || j==N/2)) printf("+");
			else if(i==3*N/4 && (j==3*N/4 || j==3*N/4+1)) printf("+");
			else if(i==3*N/4+1 && (j==3*N/4 || j==3*N/4+1)) printf("+");
			else if(i==1 && j>N/2+1 && i<N) printf("-");
			else if(i==N/2 && j>N/2+1 && j<N) printf("-");
			else if(i==N/2+1 && j>1 && j<N/2) printf("-");
			else if(i==N && j>1 && j<N/2) printf("-");
			else if(i==3*N/4 && j>N/2 && j<3*N/4) printf("-");
			else if(i==3*N/4 && j>3*N/4+1 && j<N+1) printf("-");
			else if(i==3*N/4+1 && j>N/2 && j<3*N/4) printf("-");
			else if(i==3*N/4+1 && j>3*N/4+1 && j<N+1) printf("-");
			else if(i==3*N/4+1 && j>N/2 && j<3*N/4) printf("-");
			else if(j==N/2+1 && i>1 && i<N/2) printf("|");
			else if(j==N && i>1 && i<N/2) printf("|");
			else if(j==1 && i>N/2+1 && i<N) printf("|");
			else if(j==N/2 && i>N/2+1 && i<N) printf("|");
			else if(j==3*N/4 && i>N/2 && i<3*N/4) printf("|");
			else if(j==3*N/4+1 && i>N/2 && i<3*N/4) printf("|");
			else if(j==3*N/4 && i>3*N/4+1 && i<N+1) printf("|");
			else if(j==3*N/4+1 && i>3*N/4+1 && i<N+1) printf("|");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
