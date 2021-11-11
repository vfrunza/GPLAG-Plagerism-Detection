#include <stdio.h>
#include <math.h>
// funkcija za aokruzivanje broja na 1 decimalu 
void zaokruzi1 (float niz[], int velicina){
	int i;
	
	for( i = 0; i < velicina; i++){
		niz[i] = niz[i] * 10;
		niz[i] =  round (niz[i]);
		niz[i] = niz[i] / 10;
	}
}

void preslozi (float niz[], int velicina, int k){
	int i, cifra, manjih = 0, vecih = 0 ,minus = 0, suma, broj, velicina_novog = 0, velicina_drugog = 0, j;
	float  novi_niz[100], novi_niz2[100];
	zaokruzi1(niz, velicina);
	
	for(i = 0; i < velicina; i ++){
		if (niz[i] < 0){    // provjeravamo da li je broj negativan 
			minus = 1;
			niz[i] = - niz[i];
		}
		
		else minus = 0;
		suma = 0;
		broj = niz[i] * 10; // da ne bi radili sa decimalnim brojem, mnozimo sa 10, jer znamo da je svaki broj zaokruzen na jednu decimalu
		// rastavljanje broja na cifre
		do{
			cifra = broj % 10;
			broj = broj /10;
			suma += cifra;
			
		}while(broj != 0);
		// pravimo dva niza, prvi sacinjen od onih brojeva kojima je suma cifara veca od broja k, a drugi od brojeva kojima je suma cifara manja od k
		if( suma >= k) {
			if(minus == 1 )novi_niz[velicina_novog ++] = - niz[i];
			else novi_niz[velicina_novog ++] = niz[i];
		}
		
		else{
			if(minus == 1)novi_niz2[velicina_drugog++] = -niz[i];
			else novi_niz2[velicina_drugog++] = niz[i];
		}
	}
	// spajanje ta dva niza, dati ce nas niz u zeljenom poretku
	for(j = i = 0; i < velicina_novog + velicina_drugog ; i ++){
		if( i >= velicina_novog){ niz[i] =  novi_niz2[j]; j++;}
		else niz[i] = novi_niz[i];
	}

	
}




int main() {
	printf("Unesite niz brojeva tipa float: ");
	float niz[4];
	int i ;
	
	for (i = 0; i < 4; i++){
		scanf("%f", &niz[i]);
	}
	
	printf("\n Nakon zaokruzivanja: \n");
	
	zaokruzi1(niz, 4);
	
	for (i = 0; i < 4; i++){
		printf("%f", niz[i]);
	}
	
	return 0;
}
