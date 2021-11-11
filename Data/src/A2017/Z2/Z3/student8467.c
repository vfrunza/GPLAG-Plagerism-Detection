#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	int AS,AV,i,j,tc,tr;
	int BS,BV;
	int brojac = 0;
	double A[100][100];
	double B[100][100];
	double C[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &AS, &AV);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < AV; i++){
		for(j = 0; j < AS; j++){
			scanf("%lf", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &BS, &BV);
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < BV; i++){
		for(j = 0; j < BS; j++){
			scanf("%lf", &B[i][j]);
		}
	}
	/*ROTIRANJE MATRICE*/
	if(AS != BV || AV != BS){
		printf("NE");
		return 0;
	}else{
		for(i = 0, tc = BS - 1; i < AV; i++, tc--){
			for(j = AS-1, tr = BV - 1; j >= 0; j--, tr--){
				C[tr][tc] = A[i][j];
			}
		}
	}
	/*PROBNO PRINANJE OKRENUTE MATRICE*/
	int iste = 1;
	for(i = 0; i < BV; i++){
		for(j = 0; j < BS; j++){
			if(C[i][j] != B[i][j]){
				iste = 0;
				break;
			}
		}
		
	}
	/*UPOREĐIVANJE MATRICA*/
	/*
	for(i = 0; i < BV; i++){
		for(j = 0; j < BS; j++){
			if(fabs(C[i][j]-B[i][j]) < EPSILON){
				brojac++;
			}else{
				printf("NE");
				break;
			}
		}
	}
	*/
	if(iste){
		printf("DA");
	}else{
		printf("NE");
	}
	return 0;
}
