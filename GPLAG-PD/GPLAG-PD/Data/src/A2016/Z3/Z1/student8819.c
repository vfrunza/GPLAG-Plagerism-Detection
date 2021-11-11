#include <stdio.h>

//int g=1;
int daj_prost () {
	int i, b=1, j;
	static int g=1;
	i=g;
	i++;
	for (; b>0;i++) {
		b=0;
		for (j=2; j<i; j++) {
			if (i%j == 0) b++;
			
		}
		
	} 
	i--;
	g=i;
	return i;
}

int main() {
//	printf("Zadaća 3, Zadatak 1");
	int a, b, c=0, suma=0;
	unos: {
		printf ("\nUnesite brojeve A i B: ");
		scanf ("%d", &a);
		scanf ("%d", &b);
		if ((int) a!=a || a<=0 ) {
			printf ("A nije prirodan broj. ");
			goto unos;
		}
		if (a>=b) {
			printf ("A nije manje od B. ");
			goto unos;
		}
		if ((int) b!=b || b<=0) {
			printf ("B nije prirodan broj. ");
			goto unos;
		}
	}
	
	/*prost: {
		c=daj_prost();
		if (c<b) {
			suma+=c;
			goto prost;
		}
	}//napomena
*/	
/*	do {
	suma+=c;
		prost: {
			c=daj_prost();
			if (c<a) goto prost;
		}
	} while (c<b);
	*/
	
	do {
		suma+=c;
	//	printf ("\nS:%d", suma);
		do {
			c=daj_prost();
	//		printf ("\nC:%d", c);
		} while (c<=a);
	} while (c<b);
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
/*

int main() {
	int x, i;
	scanf ("%d", &x);
	for (i=0; i<x; i++)	printf ("\nR:%d, %d", daj_prost(), g);
	return 0;
}
*/