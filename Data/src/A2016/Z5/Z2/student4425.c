#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

void kompresuj (char* ime_ulazne, char* ime_izlazne) {
	
}

void dekompresuj (char* ime_komp, char* ime_dekomp) {
	
}

int main() {
	
	int odabir;
	char ime_ulazne[20], ime_izlazne[20], ime_komp[20], ime_dekomp[20];
	
	do {
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &odabir);
		if (odabir == 1) {
			printf ("Unesite ime ulazne datoteke: ");
			unesi(ime_ulazne, 20);
			printf ("\nUnesite ime izlazne datoteke: ");
			unesi(ime_izlazne, 20);
			kompresuj(ime_ulazne, ime_izlazne);
			printf ("Datoteka kompresovana.");
		}
		if (odabir == 2) {
			printf ("Unesite ime ulazne datoteke: ");
			unesi(ime_komp, 20);
			printf ("\nUnesite ime izlazne datoteke: ");
			unesi(ime_dekomp, 20);
			dekompresuj(ime_komp, ime_dekomp);
			printf ("Datoteka dekompresovana.");
		}
	} while (odabir!=0);
	
	
	return 0;
}
