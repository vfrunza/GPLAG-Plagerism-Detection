#include <stdio.h>
int daj_prost () {
	static int k=1;
	k++;
	int j,prost;
	prost=1;
	while (k<10000) {
		for (j=2; j<k; j++) {
			
			if (k%j==0) {
				prost=0;
			}
		}
		if (prost==0) {
			prost=1;
			k++; 
			continue;
		}
		else if (prost==1) {
			return k;
		}
		k++;
}
return 0;
}
int main() {
	int a,b,i,x,suma=0;
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d%d",&a,&b);
		if (a>=b) {
			printf ("A nije manje od B.\n");
		}
		else if (a<=0) {
			printf ("A nije prirodan broj.\n");
		}
	}
	while (a>=b || a<=0);
	for (i=1; i<b; i++) {
		x=daj_prost();
		if (x>a && x<b) {
			suma=suma+x;
		}
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
return 0;	
}