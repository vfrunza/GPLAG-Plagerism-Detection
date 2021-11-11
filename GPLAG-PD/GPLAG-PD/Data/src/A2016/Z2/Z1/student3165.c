#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, br, suma_NB=0, c1, c2, i, d, suma=0;
	
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	
	if (n < 0){
		n*=(-1);
	}
	
	if (n <= 9 && n >= 0){
		printf ("0");
		return 0;
	}
	
	br = 0;
	d = n;
	while (n != 0){
		n = n/10;
		br++;
	}

	for(i=0; i<br-1; i++) {
		c1 = d%10;
		d = d/10;
		c2 = d%10;
		suma_NB+=(abs)(c1-c2);
		suma_NB*=10;
	}
suma_NB/=10;

	for(i=0; i<br-1; i++) {
	suma=suma+suma_NB%10;
	suma*=10;
	suma_NB = suma_NB/10;
	
}
	suma = suma/10;
	printf("%d",suma);
		return 0;
}
