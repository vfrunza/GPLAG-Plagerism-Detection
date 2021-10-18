#include <stdio.h>


int dajSljedeciProst(int prethodni){
	int i = 2,j;
	for(i=prethodni-1;;i++){
		int prost = 1;
		for(j=2;j<i;j++){
			if(i%j == 0){
				prost = 0;
			}
		}
		if(prost == 1){
			if(i > prethodni) return i;
		}
	}
}

int daj_prost(){
	static int prethodni, prosti=2, i=0;
	if(i++ == 0){
		prethodni = prosti;
		return prosti;
	}else{
		prethodni = prosti;
		prosti = dajSljedeciProst(prethodni);
		return prosti;
	}
}

int main() {
	int suma = 0,i,a,b;
	while(1){
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a <= 0){
			printf("A nije prirodan broj.\n");
		}else if(a >= b){
			printf("A nije manje od B.\n");
		}else{
			break;
		}
	}
	for(i = 2;i<b;i++){
		int prost = daj_prost();
		if (prost > a && prost <b) {
			suma += prost; 
		}
		
	}

	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma); 
	return 0;
}
