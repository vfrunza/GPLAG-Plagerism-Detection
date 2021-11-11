#include <stdio.h>

int daj_prost() {
	static int n = 1 ;
	int prost,i,j;
	for(i=n+1; ; i++) {
		prost=1;
		for(j=i/2; j>1; j--) {
			if(i%j==0) {
				prost = 0;
				break;
			}
		}
		if(prost) {
			n=i;
			break;
		}
	}
	return n;
}
int main() {
	int a,b,broj,suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0)
			printf("A nije prirodan broj.\n");
		else if(a>=b)
			printf("A nije manje od B.\n");
	} while(b<=a || a<=0 || b<=0);

	do {
		broj = daj_prost();
	} while(broj<=a);

	while (broj<b) {
		suma+=broj;
		broj = daj_prost();
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
