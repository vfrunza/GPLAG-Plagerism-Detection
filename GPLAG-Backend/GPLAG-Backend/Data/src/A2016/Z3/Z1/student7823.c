#include <stdio.h>
int daj_prost();
int daLiJeProst(int broj);
int main() {
	//printf("Zadaća 3, Zadatak 1");
	int A, B, trenutniProstBroj=0, suma=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d%d", &A, &B);
	
	if(A<1){
		printf("A nije prirodan broj.\n");
		continue;
	}
	if(B<=A){
		printf("A nije manje od B.\n");
		continue;
	}
	}while(A<1 || B<=A);
	
	while(trenutniProstBroj<=A){
		trenutniProstBroj=daj_prost();
	}
	
	while(trenutniProstBroj<B){
		suma+=trenutniProstBroj;
		trenutniProstBroj=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
int daj_prost(){
	static int broj=1;
	int i;
	broj++;
	for(i=2; i<broj; i++){
		if(broj%i==0){
			i= 1;
			broj++;
		}
	}
	return broj;
}
