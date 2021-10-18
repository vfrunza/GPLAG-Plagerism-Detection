#include <stdio.h>

int main() {
	int crna=0, crvena=0, siva=0, plava=0, bijela=0, ukupan_broj=0, max_boja=0;
	float postotak;
	char znak, max_ime_boje=0;
	printf ("Unesite vozila: ");
	do {
		scanf("%c", &znak);
		switch (znak) {
	
	
		   case ('C'): crna++;
		if (crna > max_boja) {
			max_boja=crna;
			max_ime_boje=znak;}
			break;
			case ('c'): crna++;
		if (crna > max_boja){
			max_boja=crna;
			max_ime_boje=znak;}
			break;
		
			case ('V'): crvena++;
		if (crvena > max_boja) {
			max_boja=crvena;
			max_ime_boje=znak;}
			break;
			case ('v'): crvena++;
		if (crvena > max_boja) {
			max_boja=crvena;
			max_ime_boje=znak;}
			break;
			
			case ('S'): siva++;
		if (siva > max_boja) {
			max_boja=siva;
			max_ime_boje=znak;}
			break;
			case ('s'): siva++;
		if (siva > max_boja) {
			max_boja=siva;
			max_ime_boje=znak;}
			break;
			
			case ('P'): plava++;
		if (plava > max_boja) {
			max_boja=plava;
			max_ime_boje=znak;}
			break;
			case ('p'): plava++;
		if (plava > max_boja) {
			max_boja=plava;
			max_ime_boje=znak;}
			break;
			
			case ('B'): bijela++;
		if (bijela > max_boja) {
			max_boja=bijela;
			max_ime_boje=znak;}
			break;
			case ('b'): bijela++;
		if (bijela > max_boja) {
			max_boja=bijela;
			max_ime_boje=znak;}
			break;
			
			case('K'): break;
			case('k'): break;
			
		if (znak != 'c' && znak !='C'){
			printf ("Neispravan unos");
		}		
		if (znak != 'v' && znak !='V'){
			printf ("Neispravan unos");
		}	
		if (znak != 's' && znak !='S'){
			printf ("Neispravan unos");
		}	
		if (znak != 'p' && znak !='P'){
			printf ("Neispravan unos");
		}
		if (znak != 'b' && znak !='B'){
			printf ("Neispravan unos");
		}
		if (znak != 'k' && znak !='K'){
			printf ("Neispravan unos");
		}	
		
			}
       }
       while (znak != 'k' && znak != 'K');
       ukupan_broj= crna+crvena+plava+siva+bijela;
       printf ("Ukupno evidentirano %d vozila. ", ukupan_broj);
       postotak=(max_boja/(float)ukupan_broj)*100.;
       switch (max_ime_boje) {
       	case ('C'): printf ("\nNajpopularnija boja je crna (%.2f%). ", postotak); break;
       	case ('c'): printf ("\nNajpopularnija boja je crna (%.2f%). ", postotak); break;
       	case ('V'): printf ("\nNajpopularnija boja je crvena (%.2f%). ", postotak); break;
       	case ('v'): printf ("\nNajpopularnija boja je crvena (%.2f%). ", postotak); break;
       	case ('S'): printf ("\nNajpopularnija boja je siva (%.2f%). ", postotak); break;
       	case ('s'): printf ("\nNajpopularnija boja je siva (%.2f%). ", postotak); break;
       	case ('P'): printf ("\nNajpopularnija boja je plava (%.2f%). ", postotak); break;
     		case ('p'): printf ("\nNajpopularnija boja je plava (%.2f%). ", postotak); break;
       	case ('B'): printf ("\nNajpopularnija boja je bijela (%.2f%). ", postotak); break;
       	case ('b'): printf ("\nNajpopularnija boja je bijela (%.2f%). ", postotak); break;
       }
		return 0;
			
			
			
			
			
			
			
		
	}