#include <stdio.h>

int daj_prost() {
	static int broj = 2;
	int i;
	int tacno = 1;
	while (1) {
		tacno = 1;
		for (i = 2; i < broj; i++)
			if (broj % i == 0) {
				tacno = 0;
				break;
			}
		
		if (tacno) return broj++;
		else broj++;
	}
}
int main() {
	int A, B, i, sum = 0, increment;
	
	//for (i = 0; i < 11; i++)
	//printf("%d\n",daj_prost());
	
	while (1) {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if (A <= 0) printf("A nije prirodan broj.\n");
		else if (A >= B) printf("A nije manje od B.\n");
		else break;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je ", A, B);
	for (increment = 0; ; increment++) {
		i = daj_prost();
	    //printf("%d\n", i);
		if (i > A && i < B) sum += i;
		else if (i >= B) break;
	}
	printf("%d.\n", sum);
	return 0;
}
