#include <stdio.h>

int main() {
char TARIK, BOJAN, MIRZA, novi_red ;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &TARIK);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &BOJAN);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &MIRZA);
	scanf ("%c", &novi_red);
	if ((TARIK=='P') && (BOJAN=='P') && (MIRZA=='P')){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
		} 
	else if ((TARIK=='H') && (BOJAN=='H') && (MIRZA=='H')){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (8.91 KM).");
		}
	else if ((TARIK=='C') && (BOJAN=='C') && (MIRZA=='C')){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM).");
		}
	else if ((TARIK=='P') && (BOJAN=='P') && (MIRZA=='H') || (TARIK=='P') && (BOJAN=='H') && (MIRZA=='P') || (TARIK=='H') && (BOJAN=='P') && (MIRZA=='P')) {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM). \n");
		printf ("Sa popustom bi Restoran bio jeftiniji (15.54 KM).");
	}
	else if ((TARIK=='P') && (BOJAN=='P') && (MIRZA=='C') || (TARIK=='P') && (BOJAN=='C') && (MIRZA=='P') || (TARIK=='C') && (BOJAN=='P') && (MIRZA=='P')){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
		}
	else if ((TARIK=='H') && (BOJAN=='H') && (MIRZA=='P') || (TARIK=='H') && (BOJAN=='P') && (MIRZA=='H') || (TARIK=='P') && (BOJAN=='H') && (MIRZA=='H')){
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}	
	else if ((TARIK=='H') && (BOJAN=='H') && (MIRZA=='C') || (TARIK=='H') && (BOJAN=='C') && (MIRZA=='H') || (TARIK=='C') && (BOJAN=='H') && (MIRZA=='H')){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	else if ((TARIK=='C') && (BOJAN=='C') && (MIRZA=='P') || (TARIK=='C') && (BOJAN=='P') && (MIRZA=='C') || (TARIK=='P') && (BOJAN=='C') && (MIRZA=='C')){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).\n");
	}
	else if ((TARIK=='C') && (BOJAN=='C') && (MIRZA=='H') || (TARIK=='C') && (BOJAN=='H') && (MIRZA=='C') || (TARIK=='H') && (BOJAN=='C') && (MIRZA=='C')){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	else if ((TARIK=='P') && (BOJAN=='H') && (MIRZA=='C') || (TARIK=='P') && (BOJAN=='C') && (MIRZA=='H') || (TARIK=='H') && (BOJAN=='C') && (MIRZA=='P') || (TARIK=='H') && (BOJAN=='P') && (MIRZA=='C') || (TARIK=='C') && (BOJAN=='H') && (MIRZA=='P') || (TARIK=='C') && (BOJAN=='P') && (MIRZA=='H')){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	return 0;
}
