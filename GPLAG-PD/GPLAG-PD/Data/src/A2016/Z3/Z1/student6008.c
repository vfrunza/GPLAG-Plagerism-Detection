#include <stdio.h>

int daj_prost(){
	int k, c, j;
	static int i = 2;
	for (c = i; c < 1000000; c++){ 
		k = 1;
		for (j = 2; j < c; j++){
			if(c % j == 0){
				k = 0; 
			}
		}
		i++;
		
		if (k == 0) 
			continue;
		
		if (k == 1)
			return c;
	}
}


int main() {
	int a, b, i, suma=0, d = 0;
	
	while(2>1){ 
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &a, &b);
		if(a>=b){
			printf("A nije manje od B.\n");
			continue;
		}
		if(a<=0){
			printf("A nije prirodan broj.\n");
			continue;
		}
		if (b < 1) {
			printf("B nije prirodan broj.\n");
			continue;
		}
		break;
	}
	
	
	while(d < a)
		d = daj_prost();
	
	for(i=a; i<b; i++){
		if(d>a && d<b)
			suma = suma + d;
		d=daj_prost();
		
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	return 0;
}
