#include <stdio.h>
int daj_prost()
{
	int prost,i;
	static int p=1;
	p++;
	do {
		prost=1;
		for(i=2; i<p; i++) {
			if(p%i==0) {
				prost=0;
				p++;
				break;
			}
		}
	} while(prost==0);
	return p;
}
int main()
{
	int s=0,i,A,B;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A<=0) {
			printf("A nije prirodan broj.\n");
		} else if(A>=B) {
			printf("A nije manje od B.\n");
		}
	} while(A<=0 || B<=0 || A>=B);

	for(i=0; i<B; i=daj_prost()) {
		if(i>A)
			s+=i;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,s);
	return 0;
}
