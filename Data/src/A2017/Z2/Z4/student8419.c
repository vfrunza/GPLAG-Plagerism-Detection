#include <stdio.h>

int main() {
	
	int m, n, temp, i, j, k, l, suma_A=0, suma_B=0, suma_C=0;
	int A[100][100], B[100][100], C[100][100];
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}
	
	while(m>100 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &C[i][j]);
		}
	}
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			
			temp=A[i][j];
			suma_A=0; 
			suma_B=0; 
			suma_C=0;
			
			for(k=0; k<m; k++) {
				for(l=0; l<n; l++) {
					if(temp==A[k][l]) suma_A++;
					if(temp==B[k][l]) suma_B++;
					if(temp==C[k][l]) suma_C++;
				}
			}
			
			if(suma_A!=suma_B || suma_A!=suma_C) {
				printf("NE");
				return 0;
			}
		}
	}
	
	printf("DA");
	
	return 0;
}
