#include <stdio.h>

int main() { 
	
	char m, b, t, nr;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m); 
	scanf("%c", &nr); // possibly ne treba
	if(m=='C' && t=='C' && b=='C') 
	printf("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM).");
	else if(m=='H' && t=='H' && b=='H')
	printf("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).\nSa popustom bi Restoran bio jeftiniji (8.91 KM).");
	else if(m=='P' && t=='P' && b=='P')
	printf("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
	else if((m=='P' && t=='P' && b=='H') || (m=='P' && b=='P' && t=='H') || (b=='P' && t=='P' && m=='H'))
	printf("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\nSa popustom bi Restoran bio jeftiniji (15.54 KM).");
	else if((m=='P' && t=='P' && b=='C') || (m=='P' && b=='P' && t=='C') || (b=='P' && t=='P' && m=='C'))
	printf("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	else if((m=='H' && t=='H' && b=='P') || (m=='H' && b=='H' && t=='P') || (b=='H' && t=='H' && m=='P'))
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	else if((m=='H' && t=='H' && b=='C') || (m=='H' && b=='H' && t=='C') || (b=='H' && t=='H' && m=='C'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM)."); 
	else if((m=='C' && t=='C' && b=='P') || (m=='C' && b=='C' && t=='P') || (b=='C' && t=='C' && m=='P'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).");
	else if((m=='C' && t=='C' && b=='H') || (m=='C' && b=='C' && t=='H') || (b=='C' && t=='C' && m=='H'))
	printf("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	else printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM).");
	
	return 0;
}
