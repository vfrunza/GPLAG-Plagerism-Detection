#include <stdio.h>
int prost (int n) {
	int br=0,i;
	for (i=1; i<=n; i++) {
		if (n%i==0)
			br++;
	}
	if (br==2) 
		return 1;
	else 
		return 0;
}
int daj_prost () {
	static int x=1;
	x+=1;
	while (prost(x)!=1) {
		x++;
	}
	return x;
}
/*Suma prostih brojeva izmedju A i B*/
	int funkcija (int A, int B) {
		int suma=0,x=daj_prost();
		while (x<=A) {
			x=daj_prost();
		}
		while (x<B) {
				suma+=x;
				x=daj_prost();
		}
	return suma;
	}

int main () {
	int A, B;
	for (;;) {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d%d", &A, &B);
		if (A<=0)
			printf("A nije prirodan broj.\n");
		else if (A>=B)
			printf ("A nije manje od B.\n");
		else 
			break;
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",A,B,funkcija(A,B));

	return 0;
}
