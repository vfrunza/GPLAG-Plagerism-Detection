#include <stdio.h>

int daj_prost() {
	static int a=2;
	int i, brojac=0;
	while (1) {
		brojac=0;
		for(i=2; i<a; i++){
			if(a%i==0) brojac++;
		}
		if (brojac==0)
		return a++;
		a++;
	}
	return 0;
}

int main() {
	int a, b, suma=0, broj;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &a, &b);
		if (a>0 && b>0 && a<b) break;	
		if (a<=0) 
			printf ("A nije prirodan broj.\n");
		else if (a>=b) 
			printf ("A nije manje od B.\n");
		else if (b<=0) 
			printf ("B nije prirodan broj.\n");	
	} while (1);
	
	while (1) {
		broj=daj_prost();
		if(broj>b) break;
		if(broj>a && broj<b) suma+=broj;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
