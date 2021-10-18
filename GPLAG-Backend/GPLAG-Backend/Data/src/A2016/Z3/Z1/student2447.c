#include <stdio.h>

int daj_prost(){
	static int x=1;
	int i,prost=0;
	x++;
	while(prost==0){
		for(i=2;i<x;i++){
		if(x%i==0){
			prost=0;
			break;
			}
    	}
    	if(x==i){
    		prost=1;
    		break;
    	}
    	x++;
	}
	
	return x;
}


int main() {

	int a,b,suma=0,broj;
	
	printf("Unesite brojeve A i B: ");

	do{
	scanf("%d %d",&a,&b);
	if(a<1){
		printf("A nije prirodan broj.\n");
		printf("Unesite brojeve A i B: ");
		
		
	}
	if (a>=b){
		printf("A nije manje od B.\n");
		printf("Unesite brojeve A i B: ");
		
	}


	}while(a>=b || a<1);
	broj=daj_prost();
	while(broj<b){
		
		if(broj>a && broj<b){
			suma=suma+broj;
		}
		broj=daj_prost();
	
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);

	return 0;
}
