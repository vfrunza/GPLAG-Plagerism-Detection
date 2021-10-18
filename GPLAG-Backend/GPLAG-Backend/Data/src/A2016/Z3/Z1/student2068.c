#include <stdio.h>

int daj_prost() {
	static int prost=1;
	int i, j;
	for(i=prost+1; ; i++) {
		for(j=2; j<i; j++) {
			if(i%j==0) break;
		}
		if(j==i) {
			prost=i;
			return i;
		}
	}
}

int main() {
	int a, b, suma=0, x=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a<1) printf("A nije prirodan broj.\n");
		else if(a>=b) printf("A nije manje od B.\n");
	} while(a>=b||a<1);
	for(; x<b;) {
		x=daj_prost();
		if(x>a&&x<b) suma+=x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
