#include <stdio.h>

void unesi (char* niz, int velicina) {
	char znak=getchar();
	int i=0;
	if (znak=='\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine (char* recenica, int* brojevi, int velicina) {
	int razmak=1, brojRijeci=0, duzina, pomocna;
	char* pom;
	
	while (*recenica!='\0') {
		pom=recenica;
		duzina=0;
		pomocna=0;
		
		if (!((*recenica>='A' && *recenica<='Z') || (*recenica>='a' && *recenica<='z'))) razmak=1;
		else if (razmak==1) {
			razmak=0;
			brojRijeci++;
			pomocna=1;
		}
		
		if (pomocna) {
			while ((*pom>='A' && *pom<='Z') || (*pom>='a' && *pom<= 'z')) {
				duzina++;
				pom++;
			}	
			
			if (duzina!=brojevi[brojRijeci-1]) return 0;
		}
		
		
		recenica++;
	}
	
	if (brojRijeci!=velicina) return 0;
	
	return 1;
}


int main() {
	char recenica[200];
	int brojevi[100], i, velicina=0;
	
	printf ("Unesite recenicu: ");
	unesi(recenica, 200);
	
	printf ("\nUnesite niz brojeva: ");
	
	for (i=0; i<200; i++) {
		scanf ("%d", &brojevi[i]);
		 if (brojevi[i]==-1) break;
		 velicina++;
	}
	
	printf ("\n%d", provjeri_duzine(recenica, brojevi, velicina));
	
	return 0;
}
