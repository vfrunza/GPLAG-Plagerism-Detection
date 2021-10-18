#include <stdio.h>

int daj_prost () {
	static int i=1,j;
	int prost;
	i++;
	for ( ; ; i++) {
		prost=1;
		for (j=2; j<i; j++) {
			if (i%j==0) {
				prost=0;
				break;
			}
		}
		if (prost==1)
			return i;
	}
}

int main() {
	int a,b,i,suma=0,y;
	printf ("Unesite brojeve A i B: ");
	scanf ("%d %d",&a,&b);
	while (a<1 || b<1 || a>=b) {
		while (a<1) {
			printf ("A nije prirodan broj.\nUnesite brojeve A i B: ");
			scanf ("%d %d",&a,&b);
		}
		while (a>=b && a>0) {
			printf ("A nije manje od B.\nUnesite brojeve A i B: ");
			scanf ("%d %d",&a,&b);
		}
	}
	
	for (i=a+1; i<b; i++) {
		y=daj_prost();
		if (y>a && y<b)
			suma+=y;
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
