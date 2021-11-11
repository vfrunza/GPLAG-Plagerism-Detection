#include <stdio.h>

int daj_prost() {
	static int prost=1;
	int i, j;
	
	for(i=prost+1;; i++) {
		for(j=2; j<i; j++) {
			if(i%j==0) 
				break;
		}
		
		if(i==j) {
			prost=i;
			break;
			}
	}

	return prost;
}

int main() {
	
	int i, a, b, p, suma=0;
	
	for(;;) {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	
	if(a<1) printf("A nije prirodan broj.\n");
	else if(a>=b) printf("A nije manje od B.\n");
	else break;
	
	}
	
	for(i=0;; i++) {
		p=daj_prost();
		if(p>=b) break;
		else if (p>a)
			suma+=p;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	return 0;
}
