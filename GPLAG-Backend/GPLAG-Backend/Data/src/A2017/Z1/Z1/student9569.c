#include <stdio.h>


int main() {
	char Tarik, Bojan, Mirza, novi_red;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	
	if(Tarik=='P' && Bojan=='P' && Mirza =='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
	}
	else if((Tarik=='P' && Bojan=='P' && Mirza=='H') || (Tarik=='P' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='P')){
		printf("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).");
		printf("\nSa popustom bi Restoran bio jeftiniji (15.54 KM).");
	}
	else if((Tarik=='P' && Bojan=='P' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='P')){
		printf("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	else if((Tarik=='P' && Bojan=='C' && Mirza=='H') || (Tarik=='P' && Bojan=='H' && Mirza=='C') || (Tarik=='C' && Bojan=='P' && Mirza=='H') ||(Tarik=='C' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='P')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).");
		printf("\nSa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
	else if((Tarik=='P' && Bojan=='H' && Mirza=='H') || (Tarik=='H' && Bojan=='P' && Mirza=='H') || (Tarik=='H' && Bojan=='H' && Mirza=='P')){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}
	else if((Tarik=='C' && Bojan=='H' && Mirza=='H') || (Tarik=='H' && Bojan=='C' && Mirza=='H') || (Tarik=='H' && Bojan=='H' && Mirza=='C')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	else if(Tarik=='H' && Bojan=='H' && Mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).");
		printf("\nSa popustom bi Restoran bio jeftiniji (8.91 KM).");
	}
	else if((Tarik=='C' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='C')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).");
		
	}
	else if((Tarik=='C' && Bojan=='C' && Mirza=='H') ||(Tarik=='C' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='C')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	else if((Tarik=='C' && Bojan=='C' && Mirza=='C')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM).");
	}
	return 0;
}
