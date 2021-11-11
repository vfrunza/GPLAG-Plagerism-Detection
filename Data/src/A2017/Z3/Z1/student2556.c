#include <stdio.h>
int dva_od_tri (int niz_A[100], int duzina_A, int niz_B[100], int duzina_B, int niz_C[100], int duzina_C)
{
	int pomocni_niz_A[100]= {0}, pomocni_niz_B[100]= {0}, pomocni_niz_C[100]= {0};
	int i, j, k;
	int broj_u_dva_niza = 0;
	int max_A = pomocni_niz_A[0], max_B = pomocni_niz_B[0], max_C = pomocni_niz_C[0];
	int zamjena;

	for(i = 0; i < duzina_A ; i++){
		pomocni_niz_A[i] = niz_A[i];
	}	
	
	for(i = 0; i < duzina_B ; i++){
		pomocni_niz_B[i] = niz_B[i];
	}	
	
	for(i = 0; i < duzina_C ; i++){
		pomocni_niz_C[i] = niz_C[i];
	}	

	for(i = 0; i < duzina_A ; i++) {
		for(j = i+1; j < duzina_A ; j++) {

			if(pomocni_niz_A[i] == pomocni_niz_A[j]) {
				for(k = j; k < duzina_A ; k++) {
					pomocni_niz_A[k] = pomocni_niz_A[k+1];
					
				}
				j--;
				duzina_A--;
			} else continue;

		}
	}

	for(i = 0; i < duzina_B ; i++) {
		for(j = i+1; j < duzina_B ; j++) {
			if(pomocni_niz_B[i] == pomocni_niz_B[j]) {
				for(k = j; k < duzina_B ; k++) {
					pomocni_niz_B[k] = pomocni_niz_B[k+1];
					
				}
				j--;
				duzina_B--;
			} else continue;
		}
	}

	for(i = 0 ; i < duzina_C ; i++) {
		for(j = i+1 ; j < duzina_C ; j++) {
			if(pomocni_niz_C[i] == pomocni_niz_C[j]) {
				for(k = j; k < duzina_C ; k++) {
					pomocni_niz_C[k] = pomocni_niz_C[k+1];
					
				}
				j--;
				duzina_C--;
			} else continue;
		}
	}

	for(i = 0; i < duzina_A - 1 ; i++) {
		for(j = 0; j < duzina_A - 1 ; j++) {
			if(pomocni_niz_A[j] < max_A) {
				zamjena = pomocni_niz_A[j];
				pomocni_niz_A[j] = max_A;
				max_A = zamjena;
			}
		}
	}

	for(i = 0; i < duzina_B - 1 ; i++) {
		for(j = 0; j < duzina_B - 1 ; j++) {
			if(pomocni_niz_B[j] < max_B) {
				zamjena = pomocni_niz_B[j];
				pomocni_niz_B[j] = max_B;
				max_B = zamjena;
			}
		}
	}
	for(i = 0; i < duzina_C - 1 ; i++) {
		for(j = 0; j < duzina_C - 1 ; j++) {
			if(pomocni_niz_C[j] < max_C) {
				zamjena = pomocni_niz_C[j];
				pomocni_niz_C[j] = max_C;
				max_C = zamjena;
			}
		}
	}

	for(i = 0 ; i < duzina_A ; i++) {
		for(j = 0 ; j < duzina_B ; j++) {
			if(pomocni_niz_A[i] == pomocni_niz_B[j])
				broj_u_dva_niza++;
		}
	}
	for(i = 0 ; i < duzina_A ; i++) {
		for(j = 0 ; j < duzina_C ; j++) {
			if(pomocni_niz_A[i] == pomocni_niz_C[j])
				broj_u_dva_niza++;
		}
	}
	for(i = 0 ; i < duzina_C ; i++) {
		for(j = 0 ; j < duzina_B ; j++) {
			if(pomocni_niz_C[i] == pomocni_niz_B[j])
				broj_u_dva_niza++;
		}
	}
	
	for(i = 0 ; i < duzina_A ; i++){
		for(j = 0 ; j < duzina_B ; j++){
			for(k = 0 ; k < duzina_C ; k++){
				if(pomocni_niz_A[i] == pomocni_niz_C[k] && pomocni_niz_B[j] == pomocni_niz_C[k])
				broj_u_dva_niza = broj_u_dva_niza - 3;
			}
		}
	}
	
	return broj_u_dva_niza;
}
int main()
{
	int broj_u_dva_niza;
	int i;
	int broj_clanova_A, broj_clanova_B, broj_clanova_C;
	int nizA[100], nizB[100], nizC[100];

	printf("Unesite broj clanova niza A: ");
	scanf("%d", &broj_clanova_A);
	printf("Unesite niz A: ");
	for(i=0; i<broj_clanova_A; i++) {
		scanf("%d", &nizA[i]);
	}
	printf("Unesite broj clanova niza B: ");
	scanf("%d", &broj_clanova_B);
	printf("Unesite niz B: ");
	for(i=0; i<broj_clanova_B; i++) {
		scanf("%d", &nizB[i]);
	}
	printf("Unesite broj clanova niza C: ");
	scanf("%d", &broj_clanova_C);
	printf("Unesite niz C: ");
	for(i=0; i<broj_clanova_C; i++) {
		scanf("%d", &nizC[i]);
	}

	broj_u_dva_niza = dva_od_tri(nizA, broj_clanova_A, nizB, broj_clanova_B, nizC, broj_clanova_C);

	printf("%d", broj_u_dva_niza);
	return 0;
}
