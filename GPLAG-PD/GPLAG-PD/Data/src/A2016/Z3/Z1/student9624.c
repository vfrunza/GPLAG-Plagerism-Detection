#include <stdio.h>


int prost (int broj) {
	int istina = 1;
	int i = 2;
	for (i = 2; i < broj; i++) {
		if (broj % i == 0) istina = 0;
	}
	
	return istina;
}


int daj_prost() {
    static	int i = 1;
    i++;
	while(prost(i) == 0) i++;
	return i;
	
}




int main() {
	int A,B, suma=0;
	
	do { 
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A<=0) 
			printf("A nije prirodan broj.\n");
		if(B<=A)
			printf("A nije manje od B.\n");
		
	} while(B<=A || A<=0) ;
	
	int k = daj_prost();
	while(k<=A) {
		k = daj_prost();
	}

	while(k<B) {
		suma=suma+k;
		k=daj_prost();
	
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	
	
	
	
	
	return 0;
}
