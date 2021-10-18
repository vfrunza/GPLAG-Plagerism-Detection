#include <stdio.h>
#include <stdlib.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void dodaj_oblik(struct Oblik *ob) {
	FILE* izlaz;
	izlaz=fopen("oblici.dat", "ab");
	if(izlaz==NULL) exit(1);
	fwrite("1", sizeof(int), 1, izlaz);
	fwrite(ob.naziv, sizeof(char), 20, izlaz);
	fwrite(ob.)
}

int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}
