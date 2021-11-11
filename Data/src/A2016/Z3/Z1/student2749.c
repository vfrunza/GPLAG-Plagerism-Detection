
#include <stdio.h>
#include <stdio.h>
#include <math.h>
int daj_prost(){
	static int brojac = 1;
	int i;
	do{
	brojac++; 
	for(i = 2; i < brojac; i++){
		if(brojac % i == 0){
			break;
		}
	}
	if(brojac == i) break;
	}while(1);
	return brojac;
}
int main() {
	int i,suma=0,x;
	float a,b;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%f %f",&a,&b);
		if(a >= b ){
			printf("A nije manje od B.\n");
			continue;
		}else if(a <= 0){
			printf("A nije prirodan broj.\n");
			continue;		
		}
		else if(b <= 0){
			printf("B nije prirodan broj.\n");
			continue;		
		}
		else break;
	}while(1);
	for(i = 1; i < (int)b; i++){
		x = daj_prost();
		if(x > (int)a && x < (int)b) {
			suma += x;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",(int)a,(int)b,suma);
	return 0;
}
