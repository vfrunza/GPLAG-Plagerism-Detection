#include <stdio.h>
#include<stdlib.h>

int prost(int x){
	int i;
	int p;
	p = 1;
	for(i = 2; i <x; i++)
	if(x % i == 0)
	return p = 0;
	return p;
} 
int daj_prost(){
	static int b = 1;
	if (b == 1) {
	b++;
	return 2;
	}
	do{
		b++;
		if(prost(b)){
		break;
		}
	}while(prost(b!=1));
	return b;
}
int main() {
	int A;
	int B;
	int suma = 0;
	int p = 0;
	do{
	printf("\nUnesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if (A <= 0){
		printf("A nije prirodan broj.");
		}else if (A >= B){
			printf("A nije manje od B.");
		}
	}while (A >= B || A <= 0 || B <= 0);
	while (p <= B){
		p = daj_prost();
		if (p <= A || p >= B){ 
			continue;
		}else{
			suma = suma + p;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
		return 0;
}