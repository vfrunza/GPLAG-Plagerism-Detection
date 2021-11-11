#include <stdio.h>
/*Funkcija provjerava da li je broj prost*/ 
int prost(int broj){
	int i,prost;
	prost=1;
	for(i=2; i<broj; i++)
		if(broj%i==0)
			return prost=0;
	return prost;
}
int daj_prost(){
	/*Koristit cemo staticku promjenjljivu jer je tako dato u zadatku*/
	static int broj=1;
	if(broj==1){
		broj++;
		return 2;
	}
	do{
		broj ++;
		if(prost(broj))
			break;
	}while(prost(broj!=1));
	return broj;
}
int main() {
	int A,B,prost=0,suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A>=B)
			printf("A nije manje od B.\n");
		if(A<1)
			printf("A nije prirodan broj.\n");
	}while(A>=B || A<1);
	while(prost<=B){
		prost=daj_prost();
		if(prost<=A || prost>=B)
			continue;
		else suma+=prost;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
