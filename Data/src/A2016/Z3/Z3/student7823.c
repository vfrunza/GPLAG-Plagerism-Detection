#include <stdio.h>

void ukloniKolonu(int matrica[200][200], int *M, int *N, int kolona);
void ukloniRed(int matrica[200][200], int *M, int *N, int red);

void IzbaciDupleRedove(int matrica[200][200], int *M, int *N, int red);
void IzbaciDupleKolone(int matrica[200][200], int *M, int *N, int kolona);

void printajMatricu(int matrica[200][200], int M, int N);

int main(){
	//printf("Zadaća 3, Zadatak 3");
	int i,j,k;
	int M,N;
	int matrica[200][200];
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &M, &N);
		if(M<=0 || M>200 || N<=0 || N>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<=0 || M>200 || N<=0 || N>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	
	for(i=0; i<M; i++)
		IzbaciDupleRedove(matrica, &M, &N, i);
	for(i=0; i<N; i++)
		IzbaciDupleKolone(matrica, &M, &N, i);
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	printajMatricu(matrica, M, N);
	return 0;
}
void printajMatricu(int matrica[200][200], int M, int N){
	int i, j;
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}
}
void ukloniRed(int matrica[200][200], int *M, int *N, int red){
	int i, j;
	for(i=red; i<*M-1; i++) {
		for(j=0; j<*N; j++) {
			matrica[i][j]=matrica[i+1][j];
		}
	}
	(*M)--;
}
void ukloniKolonu(int matrica[200][200], int *M, int *N, int kolona){
	int i, j;
	for(j=kolona; j<*N-1; j++) {
		for(i=0; i<*M; i++) {
			matrica[i][j]=matrica[i][j+1];
		}
	}
	(*N)--;
}

void IzbaciDupleRedove(int matrica[200][200], int *M, int *N, int red){
	int i, j, k;
	for(k=red; k<*M; k++) {								//Prolazi onoliko puta koliko ima redova izmedju reda koji se provjerava i zadnjeg
		for(i=red+1; i<*M; i++) {						
			for(j=0; j<*N; j++) {						//Prolazi kroz kolone redova, ako vrijednosti nisu jednake prelazi na sljedeci red
				if(matrica[red][j]!=matrica[i][j])			//ako jesu nastavlja ili dok nisu jednake ili dok ne dosegne kraj reda
					break;
				if(j==(*N)-1) {
					ukloniRed(matrica, M, N, i);		//Kad dosegne kraj reda izbaci taj red iz matrice
				}
			}
		}
	}
}

void IzbaciDupleKolone(int matrica[200][200], int *M, int *N, int kolona){
	int i, j, k;
	for(k=kolona; k<*N; k++) {							//Prolazi onoliko puta koliko ima kolona izmedju kolone koja se provjerava i zadnje
		for(j=kolona+1; j<*N; j++) {
			for(i=0; i<*M; i++) {						//Prolazi kroz redove kolona, ako vrijednosti nisu jednake prelazi na sljedeci red
				if(matrica[i][kolona]!=matrica[i][j])		//ako jesu nastavlja ili dok nisu jednake ili dok ne dosegne kraj reda
					break;
				if(i==(*M)-1) {
					ukloniKolonu(matrica, M, N, j);		//Kad dosegne kraj kolone izbaci tu kolonu iz matrice
				}
			}
		}
	}
}