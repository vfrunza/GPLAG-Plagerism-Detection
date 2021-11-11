#include <stdio.h>

int cifra_sadrzana(int *niz, int vel, int cifra){
	int *pok = niz;
	while(pok < niz+vel){
		if(cifra == *pok) return 1;
		pok++;
	}
	return 0;
}

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
	int dva_od_tri = 0, *cifra = niz1;
	while(cifra < niz1+vel1){
		if(((cifra_sadrzana(niz2, vel2, *cifra) && !(cifra_sadrzana(niz3, vel3, *cifra))) || (!(cifra_sadrzana(niz2, vel2, *cifra)) && cifra_sadrzana(niz3, vel3, *cifra))) && !(cifra_sadrzana(niz1, cifra-niz1, *cifra)))
			dva_od_tri++; //Provjera da li se elemenat iz prvog niza nalazi u samo jednom od ostala dva, i da li smo taj elemenat vec ispitali
		cifra++;
	}
	cifra = niz2;
	while(cifra < niz2+vel2){
		if(cifra_sadrzana(niz3, vel3, *cifra) && !cifra_sadrzana(niz1, vel1, *cifra) && !cifra_sadrzana(niz2, cifra-niz2, *cifra))
			dva_od_tri++; //Provjera postoje li element u drugom i trecem nizu, a da nije u prvom, i da li smo taj elelemnt vec ispitali
		cifra++;
	}
	
	return dva_od_tri;
}

int main() {
	return 0;
}
