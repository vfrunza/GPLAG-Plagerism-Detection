#include <stdio.h>
#include <stdlib.h>
int daj_prost() {
	int i,j=0,n=2;
	for(i=2;i<100;i++) {
		if(n%i!=0) j++;
	}
	if (j==0) return n;
	n++;
}
int main() {
	int A,B,C,suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&A,&B);
		if(A<=0) {
			printf("A nije prirodan broj.\n");
		}
		else if(A>=B) {
			printf("A nije manje od B.\n");
		}
		else if (B<=0) {
			printf("B nije prirodan broj.\n");
		}
	}
	while(A>=B || A<=0 || B<=0);
	C=A+1;
	do {
		if(C==daj_prost(A,B,C)) {
			suma+=C;
		}
		C++;
	}
	while(C<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
