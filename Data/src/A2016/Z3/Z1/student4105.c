#include <stdio.h>

int prost(int x) {
	int i;
	if(x == 1) return 0;
	for(i = 2; i < x; i++) {
		if(x % i == 0) return 0;
	}
	return 1;
}

int daj_prost(){
	static int broj=1;
	broj++;
	
	while(!prost(broj)) broj++;
	
	return broj;
}

int main() {
	
	int a, b, suma=0, z;
	
    do {
		printf("Unesite brojeve A i B: ");
		scanf("%d", &a);
		scanf("%d", &b);
		
		if(a>=b)
		printf("A nije manje od B.\n");
		else if(a<=0)
		printf("A nije prirodan broj.\n");
		else if(b<=0)
		printf("B nije prirodan broj.\n");
	}
	while (a>=b || a<=0 || b<=0);
	
	z = daj_prost();
	while(z < b) {
		if(z > a && z < b) suma += z;
		z = daj_prost();
	}
	
    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
    
   
    
    
	return 0;
}
