#include <stdio.h>
int daj_prost()
{
	static int prost=1;
	int j;
a:
	prost++;
	for(j=2; j<prost; j++) {
		if(prost%j==0) {
			break;
		}
	}
	if(prost==j) return prost;
	goto a;
}
int main()
{
	int A,B,i;
	int prost;
	int suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A>=B) {
			printf("A nije manje od B.\n");
		} else if(A<=0) {
			printf("A nije prirodan broj.\n");
		} else if(B<=0) {
			printf("B nije prirodan broj.\n");
		}
	} while(A<=0 || B<=0 || A>=B);
	for(i=0; i<B; i++) {
		prost=daj_prost();
		if(prost>=B)
		    break;
		if(prost>A && prost<B)
			suma=suma+prost;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
