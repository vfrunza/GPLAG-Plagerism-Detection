#include <stdio.h>


int poredi_redove(int matrica[][200], int poredi, int sa, int velicina){
	int i = 0;
	for(; i < velicina; ++i){
		if(matrica[sa][i] != matrica[poredi][i] )
			return 0;
	}
	return 1;
}

void izbaci_red(int matrica[][200], int broj_redova, int broj_kolona, int mjesto){
	int i = mjesto + 1;
	for(; i < broj_redova; ++i){
		int j = 0;
		for(; j  < broj_redova; ++j)
			matrica[i-1][j] = matrica[i][j];
	}
}

void izbaci_specijalno_red(int matrica[][200], int broj_redova, int mjesto) {
	int i = mjesto + 1;
	for(; i < broj_redova; ++i){
		matrica[i - 1][0] = matrica[i][0];
	}
}

int izbaci_iste_redove(int matrica[][200], int broj_redova, int broj_kolona){
	int i = 0;
	for(; i < broj_redova - 1; ++i){
		int j = i + 1;
		for(; j < broj_redova; ++j)
			if(poredi_redove(matrica, i, j, broj_kolona) ){
				izbaci_red(matrica, broj_redova, broj_kolona, j);
				--j;
				--broj_redova;
			}
	}
	return broj_redova;
}

int poredi_kolone(int matrica[][200], int broj_redova, int poredi, int sa){
	int i = 0;
	for(; i < broj_redova; ++i)
		if(matrica[i][poredi] != matrica[i][sa])
			return 0;
	return 1;
}

void izbaci_kolonu(int matrica[][200], int broj_redova, int broj_kolona, int mjesto){
	int i = 0;
	for(; i < broj_redova; ++i){
		int j = mjesto + 1;
		for(; j < broj_kolona; ++j)
			matrica[i][j-1] = matrica[i][j];
	}
}


int izbaci_iste_kolone(int matrica[][200], int broj_redova, int broj_kolona){
	int i = 0;
	for(; i < broj_kolona - 1; ++i){
		int j = i + 1;
		for(; j < broj_kolona; ++j)
			if(poredi_kolone(matrica, broj_redova, i, j)){
				izbaci_kolonu(matrica, broj_redova, broj_kolona, j);
				--j;
				--broj_kolona;
			}
	}
	return broj_kolona;
}



int main() {
	int matrica[200][200] = {{0}};
	int M, N;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d", &M);
		scanf("%d", &N);
		if(M <= 0 || M > 200 || N <= 0 || N > 200){
			printf("Brojevi nisu u trazenom opsegu.\n");
			continue;
		}
	}while(M <= 0 || M > 200 || N <= 0 || N > 200);
	printf("Unesite elemente matrice: ");
	int i = 0, j = 0;
	for(; i < M; ++i)
		for(j = 0; j < N; ++j)
			scanf("%d", &matrica[i][j]);
	M = izbaci_iste_redove(matrica, M, N);
	N = izbaci_iste_kolone(matrica, M, N);
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i = 0; i < M; ++i){
		for(j = 0; j < N; ++j)
			printf("%5d", matrica[i][j]);
		printf("\n");	
	}
	return 0;
}
