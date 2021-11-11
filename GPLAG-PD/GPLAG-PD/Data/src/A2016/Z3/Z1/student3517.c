#include <stdio.h>

int daj_prost () {
	static int broj=2;
	int nije_prost=1;
	int i;
	while (nije_prost) {
		nije_prost=0;
		for(i=2; i*i<=broj; i++)
		if(broj%i==0) 
		nije_prost=1;
		broj++;
	}
	return broj-1;
}

int main() {

int a,b,suma=0,i,broj;

do{
	printf("Unesite brojeve A i B: ");
    scanf("%d %d" , &a,&b);
	if(a<=0) 
	printf("A nije prirodan broj.\n");
	
    if(a>b || a==b) 
	printf("A nije manje od B.\n");	
	
} while  (a<=0 || a>b || a==b);
if(a<b) {
for(i=0; i<b; i++) {
	broj=daj_prost();
	if(broj>a && broj<b) {
		suma+=broj;
	} }
	printf("Suma prostih brojeva izmedju %d i %d je %d." ,a,b,suma);
 }


	return 0;
}
