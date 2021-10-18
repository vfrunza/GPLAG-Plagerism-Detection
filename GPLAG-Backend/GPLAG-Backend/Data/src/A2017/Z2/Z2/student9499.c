#include <stdio.h>
#include <stdlib.h>

#define s_SIZE 100
#define f_SIZE 1000
#define leftB 0
#define rightB 100

int main() {
	/* initial */
	int A[s_SIZE], C[f_SIZE] = {0}, i, n, N_SIZE, temp, p_num, n_num;
	n = 0;
	/* input */
	do {
		printf("Unesite velicinu niza: "); scanf("%d", &n); 
	} while(n < leftB || n > rightB);
	printf("Unesite clanove niza: ");
	for(i = 0; i < n; i++) {
		do scanf("%d", &A[i]);
		while(A[i] < leftB);
	}
	/* calculate */
	i = n-1;
	N_SIZE = 0; /* size of new array */
	p_num = -1;
	temp = A[i];
	
	if(A[i] == 0) {
		N_SIZE = 1;
		C[1] = 0;
		C[0] = 1;
		p_num = 0;
	}
	
	while(i >= 0) {
		if(temp >= 1)
			n_num = temp%10;
		else {
			if(--i == -1) break;
			temp = A[i];
			n_num = temp%10;
		}
		if(p_num == n_num) 
			C[N_SIZE-1]+=1;
		else { 
			if(N_SIZE > 0) N_SIZE++;
			C[N_SIZE] = 1;
			C[++N_SIZE] = n_num;
			p_num = n_num;
		}
		temp = temp/10;
	}
	/* output */
	printf("Finalni niz glasi: \n");
	for(i = N_SIZE; i >= 0; i--) 
		printf("%d ", C[i]);
	printf("\n");
	return 0;
}