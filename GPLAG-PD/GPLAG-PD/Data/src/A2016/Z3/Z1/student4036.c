#include <stdio.h>
int daj_prost (){
	int i;
	static int broj = 2;
	while (1) {
		int pr = 1;
		for (i = 2; i < broj; i++){
			if (broj % i == 0){
				pr = 0;
			}
		}
		if (pr == 0){
				broj++;
		}
		else break;
	}
	broj++;
	return broj-1;
}

int main() {
	int A, B;
	int suma = 0;
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d",&A,&B);
		if (A <= 0) printf ("A nije prirodan broj.\n");
		else if (A >= B) printf("A nije manje od B.\n");
		else break;
	} while (1);
	while(1){
		int temp = daj_prost();
		if(temp > A && temp < B)
			suma += temp;
		if(temp >= B)
			break;
		
	}
   	printf ("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
