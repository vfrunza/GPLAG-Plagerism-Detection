#include <stdio.h>

int isProst(int broj){
	int i;
	for(i = 2; i<broj; i++)
		if(broj%i == 0) return 0;
	return 1;
}

int daj_prost(){
	static int prost = 1;
	while(1){
		prost++;
		if(isProst(prost) == 1)
		{
			break;
		}
	}
	return prost;
}

int main() {
	int a, b, suma = 0, temp;
	while(1){
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a >= b){
			printf("A nije manje od B.\n");
		}
		else if(a <= 0)
			printf("A nije prirodan broj.\n");
		else if(b <= 0)
			printf("B nije prirodan broj.\n");
		else 
			break;
	}
	while(1){
		temp = daj_prost();
		if(a < temp && temp < b)
			suma += temp;
		if(temp >= b)
			break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
