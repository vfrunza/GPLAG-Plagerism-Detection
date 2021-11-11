#include <stdio.h>

int daj_prost () {
	static int prost=1;
	int i=2;
	
	while (prost++) {
		
		for(i=2; i<prost; i++) {
			
			
			if (prost%i==0)
			break;
			
			
		} 
		
		if (i==prost) 
		break;
		
	}
return prost;	
}

int main() {
	int a, b, suma = 0, prost;
	do  {
		printf ("Unesite brojeve A i B: ");
	scanf ("%d %d", &a, &b);
	
	if (a < 1) {
		printf("A nije prirodan broj.\n");
		continue;
		} 
		if (a >= b) {
		printf("A nije manje od B.\n");
		continue;
	}
	if (b < 1) {
		printf("B nije prirodan broj.\n");
		continue;
}
	if (a > 1 && b > 1 && a < b ) { 
		prost = daj_prost();
		while(prost < b) {
			if (prost > a) suma += prost;
			prost = daj_prost();
		}
						printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
		
}

}

	while (a < 1 || b < 1 || a >= b );

	 

	return 0;
}
