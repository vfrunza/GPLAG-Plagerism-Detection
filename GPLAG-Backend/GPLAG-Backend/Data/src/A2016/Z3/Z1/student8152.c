#include <stdio.h>

int jeProst(int br) {
	
	int i = 2;
	
	if(br ==0 || br == 1 || br == 2) return 0;
	
	for(i = 2; i < br; i++) {
		
		if(br % i == 0) return 0;
	}
	return 1;
}


int daj_prost() {
	
	int prvi_put = 1;
	static int prost;
	if(prost >= 2) prvi_put = 0;

	
	if(prvi_put) {
		prost = 2;
		prost++;
		return prost - 1;
	}
	
	while(1) {
		if(jeProst(prost)) {
			prost++;
			break;
		} else prost++;
		
	}
		
		return prost - 1;
	
	
}
	
 

int main() {
	
	int a,b, suma = 0, prost, i;


	while(1) {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	
	if(a <= 0) printf("A nije prirodan broj.\n");
	else if(b <= a) printf("A nije manje od B.\n");
	
	else break;
	
	
}
	

	for(i = 0; i < b; i++) {
		
	prost = daj_prost();
	
	if(prost > a && prost < b) 
		
		suma += prost;
	
	
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
