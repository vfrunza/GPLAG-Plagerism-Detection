#include <stdio.h>

int main() {
	char tarik, novi_red, bojan, mirza; 
	double p1, p2, p3, h1, h2, h3, c1, c2, c3, racun, kkk;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	p1=6.8; p2=8; p3=5.3;
	h1=3.3; h2=3; h3=5;
	c1=5; c2=3.9; c3=6;
	if (tarik=='C' && bojan=='C' && mirza=='C') {
	    racun=3*c2;
	    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", racun);
	    kkk=3*c1-(3*c1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}
	else if (tarik=='H' && bojan=='H' && mirza=='H') {
	    racun=3*h2;
	    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", racun);
	    kkk=3*h1-(3*h1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}
	else if (tarik=='P' && bojan=='P' && mirza=='P') {
	    racun=3*p3;
	    printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", racun);
	    kkk=3*p1-(3*p1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}
	else if (tarik=='H' && bojan=='P' && mirza =='P') {
	    racun=h3+2*p3;
	    printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", racun);
	    kkk=(h1+2*p1)-(2*p1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}
    else if (tarik=='H' && bojan=='H' && mirza =='P') {
	    racun=2*h1+p1;
	    printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", racun);
	    
	}
		else if (tarik=='C' && bojan=='H' && mirza =='P') {
	    racun=h2+p2+c2;
	    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", racun);
	    kkk=h1+c1+p1-(p1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}
	else if (tarik=='C' && bojan=='P' && mirza =='C') {
	    racun=p2+2*c2;
	    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", racun);
	    kkk=p1+2*c1-(2*c1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}
	else if (tarik=='P' && bojan=='P' && mirza =='C') {
	    racun=2*p3+c3;
	    printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", racun);
	    kkk=2*p1+c1-(2*p1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}
	else if (tarik=='H' && bojan=='C' && mirza =='C') {
	    racun=h2+2*c2;
	    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", racun);
	    kkk=h1+2*c1-(2*c1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}
	else if (tarik=='C' && bojan=='H' && mirza =='H') {
	    racun=2*h2+c2;
	    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", racun);
	    kkk=2*h1+c1-(2*h1*0.1);
	    if (kkk<racun) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk);
	}

	
	
	
	return 0;
}
