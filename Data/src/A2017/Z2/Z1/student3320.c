#include <stdio.h>

int main() {
	int M, N;
	int i, j;
	int temp, temp1;
	char a, b;
	printf("Unesite redove i kolone: ");
	scanf("%d %d", &M, &N);
	
	temp=M;
	temp1=N;
	a=92;
	b=47;
	for(i=0; i<M*2; i++) {
		for(j=0; j<N*2; j++) {
			if(i<M && j<N) {
				if(i==j) {
					printf("%c", a);
				} else {
					printf(" ");
				}
			} else {
				if(i==temp-i-2 && j==temp1-j-2) {
					printf("%c", b);
				} else {
					printf(" ");
				} 
			} 
		}
		printf("\n");
	}
	return 0;
}
