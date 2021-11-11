#include <stdio.h>

int daj_prost(){
	static int x=1;
	int i, prost;
	while(1){
		x++;
		prost=1;
		for(i=2; i<x; i++)
			if(x%i==0)
				prost=0;
		if(prost==1)
			return x;
	}
}

int main() {
	int a, b, suma, prostBroj;
	suma=0;

	/* Unos brojeva */
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a>=b)
			printf("A nije manje od B.\n");
		else if(a<1)
			printf("A nije prirodan broj.\n");
		else if(b<1)
			printf("B nije prirodan broj.\n");
	}
	while(a>=b || a<1 || b<1);

	/* Racunanje sume */
	do{
	prostBroj=daj_prost();
	if(prostBroj>a && prostBroj<b)
		suma+=prostBroj;
	}
	while(prostBroj<b);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
