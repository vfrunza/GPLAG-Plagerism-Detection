#include <stdio.h>

int main() {
	
	char tarik, bojan, mirza, novi_red;
	
	double pizza_1 = 6.8;
	double pizza_2 = 8;
	double pizza_3 = 5.3;
	
	double hamburger_1 = 3.3;
	double hamburger_2 = 3;
	double hamburger_3 = 5;
	
	double cevapi_1 = 5;
	double cevapi_2 = 3.9;
	double cevapi_3 = 6;
	
	double ukupna_cijena = 0;
	
	int odabir_1 = 0;
	int odabir_2 = 0;
	int odabir_3 = 0;
	
	double cijena_tarik = 0;
	double cijena_bojan = 0;
	double cijena_mirza = 0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	
	if (tarik == 'P')															/// Odabir za Tarika.
		{
			odabir_1 = 3;
			cijena_tarik = pizza_3;
		}
	else if (tarik == 'H')
	{
		odabir_1 = 2;
		cijena_tarik = hamburger_2;
	}
	else if (tarik == 'C')
	{
		odabir_1 = 2;
		cijena_tarik = cevapi_2;
	}
	
	
	
	if (bojan == 'P')															/// Odabir za Bojana.
		{
			odabir_2 = 3;
			cijena_bojan = pizza_3;
		}
	else if (bojan == 'H')
	{
		odabir_2 = 2;
		cijena_bojan = hamburger_2;
	}
	else if (bojan == 'C')
	{
		odabir_2 = 2;
		cijena_bojan = cevapi_2;
	}
	
	
	
	if (mirza == 'P')															///Odabir za Mirzu.
		{
			odabir_3 = 3;
			cijena_mirza = pizza_3;
		}
	else if (mirza == 'H')
	{
		odabir_3 = 2;
		cijena_mirza = hamburger_2;
	}
	else if (mirza == 'C')
	{
		odabir_3 = 2;
		cijena_mirza = cevapi_2;
	}
	
	
	char navodnici = '"';
	int odabir_lokala = 0;
	
	int brojac_pizza = 0;
			if (tarik == 'P')
				brojac_pizza++;
			if (bojan == 'P')
				brojac_pizza++;
			if (mirza == 'P')
				brojac_pizza++;
				
			int brojac_hamburger = 0;
			if (tarik == 'H')
				brojac_hamburger++;
			if (bojan == 'H')
				brojac_hamburger++;
			if (mirza == 'H')
				brojac_hamburger++;
				
			int brojac_cevapi = 0;
			if (tarik == 'C')
				brojac_cevapi++;
			if (bojan == 'C')
				brojac_cevapi++;
			if (mirza == 'C')
				brojac_cevapi++;
	
	
	if (odabir_1 == odabir_2 && odabir_2 == odabir_3 && odabir_3 == odabir_1)   /// Svi odabrali isto.
		{
			ukupna_cijena = cijena_tarik + cijena_bojan + cijena_mirza;
			printf("Najjeftiniji je ");
			if (odabir_1 == 1)
				printf ("Restoran %cKod konja i konjusara%c (%.2f KM).\n", navodnici, navodnici, ukupna_cijena);
			else if (odabir_1 == 2)
				printf ("Fast-food %cTrovac%c (%.2f KM).\n", navodnici, navodnici, ukupna_cijena);
			else if (odabir_1 == 3)
				printf ("Bistro %cLorelei%c (%.2f KM).\n", navodnici, navodnici, ukupna_cijena);
		}
	else
		{
				
			if (brojac_pizza == 1 && brojac_hamburger == 1 && brojac_cevapi == 1)
				{
					ukupna_cijena = pizza_2 + hamburger_2 + cevapi_2;
					odabir_lokala = 2;
				}
				
			if (brojac_pizza == 2)
				{
					if (brojac_hamburger == 1)
						ukupna_cijena = 2*pizza_3 + hamburger_3;
					if (brojac_cevapi == 1)
						ukupna_cijena = 2*pizza_3 + cevapi_3;
						
					odabir_lokala = 3;
				}
			
			else if (brojac_hamburger == 2)
				{
					if (brojac_pizza == 1)
						{
							ukupna_cijena = 2*hamburger_1+pizza_1;
							odabir_lokala = 1;
						}
					if (brojac_cevapi == 1)
						{
							ukupna_cijena = 2*hamburger_2+cevapi_2;
							odabir_lokala = 2;
						}
				}
				
			else if (brojac_cevapi == 2)
				{
					if (brojac_pizza == 1)
						ukupna_cijena = 2*cevapi_2+pizza_2;
					if (brojac_hamburger == 1)
						ukupna_cijena = 2*cevapi_2+hamburger_2;
						
					odabir_lokala = 2;
				}
				
			printf("Najjeftiniji je ");
			if (odabir_lokala == 1)
				printf ("Restoran %cKod konja i konjusara%c (%.2f KM).\n", navodnici, navodnici, ukupna_cijena);
			else if (odabir_lokala == 2)
				printf ("Fast-food %cTrovac%c (%.2f KM).\n", navodnici, navodnici, ukupna_cijena);
			else if (odabir_lokala == 3)
				printf ("Bistro %cLorelei%c (%.2f KM).\n", navodnici, navodnici, ukupna_cijena);
		}
	
	
	if (odabir_lokala != 1)														/// Racunanje popusta.
		{
			double popust = 0;
			
			if (brojac_pizza == 3)
				popust = 3*pizza_1*0.9;
			if (brojac_hamburger == 3)
				popust = 3*hamburger_1*0.9;
			if (brojac_cevapi == 3)
				popust = 3*cevapi_1*0.9;
				
			
			if (brojac_pizza == 2)
				{
					popust = 2*pizza_1*0.9;
					if (brojac_hamburger == 1)
						popust += hamburger_1;
					if (brojac_cevapi == 1)
						popust += cevapi_1;
				}
				
			if (brojac_hamburger == 2)
				{
					if (brojac_pizza == 1)
						popust = 2*hamburger_1 + pizza_1*0.9;
					if (brojac_cevapi == 1)
						popust = 2*hamburger_1*0.9+cevapi_1;
				}
				
			if (brojac_cevapi == 2)
				{
					popust = 2*cevapi_1*0.9;
					if (brojac_pizza == 1)
						popust += pizza_1;
					if (brojac_hamburger == 1)
						popust += hamburger_1;
				}
				
				
			if (brojac_pizza == 1 && brojac_hamburger == 1 && brojac_cevapi == 1)
				popust = pizza_1*0.9+hamburger_1+cevapi_1;
			
			
			if (ukupna_cijena > popust)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
			
			
		}
	
	
	
	
	
	
	return 0;
}
