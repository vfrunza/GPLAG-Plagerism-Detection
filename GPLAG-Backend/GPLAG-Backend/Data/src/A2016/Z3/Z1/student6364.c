#include <stdio.h>
int daj_prost() {
	static int a=1;
	int i;
	a++;
	for(i=2; i<a; i++) {
		if(a%i==0) {
		a++;
		i=1;
		}
	}
	return a;
}	
int main() { int A, B, suma=0, i, x;
	do { printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B); 
		if(A>=B)
		printf("A nije manje od B.\n");
		else if (A<=0) 
		printf("A nije prirodan broj.\n");
	}
	while (A<=0 || B<=0 || A>=B);
	x=0;
	do {
		x=daj_prost();
	} while(x<=A);
	while(x<B) {
		suma+=x;
		x=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
