#include <stdio.h>

int daj_prost() {
	static int y = 2;
    int w;
	static int i;
	for (i=2;i<y;i++) {
		if (y % i == 0) {
			y++;
			i=2;
		}
	}
	w = y;
	y++;
	return w;
}

int main() {
	int A, B;
	int i, j;
	int x;
	int suma=0;
	for (i=0; ;i++) {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if (A>=B) { 
			printf("A nije manje od B.\n");
			scanf("%d %d", &A, &B);
		} else if (A == 0) {
			printf("A nije prirodan broj.\n");
			scanf("%d %d", &A, &B);
		} else  if (A < 0) {
			printf("A nije prirodan broj.\n");
			scanf("%d %d", &A, &B);
		} else {
			break;
		}
	}
	for(j=0;j<=B;j++) {
		x = daj_prost();
		 if (x > A && x < B) {
		 	suma+= x;
		 }
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
