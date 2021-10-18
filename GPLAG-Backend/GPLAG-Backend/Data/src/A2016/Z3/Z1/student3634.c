#include <stdio.h>

int daj_prost() {
	static int x=1;
	int i, br=0;
	x++;
	if(x==2) { 
		return x; 
	}
	for(;;) {
		br=0;
		for(i=2; i<x; i++) {
			if(x%i==0) { br++;
			}
		}
		if(br==0) { 
			return x; 
		}
		else x++;
	}
	return x;
	
}

int main() {
	int A, B, i, x, suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<=0) { 
			printf("A nije prirodan broj.\n"); 
		}
		else if(A>=B) { 
			printf("A nije manje od B.\n"); 
		}
		}while(A<=0 || B<=0 || A>=B);
		
		for(i=0; i<B; i++) {
			x=daj_prost();
			if(x>A && x<B) {
				suma+=x;
			}
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);

	return 0;
}
