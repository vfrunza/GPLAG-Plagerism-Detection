#include <stdio.h>

int main(){
	
	int m, n, i, j, matrica_A[100][100], matrica_B[100][100], matrica_C[100][100], niz_A[10000], niz_B[10000], niz_C[10000], min, tmp, temp, pomocna, ista_B = 1, ista_C = 1;
	
		
	do
	{
	printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}while(m > 100 || m < 0 || n > 100 || n < 0);
	
	printf("Unesite clanove matrice A: ");
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &matrica_A[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &matrica_B[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	
	for(i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			scanf("%d", &matrica_C[i][j]);
		}
	}
	// elemente matrica A, B i C cemo da poredamo u nizove radi alkseg poredjenja
	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			niz_A[i * m + j] = matrica_A[i][j];
		}
		
	}
	for(i = 0; i < m; i++){								
		for(j = 0; j < n; j++){
			niz_B[i * m + j] = matrica_B[i][j];
		}
		
	}
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			niz_C[i * m + j] = matrica_C[i][j];
		}
		
	}
	// sortiranje nizva koje smo dobili od matrica da bi dobili isti poredak elemenata, svejedno je kakvo je sortiranje

	for( i = 0; i < m * n; i++){
		min = i;
		for(j = i + 1; j <m * n; j++){
			if (niz_A[j] < niz_A[min])
			min = j;
			
		}
		temp = niz_A[i];
		niz_A[i] = niz_A[min];
		niz_A[min] = temp;
	}
	
	
	 for( i = 0; i < m *n; i ++){
	 	min = i;
	 	for(j = i +1; j < m * n; j++){
	 		if (niz_B[j] < niz_B[min])
	 		min = j;
	 	}
	 	tmp = niz_B[i];
	 	niz_B[i] = niz_B[min];
	 	niz_B[min] = tmp;
	 }
	 
	 for( i = 0; i < m * n; i++){
	 	min  = i;
	 	for( j = i + 1; j < m * n; j++){
	 		if(niz_C [j] < niz_C[min])
	 		min = j;
	 	}
	 	pomocna = niz_C[i];
	 	niz_C[i] = niz_C[min];
	 	niz_C[min] = pomocna;
	 }
	
	for( i= 0; i < m * n; i++){
		if (niz_A[i] != niz_B[i]){
			ista_B = 0;
			break;
		}
	}
	for( i = 0; i < m *n; i++){
		if(niz_A[i] != niz_C[i]){
			ista_C = 0;
			break;
		}
	}
	if(ista_C == 1 && ista_B == 1) printf("DA");
	else printf("NE");
	return 0;
}