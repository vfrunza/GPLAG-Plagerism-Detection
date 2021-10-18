#include <stdio.h>

int provjeri_duzine (char* s, int niz[], int vel) {
	int prekid=1, broj_rijeci=0, duzina_rijeci=0;
	
	while (*s!='\0') {
		if (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) prekid=1;
		else if (prekid==1) {
			prekid=0;
			if (vel<broj_rijeci) return 0;
			broj_rijeci++;
			duzina_rijeci=0;
			
			/* Posmatramo isključivo velika i mala slova: */
			while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				duzina_rijeci++;
				s++;
			}
			
			/* Poredimo odgovarajući član niza sa dužinom svake riječi: */
			if (niz[broj_rijeci-1]!=duzina_rijeci) return 0;
			
			/* Pokazivač vraćamo na prekid riječi: */
			s--;
		}
		s++;
	}
	
	/* Veličina niza i broj riječi moraju biti jednaki: */
	if (vel!=broj_rijeci) return 0;
	
	return 1;
}

int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
