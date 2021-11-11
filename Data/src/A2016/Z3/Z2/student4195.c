#include <stdio.h>
#include <stdlib.h>

void ubaci(int *niz, int velicina) {
	int velicina_2=velicina, suma_cifara,clan_nije_novi=1,broj,*adresa_pocetnog = niz,*q,temp;
	velicina*=2;
	for(; niz<adresa_pocetnog + velicina; niz++) {
		suma_cifara=0;
		if(clan_nije_novi)
			clan_nije_novi=0;
		else if (!clan_nije_novi) {
			clan_nije_novi = 1;
			continue;
		}
		broj=abs(*niz);
		do{
			suma_cifara+=broj%10;
			broj/=10;
		}while(broj>0);
		/*Sljedecom petljom cemo ubaciti novi clan, prepisati sve ostale na jedno mjesto "udesno" i povecati velicinu niza za 1*/
		for(q=niz+1; q<=adresa_pocetnog+velicina_2; q++) {
			if(q!=adresa_pocetnog+velicina_2)
				temp=*q;
			*q=suma_cifara;
			if(q!=adresa_pocetnog+velicina_2)	
				suma_cifara = temp;
		}
		velicina_2++; 
	}
}

int fibonnacijeva_funkcija (int broj) {
	int fibonacijev_broj_1=1,fibonacijev_broj_2=2,temp;
	if(broj==1)
		return 1;
	 while (1){
		temp = fibonacijev_broj_2 + fibonacijev_broj_1;
		fibonacijev_broj_1 = fibonacijev_broj_2;
		fibonacijev_broj_2 = temp;
		if(broj==fibonacijev_broj_1 || broj==fibonacijev_broj_2 ) {
			return 1;
			break;
		}
		else if (broj<fibonacijev_broj_1 || broj<fibonacijev_broj_2){
			return 0;
			break;
		}
	}
}


int izbaci (int *niz, int velicina) {
	int *q,temp,*adresa_pocetnog = niz;
	for(; niz<adresa_pocetnog+velicina; niz++) {
		if(*niz>0 && fibonnacijeva_funkcija(*niz)) {
			/*Izbacujemo clan iz niza tako sto ga "guramo" za jedno mjesto naprijed sve do kraja niza i na kraju smanjimo velicinu za 1*/
			for(q=niz; q<adresa_pocetnog + velicina - 1; q++) {
				temp = *q;
				*q = *(q+1);
				*(q+1) = temp;
			}
			velicina--;
			niz--;
		}
		
	}
	return velicina;
	
}

int main() {
	int velicina_niza=10;
	int niz[20] ,i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<velicina_niza; i++) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,velicina_niza);
	/*Velicina niza se udvostrucila*/
	velicina_niza*=2;
    velicina_niza = izbaci(niz,velicina_niza);
	printf("Modificirani niz glasi: ");
	for(i=0; i<velicina_niza; i++) {
		if(i==velicina_niza-1)
			printf("%d.", niz[i]);
		else	
			printf("%d, ", niz[i]);
	}
	return 0;
}
