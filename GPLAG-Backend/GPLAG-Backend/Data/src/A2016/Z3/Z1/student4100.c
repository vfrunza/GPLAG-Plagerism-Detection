#include <stdio.h>

int daj_prost () {
	static int v=1;
	int k;
	v++;
	for (k=2; k<v; k++){
		if (v%k==0){
			k=2;
			v++;
		}
	}
	return v;
}
int main () {
	int k, y, A, B, suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if (A>=B){ printf("A nije manje od B.\n");}
		else if (A<=0){ printf("A nije prirodan broj.\n");}
		else if(B<=0){ printf("B nije prirodan broj.\n");}
	}while ( A>=B || A<=0 || B<=0);
	for (k=0; k<B; k++){
		y= daj_prost();
		if(y>A && y<B){ suma=suma + y;}
		else continue;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}

