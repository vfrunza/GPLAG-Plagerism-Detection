#include <stdio.h>

int daj_prost() {
	static int i=2;
	int prost, _prost, j;
	
	for(;;i++) {
		_prost = 0;
		for(j=2; j<=i/2; j++) {
			if(i%j==0) {
				_prost = 1;
				break;
			}
		}
		
		if(_prost==0) {
			goto A;
		}
	}
	
	A: prost = i;
	++i;
	
	return prost;
}

int main() {
	
	int i, j, A, B, suma=0, nizProst[55555];
	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		
		if(A<=0) {
			printf("A nije prirodan broj.\n");
			continue;
		}
		else if(A>=B) {
			printf("A nije manje od B.\n");
			continue;
		}
		else if(B<=0) {
			printf("B nije prirodan broj.\n");
			continue;
		} 
		else break;
	}while(1);
	
	for(i=0; i<B; i++) {
		nizProst[i] = daj_prost();
	}
	
	for(i=0; i<B; i++) {
		for(j=A+1; j<B; j++) {
			if(nizProst[i]==j) {
				suma+=j;
			}
		}
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}