#include <stdio.h>

int main() {
	char bojan,tarik,mirza;
	float p1,p2,p3,c1,c2,c3,h1,h2,h3;
	float popust_p,popust_c,popust_h;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	printf("Unesite jelo za Bojana: ");
	scanf(" %c",&bojan);
	printf("Unesite jelo za Mirzu: ");
	scanf(" %c",&mirza);
	p1=6.80; p2=8.00; p3=5.30; popust_p=6.12;
	h1=3.30; h2=3.00; h3=5.00; popust_h=2.97;
	c1=5.00; c2=3.90; c3=6.00; popust_c=4.50;
	if(bojan=='H' && tarik=='H' && mirza=='H')
	{
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",3*h2);
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",3*popust_h);
	}
	else if(bojan=='P' && tarik=='P' && mirza=='P')
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",3*p3);
	}
	else if(bojan=='P' && tarik=='H' && mirza=='P')
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",h3+2*p3);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",h1+2*popust_p);
	}
	else if(tarik=='H' && bojan=='H' && mirza=='P')
	{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",2*h1+p1);
	}
	else if(tarik=='C' && bojan=='H' && mirza=='P')
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",h2+p2+c2);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",popust_p+h1+c1);
	}
	else if(tarik=='C' && bojan=='P' && mirza=='C')
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",2*c2+p2);
	}
	else if(tarik=='P' && bojan=='P' && mirza=='C')
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",2*p3+c3);
	}
	else if(tarik=='H' && bojan=='C' && mirza=='C')
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",h2+2*c2);
	}
	else if(tarik=='C' && bojan=='H' && mirza=='H')
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",c2+2*h2);
	}
	else if(tarik=='C' && bojan=='C' && mirza=='C')
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",3*c2);
	}
	return 0;
	
}
