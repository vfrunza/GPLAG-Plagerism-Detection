#include <stdio.h>
#include <stdlib.h>

int daj_prost()
{
	int i;
	static int prost=2;
	for(i=2; i<prost; i++) {
		if(prost%i==0) {
			prost++;
			i=2;
		}
	}
	return prost++;
}


int main()
{
	int A,B,i,suma=0;
	for(;;) {
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&A,&B);
		if(A<=0) printf("A nije prirodan broj.\n");
		else if(A>=B) printf("A nije manje od B.\n");
		else break;
	}

	i=A+1;
	while(i<B) {
		int prosti=daj_prost();
		while(prosti>i) i++;
		if(i>=B) break;
		if(prosti==i) suma+=prosti;
	}

	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);

	return 0;
}
