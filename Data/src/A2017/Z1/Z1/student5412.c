#include <stdio.h>
#define hamburger1  3.30
#define hamburger2  3.00
#define hamburger3  5.00
#define pizza1  6.80
#define pizza2  8.00
#define pizza3  5.30

#define cevapi  5.00
#define cevapi2  3.90
#define cevapi3  6.00

int main() 
{
	char T, B, M, novi_red;
	double popust1, popust2, popust3, ukupna1, ukupna2, ukupna3, najjeftinija1, najjeftinija2, najjeftinija3, popust, najjeftinija;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &T);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &B);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &M);
	scanf ("%c", &novi_red);
	
	
	if (T == 'H' && B == 'H' && M == 'H') 
	{
		ukupna1 = hamburger1 + hamburger1 + hamburger1; 
		ukupna2 = hamburger2 + hamburger2 + hamburger2;
		ukupna3 = hamburger3 + hamburger3 + hamburger3;
		popust1 = (0.1 * hamburger1) * 3;
	}
	else if (T == 'P' && B == 'P' && M == 'P')
	{
		ukupna1 = pizza1 + pizza1 + pizza1;
		ukupna2 = pizza2 + pizza2 + pizza2;
		ukupna3 = pizza3 + pizza3 + pizza3;
		popust2 = (0.1 * pizza1) * 3;
	}
	else if (T == 'C' && B == 'C' && M == 'C')
	{
		ukupna1 = cevapi + cevapi + cevapi;
		ukupna2 = cevapi2 + cevapi2 + cevapi2;
		ukupna3 = cevapi3 + cevapi3 + cevapi3;
		popust3 = (0.1 * cevapi) * 3;
	}
	else if (T == 'H' && B == 'P' && M == 'P')
	{
		ukupna1 = hamburger1 + pizza1 + pizza1; 
		ukupna2 = hamburger2 + pizza2 + pizza2;
		ukupna3 = hamburger3 + pizza3 + pizza3;
		popust = 0.1 * hamburger1 + 0.1 * pizza1 * 2;
	}
	else if (T == 'H' && B == 'H' && M == 'P')
	{
		ukupna1 = hamburger1 + hamburger1 + pizza1;
		ukupna2 = hamburger2 + hamburger2 + pizza2;
		ukupna3 = hamburger3 + hamburger3 + pizza3;
		//popust = 0.1 * hamburger1 * 2 + 0.1 * pizza1;
	}
	else if (T == 'C' && B == 'H' && M == 'P')
	{
		ukupna1 = cevapi + hamburger1 + pizza1; 
		ukupna2 = cevapi2 + hamburger2 + pizza2;
		ukupna3 = cevapi3 + hamburger3 + pizza3;
		//popust = 0.1 * hamburger1 + 0.1 * pizza1 + 0.1 * cevapi;
	}
	else if (T == 'C' && B == 'P' && M == 'C')
	{
		ukupna1 = cevapi + pizza1 + cevapi;
		ukupna2 = cevapi2 + pizza2 + cevapi2;
		ukupna3 = cevapi3 + pizza3 + cevapi3;
		//popust = 0.1 * cevapi * 2 + 0.1 * pizza1;
	}
	else if (T == 'P' && B == 'P' && M == 'C')
	{
		ukupna1 = pizza1 + pizza1 + cevapi;
		ukupna2 = pizza2 + pizza2 + cevapi2;
		ukupna3 = pizza3 + pizza3 + cevapi3;
		//popust = 0.1 * cevapi + 0.1 * pizza1 * 2;
	}
	else if (T == 'H' && B == 'C' && M == 'C')
	{
		ukupna1 = hamburger1 + cevapi + cevapi;
		ukupna2 = hamburger2 + cevapi2 + cevapi2;
		ukupna3 = hamburger3 + cevapi3 + cevapi3;
		//popust = 0.1 * hamburger1 + 0.1 * cevapi * 2;
	}
	else if (T == 'C' && B == 'H' && M == 'H')
	{
		ukupna1 = cevapi + hamburger1 + hamburger1;
		ukupna2 = cevapi2 + hamburger2 + hamburger2;
		ukupna3 = cevapi3 + hamburger3 + hamburger3;
		//popust = 0.1 * hamburger1 * 2 + 0.1 * cevapi;
	}
	else if (T == 'H' && B == 'P' && M == 'P')
	{
		ukupna1 = hamburger1 + pizza1 + pizza1;
		ukupna2 = hamburger2 + pizza2 + pizza2;
		ukupna3 = hamburger3 + pizza3 + pizza3;
		//popust = 0.1 * hamburger1 + 0.1 * pizza1 * 2;
	}
	else if (T == 'H' && B == 'H' && M == 'P')
	{
		ukupna1 = hamburger1 + hamburger1 + pizza1;
		ukupna2 = hamburger2 + hamburger2 + pizza2;
		ukupna3 = hamburger3 + hamburger3 + pizza3;
		//popust = 0.1 * hamburger1 * 2 + 0.1 * pizza1;
	}
	else if (T == 'P' && B == 'P' && M == 'H')
	{
		ukupna1 = pizza1 + pizza1 + hamburger1;
		ukupna2 = pizza2 + pizza2 + hamburger2;
		ukupna3 = pizza3 + pizza3 + hamburger3;
		//popust = 0.1 * hamburger1 + 0.1 * pizza1 * 2;
	}
	else if (T == 'P' && B == 'H' && M == 'H')
	{
		ukupna1 = pizza1 + hamburger1 + hamburger1;
		ukupna2 = pizza2 + hamburger2 + hamburger2;
		ukupna3 = pizza3 + hamburger3 + hamburger3;
		//popust = 0.1 * hamburger1 * 2 + 0.1 * pizza1;
	}
	else if (T == 'P' && B == 'C' && M == 'C')
	{
		ukupna1 = pizza1 + cevapi + cevapi;
		ukupna2 = pizza2 + cevapi2 + cevapi2;
		ukupna3 = pizza3 + cevapi3 + cevapi3;
	//	popust = 0.1 * cevapi * 2 + 0.1 * pizza1;
	}
	else if (T == 'C' && B == 'C' && M == 'H')
	{
		ukupna1 = cevapi + cevapi + hamburger1;
		ukupna2 = cevapi2 + cevapi2 + hamburger2;
		ukupna3 = cevapi3 + cevapi3 + hamburger3;
		//popust = 0.1 * hamburger1 + 0.1 * cevapi * 2;
	}
	else if (T == 'C' && B == 'C' && M == 'P')
	{
		ukupna1 = cevapi + cevapi + pizza1;
		ukupna2 = cevapi2 + cevapi2 + pizza2;
		ukupna3 = cevapi3 + cevapi3 + pizza3;
		//popust = 0.1 * cevapi * 2 + 0.1 * pizza1;
	}
	else if (T == 'C' && B == 'P' && M == 'P')
	{
		ukupna1 = cevapi + pizza1 + pizza1;
		ukupna2 = cevapi2 + pizza2 + pizza2;
		ukupna3 = cevapi3 + pizza3 + pizza3;
		//popust = 0.1 * cevapi + 0.1 * pizza1 * 2;
	}
	else if (T == 'H' && B == 'P' && M == 'H')
	{
		ukupna1 = hamburger1 + pizza1 + hamburger1;
		ukupna2 = hamburger2 + pizza2 + hamburger2;
		ukupna3 = hamburger3 + pizza3 + hamburger3;
		//popust = 0.1 * hamburger1 * 2 + 0.1 * pizza1;
	}
	else if (T == 'H' && B == 'C' && M == 'H')
	{
		ukupna1 = hamburger1 + cevapi + hamburger1;
		ukupna2 = hamburger2 + cevapi2 + hamburger2;
		ukupna3 = hamburger3 + cevapi3 + hamburger3;
		//popust = 0.1 * hamburger1 * 2 + 0.1 * cevapi;
	}
	else if (T == 'P' && B == 'C' && M == 'P')
	{
		ukupna1 = pizza1 + cevapi + pizza1;
		ukupna2 = pizza2 + cevapi2 + pizza2;
		ukupna3 = pizza3 + cevapi3 + pizza3;
		//popust = 0.1 * cevapi + 0.1 * pizza1 * 2;
	}
	else if (T == 'P' && B == 'H' && M == 'P')
	{
		ukupna1 = pizza1 + hamburger1 + pizza1;
		ukupna2 = pizza2 + hamburger2 + pizza2;
		ukupna3 = pizza3 + hamburger3 + pizza3;
		//popust = 0.1 * hamburger1 + 0.1 * pizza1 * 2;
	}
	else if (T == 'C' && B == 'H' && M == 'C')
	{
		ukupna1 = cevapi + hamburger1 + cevapi;
		ukupna2 = cevapi2 + hamburger2 + cevapi2;
		ukupna3 = cevapi3 + hamburger3 + cevapi3;
		//popust = 0.1 * hamburger1 + 0.1 * cevapi * 2;
	}
	else if (T == 'H' && B == 'C' && M == 'P')
	{
		ukupna1 = hamburger1 + cevapi + pizza1;
		ukupna2 = hamburger2 + cevapi2 + pizza2;
		ukupna3 = hamburger3 + cevapi3 + pizza3;
		//popust = 0.1 * hamburger1 + 0.1 * pizza1 + 0.1 * cevapi;
	}
	else if (T == 'P' && B == 'H' && M == 'C')
	{
		ukupna1 = pizza1 + hamburger1 + cevapi;
		ukupna2 = pizza2 + hamburger1 + cevapi2;
		ukupna3 = pizza3 + hamburger3 + cevapi3;
		//popust = 0.1 * hamburger1 + 0.1 * pizza1 + 0.1 * cevapi;
	}
	else if (T == 'P' && B == 'C' && M == 'H')
	{
		ukupna1 = pizza1 + cevapi + hamburger1;
		ukupna2 = pizza2 + cevapi2 + hamburger2;
		ukupna3 = pizza3 + cevapi3 + hamburger3;
		//popust = 0.1 * hamburger1 + 0.1 * pizza1 + 0.1 cevapi;
	}
	//najjeftinija1 = ukupna1 - popust1;
	//najjeftinija2 = ukupna1 - popust2;
	//najjeftinija3 = ukupna1 - popust3;
	//najjeftinija = ukupna1 - popust;
	
	if (ukupna1 < ukupna2 && ukupna1 < ukupna3) 
	{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\"");
		printf (" (%.2f KM).\n", ukupna1);
	}
	else if (ukupna2 < ukupna3 && ukupna2 < ukupna1)
	{
		printf ("Najjeftiniji je Fast-food \"Trovac\"");
		printf (" (%.2f KM).\n", ukupna2);
		
		if (ukupna2 > (ukupna1 - popust1)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", (ukupna1 - popust1)); 
		else if (ukupna2 > (ukupna1 - popust2)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", (ukupna1 - popust2));
		else if (ukupna2 > (ukupna1 - popust3)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", (ukupna1 - popust3));
		//else if (ukupna2 > najjeftinija) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", najjeftinija);
		//else return 0;
		//if (popust1 < ukupna2) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", ukupna1 - popust1); 
		// else if (popust2 < ukupna2) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", ukupna1 - popust2);
		// else if (popust3 < ukupna2) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", ukupna1 - popust3);
		
	}
	else if (ukupna3 < ukupna1 && ukupna3 < ukupna2)
	{
		printf ("Najjeftiniji je Bistro \"Lorelei\"");
		printf (" (%.2f KM).\n", ukupna3);
		
		if (ukupna3 > (ukupna1 - popust1)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", (ukupna1 - popust1)); 
		else if (ukupna3 > (ukupna1 - popust2)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", (ukupna1 - popust2));
		else if (ukupna3 > (ukupna1 - popust3)) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", (ukupna1 - popust3));
		//else if (ukupna3 > najjeftinija) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", najjeftinija);
		//else return 0;
		// if (popust1 < ukupna3) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", ukupna1 - popust1); 
		// else if (popust2 < ukupna3) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", ukupna1 - popust2);
	 //   else if (popust3 < ukupna3) printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", ukupna1 - popust3);
		// else if (ukupna3 > popust1 || ukupna2 > popust2 || ukupna3 > popust3) return 0;
	}
	
	return 0;
}