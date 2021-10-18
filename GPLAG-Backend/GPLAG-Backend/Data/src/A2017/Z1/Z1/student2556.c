#include <stdio.h>
int main() {
	char tarik, bojan, mirza, enter;
	float cijena1=6.80, cijena2=8.00, cijena3=5.30, cijena4=3.30, cijena5=3.00, cijena6=5.00, cijena7=5.00, cijena8=3.90, cijena9=6.00, cijena=0, popust=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &enter);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &enter);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	if(tarik=='H' && mirza=='H' && bojan=='H')
	{
		cijena = cijena5 + cijena5 + cijena5;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena);
		popust = (cijena4*3) - (cijena4*3)/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	if(tarik=='C' && mirza=='C' && bojan=='C')
	{
		cijena = cijena8 + cijena8 + cijena8;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena);
		popust = cijena7*3 - (cijena7*3)/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	if(tarik=='P' && mirza=='P' && bojan=='P')
	{
		cijena = cijena3 + cijena3 + cijena3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena );
		popust = cijena1*3 - cijena1*3/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	if(tarik=='C' && mirza=='C' && bojan=='H' || tarik=='C' && mirza=='H' && bojan=='C' || tarik=='H' && mirza=='C' && bojan=='C')
	{
		cijena = cijena8 + cijena8 + cijena5;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena);
		popust = cijena7*2 + cijena3 - (cijena7*2)/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	if(tarik=='C' && mirza=='P' && bojan=='P' || tarik=='P' && mirza=='P' && bojan=='C' || tarik=='P' && mirza=='C' && bojan=='P')
	{
		cijena = cijena9 + cijena3 + cijena3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena);
		popust = cijena1*2 + cijena7 - (cijena1*2)/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	if(tarik=='C' && mirza=='H' && bojan=='H' || tarik=='H' && mirza=='H' && bojan=='C' || tarik=='H' && mirza=='C' && bojan=='H')
	{
		cijena = cijena8 + cijena5 + cijena5;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena);	
		popust = cijena4*2 + cijena7 - (cijena7*2)/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	if(tarik=='P' && mirza=='P' && bojan=='H' || tarik=='P' && mirza=='H' && bojan=='P' || tarik=='H' && mirza=='P' && bojan=='P')
	{
		cijena = cijena3 + cijena3 + cijena6;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijena);	
		popust = cijena1*2 + cijena4 - (cijena1*2)/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	if(tarik=='P' && mirza=='H' && bojan=='H' || tarik=='H' && mirza=='P' && bojan=='H' || tarik=='H' && mirza=='H' && bojan=='P')
	{
		cijena = cijena1 + cijena4 + cijena4;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijena);
		popust = cijena1 + cijena4*2 - (cijena1)/10;
	}
	if(tarik=='P' && mirza=='C' && bojan=='C' || tarik=='C' && mirza=='P' && bojan=='C' || tarik=='C' && mirza=='C' && bojan=='P')
	{
		cijena = cijena2 + cijena8 + cijena8;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena);
		popust = cijena1 + cijena7*2 - (cijena1)/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	if(tarik=='C' && mirza=='P' && bojan=='H' || tarik=='C' && mirza=='H' && bojan=='P' || tarik=='P' && mirza=='C' && bojan=='H' || tarik=='P' && mirza=='H' && bojan=='C' || tarik=='H' && mirza=='P' && bojan=='C' || tarik=='H' && mirza=='C' && bojan=='P')
	{
		cijena = cijena2 + cijena5 + cijena8;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijena);
		popust = cijena1 + cijena7 + cijena4 - (cijena1)/10;
		if(popust<cijena)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	return 0;
}