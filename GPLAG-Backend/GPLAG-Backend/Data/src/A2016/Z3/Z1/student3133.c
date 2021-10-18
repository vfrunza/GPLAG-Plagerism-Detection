#include <stdio.h>

int jeliprost(int broj) //ova funkcija provjerava da li je broj prost
{
	int i;
	for(i=2; i<broj; i++) {
		if(broj%i==0) return 0;
	}
	return 1;
}

int daj_prost() //ako je broj prost, ova funkcija ce ga vratiti i povecati za iduce pozivanje
{
	static int broj=2;
	while(1)
		if(jeliprost(broj)) break;
		else broj++;
	return broj++;
}

int main()
{
	int A, B, suma=0, i;

	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<=0) printf("A nije prirodan broj.\n");
		else if(A>=B) printf("A nije manje od B.\n");
		else break;
	} while(A<=0||B<=0||A>=B); //petljom se provjerava da li su brojevi prirodni i A manje od B


	do {
		i=daj_prost();
		if(i>A&&i<B) suma+=i;
	} while(i<B); //ovom petljom se racuna suma prostih izmedju A i B
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
