#include <stdio.h>
#include <stdlib.h>

int main() {
	const double eps = 10e-10;
	double matrica[100][100];
	int redovi = -1, kolone = -1, teplicova = 1, cirkularna = 1;
	int i, j;
	do{
		printf("Unesite M i N: ");
		scanf("%d", &redovi);
		scanf("%d", &kolone);
		if(redovi <= 0 || redovi > 100 || kolone <= 0 || kolone > 100){
			printf("Pogresan unos!\n");
			continue;
		}
			
	}while (redovi <= 0 || redovi > 100 || kolone <= 0 || kolone > 100);
	/* Unos matrice */
	printf("Unesite elemente matrice: ");
	for(i = 0; i < redovi; ++i)
		for(j = 0; j < kolone; ++j)
			scanf("%lf", &matrica[i][j]);
	
	if(redovi == 1){
		printf("Matrica je cirkularna");
		return 0;
	}
	else if(kolone == 1){
		printf("Matrica je Teplicova");
		return 0;
	}
	
	for(i = 0; i < redovi - 1; ++i)
		for(j = 0; j < kolone - 1; ++j) {
			if( abs(matrica[i][j] - matrica[i + 1][j + 1]) > eps){
				teplicova = 0;
				goto IZLAZ_TEPLICOVE;
			}
		}
	IZLAZ_TEPLICOVE:
	/* Provjera cirkularne */
	for(i = 0; i < redovi - 1; ++i)
		for(j = 0; j < kolone - 1; ++j){
			if(abs (matrica[i][j] - matrica[i + 1][j + 1]) > eps){
				cirkularna = 0;
				goto IZLAZ_CIRKULARNE;
			}
			if(j == kolone - 2  && abs(matrica[i][j + 1] - matrica[i+1][0]) > eps ){
				cirkularna = 0;
				goto IZLAZ_CIRKULARNE;
			}
		}
	
	IZLAZ_CIRKULARNE:
	if(cirkularna){
		printf("Matrica je cirkularna");
	}
	else if(teplicova){
		printf("Matrica je Teplicova");
	}
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
