#include <stdio.h>


int daj_prost () {
	static int brojac = 2;
	int i = brojac - 1;
	while (i > 1) {
		if (brojac % i == 0){
			brojac++;
			i = brojac - 1;
			continue;
		}
		i--;
	}
	brojac++;
	return brojac - 1;
}


int main() {
	int i, A, B, suma = 0;
	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if (A >= B) printf("A nije manje od B.\n");
		else if (A < 1) printf("A nije prirodan broj.\n");
	}while (A >= B || A < 1);
	
	for (i = 1; ; i++){
		int prost = daj_prost();
		if (prost > B) break;
		if (prost > A && prost < B){
			suma += prost;
		}
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
