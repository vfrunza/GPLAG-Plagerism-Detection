#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	char tarik, bojan, mirza, novi_red;
	float restoran, fast_food, bistro, procenat = 0.1, restoran1, restoran2, restoran3;
	int pizza=0, hamburger=0, cevapi=0;
	
	printf ("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf ("%c", &novi_red);
	if (tarik == 'P') {
	    pizza++;
	} else if (tarik == 'H') {
	    hamburger++;
	} else cevapi++;
	
	printf ("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf ("%c", &novi_red);
	if (bojan == 'P') {
	    pizza++;
	} else if (bojan == 'H') {
	    hamburger++;
	} else cevapi++;
	
	printf ("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf ("%c", &novi_red);
	if (mirza == 'P') {
	    pizza++;
	} else if (mirza == 'H') {
	    hamburger++;
	} else cevapi++;
	
	
    /*racunanje iznosa rucka u restoranu*/
	restoran = pizza*6.80 + hamburger*3.30 + cevapi*5.00;
	
    /*racunanje iznosa rucka u fast food*/
	fast_food = pizza*8.00 + hamburger*3.00 + cevapi*3.90;
	
	/*racunanje iznosa rucka u bistro*/
	 bistro = pizza*5.30 + hamburger*5.00 + cevapi*6.00;

    
   
    if (restoran < fast_food && restoran < bistro) {
        printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
    } else if (fast_food < restoran && fast_food < bistro) {
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", fast_food);
        
        if (fabs(procenat - 0.1)< EPSILON) {
		
				restoran1 = pizza*(6.80 - 6.80*procenat) + hamburger*3.30 + cevapi*5.00;
				restoran2 = pizza*6.80 + hamburger*(3.30 - 3.30*procenat) + cevapi*5.00;
				restoran3 = pizza*6.80 + hamburger*3.30 + cevapi*(5.00 - 5.00*procenat);
				
				if (restoran1 < fast_food || restoran2 < fast_food || restoran3 < fast_food) {
					if (restoran1 < restoran2 && restoran1 < restoran3) {
						printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran1);
					} else if (restoran2 < restoran1 && restoran2 < restoran3) {
						printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran2);
					} else printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran3);
					
				}
			
		}
		
	} else {
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", bistro);
        
        if (fabs(procenat - 0.1)< EPSILON) {
			restoran1 = pizza*(6.80 - 6.80*procenat) + hamburger*3.30 + cevapi*5.00;
				restoran2 = pizza*6.80 + hamburger*(3.30 - 3.30*procenat) + cevapi*5.00;
				restoran3 = pizza*6.80 + hamburger*3.30 + cevapi*(5.00 - 5.00*procenat);
				
				if (restoran1 < bistro || restoran2 < bistro || restoran3 < bistro) {
					if (restoran1 < restoran2 && restoran1 < restoran3) {
						printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran1);
					} else if (restoran2 < restoran1 && restoran2 < restoran3) {
						printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran2);
					} else printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran3);
					
				}
			
		}
    }
	   
	    
	
	return 0;
}
