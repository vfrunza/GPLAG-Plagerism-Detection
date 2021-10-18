#include <stdio.h>

int provjeri_duzine(char* tekst, int* duzine, int vel);

int main() {
	char tekst[] = "Ovo je neki primjer teksta";
	int niz[] = {3, 2, 4, 7, 6};
	
	printf("%d ", provjeri_duzine(tekst, niz, 5));
	printf("%d ", provjeri_duzine(tekst, bezveze_niz, 5));
	
	return 0;
}

int provjeri_duzine(char* tekst, int* duzine, int vel) {
	int i;
	int duzina = 0, duzine_i = 0;
	
	for (i = 0; tekst[i] != '\0'; i++) {
		if ((tekst[i] >= 'a' && tekst[i] <= 'z') || (tekst[i] >= 'A' && tekst[i] <= 'Z')) {
			if (duzine_i == vel)
				return 0;
				
			duzina += 1;
		} 
		else if (duzina > 0) {
			if (duzina != duzine[duzine_i]) {
				return 0;
			} else {
				duzine_i += 1;
				duzina = 0;
				
				if (duzine_i < vel && duzine[duzine_i] == 0)
					return 0;
			}
		}
	}
	
	duzine_i += 1;
	if (duzine_i < vel)
		return 0;
	
	return 1;
}
