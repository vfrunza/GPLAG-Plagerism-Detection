#include <stdio.h>

int daj_prost() {
	static int a=1;
	int i;
	a++;
	for(i=2; i<a; i++) {
		if(a%i==0){
			a++;
			i=2;
		}
	}	
	return a;
} 

int main() {
	int A, B, k=0, suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<1) {
			printf("A nije prirodan broj.\n");
			continue;
		}
		if(A>=B){
			printf("A nije manje od B.\n");
			continue;
		}
		if(B<1) {
			printf("B nije prirodan broj.\n");
			continue;
		}
	} while(A<1 || A>=B || B<1);
	/*Pozivamo funkciju daj_prost u do while petlji sve dok je prost broj koji pozivamo manji od B*/
	do {
		k=daj_prost();
		if(k<=A)
		continue;
		if(k>=B)
		break;
		suma+=k;
	} while(k<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
} 
