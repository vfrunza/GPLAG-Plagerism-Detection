#include <stdio.h>
int main() {
	char novi_red, tarik, bojan, mirza;
	
	// Zahtjev za unos jela//
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	// Utjecaj izbora jela na cijenu //
	
	if (tarik=='P' && bojan=='P' && mirza=='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
	}
	else if (tarik=='P' && bojan=='P' && mirza=='C'){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	else if (tarik=='P' && bojan=='C' && mirza=='P'){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	else if (tarik=='C' && bojan=='P' && mirza=='P'){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	else if (tarik=='P' && bojan=='P' && mirza=='H'){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (15.54 KM).");
	}
	else if (tarik=='P' && bojan=='H' && mirza=='P'){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (15.54 KM).");
	}
	else if (tarik=='H' && bojan=='P' && mirza=='P'){
		printf ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (15.54 KM).");
	}
	else if (tarik=='H' && bojan=='H' && mirza=='H'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (8.91 KM).");
	}
	else if (tarik=='H' && bojan=='H' && mirza=='P'){
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}
	else if (tarik=='H' && bojan=='P' && mirza=='H'){
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}
	else if (tarik=='P' && bojan=='H' && mirza=='H'){
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}
	else if (tarik=='H' && bojan=='H' && mirza=='C'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	else if (tarik=='H' && bojan=='C' && mirza=='H'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	else if (tarik=='C' && bojan=='H' && mirza=='H'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	else if (tarik=='C' && bojan=='C' && mirza=='C'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM).");
	}
	else if (tarik=='C' && bojan=='C' && mirza=='P'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).\n");
	}
	else if (tarik=='C' && bojan=='P' && mirza=='C'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).\n");
	}
	else if (tarik=='P' && bojan=='C' && mirza=='C'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).\n");
	}
	else if (tarik=='C' && bojan=='C' && mirza=='H'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	else if (tarik=='C' && bojan=='H' && mirza=='C'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	else if (tarik=='H' && bojan=='C' && mirza=='C'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	else if (tarik=='P' && bojan=='H' && mirza=='C'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	else if (tarik=='C' && bojan=='H' && mirza=='P'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	else if (tarik=='H' && bojan=='P' && mirza=='C'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	else if (tarik=='H' && bojan=='C' && mirza=='P'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	else if (tarik=='P' && bojan=='C' && mirza=='H'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	else if (tarik=='C' && bojan=='P' && mirza=='H'){
		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		printf ("Sa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	return 0;
}
