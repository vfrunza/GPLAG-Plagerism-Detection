#include <stdio.h>

int daj_prost() { 
	static int a=2;
	int i;
	for(i=2; i<a; i++) {
		if(a%i==0) {
			a++;
			i=1;
		}
	}
	a++;
	return a-1;
}

int main() {
	int A, B, suma=0, x;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	while(A<=0 || A>=B) {
		if(A<=0) {
		printf("A nije prirodan broj.\n");
		}
		if(A>=B) {
			printf("A nije manje od B.\n");
		}
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}
	x=daj_prost();
	while(x<B) {
		if(x>A)
		suma+=x;
		x=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
		return 0;
}