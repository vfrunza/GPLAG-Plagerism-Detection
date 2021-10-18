#include <stdio.h>

enum TipOblika{TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};
struct Tacka {
	float x,y;
};
struct Kruznica {
	struct Tacka centar;
	float poluprecnik;
};

struct Pravougaonik{
	struct Tacka prva;
	struct Tacka druga;
	struct Tacka treca;
};
int main() {
	printf("Zadaća 5, Zadatak 2");
	return 0;
}
