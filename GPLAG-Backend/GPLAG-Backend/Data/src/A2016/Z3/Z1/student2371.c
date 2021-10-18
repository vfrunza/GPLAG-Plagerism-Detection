#include <stdio.h>

int daj_prost(){
	static int n=1;
	int i;
	n++;
	for (;;){
		int prost=1;
		for (i=2;i<n;i++){
			if (n%i==0) prost=0;
	}
	if (prost==1) return n;
	else n++;
	}
}

int main() {
	int a, b, c=0, suma=0;
	greska:
	printf("Unesite brojeve A i B: ");
	scanf ("%d %d", &a, &b);
	if (a<=0) {printf ("A nije prirodan broj.\n"); goto greska;}
	if (a>=b) {printf ("A nije manje od B.\n"); goto greska;}
	if (b<=0) {printf ("B nije prirodan broj.\n"); goto greska;}
	
	while (c<a){
		c=daj_prost();
	}
	if (c==a) c=daj_prost();
	
	if (c>=b){
		printf ("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
		return 0;
	}
	else {
		while (c<b){
			suma=suma+c;
			c=daj_prost();
		}
		printf ("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	}
	return 0;
}
