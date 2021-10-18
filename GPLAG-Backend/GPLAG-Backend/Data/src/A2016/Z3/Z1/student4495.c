#include <stdio.h>

int daj_prost() {
	static int prost_br=1;
	int i=0;
	
	while (prost_br > i){
		prost_br++;
		for (i=2; i<prost_br; i++){
			if (prost_br % i == 0) break;
		}
	}
	return prost_br;
}

int main() {
	int br_a, br_b, i, temp;
	int suma_prostih=0;
	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &br_a, &br_b);
		
		if (br_a < 1)
			printf("A nije prirodan broj.\n");
		if (br_a >= br_b)
			printf("A nije manje od B.\n");
		
	} while(br_a >= br_b || br_a < 1);
	
	for (i = br_a + 1; i < br_b; i++){
		
		do {
			temp=daj_prost();
		} while(temp < br_a + 1);
		
		if (temp >= br_b) break;
		
		suma_prostih+=temp;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", br_a, br_b, suma_prostih);
	
	return 0;
}
