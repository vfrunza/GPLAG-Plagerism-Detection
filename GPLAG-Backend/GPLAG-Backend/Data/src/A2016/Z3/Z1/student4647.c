#include <stdio.h>

/* funkcija daj_prost koja svaki put kada se pozove vraća sljedeći prost broj */
int daj_prost() {
	int i, j;
	static int prost_broj=1;
	prost_broj++;
	j=1;
	for (i=2; i<prost_broj; i++) {
		if (prost_broj%i==0) {
			j=0;
			break;
		}
	}
	if (j==1)
		return prost_broj;
	else daj_prost();
}

int main() {
	int A, B, suma=0, i, C;
	/* unos brojeva */
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if (A<1)
			printf("A nije prirodan broj.\n");
		else if (A>=B)
			printf("A nije manje od B.\n");
		else if (B<1)
			printf("B nije prirodan broj.\n");
	}
	while (A<1 || B<1 || A==B || A>B);
	/* sabiranje svih prostih brojeva vecih od A, a manjih od B*/
	for(i=1; i<=B; i++) {
		C=daj_prost();
		if(C>A && C<B)
			suma+=C;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
