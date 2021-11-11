#include <stdio.h>

int daj_prost()
{
	static int x=2;
	int i;
    /*petlja se ponavlja dok ne pronadje slijedeci prost broj*/
	while(1) {
		int prost = 1;
	/*provjeravamo da li je vrijednost promjenjive x prost broj*/
		for(i=2; i<x; i++) {
			if(x%i==0) {
				prost = 0;
				break;
			}
		}
		if (prost) return x++;
		else x++;
	}
}
int main()
{
	int i, A, B, prost_br, suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<=0)
			printf("A nije prirodan broj.\n");
		if(A>=B)
			printf("A nije manje od B.\n");
	} while (A<=0 || A>=B);

	for(i=2; i<B ; i++) {

		prost_br=daj_prost();
		
		/*br mora biti na intervalu izmedju A i B*/
		if(prost_br>A && prost_br<B )

			suma += prost_br;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
