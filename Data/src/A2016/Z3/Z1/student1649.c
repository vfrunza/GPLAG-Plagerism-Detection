#include <stdio.h>
int daj_prost(){
	static int br=2;
	int i=2;
	/*Petlja provjerava da li je cijeli broj br prost. Deklaracija br kao staticke
	promjenljive osigurava da pri svakom pozivu funkcija vrati sljedeci prost broj*/
	while(i<br){
		if(!(br%i++)){
			br++;
			i=2;
		}
	}
	return br++;
}
int main() {
	int A,B,suma=0, prostbr;
	/*Unos prirodnih brojeva A i B takvih da je A<B*/
	while(1){
		printf("\nUnesite brojeve A i B: ");
		scanf("%d", &A);
		scanf("%d", &B);
		if(A<1){
			printf("A nije prirodan broj.");
			continue;
		}
		if(!(A<B)){
			printf("A nije manje od B.");
			continue;
		}
		break;
	}
	/*U petlji se vrsi poziv funkcije daj_prost i racuna suma prostih brojeva
	 strogo većih od A a strogo manjih od B. Petlja prekida kada prosti brojevi 
	 koje vraca funkcija daj_prost postanu veci (ili jednaki) B.*/
	while(1){
		prostbr=daj_prost();
		if(!(prostbr<B)) break;
		if(prostbr>A && prostbr<B) suma+=prostbr;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
