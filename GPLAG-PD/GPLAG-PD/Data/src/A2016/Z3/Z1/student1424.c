#include <stdio.h>
int daj_prost() {
	static int broj=1;
	int i,j,brojac;
	broj++;
	for(i=broj; i<10000000; ++i) {
		brojac=0;
		for(j=1; j<=i; ++j) {
			if(i%j==0) 
				brojac++;
		}
		if(brojac==2)
			break;
	}
	broj=i;
	return broj;
}
int main() {
	
	int a,b,suma=0,neki_br;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a==b || a>b) {
			printf("A nije manje od B.\n");
		}
		else if(a==0 || a<0) {
			printf("A nije prirodan broj.\n");
		}
		else if(b==0 || b<0) {
			printf("B nije prirodan broj.\n");
		}
	} while(a==b || a>b || a==0 || a<0 || b==0 || b<0);
	for(;;) {
		neki_br=daj_prost();
		if(neki_br>a && neki_br<b) {
			suma+=neki_br;
		}
		if(neki_br>b) {
			break;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}