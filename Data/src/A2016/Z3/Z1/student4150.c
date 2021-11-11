#include <stdio.h>
int daj_prost() {
	static int a=1;
	int j;
	pocetak:
	a++;
	for(j=2;j<a;j++) {
		if(a%j==0) goto pocetak;
		}
		return a;
}

int main() {
	int A,B,suma=0,prost=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A>B || A==B) printf("A nije manje od B.\n");
		else if (A<0 || A==0) printf("A nije prirodan broj.\n");
	} while(A<=0 || A>=B);
while(1) {
prost=daj_prost();
if(prost<A || prost==A) continue;
else if(prost>B || prost==B) break;
suma+=prost;
	
}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
