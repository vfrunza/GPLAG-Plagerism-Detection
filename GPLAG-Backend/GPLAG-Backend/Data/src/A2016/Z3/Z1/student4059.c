#include <stdio.h>
#define TRUE 1
#define FALSE 0

int daj_prost() {
	static int prost = 1;
	int i, je_prost;
	
	do {
		prost++;
		je_prost = TRUE;
		for(i = 2; i < prost-1; i++) {
			if(prost % i == 0) {
				je_prost = FALSE;
				break;
			}
		}
		if(je_prost) break;
	} while(TRUE);
	
	return prost;
}

int main() {
	int a, b, c = 0, suma = 0; 
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a <= 0) printf("A nije prirodan broj.\n");
		if(a >= b) printf("A nije manje od B.\n");
	} while(a <= 0 || b <= 0 || a >= b);
	do {
		c = daj_prost();
		if(c > a && c < b) suma += c;
	} while(c < b);
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
