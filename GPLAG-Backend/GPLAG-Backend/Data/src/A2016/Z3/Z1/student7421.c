#include <stdio.h>
#include <math.h>

int jel_prost(int n)
{
	int i = 2;
	for(; i <= (int)sqrt(n); ++i)
		if(n % i == 0)
			return 0;
	return 1;
}

int daj_prost(){
	static int broj = 1;
	while(jel_prost(++broj) == 0){}
	return broj;
}

int main() {
	int A, B;
	for(;;){
		printf("Unesite brojeve A i B: ");
		scanf("%d", &A);
		scanf("%d", &B);
		if(A <= 0){
			printf("A nije prirodan broj.\n");
			continue;
		}
		if(B <= A){
			printf("A nije manje od B.\n");
			continue;
		}
		break;
	}
	int suma = 0, n = 0;
	while(15){
		n = daj_prost();
		if(n >= B)
			break;
		if(n > A)
			suma += n;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}
