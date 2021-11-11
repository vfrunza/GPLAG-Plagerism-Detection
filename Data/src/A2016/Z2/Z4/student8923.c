#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define R 100
#define DONJA_GRANICA 1

int main() {
	double Mat[R][R];
	int teplic=1,cirkular=1;
	int A,B,i,j;
	double const EPS=1e-10;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &A, &B);
		if(A>R || B>R || A<DONJA_GRANICA || B<DONJA_GRANICA)
		   printf("Pogresan unos!\n");
	}while(A>R || B>R || A<DONJA_GRANICA || B<DONJA_GRANICA);
	
	/*Unos matrice realnih brojeva*/
	printf("Unesite elemente matrice: ");
	for(i=0;i<A;i++){
		for(j=0;j<B;j++){
			scanf("%lf", &Mat[i][j]);
		}
	}
	
	for(i=0;i<A-1;i++){
		for(j=0;j<B-1;j++){
				/*poredi elemente na svim dijagonalama koji su paralelni glavnoj dijagonali*/
			    if(fabs(Mat[i][j] - Mat[i+1][j+1]) > EPS)
				   teplic=0;
				/*poredi elemente sa kraja reda da li se ponavljaju u prvoj koloni matrice, ako ne onda nije cirkularna*/   
				if(fabs(Mat[i][B-1] - Mat[i+1][0]) > EPS)
				   cirkular=0;
			}
	}
	/*Svaka matrica sa samo jednom kolonom je Teplicova*/
	if(B==1 && A!=1){
		teplic=1;
		cirkular=0;
	}
	if(teplic){
		if(cirkular) printf("Matrica je cirkularna");
		else printf("Matrica je Teplicova");
	}else{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
