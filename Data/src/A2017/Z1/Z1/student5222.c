#include <stdio.h>

int main() {
	
	float PK=6.80, HK=3.30, CK=5, PT=8, HT=3, CT=3.90, PL=5.30, HL=5, CL=6, PKP, HTP, CLP;
	char Tarik, Bojan, Mirza, novi_red;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);
	
	PKP=PK-(PK/100);
	HTP=HT-(HT/100);
	CLP=CL-(CL/100);
	
	
	if(Tarik=='P' || Bojan=='P' || Mirza=='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", 3*PL);
	}
	else if(Tarik=='H' || Bojan=='H' || Mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 3*HT);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", 3*HTP);
	}
	else if(Tarik=='C' || Bojan=='C' || Mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", 3*CT);
	}
	else if(Tarik=='P' || Bojan=='H' || Mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", PT+HT+CT);
	}
	else if(Tarik=='H' || Bojan=='P' || Mirza=='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", HL+(2*PL));
		
	}
	else if(Tarik=='P' || Bojan=='P' || Mirza=='C'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", (2*PL)+CL);
	}
	else if(Tarik=='H' || Bojan=='H' || Mirza=='P'){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", (2*HK)+PK);
	}
	else if(Tarik=='H' || Bojan=='H' || Mirza=='C'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (2*HT)+CT);
	}
	else if(Tarik=='C' || Bojan=='C' || Mirza=='P'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (2*CT)+PT);
	}
	else if(Tarik=='C' || Bojan=='C' || Mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (2*CT)+HT);
	}
	return 0;
}
