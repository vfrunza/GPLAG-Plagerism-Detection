#include <stdio.h>
int vrati_broj_prestupnih(int x){
	int n=0,i;
	for(i=0;i<x;i++){
		if(i%4==0 || (i%100==0 && i%400==0)) n++;
		return n;
	}
}
int pretvori_u_broj_dana(int god,int mjes,int dan){
	
}
struct Datum{
	int dan;
	int mjesec;
	int godina
};
struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
}
int suzi_listu(struct Uposlenik* kandidat,int vel,struct Uposlenik direktor,int broj_dana){
	
	
	for(i=0;i<vel;i++){
		
	}
}


int main() {
	
	return 0;
}
