#include <stdio.h>
#include <math.h>

int daj_prost(){
	static unsigned long int prost=2,i=2,j;
	int prost_je=1;
	while(1){
		for(j=2;j<(unsigned long int)sqrt(i)+1;j++)
			if(i%j==0){
				prost_je=0;
				i++; 
				break;
			}
		if(prost_je){
			prost=i;
			i++;
			break;
		}
		prost_je=1;
	}
	return prost;
}

int main() {
    long int broj_a,broj_b;
	unsigned long int suma=0,prost_broj;
	while(1){
		printf("Unesite brojeve A i B: ");
		scanf("%ld", &broj_a);
		scanf("%ld", &broj_b);
		if(broj_a<1) printf("A nije prirodan broj.\n");
		else if(broj_b<=broj_a) printf("A nije manje od B.\n");
		else break;
	}
	while(1){
		prost_broj=daj_prost();
		if(broj_b<=prost_broj) break;
		else if(prost_broj>broj_a && prost_broj<broj_b) suma+=prost_broj;
	}
	printf("Suma prostih brojeva izmedju %ld i %ld je %lu.", broj_a,broj_b,suma);
	return 0;
}
