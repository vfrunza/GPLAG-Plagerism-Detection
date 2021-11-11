#include <stdio.h>

int main()
{
	char T, B, M, gutac; /* T-Tarik; B-Bojan; M-Mirza */
	float restoran, restoran_popust, fast_food, bistro;
	int hamburger=0, pizza=0, cevapi=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &gutac);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &gutac);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c", &gutac);
	
	if (T == 'H')
	{
		hamburger++;
	}
	else if (T == 'P')
	{
		pizza++;
	}
	else if (T == 'C')
	{
		cevapi++;
	}
	
	if (B == 'H')
	{
		hamburger++;
	}
	else if (B == 'P')
	{
		pizza++;
	}
	else if (B == 'C')
	{
		cevapi++;
	}
	
	if (M == 'H')
	{
		hamburger++;
	}
	else if (M == 'P')
	{
		pizza++;
	}
	else if (M == 'C')
	{
		cevapi++;
	}
	
	restoran = hamburger*3.30 + pizza*6.80 + cevapi*5.00;
	fast_food = hamburger*3.00 + pizza*8.00 + cevapi*3.90;
	bistro = hamburger*5.00 + pizza*5.30 + cevapi*6.00;
	
	if (pizza>=1 && pizza<=3)
	{
		restoran_popust = pizza*6.80 - (pizza*6.80*10)/100 +hamburger*3.30 + cevapi*5.00;
	}
	else if (cevapi>=1 && cevapi<=3)
	{
		restoran_popust = cevapi*5.50 - (cevapi*5.50*10)/100 + hamburger*3.30;
	}
	else if (hamburger>=1 && hamburger<=3)
	{
		restoran_popust = hamburger*3.30 - (hamburger*3.30*10)/100;
	}
	
	if (restoran<fast_food && restoran<bistro)
	{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	}
	else if (fast_food<restoran && fast_food<bistro)
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", fast_food);
		if (restoran_popust<fast_food)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran_popust);
		}
	}
	else if (bistro<restoran && bistro<fast_food)
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", bistro);
		if (restoran_popust<bistro)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran_popust);
		}
	}
	
	return 0;
}