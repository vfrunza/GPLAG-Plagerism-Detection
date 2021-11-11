#include <stdio.h>

int main() {
	int pocetni[100],finalni[100];
	int vel;
	int i,j;
	int velicina = 0 ; 
	int cifra = 0 ;
	int vell = 0;
	int konacni[100];
	int brojac = 0 ;
	
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&vel);
		if( vel <= 0 ) printf("Ponovite unos!");
	}while(vel <= 0);
	
	printf("Unesite clanove niza: ");
	for(i = 0 ; i < vel ; i++){
		scanf("%d",&pocetni[i]);
	}
	velicina = 0 ;
	for( i = 0 ; i < vel; i++){
		while(pocetni[i] != 0){
			cifra = pocetni[i] % 10;
			pocetni[i] /= 10;
			finalni[velicina] = cifra;
			velicina++;
		}
	}
	
	
	for( i = 0 ; i < velicina; i++){
		for( j = i ; j < velicina - 1; j++){
			if(finalni[j] = finalni[j+1]) brojac++;
		}
		konacni[vell] = finalni[i];
		konacni[vell+1] = brojac;
		vell++;
	}
	
	printf("Konacni niz: ");
	for( i = 0 ; i < vell; i++){
		printf("%d ",konacni[i]);
	}
	return 0;
}
