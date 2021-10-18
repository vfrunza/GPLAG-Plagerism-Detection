#include <stdio.h>
#define pr 6.80
#define pff 8.00
#define pb 5.30
#define hr 3.30
#define hff 3.00
#define hb 5.00
#define cr 5.00
#define cff 3.90
#define cb 6.00

int main()
{
	char tarik, bojan, mirza, novired;
	float restoran=0, trovac=0, bistro=0, popust;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novired);

	if (tarik=='P') {
		restoran+=pr;
		trovac+=pff;
		bistro+=pb;
	} else if (tarik=='H') {
		restoran+=hr;
		trovac+=hff;
		bistro+=hb;
	} else if (tarik=='C') {
		restoran+=cr;
		trovac+=cff;
		bistro+=cb;
	}
	if (bojan=='P') {
		restoran+=pr;
		trovac+=pff;
		bistro+=pb;
	} else if (bojan=='H') {
		restoran+=hr;
		trovac+=hff;
		bistro+=hb;
	} else if (bojan=='C') {
		restoran+=cr;
		trovac+=cff;
		bistro+=cb;
	}
	if (mirza=='P') {
		restoran+=pr;
		trovac+=pff;
		bistro+=pb;
	} else if (mirza=='H') {
		restoran+=hr;
		trovac+=hff;
		bistro+=hb;
	} else if (mirza=='C') {
		restoran+=cr;
		trovac+=cff;
		bistro+=cb;
	}
	if (mirza=='H' && tarik=='H' && bojan=='H') popust=restoran-0.1*3*hr;
	else if (mirza=='P' && tarik=='P' && bojan=='P') popust=restoran-0.1*3*pr;
	else if (mirza=='C' && tarik=='C' && bojan=='C') popust=restoran-0.1*3*cr;
	else if (mirza!=bojan && mirza!=tarik && bojan!=tarik) popust=restoran-0.1*pr;
	else if ((mirza=='C' && (tarik=='C' || bojan=='C')) || (bojan=='C' && tarik=='C')) popust=restoran-0.1*2*cr;
	else if ((mirza=='H' && (tarik=='H' || bojan=='H')) || (bojan=='H' && tarik=='H')) popust=restoran-0.1*2*hr;
	else if ((mirza=='P' && (tarik=='P' || bojan=='P')) || (bojan=='P' && tarik=='P')) popust=restoran-0.1*2*pr;

	if (restoran<bistro && restoran<trovac) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (bistro<restoran && bistro<trovac) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
		if (popust<bistro) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	} else if (trovac<restoran && trovac<bistro) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", trovac);
		if (popust<trovac) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
	return 0;
}