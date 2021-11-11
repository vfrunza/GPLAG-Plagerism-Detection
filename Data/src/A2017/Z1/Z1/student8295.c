#include <stdio.h>
#define HHH 9.0
#define PPP 15.9
#define CCC 11.7
#define HHP 13.4
#define HHC 9.9
#define HPP 15.6
#define HCC 10.8
#define PPC 16.6
#define HCP 14.9
#define PCC 15.8
#define c1 6

int main()
{

	char Bojan,Mirza,Tarik,novi_red;
	double H,P,C,h,popust,popust1;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);

	h=HHH/100;
	popust=HHH-h;
	if(Tarik=='H' && Bojan=='H' && Mirza=='H') {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HHH);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);

	}

	if(Tarik=='P' && Bojan=='P' && Mirza=='P') {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", PPP);

	}

	if(Tarik=='C' && Bojan=='C' && Mirza=='C') {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", CCC);

	}

	if((Tarik=='H' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='H') || ((Tarik=='P' && Bojan=='H' && Mirza=='H'))) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", HHP);

	}

	if((Tarik=='H' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='H') || ((Tarik=='C' && Bojan=='H' && Mirza=='H'))) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HHC );

	}

	popust1=HPP-0.06;
	if((Tarik=='H' && Bojan=='P' && Mirza=='P') || (Tarik=='P' && Bojan=='H' && Mirza=='P') || ((Tarik=='P' && Bojan=='P' && Mirza=='H'))) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", HPP );
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",popust1);

	}



	if((Tarik=='H' && Bojan=='C' && Mirza=='C') || (Tarik=='C' && Bojan=='C' && Mirza=='H') || ((Tarik=='C' && Bojan=='H' && Mirza=='C'))) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HCC );

	}

	if((Tarik=='P' && Bojan=='P' && Mirza=='C') || (Tarik=='C' && Bojan=='P' && Mirza=='P') || ((Tarik=='P' && Bojan=='C' && Mirza=='P'))) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", PPC );

	}

	if((Tarik=='C' && Bojan=='H' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='H') || ((Tarik=='P' && Bojan=='H' && Mirza=='C'))) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HCP );
		printf("\nSa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}

	if((Tarik=='C' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='C') || ((Tarik=='P' && Bojan=='C' && Mirza=='C'))) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", PCC );

	}


	return 0;
}
