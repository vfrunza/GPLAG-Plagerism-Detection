#include <stdio.h>

int daLiJeProst (int a) {
	int i, jeste = 1;
	for (i = 2; i < a; i++) {
		if (a%i == 0) {
			jeste=0;
			break;
		}
	}
return jeste;
}

int daj_prost () {
	static int prost=1;
	int i, j;
   
   	prost++;
		//s=prost;
	if (prost == 2) 
		return 2;
		
	else {
			for(i=prost; i<prost*2; i++){
				if(daLiJeProst(i)==1) {
					prost=i;
		//printf("prosti: %d\n",prost);
					return prost;
				}
			}
		
		prost+=2;
	}
}

int main() {
	//printf("Zadaća 3, Zadatak 1");
	int A, B, suma = 0, p;

	
	printf ("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	
	while( A<=0 || A>=B) {
			if (A<=0){
				printf("A nije prirodan broj.\n");
				/*printf("Unesite brojeve A i B: ");
				scanf("%d %d", &A, &B);*/
			}
			if (A>=B){
				printf("A nije manje od B.\n");
				/*printf("Unesite brojeve A i B: ");
				scanf("%d %d", &A, &B);*/
			}
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}
	
	p = daj_prost();
	
	while(p<=A)
		p = daj_prost();
	
	suma = p;
	int brojac = 0;
	while(p < B) {
		p = daj_prost();
		
		if(p>=B) 
			break;
		suma+=p;
		brojac++;
	}
	
	if (brojac > 0) 
		printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	else
		printf("Suma prostih brojeva izmedju %d i %d je 0.", A, B);
	
	return 0;
}
