#include <stdio.h>

int daj_prost()
{
	static int x=1;
	ponovo:
	x++;
	if(x==2) return 2;
	int brojac=0;
	int i;
	for(i=2; i<x; i++){
		if(x%i==0) brojac++;
	}
	if(brojac!=0) goto ponovo;
	/*printf("i: %d\n", i);*/
	return i;
}

int main() {
	int a, b, i;
	long int suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(b<=a) printf("A nije manje od B.\n");
		else if(a<=0) printf("A nije prirodan broj.\n");
		else if(b<=0) printf("B nije prirodan broj.\n");
	}while(a<=0 || b<=0 || b<=a);
	
	for(i=a; i<=b; i++){
		int prost=daj_prost();
		while(prost<a) prost=daj_prost();
		if(prost>a && prost<b) suma+=prost;
		else continue;
		/*printf("Prsot: %d", prost);*/
	}
	printf("Suma prostih brojeva izmedju %d i %d je %li.", a, b, suma);
	
	return 0;
}
