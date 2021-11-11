#include <stdio.h> 

int daj_prost()	{
	static int a=1;
	int i, prost;
	a++;
	prost=a;
	
	if(a==2) {
		prost=a;
		return prost;
	}
	
	for(i=2; i<a; i++) {

		if (a%i==0) {
			a++;
			i=1;
			prost=a;
		}
	}
	return prost;
}


int main() {
	int A,B,i,suma=0,prost;
	
	/* Unos brojeva */
	
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	
	if(A>B || A==B) {
		printf("A nije manje od B.\n");
	}
	
	if(A<1) {
		printf("A nije prirodan broj.\n");
}
	} 	while (A>B || A<1 || B<1 || A==B);
	
	for(i=0; i<3000; i++) {
		prost=daj_prost();
		if(prost>A && prost<B) {
			suma=suma+prost;
		}
	}
	
	if (A<B && A>0 && B>0) {
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	}
	
	return 0;
}
