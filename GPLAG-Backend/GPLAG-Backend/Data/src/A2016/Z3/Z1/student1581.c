#include <stdio.h>

int daj_prost () {
	int i=0, j=0, p=1, k=0;
	int niz[1000];
	static int br=-1;
	br++;
	/*Traženje prostih brojeva i upisivanje istih u niz.*/
	for (i=2; i<3000; i++) {
		p=1;
		for (j=2; j<i; j++) {
			if (i%j==0) {
				p=0;
				break;
			}
		}
		if (p==1) {
			niz[k]=i;  
			k++;
		}	
	}
	return niz[br];
}


int main() {
	/*printf("Zadaća 3, Zadatak 1");*/
	
	int A=0, B=0, i=0, suma=0, j=0;
	
	printf ("Unesite brojeve A i B: ");
	
	do {
		scanf ("%d %d", &A, &B);
		if (A>B || A==B) {
			printf ("A nije manje od B.\n");
			printf ("Unesite brojeve A i B: ");
			continue;
		}
		else if (A<=0) {
			printf ("A nije prirodan broj.\n");
			printf ("Unesite brojeve A i B: ");
			continue;
		}
	}
	while (A>B || A<=0 || A==B);
	
	/*Izračunavanje sume.*/
	for (i=0; i<B; i++) {
		j=daj_prost ();
        if (j>B) break; /*Ukoliko je j veće od B prestani izvršavati petlju jer je uslov da j bude manje od B i prema tome nema je smisla dalje izvršavati.*/
		if (j>A && j<B) {
			suma+=j;
		}
	}
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}

