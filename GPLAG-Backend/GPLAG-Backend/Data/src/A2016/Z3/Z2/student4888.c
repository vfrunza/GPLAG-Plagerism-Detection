#include <stdio.h>


void ubaci (int* niz, int v) {
	int i, sum=0, tmp;
	//pravim prazan prostor
	for (i=(v-1)/2; i>0; i--) {
		niz[(i)*2]=niz[i];
	}
	
//	for (i=0; i<20 ; i++) printf ("R_%d ", niz[i]);
	
	
	//ubacivam elemente
	for (i=0; i<v; i++) {
		if (i%2==0) {
		//	if (niz[i]<0) niz[i]*=-1;
			tmp = niz[i];
			if (tmp<0) tmp*=-1;
			sum=0;
			do {
			//	tmp = niz[i*2];
			//	if (niz[i*2] %i==0) 
				sum+=tmp%10;
				tmp=tmp/10;
			} while (tmp!=0);
			niz[i+1]=sum;
		}
	}
}

int izbaci (int *niz, int v) {
	int i, j, z;
	int fib[29] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811};
	for (i=0; i<v; i++) {
		for (j=0; j<29; j++ ) {
			if (niz[i]==fib[j]) {
				for (z=i; z<v; z++) {
					niz[z]=niz[z+1];
				}
				v--;
				i--;
				break; 
			}
		}
	}
	return v;
}

int main() {
//	printf("Zadaća 3, Zadatak 2");

	int niz[20], i, v=20;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) scanf ("%d", &niz[i]);
//		for (i=0; i<20 ; i++) printf ("R1_%d ", niz[i]);
	ubaci(niz, v);
//	for (i=0; i<v; i++) printf ("R:%d, ", niz[i]);
	v=izbaci(niz, v);
	if (v==0) printf ("Prazan niz");
	else printf ("Modificirani niz glasi: ");

	for (i=0; i<v; i++) {
		if (i==v-1) printf ("%d.", niz[i]);
		else printf ("%d, ", niz[i]);
	}
	return 0;
}