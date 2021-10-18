#include <stdio.h>

int daj_prost() {
	static int s=1;
	int i;
	s++;
	for(i=2; i<s; i++) {
		if(s%i==0) {
			s++;
			i=2;
			continue;
		}
	}
	return s;
}

int main() {
	int i, a, b, x, suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a<=0) {
			printf("A nije prirodan broj.\n");
			continue;
		}
		if(a>=b) {
			printf("A nije manje od B.\n");
			continue;
		}
		if(b<=0) {
			printf("B nije prirodan broj.\n");
			continue;
		}
	} while(a<=0 || b<=0 || a>=b);
	
	for(i=0; i<b; i++) {
		x=daj_prost();
		if(x>a && x<b)
		suma+=x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
