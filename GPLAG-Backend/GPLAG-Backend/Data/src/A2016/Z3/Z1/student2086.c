#include<stdio.h>
int daj_prost () {
	int prost=1, n;
	static int br=1;
	while (1) {
		br++;
		if (br==2){
			return br;
		} else {
			for (n=2;n<br;n++) {
				if (br%n==0){
					prost=0;
					break;
				}
			}
			if (prost) {
				return br;
			} else {
				prost=1;
			}
		}
	}
}

int main () {
	int X,Y,zbir=0,br=0;
	
	/*UNOS INTERVALA*/
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d%d", &X, &Y);
		if (X<1) {
			printf ("A nije prirodan broj.\n");
		} else if (X>=Y) {
			printf ("A nije manje od B.\n");
		}
	} while (X<1 || X>=Y || Y<=0);
	while (br<Y) {
		br=daj_prost ();
		if (br>X && br<Y) {
			zbir+=br;
		}
	}
	
	/*ISPPIS SUME*/
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", X, Y, zbir);
	return 0;
}