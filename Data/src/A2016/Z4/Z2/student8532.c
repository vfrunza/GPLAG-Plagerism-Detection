#include <stdio.h>

void unesi(char niz[], int velicina)	{
    char znak = getchar();
    int i;
    if (znak == '\n') znak = getchar();
    i = 0;
    while (i < velicina-1 && znak != '\n')	{
        niz[i] = znak;
        i++;
        znak = getchar();
    }	niz[i] = '\0';
}

/* Pomocna funkcija funkcije kodiraj */
void kodiraj_sort_znak (char *znak, int *brojac) {
	char novicode[120] = "";
	int novi_br_niz[100] = {0};
	char *resetZnak = znak;
	int *resetBrojac = brojac;
	char *codepok = novicode;
	int *novi_br = novi_br_niz;
	int i, max;
	
	/* max ? */
	max = *brojac;
	while (*brojac != '\0') {
		if (*brojac > max)
			max = *brojac;
		brojac++;
	}
	/* Kopiram string */
	while (*znak != '\0') {
		*codepok = *znak;
		codepok++;
		znak++;
	}	*codepok = '\0';
	
	/* Kopiram niz brojeva */
	brojac = resetBrojac;
	while (*brojac != '\0') {
		*novi_br = *brojac;
		novi_br++;
		brojac++;
	}	*novi_br = '\0';
	
	/* Redam po ASCII vrijednosti prvo */
	znak = resetZnak;
	brojac = resetBrojac;
	for (i=32; i<=126; ++i) {
		codepok = novicode;
		novi_br = novi_br_niz;
		
		while (*codepok != '\0') {
			if (*codepok == i) {
				*znak = *codepok;
				*brojac = *novi_br;
				brojac++;
				znak++;
			}	
			codepok++;
			novi_br++;
		}
	}	*znak = '\0';	*novi_br = '\0';

	codepok = novicode;
	for (i=max; i>0; --i) {
		znak = resetZnak;
		brojac = resetBrojac;
		
		while (*brojac != '\0') {
			if (*brojac == i) {
				*codepok = *znak;
				codepok++;
			}
			brojac++;
			znak++;
		}
	}
	
	znak = resetZnak;
	codepok = novicode;
	while (*codepok != '\0') {
		*znak = *codepok;
		codepok++;
		znak++;
	}	*znak = '\0';
}

char* kodiraj (char *s, char *p) {
	 char code[120];
	 char glavni_niz_copy[500];
	 int br_znakova[100] = {0};
	 int *brojac = br_znakova, kontrolna, i, codebrojac;
	 /* pomocne pokazivacke varijable za niz -> tekst i -> sifre */
	 char *glavniS = s, *glavniP = p, *resetS = s;
	 /* pokazivacke varijable i pomocne za temp niz code */
	 char *codepok = code, *codetest = code; 
	 char *codedelone = code, *codedeltwo = code;
	 /* pokazivac na pomocni glavni niz */
	 char *glavni2 = glavni_niz_copy;
	 
	 /* Kopiram u pomocni niz */
	 while (*glavniS != '\0') {
	 	*codepok = *glavniS;
	 	codepok++;
	 	glavniS++;
	 }	*codepok = '\0';
	 
	 /* Izbacujem iz pomocnog niza višak */
	 codepok = code;
	 while (*codepok != '\0') {
	 	codetest = (codepok+1);
	 	
	 	while (*codetest != '\0') {
	 		if (*codetest == *codepok) {
	 			codedelone = codetest;
	 			codedeltwo = (codetest+1);
	 			
	 			while (*codedeltwo != '\0') {
	 				*codedelone = *codedeltwo;
	 				codedelone++;
	 				codedeltwo++;
	 			}	*codedelone = '\0';
	 			
	 			codetest--;
	 		}	codetest++;
	 	}	codepok++;
	 }
	 
	 /* Brojim iste znakova iz pomocnog */
	 codepok = code;
	 brojac = br_znakova;
	 while (*codepok != '\0') {
        	glavniS = resetS;
	 
	 	while (*glavniS != '\0') {
	 		if (*codepok == *glavniS) {
	 			*brojac += 1;
	 		}
	 		glavniS++;
	 	}	codepok++;
	 	brojac++;
	 }	*brojac = '\0';
	 
	 /* Redam moj novi "code" niz od najcesceg znaka pomocu funkcije */
	 kodiraj_sort_znak (code, br_znakova);
	 
	 /* Kopiram u poslani niz za šifre  */
	 glavniP = p;
	 codepok = code;
	 while (*codepok != '\0') {
	 	*glavniP = *codepok;
	 	glavniP++;
	 	codepok++;
	 }
	 
	 for (i = 32; i <= 126; i++) {
	 	
	 	codepok = code;
	 	kontrolna = 1;
	 	while (*codepok != '\0') {
	 		if (*codepok == i) {
	 			kontrolna = 0;
	 		}	++codepok;
	 	}
	 	
	 	if (kontrolna) {
	 		*glavniP = i;
	 		glavniP++;
	 	}
	 }	*glavniP = '\0';
	 
	 glavniS = resetS;
	 while (*glavniS != '\0') {
	 	*glavni2 = *glavniS;
	 	glavni2++;
	 	glavniS++;
	 }	*glavni2 = '\0';
	 
	 /* kodiram oduzimajuci od '~' na osnovu brojaca pomaka u nizu code */
	 codepok = code;
	 codebrojac = 0;
	 while (*codepok != '\0') {
	 	glavni2 = glavni_niz_copy;
	 	glavniS = resetS;
	 	
		while (*glavni2 != '\0') {
			if (*codepok == *glavni2)
				*glavniS = ('~' - codebrojac);
				glavniS++;
				glavni2++;
		}
		codebrojac++;
		codepok++;
	 }
	 return resetS;
}

char* dekodiraj (char *s, char *p) {
	char code[100], sporedni[500], kopijaniz[500];
	char *alt = sporedni, *altx2 = sporedni;
	char *altdelone = sporedni, *altdeltwo = sporedni;
	char *codepok = code, *kopijaS = kopijaniz;
	char *resetS = s;
	char *glavniS = s, *glavniP = p;
	int razlicitih = 0, i = 0, asciirazlika;
	
	while (*glavniS != '\0') {
		*alt = *glavniS;
		alt++;
		glavniS++;
	}	*alt = '\0';
	
	alt = sporedni;
	while (*alt != '\0') {
			
		altx2 = alt+1;
		while (*altx2 != '\0') {
			if (*alt == *altx2) {
				
				altdelone = altx2;
				altdeltwo = altx2;
				while (*(altdeltwo+1) != '\0') {
					*altdelone = *(altdeltwo+1);
					altdelone++;
					altdeltwo++;
				}	*altdelone = '\0';
				altx2--;
			}
			altx2++;
		}
		alt++;
	}
	
	alt = sporedni;
	while (*alt != '\0') {
		razlicitih++;
		alt++;
	}
	
	alt = sporedni;
	asciirazlika = 126 - razlicitih;
	for (i=126; i>asciirazlika; --i) {
		*alt = i;
		alt++;
	}	*alt = '\0';
	
	for (i=0; i<razlicitih; i++) {
		*codepok = *glavniP;
		codepok++;
		glavniP++;
	}	*codepok = '\0';
	
	glavniS = resetS;
	while (*glavniS != '\0') {
		*kopijaS = *glavniS;
		glavniS++;
		kopijaS++;
	}	*kopijaS = '\0';
	
	codepok = code;
	alt = sporedni;
	while (*alt != '\0') {
		
		kopijaS = kopijaniz;
		glavniS = resetS;
		while (*glavniS != '\0') {
			if (*kopijaS == *alt)
			*glavniS = *codepok;
			glavniS++;
			kopijaS++;
		}
		alt++;
		codepok++;
	}
	return resetS;
}

int main() {
	char tekst[500];
	char sifrarnik[100] = "";
	printf ("Unesite tekst: ");
	unesi(tekst, 500);
	
	kodiraj(tekst, sifrarnik);
	printf ("Kodirano: \n");
	printf ("'%s'\n", tekst);
	printf ("'%s'\n", sifrarnik);
	
	dekodiraj(tekst, sifrarnik);
	printf ("Dekodirano: \n");
	printf ("'%s'\n", tekst);
	printf ("'%s'", sifrarnik);
	
	return 0;
}