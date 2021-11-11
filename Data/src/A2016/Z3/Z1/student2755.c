#include <stdio.h>

int prost(int x) {
	int i;
	for(i=2; i<x; i++) {
		if(x%i==0) return 0;
	}
	return 1;
}

int daj_prost() {
	static int broj=2;
	while(1){
		if(prost(broj)==1) {
			broj++;
			break;
		}
		else broj++;
	}
	return broj-1;
}

int main() {
	int a, b, i, prost, suma=0;

	while(1){
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a<=0) printf("A nije prirodan broj.\n");
		else if(b<=a) printf("A nije manje od B.\n");
		else break;
	}
	

	for(i=0; i<b; i++) {
		prost=daj_prost();
		if(prost>a && prost<b){
			suma+=prost;
		}
			
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	
	return 0;
}
