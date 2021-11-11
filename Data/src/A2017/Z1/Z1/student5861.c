#include <stdio.h>
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define C1 5.00
#define C2 3.90
#define C3 6.00


int main() {
	
	char tarik, bojan, mirza, novi_red;
	
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	float p_cijena_konjusara=0, p_cijena_trovaca=0, p_cijena_lorelei=0,c_cijena_konjusara=0,c_cijena_trovaca=0,c_cijena_lorelei=0, h_cijena_trovaca=0, h_cijena_konjusara=0, h_cijena_lorelei=0;
	float ukup_cijena_konjusara=0, ukup_cijena_lorelei=0, ukup_cijena_trovaca=0, cijena_sa_popustom=0;
	if(tarik=='H')
	{
		h_cijena_konjusara=h_cijena_konjusara + H1 ;
		h_cijena_trovaca=h_cijena_trovaca + H2;
		h_cijena_lorelei=h_cijena_lorelei + H3;
	}
	if(tarik=='P')
	{
		p_cijena_konjusara=p_cijena_konjusara + P1;
		p_cijena_trovaca=p_cijena_trovaca + P2;
		p_cijena_lorelei=p_cijena_lorelei + P3;
	}
	if(tarik=='C')
	{
		c_cijena_konjusara=c_cijena_konjusara + C1;
		c_cijena_trovaca=c_cijena_trovaca + C2;
		c_cijena_lorelei=c_cijena_lorelei + C3;
	}
	if(bojan=='H')
	{
        h_cijena_konjusara=h_cijena_konjusara + H1;
		h_cijena_trovaca=h_cijena_trovaca + H2;
		h_cijena_lorelei=h_cijena_lorelei + H3;
	}
	if(bojan=='P')
	{
		p_cijena_konjusara=p_cijena_konjusara + P1;
		p_cijena_trovaca=p_cijena_trovaca + P2;
		p_cijena_lorelei=p_cijena_lorelei + P3;
	}
	if(bojan=='C')
	{
		c_cijena_konjusara = c_cijena_konjusara + C1;
		c_cijena_trovaca=c_cijena_trovaca + C2;
		c_cijena_lorelei= c_cijena_lorelei + C3;
	}
 	if(mirza=='H')
	{
		h_cijena_konjusara=h_cijena_konjusara + H1;
		h_cijena_trovaca=h_cijena_trovaca + H2;
		h_cijena_lorelei=h_cijena_lorelei + H3;
	}
	if(mirza=='P')
	{
		p_cijena_konjusara=p_cijena_konjusara + P1;
		p_cijena_trovaca=p_cijena_trovaca + P2;
		p_cijena_lorelei=p_cijena_lorelei + P3;
	}
	if(mirza=='C')
	{
		c_cijena_konjusara=c_cijena_konjusara + C1;
		c_cijena_trovaca=c_cijena_trovaca + C2;
		c_cijena_lorelei=c_cijena_lorelei + C3;
	}
	
	
	ukup_cijena_konjusara = c_cijena_konjusara + h_cijena_konjusara + p_cijena_konjusara;
	ukup_cijena_lorelei=c_cijena_lorelei+p_cijena_lorelei+h_cijena_lorelei;
	ukup_cijena_trovaca=c_cijena_trovaca+p_cijena_trovaca+h_cijena_trovaca;
	
	if((ukup_cijena_konjusara<ukup_cijena_trovaca) && (ukup_cijena_konjusara<ukup_cijena_lorelei))
	{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", ukup_cijena_konjusara);
		return 0 ;
		
	}
	
	if((ukup_cijena_trovaca<ukup_cijena_lorelei) && (ukup_cijena_trovaca<ukup_cijena_konjusara))
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", ukup_cijena_trovaca);
	}
	if((ukup_cijena_lorelei<ukup_cijena_trovaca) && (ukup_cijena_lorelei<ukup_cijena_konjusara))
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", ukup_cijena_lorelei);
	}
	
	
	
	if(tarik=='P' && bojan=='P' && mirza=='P')
	{
		cijena_sa_popustom=p_cijena_konjusara*0.9;
		
		
		if(cijena_sa_popustom<ukup_cijena_lorelei&& cijena_sa_popustom<ukup_cijena_trovaca)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM). \n", cijena_sa_popustom);
		}
	}
	if(tarik=='H' && bojan=='H' && mirza=='H')
	{
		cijena_sa_popustom=h_cijena_konjusara*0.9;
		
		if(cijena_sa_popustom<ukup_cijena_lorelei&& cijena_sa_popustom<ukup_cijena_trovaca)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n", cijena_sa_popustom);
		}
	}
	
	
	if(tarik=='C' && bojan=='C' && mirza=='C')
	{
		cijena_sa_popustom=c_cijena_konjusara*0.9;
		
		if(cijena_sa_popustom<ukup_cijena_lorelei && cijena_sa_popustom<ukup_cijena_trovaca)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n", cijena_sa_popustom);
		}
	}
	
	
	if(tarik=='P' || bojan=='P' || mirza=='P')
	{
		cijena_sa_popustom=p_cijena_konjusara*0.9;
		cijena_sa_popustom=cijena_sa_popustom+c_cijena_konjusara+h_cijena_konjusara;
		
		if(cijena_sa_popustom<ukup_cijena_lorelei&& cijena_sa_popustom<ukup_cijena_trovaca)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM). \n", cijena_sa_popustom);
		}
	}
	return 0;
}
