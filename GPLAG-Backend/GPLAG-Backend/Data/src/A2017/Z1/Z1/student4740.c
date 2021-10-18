#include <stdio.h>
#define pr 6.80
#define pff 8.00
#define pb 5.30
#define hr 3.30
#define hff 3.000
#define hb 5.00
#define cr 5.00
#define cff 3.90
#define cb 6.00

int main() {
	char jelo1, jelo2, jelo3, novi_red;
	double rest=0, ff=0, bist=0;
	
	/* unos jela */
printf("Unesite jelo za Tarika: ");
	scanf("%c", &jelo1);
	scanf("%c", &novi_red);
printf ("Unesite jelo za Bojana: ");
   	scanf("%c", &jelo2);
	scanf("%c", &novi_red);
printf ("Unesite jelo za Mirzu: ");
   	scanf("%c", &jelo3);
	scanf("%c", &novi_red);
	
	/* racunanje ukupnog racuna za sve restorane */
switch (jelo1) {
	case 'P': 
	rest=rest+pr; ff=ff+pff; bist=bist+pb;
	break;
	case 'H':
	rest=rest+hr; ff=ff+hff; bist=bist+hb;
	break;
	case 'C':
	rest=rest+cr; ff=ff+cff; bist=bist+cb;
	break;
}
	switch (jelo2) {
	case 'P': 
	rest=rest+pr; ff=ff+pff; bist=bist+pb;
	break;
	case 'H':
	rest=rest+hr; ff=ff+hff; bist=bist+hb;
	break;
	case 'C':
	rest=rest+cr; ff=ff+cff; bist=bist+cb;
	break;
}
switch (jelo3) {
	case 'P': 
	rest=rest+pr; ff=ff+pff; bist=bist+pb;
	break;
	case 'H':
	rest=rest+hr; ff=ff+hff; bist=bist+hb;
	break;
	case 'C':
	rest=rest+cr; ff=ff+cff; bist=bist+cb;
	break;
}

/* redanje po velicini, racunanje popusta i ispis najmanjeg racuna */
	if (ff<rest && ff<bist) printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", ff);
	if (bist<rest && bist<ff) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bist);
		if (rest<ff && rest<bist) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", rest);
	else {
		if (jelo1=='P' && jelo2=='P' && jelo3=='P') rest=rest-3*0.68;
		else if (jelo1=='C' && jelo2=='C' && jelo3=='C') rest=rest-3*0.5;
		else if ((jelo1=='P' && jelo2=='P') || (jelo2=='P' && jelo3=='P') || (jelo1=='P' && jelo3=='P')) rest=rest-2*0.68;
		else if ((jelo1=='C' && jelo2=='C') || (jelo2=='C' && jelo3=='C') || (jelo1=='C' && jelo3=='C')) rest=rest-2*0.5;
		else if (jelo1=='H' && jelo2=='H' && jelo3=='H') rest=rest-3*0.33; 
		else if ((jelo1=='H' && jelo2=='H') || (jelo2=='H' && jelo3=='H') || (jelo1=='H' && jelo3=='H')) rest=rest-2*0.33;
		else if (jelo1=='P' || jelo2=='P' || jelo3=='P') rest=rest-0.68;
		else if (jelo1=='C' || jelo2=='C' || jelo3=='C') rest=rest-0.5;
		else if (jelo1=='H' || jelo2=='H' || jelo3=='H') rest=rest-0.33;
		
		if (rest<ff && rest<bist) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",rest);
		}
	return 0;
}
