#include <stdio.h>

int daj_prost () {
	
static int i=2;
int j;

	for(;; i++) {
		
		if(i==2) {
			++i;
			return 2;
		}
		
		for(j=2; j<i ; j++) {
			
			if(i%j==0)
				break;
			if(j==i-1) {
				return i++;
			}
		}		
 	}
}


int main() {
	
	int A, B, suma=0, prost;
	do {
		
	
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A,&B);
	
	if (A<=0) {
		printf("A nije prirodan broj.\n");
	  } else if (A>=B) {
			printf("A nije manje od B.\n");
	  }	else if (B<=0) {
			printf("B nije prirodan broj.\n");
	  }
	} while (A<=0 || B<=0 || A>=B);
	
	prost = daj_prost();
	while(prost<B) {
	
		if(prost>A && prost<B)	
			suma += prost;
			
	prost = daj_prost();
			
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	
	return 0;
}
