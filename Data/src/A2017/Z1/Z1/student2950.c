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
	float  sum=0,sum1=0,rest=0;
	char t,b,m,noviRed;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&noviRed);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&noviRed);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&noviRed);

	if((m=='C' && t=='P' && b=='H') || (m=='C' && t=='H' && b=='P')  || (m=='P' && t=='H' && b=='C') || (m=='P' && t=='C' && b=='H') || (m=='H' && t=='P' && b=='C') || (m=='H' && t=='C' && b=='P')) {
		sum= PF + CF + HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sum);
	} else if(m=='C' && b=='C' && t=='C') {
		sum = 3* CF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sum);
	} else if((m=='C' && b=='C' && t=='P') || (m=='P' && b=='C' && t=='C') || (m=='C' && b=='P' && t=='C')) {
		sum = 2*CF + PF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sum);
	} else if((m=='C' && b=='C' && t=='H') || (m=='H' && b=='C' && t=='C') || (m=='C' && b=='H' && t=='C')) {
		sum = CF + CF + HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sum);
	} else if((m=='P' && b=='P' && t=='P')) {
		sum = 3* PB;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sum);
	} else if((m=='P' && b=='P' && t=='C') || (m=='C' && b=='P' && t=='P') || (m=='P' && b=='C' && t=='P')) {
		sum = 2*PB + CB;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sum);
	} else if((m=='P' && b=='P' && t=='H') || (m=='H' && b=='P' && t=='P') || (m=='P' && b=='H' && t=='P')) {
		sum = 2*PB + HB;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", sum);
	} else if((m=='H' && b=='H'&& t=='H')) {
		sum = 3* HF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sum);
	} else if((m=='H' && b=='H' && t=='C') || (m=='H' && b=='C' && t=='H') || (m=='C' && b=='H' && t=='H')) {
		sum = 2*HF + CF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", sum);
	} else if((m=='H' && b=='H' && t=='P') || (m=='H' && b=='P' && t=='H') || (m=='P' && b=='H' && t=='H')) {
		sum = 2*HR + PR;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", sum);
		rest=1;
	}


	if(m=='H' && b=='H' && t=='H') {
		sum1 = 3*HR - 3*HR*10/100;
	} else if((m=='H' && b=='H' && t=='P') || (m=='P' && b=='H' && t=='H') || (m=='H' && b=='P' && t=='H')) {
		sum1 = 2*HR + (PR- PR*10/100);
	} else if((m=='H' && b=='H' && t=='C') || (m=='C' && b=='H' && t=='H') || (m=='H' && b=='C' && t=='H')) {
		sum1 = 2*HR + (CR- CR*10/100);
	} else if(m=='P' && b=='P' && t=='P') {
		sum1 = 3*PR - 3*PR*10/100;
	} else if((m=='P' && b=='P' && t=='C') || (m=='C' && b=='P' && t=='P') || (m=='P' && b=='C' && t=='P')) {
		sum1 = 2*PR - (2*PR*10/100) + CR;
	} else if((m=='P' && b=='P' && t=='H') || (m=='H' && b=='P' && t=='P') || (m=='P' && b=='H' && t=='P')) {
		sum1 = 2*PR - (2*PR*10/100) + HR;
	} else if(m=='C' && b=='C' && t=='C') {
		sum1 = 3*CR - 3*CR*10/100;
	} else if((m=='C' && b=='C' && t=='P') || (m=='P' && b=='C' && t=='C') || (m=='C' && b=='P' && t=='C')) {
		sum1 = 2*CR + (PR - PR*10/100);
	} else if((m=='C' && b=='C' && t=='H') || (m=='H' && b=='C' && t=='C') || (m=='C' && b=='H' && t=='C')) {
		sum1 = 2*CR -(2*CR*10/100) + HR;
	} else if((m=='C' && b=='H' && t=='P')  || (m=='C' && b=='P' && t=='H') || (m=='H' && b=='C' && t=='P') || (m=='H' && b=='P' && t=='C') || (m=='P' && b=='C' && t=='H')  || (m=='P' && b=='H' && t=='C')) {
		sum1= CR+ HR + (PR - PR*10/100);
	}

	if((rest==0) && (sum1<=sum)) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", sum1);
	}
	return 0;
}