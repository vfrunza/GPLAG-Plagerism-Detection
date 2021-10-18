#include <stdio.h>
#include <stdlib.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
}

void dodaj_oblik (struct Oblik niz) {
	FILE* ulaz;
	
	ulaz=fopen("binarna.dat", "ab") 
	if (ulaz==NULL) {
		printf("Greska pri otvaranju datoteke!\n");
		exit(1);
	}
	
	
}


int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}
