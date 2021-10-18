#include <stdio.h>


void *zaokruzi1 (double niz[], int vel){
	int i , j ;
	int suma = 0 ;
	
	for( i = 0 ; i < vel ; i++){
		niz[i] = (int)(niz[i]+0.5);
	}
	
	return niz;
}

int Suma (double broj){
	int suma = 0;
	int cifra = 0 ;
	int trazena = 0 ;
		trazena = (int)(broj) ;
		
		
	for(;;){
		cifra = trazena % 10;
		trazena /= 10;
		suma += cifra;
	}
	return suma;
}

double *preslozi (double niz[],int vel, int k){
	zaokruzi1(niz,vel);
	int i , j ; 
	double preslozen[100];
	int brojac = 0 ,novi_br = 0;
	
	for( i = 0 ; i < vel ; i++){
		for( j = 0 ; j < 100; j++){
			if(Suma(niz[i]) >= k) preslozen[j];
			brojac++;
		} 
	}
	
	for(i = 0 ; i < vel; i++){
		for( j = brojac ; j < 100; j++) {
			if(Suma(niz[i]) < k) {
				preslozen[j] = niz[i];
				novi_br++;
			}
		}
	}
	
	return preslozen;
	
}


int main() {
	double niz[100];
	int vel;
	double novi[100];
	
	int i ,k; 
	
	printf("Unesite velicinu niza: \n");
	scanf("%d",&vel);
	printf("\nUnesite elemente niza: \n");
	for( i = 0 ; i < vel ; i++){
		scanf("%lf",&niz[i]);
	}
	
	printf("\nUnesite broj k: \n");
	scanf("%d",&k);
	
	preslozi(niz,vel,k);
	
	printf("\nPRESLOZEN NIZ: \n");
	for(i = 0 ; i < vel ; i++ ){
		printf("%lf",niz[i]);
	}
	
	return 0;
}
