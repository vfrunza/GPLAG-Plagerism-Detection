#include <stdio.h>

int daj_prost() {
	static int snimi=0,izlaz=1,var=-1;
	int i,j,prost_broj=1;
	i=++izlaz;
	while(i>0) { 
		prost_broj=1;
		for(j=i-1;j>1; j--)
		if(i%j==0) prost_broj=0;
		if(prost_broj==1)var++;
		if(snimi==var){izlaz=i;snimi++;break;}
		i++;
	}
	return izlaz;
}

int main() {
	int i, broj_A=0, broj_B=0,radi=1;
	long long int suma_prostih=0;
	while(radi==1){
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &broj_A, &broj_B);
	if(broj_A<1) printf("A nije prirodan broj.\n");
	else if(broj_A+1>broj_B) printf("A nije manje od B.\n");
	else radi=0;}

	while(radi<broj_B){
		radi=daj_prost();
	if(radi<=broj_A)continue;
	else if(radi<broj_B) suma_prostih+=radi;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.\n", broj_A, broj_B, suma_prostih);
	return 0;
}
