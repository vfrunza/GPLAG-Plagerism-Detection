#include <stdio.h>

/* Funkcija DAJ PROST */

int daj_prost() {
	static int x=1;
	int m, n=0;
	do{
		int i, brojac=0;
		if(x==1){
			m=0;
		}
		else{
			for(i=2;i<=x/2;i++){
				if(x%i==0){
					brojac++;
				}
			}
			if(brojac==0){
				m=1;
			}
			else{
				m=0;
			}
		}
		x++;
	} while(m!=1);
	n=x-1;
	return n;
}

/* Funkcija MAIN */

int main() {
	int a, b, suma=0, i, y=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &a, &b);
		if (a>=b) {
			printf("A nije manje od B.\n");
		}
		if (a<1) {
			printf("A nije prirodan broj.\n");
		}
	} while ((a>=b) || a<1 || b<1);
	for(i=0;i<b;i++){
		y=daj_prost();
		if(y<=a || y>=b) {
			continue;
		}
		else {
			suma=suma+y;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
