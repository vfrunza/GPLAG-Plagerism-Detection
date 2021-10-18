#include <stdio.h>
#include <stdlib.h>

int daj_prost()
{
	int i=2, pomocna;
	static int prosti_brojevi=2;
	while(i<prosti_brojevi) {
		if(prosti_brojevi%i==0) {
			prosti_brojevi++;
			i=2;
		}
		i++;

	}
	pomocna=prosti_brojevi;
	prosti_brojevi++;
	return pomocna;
}
int main()
{
	int A,B,i,suma=0,prosti;

	while(1) {
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &A,&B);
		if(A>=B) printf("A nije manje od B.\n");
		else if(A<=0) printf("A nije prirodan broj.\n");
		else break;
	}
	A++;
	i=A;
	while(i<B) {
		prosti=daj_prost();
		while(prosti>i) i++;
		if(i>=B) break;
		if(prosti==i) suma+=prosti;
	}
	A--;
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);

	return 0;
}
