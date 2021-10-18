#include <stdio.h>
int daj_prost () {
	int i, tacno; 
	static int br=1;
	do { br++;
		tacno=1;
		for (i=2; i<br; i++) {
		if (br%i==0) tacno=0; }
	} while (tacno==0);
} 

int main() {
	int A, B, S=0, i;
	do {
		printf ("Unesite brojeve A i B: ");
	scanf ("%d %d", &A,&B);
    if (A<1) {
	printf ("A nije prirodan broj.\n");
    }
	if (A>=B) {
	printf ("A nije manje od B.\n");
	}
}	while (A<1 || A>=B);
	for (i=A+1; i<B; i++) {
	i=daj_prost();
	if (i>A && i<B) { S=S+i; }
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, S);
	return 0;
}
