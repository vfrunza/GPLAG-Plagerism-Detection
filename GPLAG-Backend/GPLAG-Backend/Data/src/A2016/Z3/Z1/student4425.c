#include <stdio.h>

int daj_prost() {
	
	static int broj = 2;
	int i, j, vrati, count;
	
	vrati = 0;
	
	if (broj == 2) {
		vrati = 2;
		broj++;
		return vrati;
	}
	
	for (i = broj; i < 999999; i++) {
		
		count = 0;
		
		for (j = 2; j < i; j++) {
			if (i % j == 0) count++;
		}
		
		if (count != 0) continue;
		
		broj = i;
		vrati = broj;
		broj++;
		break;
	}
	
	return vrati;
}

int main() {
	
	int A, B, x, suma=0;
	
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);
		
		if (A>=B) printf ("A nije manje od B.\n");
		else if (A<=0) printf ("A nije prirodan broj.\n");
		else if (B<=0) printf ("B nije prirodan broj.\n");
		
	} while (A>=B || A<=0 || B<=0);
	
	x = daj_prost();
	while (x < A) x = daj_prost();
	if (x > A) suma+=x;
	while (x < B) {
		x = daj_prost();
		suma+=x;
	}
	if (suma!=0) suma-=x;
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}