#include <stdio.h>
#include <math.h>

int daj_prost()
{
	static int prost=1;
	int prostx;
	int i;

	do {
		prostx=1;
		prost++;

		// sqrt nam povecava brzinu racunanja prostog broja
		for(i=2; i<=sqrt(prost); i++) {
			if(prost%i==0) {
				prostx=0;
				break;
			}

		}
		if(prostx==1) return prost;

	} while(prostx!=1); // vrti se petlja sve dok se ne nadje naredni prost broj

	return 2;
}

int main()
{
	int a, b;
	int i;
	int suma=0;
	printf("Unesite brojeve A i B: ");
	do {
		scanf("%d %d", &a, &b);
		if(a<=0) {
			printf("A nije prirodan broj.\n");
			printf("Unesite brojeve A i B: ");

		} else if(a>=b) {
			printf("A nije manje od B.\n");
			printf("Unesite brojeve A i B: ");

		} else if(b<=0) {
			printf("B nije prirodan broj.\n");
			printf("Unesite brojeve A i B: ");

		}


	} while(a<=0 || b<=0 || a>=b);

	for(i=a; i<b; i++) {
		int promx;
		do {
			promx = daj_prost();
		} while(promx<a); // vrtimo petlju sve dok ne dodjemo do broja koji ne zadovoljava uslov

		if(promx>a && promx<b)  suma+=promx; // ako su zadovoljeni uslovi sabiramo
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
