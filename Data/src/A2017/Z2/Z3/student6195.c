#include <stdio.h>
#include <math.h>
#define VISINA 100
#define SIRINA 100
#define eps 0.0001
int main() {
	int i,j,a,b,c,d,matrice_iste;
	float matA[SIRINA][VISINA];
	float matB[SIRINA][VISINA];
	/*unos matrica A, B redom, ali prvo se unose dimenzija matrica pa elementi matrica*/
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&a, &b);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<b; i++){
		for(j=0; j<a; j++){
		scanf("%f",&matA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&c, &d);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<d; i++){
		for(j=0; j<c; j++){
		scanf("%f", &matB[i][j]);
	}
}	/* postavljamo logicku promjenljivu na 1, tako da vrijedi za svako x, primjer zadataka sa predavanja 10*/
		matrice_iste=1;
		/* kada se matrica A translatira za 90, onda sirina nase polazne matrice A mora biti jednaka visini matrice B i obratno*/
			if(a-d!=0 ||b-c!=0){
			printf("NE\n");
					return 0;
			}	
		/* petlja koja ce biti oblika kao i matrica B jer B nam je "referentna" matrica*/
		/*poredimo elemente matrice B i elemente matrice A zarotirane za 90, linija 37 uslov zapisan*/
		for(i=0; i<d; i++){
			for(j=0; j<c; j++){
			if(fabs(matB[i][j]-matA[b-j-1][i])>eps){
			matrice_iste=0;
			break;}
		}
	}
	if(matrice_iste==0)	printf("NE\n");
	else if (matrice_iste==1) printf("DA\n");
	return 0;
}
