#include <stdio.h>
/*trazenje prostog broja uz ocuvanje njegove vrijednosti*/
int daj_prost(){
	static int broj=1;
	int i;
	broj++;
	do {
	for (i=2;i<broj;i++){
		if (broj%i==0) {
		broj++;
		break;
		}
	}
	} while (broj%i!=0);
	
	return broj;
	
}
int main() {
	int A,B,suma=0,Prost_broj;
	do{
		printf("Unesite brojeve A i B:"); 
		scanf("%d %d",&A,&B);
		if(A<=0){ 
			printf(" A nije prirodan broj.\n"); 
			continue;
		}
		else if(A>=B) {
			printf(" A nije manje od B.\n"); 
			continue;
		}
		
	}while (A<=0 || A>=B);
	
	for (Prost_broj=1;Prost_broj<B;Prost_broj++){
		Prost_broj=daj_prost();
		if (Prost_broj>A && Prost_broj<B){
			suma+=Prost_broj;
		}
	}
	printf (" Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
