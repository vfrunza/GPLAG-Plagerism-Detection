#include <stdio.h>
#define PR 6.80
#define HR 3.30
#define CR 5.00
#define PF 8.00
#define HF 3.00
#define CF 3.90
#define PB 5.30
#define HB 5.00
#define CB 6.00

int main()
{
	char Tarik, Bojan, Mirza, novi_red;
	float  H, C, P, iznos=0, iznos1=0, popust=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);
	if((Mirza=='C' && Tarik=='P' && Bojan=='H') ||(Mirza=='C'&&Tarik=='H'&&Bojan=='P')||(Mirza=='P'&&Tarik=='H'&&Bojan=='C')||(Mirza=='P'&& Tarik=='C'&& Bojan=='H')||(Mirza=='H' && Tarik=='P' && Bojan=='C') || (Mirza=='H'&& Tarik=='C'&& Bojan=='P')) {
		iznos= PF +CF +HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", iznos);
	} else if(Mirza=='C' && Tarik=='C' && Bojan=='C') {
		iznos=CF+CF+CF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", iznos);

	} else if(Mirza=='H' && Tarik=='H' && Bojan=='H') {
		iznos=HF+HF+HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", iznos);

	}


	else if((Mirza=='C' && Bojan=='C' && Tarik=='P') || (Mirza=='P' && Bojan=='C' && Tarik=='C')||(Mirza=='C' && Bojan=='P' && Tarik=='C')) {
		iznos=CF+CF+PF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", iznos);
	} else if((Mirza=='C' && Bojan=='C' && Tarik=='H') || (Mirza=='H' && Bojan=='C' && Tarik=='C')||(Mirza=='C' && Bojan=='H' && Tarik=='C')) {
		iznos=CF+CF+HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", iznos);
	} else if(Mirza=='P' && Bojan=='P' && Tarik=='P') {
		iznos=PB+PB+PB;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", iznos);

	} else if((Mirza=='P' && Bojan=='P' && Tarik=='C') || (Mirza=='C' && Bojan=='P' && Tarik=='P') || (Mirza=='P' && Bojan=='C' && Tarik=='P')) {
		iznos=PB+PB+CB;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", iznos);
	} else if((Mirza=='P' && Bojan=='P' && Tarik=='H') || (Mirza=='H' && Bojan=='P' && Tarik=='P') || (Mirza=='P' && Bojan=='H' && Tarik=='P')) {
		iznos=PB+PB+HB;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", iznos);
	}

	else if((Mirza=='H' && Bojan=='H' && Tarik=='C')||(Mirza=='C' && Bojan=='H' && Tarik=='H')||(Mirza=='H' && Bojan=='C' && Tarik=='H') ) {
		iznos=HF+HF+CF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", iznos);
	} else if((Mirza=='H' && Bojan=='H' && Tarik=='P')||(Mirza=='H' && Bojan=='P' && Tarik=='H')||(Mirza=='P' && Bojan=='H' && Tarik=='H') ) {
		iznos=HR+HR+PR;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", iznos);

		
	}
	if(Mirza=='H'&&Bojan=='H'&& Tarik=='H') {
		iznos1=(HR+HR+HR)-3*HR*10/100;
	} else if((Mirza=='H'&& Bojan=='H' && Tarik=='P')||(Mirza=='H'&& Bojan=='P' && Tarik=='H')||(Mirza=='P'&& Bojan=='H' && Tarik=='H')) {
		iznos1=(HR+HR)+ (PR-PR*10/100);
	} else if((Mirza=='H'&& Bojan=='H' && Tarik=='C')||(Mirza=='H'&& Bojan=='C' && Tarik=='H')||(Mirza=='C'&& Bojan=='H' && Tarik=='H')) {
		iznos1=(HR+HR)+(CR-CR*10/100);

	} else if(Mirza=='P'&& Bojan=='P'&& Tarik=='P') {
		iznos1=(PR+PR+PR)-(PR*10/100);

	}

	else if((Mirza=='P' && Bojan=='P'&& Tarik=='C')||(Mirza=='P' && Bojan=='C'&& Tarik=='P')|| (Mirza=='C'&& Bojan=='P'&& Tarik=='P')) {
		iznos1=(PR+PR)-(2*PR*10/100)+CR;
	} else if((Mirza=='P' && Bojan=='P'&& Tarik=='H')||(Mirza=='P' && Bojan=='H'&& Tarik=='P')|| (Mirza=='H'&& Bojan=='P'&& Tarik=='P')) {
		iznos1=(PR+PR)-(2*PR*10/100)+HR;
	} else if(Mirza=='C'&& Bojan=='C'&& Tarik=='C') {
		iznos1=(CR+CR+CR)-(3*CR*10/100);
	} else if((Mirza=='C'&& Bojan=='C'&& Tarik=='P') || (Mirza=='C'&& Bojan=='P'&& Tarik=='C')||(Mirza=='P'&&Bojan=='C'&&Tarik=='C')) {
		iznos1=(CR+CR)-(PR*10/100);
	} else if((Mirza=='C'&& Bojan=='C'&& Tarik=='H') || (Mirza=='C'&& Bojan=='H'&& Tarik=='C')||(Mirza=='H'&&Bojan=='C'&&Tarik=='C')) {
		iznos1=((CR+CR)-(2*CR*10/100)+HR);
	} else if((Mirza=='C' && Bojan=='H' && Tarik=='P') || (Mirza=='C' && Bojan=='P' && Tarik=='H') || (Mirza=='H' && Bojan=='C' && Tarik=='P') || (Mirza=='H' && Bojan=='P' && Tarik=='C') || (Mirza=='P' && Bojan=='C' && Tarik=='H') || (Mirza=='P' && Bojan=='H' && Tarik=='C')) {
		iznos1=CR+HR+(PR-PR*10/100);
	}
	if((popust=1)&&(iznos1<iznos)) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", iznos1);
	}


	return 0;
}
