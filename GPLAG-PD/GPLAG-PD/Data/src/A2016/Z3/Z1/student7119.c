#include <stdio.h>

int Prost(int x) {
	int i;
	for(i=2;i<x;i++) {
		if(x%i==0) {
		return 1;
			}
		}
 		
	return 2;
}
int daj_prost() {
	
	static int prost=2;
	int x=prost,i;
	for(i=0;i<prost;i++) {
			if(Prost(x)==2) {
				prost++;
				return x;
			}
			else {
				x++; prost++;
			}
	}
}

int main() {
	int A,B,i,suma=0,samo_prost;
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<=0) printf("A nije prirodan broj.\n");
	if(A>B) printf("A nije manje od B.\n");
	if(A==B)printf("A nije manje od B.\n");
	}
	while(A>B || A<=0 || A==B);
	for(i=0;i<B;i++) {
		samo_prost=daj_prost();
		if(samo_prost<B && samo_prost>A) {
			suma+=samo_prost;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}


