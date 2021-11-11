#include <stdio.h>

//funkcija vraca 0 ako broj nije prost
int prost(int x) {
	int i;
	for (i = 2; i < x; i++)
		if (x % i == 0) return 0;
	return x;	
}

int daj_prost() {
	static int broj = 1;
	broj++;
	while(!prost(broj)) broj++; //trazimo prvi slijedeci broj koji je prost
	return broj;
}

int main() {
	int a, b, x, suma = 0;
	
	while (1) {
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &a, &b);
		if (!(a < b)) {
			printf("A nije manje od B.\n");
			continue;
		}
		if (a < 1) {
			printf("A nije prirodan broj.\n");
			continue;
		}
		if (b < 1) {
			printf("B nije prirodan broj.\n");
			continue;
		}
		break;
	}
	
	while ((x = daj_prost()) <= a); //preskocimo sve brojeve manje od A
	if (x < b) suma += x; //ako je prvi preskoceni broj u trazenom intervalu dodajemo ga u sumu
	
	while ((x = daj_prost()) < b) //
		suma += x;
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	return 0;
}
