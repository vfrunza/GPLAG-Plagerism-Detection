#include <stdio.h>
#define PR 6.8
#define PF 8.0
#define PB 5.3
#define HR 3.3
#define HF 3.0
#define HB 5.0
#define CR 5.0
#define CF 3.9
#define CB 6.0

int main() {
	char t, b, m, novi_red;
	double cijenar, cijenaf, cijenab;
	double popustp, popusth, popustc, popust;
	int brojiP=0, brojiH=0, brojiC=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&novi_red);
	
	if (t == 'P') {
		brojiP++;
	}
	else if (t == 'H') {
		brojiH++;
	}
	else {
		brojiC++;
	}
	
	if (b == 'P') {
		brojiP++;
	}
	else if (b == 'H') {
		brojiH++;
	}
	else {
		brojiC++;
	}
	
	if (m == 'P') {
		brojiP++;
	}
	else if (m == 'H') {
		brojiH++;
	}
	else {
		brojiC++;
	}
	
	cijenar = brojiP*PR + brojiH*HR + brojiC*CR;
	cijenaf = brojiP*PF + brojiH*HF + brojiC*CF;
	cijenab = brojiP*PB + brojiH*HB + brojiC*CB;
	
	popustp = brojiP*PR*(9./10) + brojiH*HR + brojiC*CR;
	popusth = brojiP*PR + brojiH*HR*(9./10) + brojiC*CR;
	popustc = brojiP*PR + brojiH*HR + brojiC*CR*(9./10);
	
	if (popustp < popusth && popustp < popustc)
		popust = popustp;
	else if (popusth < popustp && popusth < popustc)
		popust = popusth;
	else 
		popust = popustc;
	
	if (cijenar < cijenaf && cijenar < cijenab)
	{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", cijenar);
	}
	else if (cijenaf < cijenar && cijenaf < cijenab)
	{
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaf);
		
		if (popust < cijenaf) {
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", popust);
		}
	}
	else 
	{
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenab);
		
		if (popust < cijenab) {
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", popust);
		}
	}
	
	

	return 0;
}
