#include <stdio.h>

unsigned long daj_prost(){
	static unsigned long start = 1;
	unsigned long i;
	int prost;
	do{
		prost = 1;
		start++;
		for(i = 2; i < start; i++){
			if(start % i == 0){
				prost = 0;
				break;
			}
		}
	}while(prost==0);
	return start;
}

int main() {
	 long A, B;
	int isprUnos;
	unsigned long suma = 0, temp;
	int sabiraj = 1;
	
	do{
		isprUnos = 1;
		
		printf("Unesite brojeve A i B: ");
		if(scanf("%ld %ld", &A, &B)!= 2)
		isprUnos = 0;
		
		if(A>=B){
			printf("A nije manje od B.\n");
			isprUnos = 0;
		}
		
		else if(A<1){
			printf("A nije prirodan broj.\n");
			isprUnos = 0;
		}
		
	}while(isprUnos == 0);
	
	while(sabiraj){
		temp = daj_prost();
		if(temp >= B)
		break;
		if(temp > A)
		suma += temp;
	}
	
	printf("Suma prostih brojeva izmedju %ld i %ld je %lu.", A, B, suma);
	
	return 0;
}
