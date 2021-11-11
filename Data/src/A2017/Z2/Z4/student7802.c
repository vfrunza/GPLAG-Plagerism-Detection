#include <stdio.h>

int main() {
	int M,N,i,j;
	int A[100][100], B[100][100], C[100][100];
	int m,n, brojac2,brojac3,brojac1;
	
	/*Unos brojeva M i N i provjera da li su M i N u tacnom intervalu*/
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	} while(M > 100 || N > 100);
	
	/*Unos elemenata matice A*/
	printf("Unesite clanove matrice A: ");
	
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	/*Unos elemenata matrice B*/
	printf("Unesite clanove matrice B: ");
	
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &B[i][j]);
		}
	}
	
	/*Unos elemenata marice C*/
	printf("Unesite clanove matrice C: ");
	
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &C[i][j]);
		}
	}
	

	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			
			brojac1=0;
			brojac2=0;
			brojac3=0;
			
			for(m = 0; m < M; m++){
				for(n = 0; n < N; n++){
					
					/*Uporedivanje matrice A sa samom sobom*/
					if(A[i][j] == A[m][n]){	
						brojac1++;	
					}
					/*Uporedivanje matrice A sa matricom B*/
					if(A[i][j] == B[m][n]){
						brojac2++;
					}
					/*Uporedevinje matrice A sa matricom C*/
					if(A[i][j] == C[m][n]){
						brojac3++;
					}
				}
			}	
			/*Uporedivanje brojaca sve tri matrice*/
			if(brojac1 != brojac3 || brojac2 != brojac3){
			printf("NE");	
			return 0;
			}
			
		}
	}
	printf("DA");
	return 0;
}