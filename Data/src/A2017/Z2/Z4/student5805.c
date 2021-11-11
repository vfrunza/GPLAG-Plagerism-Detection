#include <stdio.h>

int main() {
	int A[10000],B[10000],C[10000],m,n,i,j,temp,min;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}while(m>100 || n>100);
	int vel=m*n;
	printf("Unesite clanove matrice A: ");
	for(i=0; i<vel; i++) {
		scanf("%d", &A[i]);
	}
		printf("Unesite clanove matrice B: ");
	for(i=0; i<vel; i++) {
		scanf("%d", &B[i]);
	}
		printf("Unesite clanove matrice C: ");
	for(i=0; i<vel; i++) {
		scanf("%d", &C[i]);
	}
	for (i=0; i<vel; i++) {
		min=i;
		for (j=i+1; j<vel; j++) { 
			if (A[j] < A[min]) min = j; }
			temp = A[i]; 
			A[i] = A[min]; 
			A[min] = temp;
			}
	for (i=0; i<vel; i++) {
		min=i;
		for (j=i+1; j<vel; j++) { 
			if (B[j] < B[min]) min = j; }
			temp = B[i]; 
			B[i] = B[min]; 
			B[min] = temp;
			}
	for (i=0; i<vel; i++) {
		min=i;
		for (j=i+1; j<vel; j++) { 
			if (C[j] < C[min]) min = j; }
			temp = C[i]; 
		    C[i] = C[min]; 
			C[min] = temp;
			}
			for(i=0; i<vel; i++) {
				if(A[i]!=B[i] || A[i]!=C[i]) {
					printf("NE\n");
					return 0;
				}
			}
			printf("DA");
			
	return 0;
}
