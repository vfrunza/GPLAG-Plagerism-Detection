#include <stdio.h>
#include <stdlib.h>

#define restoran_pizza 6.80
#define restoran_hamburger 3.30
#define restoran_cevapi 5.00

#define fastfood_pizza 8.00
#define fastfood_hamburger 3.00
#define fastfood_cevapi 3.90

#define bistro_pizza 5.30
#define bistro_hamburger 5.00
#define bistro_cevapi 6.00

int main() {
	char jelo_tarik, jelo_bojan, jelo_mirza, novi_red;
	double cijena_restoran = 0.0, cijena_fastfood = 0.0, cijena_bistro = 0.0;
	double popust_pizza = 0.0, popust_hamburger = 0.0, popust_cevapi = 0.0, naj_popust = 0.0;
	double restoran_sa_popustom = 0.0;
	
	/* Unos */
	
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &jelo_tarik);
	scanf ("%c", &novi_red);
	
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &jelo_bojan);
	scanf ("%c", &novi_red);
	
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &jelo_mirza);
	scanf ("%c", &novi_red);
	
	/* Obracun cijena. (Uporedo cemo racunati i poopust i na kraju najveci popust oduzeti od cijene) */
	/* Dodavanje cijene za Tarika */
	
	if (jelo_tarik == 'P') {
		cijena_restoran += restoran_pizza;
		cijena_fastfood += fastfood_pizza;
		cijena_bistro += bistro_pizza;
		
		popust_pizza += restoran_pizza / 10;
	}
	else if (jelo_tarik == 'H') {
		cijena_restoran += restoran_hamburger;
		cijena_fastfood += fastfood_hamburger;
		cijena_bistro += bistro_hamburger;
		
		popust_hamburger += restoran_hamburger / 10;
	}
	else if (jelo_tarik == 'C') {
		cijena_restoran += restoran_cevapi;
		cijena_fastfood += fastfood_cevapi;
		cijena_bistro += bistro_cevapi;
		
		popust_cevapi += restoran_cevapi / 10;
		
	}
	
	/* Dodavanje cijene za Bojana */ 
	
	if (jelo_bojan == 'P') {
		cijena_restoran += restoran_pizza;
		cijena_fastfood += fastfood_pizza;
		cijena_bistro += bistro_pizza;
		
		popust_pizza += restoran_pizza / 10;
		
	}
	else if (jelo_bojan == 'H') {
		cijena_restoran += restoran_hamburger;
		cijena_fastfood += fastfood_hamburger;
		cijena_bistro += bistro_hamburger;
		
		popust_hamburger += restoran_hamburger / 10;
	}
	else if (jelo_bojan == 'C') {
		cijena_restoran += restoran_cevapi;
		cijena_fastfood += fastfood_cevapi;
		cijena_bistro += bistro_cevapi;
		
		popust_cevapi += restoran_cevapi / 10;
	}
	
	/* Dodavanje cijene za MIrzu */
	
	if (jelo_mirza == 'P') {
		cijena_restoran += restoran_pizza;
		cijena_fastfood += fastfood_pizza;
		cijena_bistro += bistro_pizza;
		
		popust_pizza += restoran_pizza / 10;
	}
	else if (jelo_mirza == 'H') {
		cijena_restoran += restoran_hamburger;
		cijena_fastfood += fastfood_hamburger;
		cijena_bistro += bistro_hamburger;
		
		popust_hamburger += restoran_hamburger / 10;
	}
	else if (jelo_mirza == 'C') {
		cijena_restoran += restoran_cevapi;
		cijena_fastfood += fastfood_cevapi;
		cijena_bistro += bistro_cevapi;
		
		popust_cevapi += restoran_cevapi / 10;
		
	}
	
	/* Trazenje najveceg popusta koji cemo oduzeti od cijene restorana */
	
	if ((popust_pizza > popust_hamburger) && (popust_pizza > popust_cevapi))
		naj_popust = popust_pizza;
	else if ((popust_hamburger > popust_pizza) && (popust_hamburger > popust_cevapi))
		naj_popust = popust_hamburger;
	else if ((popust_cevapi > popust_pizza) && (popust_cevapi > popust_hamburger))
		naj_popust = popust_cevapi;
		
	/* Racunanje cijene restorana sa popustom */
	
	restoran_sa_popustom = cijena_restoran - naj_popust;
	
	/*Trazenje najbolje cijene */
	
	if ((cijena_restoran < cijena_fastfood) && (cijena_restoran < cijena_bistro)) {
	/* Ako je najjeftiniji i bez popusta ili nije najjeftiniji sa popustom, ne treba ispisivati nista */
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", cijena_restoran);
	}
	else if ((cijena_fastfood < cijena_restoran) && (cijena_fastfood < cijena_bistro)) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena_fastfood);
			if (restoran_sa_popustom < cijena_fastfood)
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran_sa_popustom);
	}
	else if ((cijena_bistro < cijena_restoran) && (cijena_bistro < cijena_fastfood)) {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena_bistro);
			if (restoran_sa_popustom < cijena_bistro)
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran_sa_popustom);
	}
	
		
		
	return 0;
}
