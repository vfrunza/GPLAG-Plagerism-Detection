#include <stdio.h>

#define size 101

int main() {
	
	int m, n, A[size][size], B[size][size], C[size][size];
	int brA[size*size], brB[size*size], brC[size*size];
	int i, j;
	int min;
	
	do{
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d", &m, &n);
	}while(n < 0 || n > 100 || m < 0 || m > 100);
	
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < m; i++){
	    for(j = 0; j < n; j++){
	        scanf("%d", &A[i][j]);
	    }
	}
	
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < m; i++){
	    for(j = 0; j < n; j++){
	        scanf("%d", &B[i][j]);
	    }
	}
	
	printf("Unesite clanove matrice C: ");
	for(i = 0; i < m; i++){
	    for(j = 0; j < n; j++){
	        scanf("%d", &C[i][j]);
	    }
	}

	/*2D to arr*/
	i = 0;
	j = 0;
	int jj = 0;
	
	while(1){
		brA[j] = A[i][jj];
		brB[j] = B[i][jj];
		brC[j] = C[i][jj];
		
		j++;
		jj++;
		
		if(jj >= n) {
			jj = 0;
			i++;
		}
		
		if(i >= m) break;
	}
	
	int minA, minB, minC;
	int temp;
	
	for(i = 0; i < m*n; i++){
		/*A*/
		minA = i;
		
		for(j = i; j < m*n; j++){
			if(brA[j] < brA[minA]){
				minA = j;
			}
		}
		
		temp = brA[minA];
		brA[minA] = brA[i];
		brA[i] = temp;
	}
	
	
	for(i = 0; i < m*n; i++){
		/*B*/
		minB = i;
		
		for(j = i; j < m*n; j++){
			if(brB[j] < brB[minB]){
				minB = j;
			}
		}
		
		temp = brB[minB];
		brB[minB] = brB[i];
		brB[i] = temp;
	}
	
	for(i = 0; i < m*n; i++){
		/*C*/
		minC = i;
		
		for(j = i; j < m*n; j++){
			if(brC[j] < brC[minC]){
				minC = j;
			}
		}
		
		temp = brC[minC];
		brC[minC] = brC[i];
		brC[i] = temp;
	}
		
	int same = 1;
	
	for(i = 0; i < m*n; i++){
		if(brC[i] != brA[i] || brB[i] != brA[i]){
			same = 0;
			break;
		}
	}
	
	if(same)
		printf("DA\n");
	else
		printf("NE\n");
	
	
	return 0;
}
