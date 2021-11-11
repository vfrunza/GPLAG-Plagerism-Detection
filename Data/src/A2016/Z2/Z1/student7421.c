#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int broj, temp, i = 0, broj_cifara = 0, broj_naopako = 0;
	int cifra_1, p , d, t, rezultat = 0, desetica = 1;
	

	printf("Unesite broj: ");
	scanf("%d", &broj);

	if(broj < 0)
		broj *= -1;
	if(broj < 10){
		printf("0");
		return 0;
	}
	
	for(temp = broj; temp != 0; temp /= 10)
		++broj_cifara;
		
	for(i = 0; i < broj_cifara; ++i){
		p = pow(10, broj_cifara -1 -i);
		d = broj / pow(10, i);
		t = 10. * (broj / (int)pow(10, i) / 10);
		broj_naopako += p * (d - t); 
	}
	
	while( broj_naopako >= 10){
		cifra_1 = broj_naopako % 10;
		broj_naopako /= 10;
		rezultat += abs(cifra_1 - broj_naopako % 10) * desetica;
		desetica *= 10;
	}
	if(rezultat == 0 && broj_naopako != 0 && broj % 10 != 0){
		printf("0");
		return 0;
	}
	
	for(;rezultat != 0; rezultat /= 10){
		printf("%d", rezultat % 10);
	}
	if(broj % 10 == 0){
		printf("%d", broj_naopako);
		for(p = 0; broj %10 == 0; broj /= 10){
			if(p == 0){
				p = 1;
				continue;
			}
			printf("0");
		}
	}
	
	return 0;
}
