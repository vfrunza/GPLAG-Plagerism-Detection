#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define MAX_EL 100

int main() {
	double matrica[MAX_EL][MAX_EL]={{0,0}};
	int M, N,i,j,k,teplicova = 1,cirkularna=1;

	/*Provjeri da li je unos ispavan*/
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M<=0 || M>100 ||N<=0 || N>100)
			printf("Pogresan unos!\n");
	}while(M<=0 || M>100 ||N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf",&matrica[i][j]);
		}
	}
	
	/*Uporedimo sve clanove svih dijagonala sa prvim te dijagonale i cim naidjemo na neki da nije isti, onda prekidamo sav proces 
	  i zakljucimo da matrica nije teplicova*/
	for(i=0; i<M-1; i++) {
		if(!teplicova)
			break;
		/* U prvom redu cemo provjeravati sve dijagonale koje pocinju za svako j koje je manje od N-1*/
		if(i==0) {
			for(j=0; j<N-1; j++) {
				if(!teplicova)
					break;
				for(k=1; ; k++) {
					if(k+i==M || k+j==N)
						break;
					else {
						if(fabs(matrica[i][j]-matrica[i+k][j+k])>EPSILON) {
						teplicova=0;
						cirkularna=0;
						}
					}
				}
			}
		}
		
		/* U ostalim redovima i>0 provjeravamo samo dijagonale koje pocinju sa prvim clanom tog reda, jer smo ostale vec provjerili
		Pa nema potrebe da to vise puta radimo za svaki clan tih dijagonala jer smanjujemo efikasnost programa */
		else {
			for(j=0; j<1; j++) {
				if(!teplicova)
					break;
				for(k=1; ; k++) {
					if(k+i==M || k+j==N)
						break;
					else {
						if(fabs(matrica[i][j]-matrica[i+k][j+k])>EPSILON){
						teplicova=0;
						cirkularna=0;
						}
					}
				}
			}
		}
		

	}
	
	if(teplicova) {
		for(i=0; i<M-1; i++) {
			if(!cirkularna)
				break;
			if(fabs(matrica[i][N-1]-matrica[i+1][0])>EPSILON){
				cirkularna=0;
				break;
			}
		}
	}
	
	/*Ispis matrica*/
	if(cirkularna)
		printf("Matrica je cirkularna");
    else if(teplicova) 
		printf("Matrica je Teplicova");
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
