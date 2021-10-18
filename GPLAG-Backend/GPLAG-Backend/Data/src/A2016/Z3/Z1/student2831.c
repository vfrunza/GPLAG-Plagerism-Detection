#include <stdio.h>

 int daj_prost()
{
	 int i;
	static   int a=1;
	a++;
	for(i=2; i<a; i++) {
		if(a%i==0) {     /*Nalazenje prosstog broja u funkciji*/
			a++;
			i=2;
		}
	}
	return a;
}





int main()
{
	  int A,B;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A<=0) printf("A nije prirodan broj.\n");
		else {
			if(A>=B) printf("A nije manje od B.\n");
			else if(B<=0) printf("B nije prirodan broj.\n");
		}

	} while(!(A<B && (A>0 && B>0))); /*Unos prirodnih brojeva A i B */
	 int suma=0,i,prost;
	for(i=0; i<B; i++) {
		prost=daj_prost();
		if(prost>A && prost<B) suma=suma+prost; /*Izračunavanje sume*/
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
