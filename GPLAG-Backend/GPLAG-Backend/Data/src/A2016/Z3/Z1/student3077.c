#include <stdio.h>
int daj_prost(){
	static int broj=2;
	int i, j, brojac=0;
	for(i=broj; i<10000;){
		for(j=1; j<broj; j++){
			if(i%j==0) brojac++;
		} if(brojac==1){
			brojac=0;
			return broj;
		} else {
			broj++;
			continue;
		}
	}
}
int main() {
	int A, B, suma=0, sabirak;
	do{
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A<1) printf("A nije prirodan broj.");
		else if(A>=B) printf("A nije manje od B.");
		else if(B<1) printf("B nije prirodan broj.");
	} while(A<1 || B<1 || A>=B);
	sabirak=daj_prost();
	while(sabirak<B && sabirak>A){
	    if(sabirak>=B) break;
	    if(sabirak>A && sabirak<B) suma+=sabirak;
	    sabirak=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	return 0;
}




