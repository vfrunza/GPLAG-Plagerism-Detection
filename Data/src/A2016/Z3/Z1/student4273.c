#include <stdio.h>

int daj_prost() {
	static int broj=1;
	int i, brojac=0;
	broj++;
	for(i=1;i<=broj;i++) {
		if(broj%i==0)
			brojac++;
	}
		if(brojac==2)
	    return broj;
	    else
	    return 0;
	}
	
int main() {
	int A,B,i,suma=0,pomocniBroj;
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<1) {
		printf("A nije prirodan broj.\n");
	}
	else if(A>B || A==B) {
		printf("A nije manje od B.\n");
	}
	else if(B<1) {
		printf("B nije prirodan broj.\n");
	}
	
	}while(A<1 || B<1 || A>B || A==B);
	
		for(i=1;i<10000;i++) {
			pomocniBroj=daj_prost();
			if(pomocniBroj>A && pomocniBroj<B){
				suma+=pomocniBroj;
			}
		}
	
		printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}





