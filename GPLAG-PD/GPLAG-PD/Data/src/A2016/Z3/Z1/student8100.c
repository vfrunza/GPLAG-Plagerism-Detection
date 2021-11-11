#include <stdio.h>

int daj_prost(){
	static int broj=1;
	int i;
	broj++;
	while(5) {
		int prostbr=1;
		for(i=2; i<broj; i++)
			if (broj%i==0) prostbr=0;
		if(prostbr) return broj;
		broj++;
   }
}

int main() {
	int a, b, i, suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a>=b) printf("A nije manje od B.\n");
		else if (a<=0) printf("A nije prirodan broj.\n");
	}while(a>=b || a<=0);
	for(;;){
		i = daj_prost();
		if(i<=a) continue;
		if(i>=b) break;
		suma+=i;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
