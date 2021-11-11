#include <stdio.h>
#include <stdlib.h>
int main() {
	int br_M, br_N;
	int T = 1;
	int C = 1;
	int i, j;
	double K[100][100]; /*double koristimo jer je precizniji kod poređenja*/
	printf("Unesite M i N: ");
	scanf("%d %d", &br_M, &br_N);
	/*Opseg brojeva je ogranicen*/
	while(br_M < 1 ||br_N < 1 || br_M > 100 || br_M > 100){
		
		printf("Pogresan unos!");
		printf("\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &br_M, &br_N);
	}
		printf("Unesite elemente matrice: ");
		/*Unos elemenata matrice*/
		for (i = 0; i < br_M; i++){
			for(j = 0; j < br_N; j++){
				scanf("%lf", &K[i][j]);
			}
		}
		if(br_M == 1 && br_N == 1 ){
			printf("Matrica je cirkularna");
			
		}
		else if(br_M == 1 ){
			printf("Matrica je cirkularna"); /*Granicni slucaj*/
			
		}
		else if (br_N == 1){
			printf("Matrica je Teplicova");
			
		} else  {
			for(i = 1; i < br_M; i++){
				if (K[i][0] != K[i-1][j-1]){ /*Da bi matrica bila cirkularna, mora vrijediti da je zadnji elemenat 
				jednog reda jednak prvom elementu sljedeceg reda, sto smo provjerili sa if-om*/
					C = 0;
				}
				for(j = 1; j < br_N; j++){ /*Provjera ostalih po dijagonali*/
					if (K[i][j] != K[i-1][j-1]){
						C = 0;
					}
				}
			}
			for(i = 0; i < br_M - 1; i++){
				for(j = 0; j < br_N - 1; j++){
					if(K[i][j] != K[i+1][j+1]){
						T = 0;
					}
				}
			}
			if(C == 1){/*Unutar prethodne petlje ako naiđe bar na jedan elemenat
				 		koji ne zadovoljava uslov cirkularne matrice, "C" ce s promijeniti na 0,
						a ako vrijednost ostane 1,zakljucujemo da svi elementi zadovoljovaju sto 
							smo ovdje i provjerili.*/
			printf("Matrica je cirkularna");
			
			}
			else if (T == 1){
				printf("Matrica je Teplicova");
				
			} 
			else{ 
				printf("Matrica nije ni cirkularna ni Teplicova");
			}
		}
	return 0;
}
