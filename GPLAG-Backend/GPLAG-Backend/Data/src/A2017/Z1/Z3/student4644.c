#include <stdio.h>

int main() {
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, ukupan_broj=0, max_boja=0;
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
	
		
			
		
			case('K'): break;
			case('k'): break;
			
			default: printf("Neispravan unos \n");
		}
			
       
	}
       while (znak != 'k' && znak != 'K');
       ukupan_broj= crna+crvena+plava+siva+bijela;
       printf ("Ukupno evidentirano %d vozila. \n", ukupan_broj);
       postotak=(max_boja/(float)ukupan_broj)*100.;
       switch (max_ime_boje) {
       	case ('C'): printf ("Najpopularnija boja je crna (%.2f%). \n", postotak); break;
       	case ('c'): printf ("Najpopularnija boja je crna (%.2f%). \n", postotak); break;
       	case ('V'): printf ("Najpopularnija boja je crvena (%.2f%). \n", postotak); break;
       	case ('v'): printf ("Najpopularnija boja je crvena (%.2f%). \n ", postotak); break;
       	case ('S'): printf ("Najpopularnija boja je siva (%.2f%). \n ", postotak); break;
       	case ('s'): printf ("Najpopularnija boja je siva (%.2f%). \n ", postotak); break;
       	case ('P'): printf ("Najpopularnija boja je plava (%.2f%). \n ", postotak); break;
     	case ('p'): printf ("Najpopularnija boja je plava (%.2f%). \n ", postotak); break;
       	case ('B'): printf ("Najpopularnija boja je bijela (%.2f%). \n ", postotak); break;
       	case ('b'): printf ("Najpopularnija boja je bijela (%.2f%). \n ", postotak); break;
       
      
       	
       }
       if(ukupan_broj==0)
          printf("Najpopularnija boja je crna (0.00%).\n");
   
    
		return 0;
			
	}