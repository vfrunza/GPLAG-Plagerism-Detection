#include <stdio.h>
#include <math.h>
#define EPSILON 0,001;
enum TipOblika {TACKA,KRUZNICA,PRAVOUGAONIK,TROUGAO};
struct Tacka{
	int x,y;
};
struct Kruznica{
	struct Tacka centar;
	float poluprecnik;
};
struct Pravougaonik{
	struct Tacka dolje_lijevo;
	float sirina;
	float visina;
};
struct Trougao{
	struct Tacka prvi_vrh;
	struct Tacka drugi_vrh;
	struct Tacka treci_vrh;
};
int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2){
	
}
int main() {
	printf("Zadaća 5, Zadatak 2");
	return 0;
}
