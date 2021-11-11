#include <stdio.h>
int daj_prost() {
	static int a=1;
	int i;
	a++;
	while(1) {
		int prost=1;
	for(i=2;i<a;i++) {
		if(a%i==0) {
			prost=0;
		}
	}
	
	if(prost==1) return a;
	a++;
	}
}
int main() {
	int A,B,i,suma=0;
	while(1) {
	printf("\nUnesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A>=B) {
		printf("A nije manje od B.");
		continue;
	}
	else if(A<=0) {
		printf("A nije prirodan broj.");
		continue;
	}
	else break;
	}
	int k;
    while(1){
    	k=daj_prost();
    	if(k>=B)break;
    	if(k<=A)continue;
		suma+=k;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	
	return 0;
}
