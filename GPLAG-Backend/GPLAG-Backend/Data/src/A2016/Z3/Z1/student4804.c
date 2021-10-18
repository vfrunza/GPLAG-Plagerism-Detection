#include <stdio.h>

int daj_prost()
{

	static int br=1;
	int i,prost;

	br++;


	do {

		prost=1;
		for(i=2; i<br; i++) {
			if(br%i==0) {
				prost=0;
				br++;
				break;
			}
		}

	} while(prost==0);


	return br;
}

int main()
{
	int a,b,i,suma=0;

	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0)
			printf("A nije prirodan broj.\n");

		if(b<=a)
			printf("A nije manje od B.\n");

	} while(a<=0 || a>=b);

	for(i=0; i<b; i=daj_prost()) {
		if(i>a)
			suma=suma+i;
	}

	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);

	return 0;
}
