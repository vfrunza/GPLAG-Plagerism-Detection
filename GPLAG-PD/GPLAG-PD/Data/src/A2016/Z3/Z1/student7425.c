#include <stdio.h>

int daj_prost() {
	static int a=1;
	int h=0;
	a++;
	int i;
	while(1) {
		h=0;
		for(i=2;i<a;i++) {
			if(a%i==0) {
				h=1;
			}
			
		}
		if(h==0) return a;
		else a++;
	}
	
}
int main() {
	int A,B,c;
	int sumica=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<1) printf("A nije prirodan broj.\n");
		else if(A>=B) printf("A nije manje od B.\n");
	}while(A>=B || A<1);
	for(;;) {
		c=daj_prost();
		if(c>A) break;
	}
	while(c<B) {
		sumica+=c;
		c=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, sumica);
	return 0;
}
