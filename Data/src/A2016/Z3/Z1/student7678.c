#include <stdio.h>

int daj_prost(){
	
	int i;
	static int broj=1;
	broj++;
	
	//Trazenje prostog broja
	for(i=2; i<broj; i++){
		
		if (broj%i==0) { broj++; i=2;} 
	}
	return broj;
	
}

int main() {
	 
	 int a,b,prekid=0,suma=0,i;
	 
	 //Unos A i B
	 
	 while (prekid!=1) {
	 	 
	 	printf("Unesite brojeve A i B: ");
	 	scanf("%d %d",&a,&b);
	 	
	 	if (a>=b) {printf("A nije manje od B.\n");}				
	 	else if (a<1) {printf("A nije prirodan broj.\n");}
	 	else {prekid=1;}
	 }
	 
	 //Trazenje sume
	 
	 for (i=0; i<b; i++) {
	 	
	 	int r=daj_prost();
	 	
	 	
	 	if (r>=b) break;
	 	else if (r<=a) continue;
	 	suma=suma+r;
	 	
	 }
	 
	 printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	 
	
	return 0;
}
