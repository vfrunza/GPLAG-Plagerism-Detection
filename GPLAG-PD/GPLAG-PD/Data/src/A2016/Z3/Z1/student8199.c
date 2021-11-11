#include <stdio.h>

/*Trazenje prostog broja*/

int daj_prost () {
	static int x = 1;
	int i;
	x++;
	for(i = 2; i < x; i++){
		if (x % i == 0){
			i = 2;
			x++;
		}
	}
	return x;
}


int main() {
	int i, j, A, B, sum = 0;
	
	/*Unos i provjera unosa*/
	
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);
		if (A >= B) {
			printf ("A nije manje od B.\n");
		}
		else if (A <= 0) {
			printf ("A nije prirodan broj.\n");
		}
		else if (B <= 0) {
			printf ("B nije prirodan broj\n");
		}
	}
	while(A >= B || A<=0 || B <= 0);
	
	/*Sabiranje prostih brojeva u rasponu*/
	
	for(i = 0; i < B; i++){
		j = daj_prost();
		
		if (j > A && j < B){
			sum = sum + j;
		}
		
		else continue;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, sum);
	
	return 0;
}