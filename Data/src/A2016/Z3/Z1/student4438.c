#include <stdio.h>

int isPrime(int number) {
    int i;
    if(number == 0 || number == 1) return 0;
    for (i = 2; i < number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}

int daj_prost() {
	static int broj = 0;
	static int oldValue;
	oldValue = broj;
	if(broj - oldValue == 0) broj++;

	while(isPrime(broj) == 0)
		broj++;
		
	return broj;
}

int main() {
	int boolean = 1;
	int a, b, i;
	int suma = 0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		
		if(a <= 0) printf("A nije prirodan broj.\n");
		else if(a >= b) printf("A nije manje od B.\n");
		else boolean = 0;
	} while(boolean == 1);
	
	for(i = 0; i < b; i++) {
		int br = daj_prost();
		if(br > a && br < b) {
			suma += br;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);

	
	return 0;
}
