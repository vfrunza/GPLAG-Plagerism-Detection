#include <stdio.h>


int main() {
	char P,H,C,jelo_za_tarika,jelo_za_bojana,jelo_za_mirzu,novi_red;
	
double restoranP=6.8;
double restoranH=3.30;
double restoranC=5.00;
double fast_foodP=8.00;
double fast_foodH=3.00;
double fast_foodC=3.90;
double bistroP=5.30;
double bistroH=5.00;
double bistroC=6.00;
	double cijena_restorana,cijena_fast_food,cijena_bistro,restoran_sa_popustom;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&jelo_za_tarika);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&jelo_za_bojana);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&jelo_za_mirzu);
	scanf("%c",&novi_red);
	if(jelo_za_tarika == 'P' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = 3 * restoranP;
		cijena_fast_food = 3 * fast_foodP;
		cijena_bistro = 3 * bistroP;
		restoran_sa_popustom = cijena_restorana - ((10 * cijena_restorana) / 100);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'H' && jelo_za_mirzu == 'H')
	{
		cijena_restorana = 3 * restoranH;
		cijena_fast_food = 3 * fast_foodH;
		cijena_bistro = 3 * bistroH;
		restoran_sa_popustom = cijena_restorana - ((10 * cijena_restorana) / 100);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'C'  && jelo_za_bojana == 'C' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = 3 * restoranC;
		cijena_fast_food = 3 * fast_foodC;
		cijena_bistro = 3 * bistroC;
		restoran_sa_popustom = cijena_restorana -((10 * cijena_restorana) / 100);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'P' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'H')
	{
		cijena_restorana = 2 * restoranP + restoranH;
		cijena_fast_food = 2 * fast_foodP + fast_foodH;
		cijena_bistro = 2 * bistroP + bistroH;
		restoran_sa_popustom = cijena_restorana - ((10. / 100) * 2 * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'P' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = 2 * restoranP + restoranC;
		cijena_fast_food = 2 * fast_foodP + fast_foodC;
		cijena_bistro = 2 * bistroP + bistroC;
		restoran_sa_popustom = cijena_restorana - ((10. / 100) * 2 * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
		
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'H' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = 2 * restoranH + restoranP;
		cijena_fast_food = 2 * fast_foodH + fast_foodP;
		cijena_bistro = 2 * bistroH + bistroP;
		restoran_sa_popustom = cijena_restorana - ((10. / 100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'H' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = 2 * restoranH + restoranC;
		cijena_fast_food = 2 * fast_foodH + fast_foodC;
		cijena_bistro = 2 * bistroH + bistroC;
		restoran_sa_popustom = cijena_restorana - ((10. / 100) * restoranC);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'C' && jelo_za_bojana == 'C' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = 2 * restoranC + restoranP;
		cijena_fast_food = 2 * fast_foodC + fast_foodP;
		cijena_bistro = 2 * bistroC + bistroP;
		restoran_sa_popustom = cijena_restorana - ((10. / 100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'C' && jelo_za_bojana == 'C' && jelo_za_mirzu == 'H')
	{
		cijena_restorana = 2 * restoranC + restoranH;
		cijena_fast_food = 2 * fast_foodC + fast_foodH;
		cijena_bistro = 2 * bistroC + bistroH;
		restoran_sa_popustom = cijena_restorana - ((10. / 100) * 2 * restoranC);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'P' && jelo_za_bojana == 'H' && jelo_za_mirzu == 'H')
	{
		cijena_restorana = restoranP + 2 * restoranH;
		cijena_fast_food = fast_foodP + 2 * fast_foodH;
		cijena_bistro = bistroP + 2 * bistroH;
		restoran_sa_popustom = cijena_restorana - ((10./100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'P' && jelo_za_bojana == 'C' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = restoranP + 2 * restoranC;
		cijena_fast_food = fast_foodP + 2 * fast_foodC;
		cijena_bistro = bistroP + 2 * bistroC;
		restoran_sa_popustom = cijena_restorana - ((10./100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
		 
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = restoranH + 2. * restoranP;
		cijena_fast_food = fast_foodH + 2. * fast_foodP;
		cijena_bistro = bistroH + 2. * bistroP;
		restoran_sa_popustom = cijena_restorana -((10./100)* 2*restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'C' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = restoranH + 2 * restoranC;
		cijena_fast_food = fast_foodH + 2 * fast_foodC;
		cijena_bistro = bistroH + 2 * bistroC;
		restoran_sa_popustom = cijena_restorana -((10. / 100) * 2 * restoranC);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'C' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = restoranC + 2 * restoranP;
		cijena_fast_food = fast_foodC + 2 * fast_foodP;
		cijena_bistro = bistroC + 2 * bistroP;
		restoran_sa_popustom = cijena_restorana - ((10. / 100)* 2 * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'C'  && jelo_za_bojana == 'H' && jelo_za_mirzu == 'H')
	{
		cijena_restorana = restoranC + 2 * restoranH;
		cijena_fast_food = fast_foodC + 2 * fast_foodH;
		cijena_bistro = bistroC + 2 * bistroH;
		restoran_sa_popustom =cijena_restorana -((10./ 100) * restoranC);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'P' && jelo_za_bojana == 'H' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = restoranP + restoranH + restoranC;
		cijena_fast_food = fast_foodP + restoranH + restoranC;
		cijena_bistro = bistroP + bistroH + bistroC;
		restoran_sa_popustom = cijena_restorana -((10./100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'P' && jelo_za_bojana == 'C' && jelo_za_mirzu == 'H')
	{
		cijena_restorana = restoranP + restoranC + restoranH;
		cijena_fast_food = fast_foodP + fast_foodC + fast_foodH;
		cijena_bistro = bistroP + bistroC + bistroH;
		restoran_sa_popustom = cijena_restorana - ((10./100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = restoranH + restoranP + restoranC;
		cijena_fast_food = fast_foodH + fast_foodP + fast_foodC;
		cijena_bistro = bistroH + bistroP + bistroC;
		restoran_sa_popustom = cijena_restorana - ((10./ 100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'C' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = restoranH + restoranC + restoranP;
		cijena_fast_food = fast_foodH + fast_foodC + fast_foodP;
		cijena_bistro = bistroH + bistroC + bistroP;
		restoran_sa_popustom = cijena_restorana - ((10./ 100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'C' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'H')
	{
		cijena_restorana = restoranC + restoranP + restoranH;
		cijena_fast_food = fast_foodC + fast_foodP + fast_foodH;
		cijena_bistro = bistroC + bistroP + bistroH;
		restoran_sa_popustom = cijena_restorana - ((10./100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'C' && jelo_za_bojana == 'H' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = restoranC + restoranH + restoranP;
		cijena_fast_food = fast_foodC + fast_foodH + fast_foodP;
		cijena_bistro = bistroC + bistroH + bistroP;
		restoran_sa_popustom = cijena_restorana - ((10./100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'P' && jelo_za_bojana == 'H' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = 2 * restoranP + restoranH;
		cijena_fast_food = 2 * fast_foodP + fast_foodH;
		cijena_bistro = 2 * bistroP + bistroH;
		restoran_sa_popustom = cijena_restorana - ((10./ 100) * 2 * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
		
	}
	else if(jelo_za_tarika == 'P' && jelo_za_bojana == 'C' && jelo_za_mirzu == 'P')
	{
		cijena_restorana = 2 * restoranP + restoranC;
		cijena_fast_food = 2 * fast_foodP + fast_foodC;
		cijena_bistro = 2 * bistroP + bistroC;
		restoran_sa_popustom = cijena_restorana - ((10./ 100) * 2 * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'H')
	{
		
		cijena_restorana = 2 * restoranH + restoranP;
		cijena_fast_food = 2 * fast_foodH + fast_foodP;
		cijena_bistro = 2 * bistroH + bistroP;
		restoran_sa_popustom = cijena_restorana - ((10./100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'H' && jelo_za_bojana == 'C' && jelo_za_mirzu == 'H')
	{
		cijena_restorana = 2 * restoranH + restoranC;
		cijena_fast_food = 2 * fast_foodH + fast_foodC;
		cijena_bistro = 2 * bistroH + bistroC;
		restoran_sa_popustom = cijena_restorana - ((10. / 100) * restoranC);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
		
	}
	else if(jelo_za_tarika == 'C' && jelo_za_bojana == 'P' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = 2 * restoranC + restoranP;
		cijena_fast_food = 2 * fast_foodC + fast_foodP;
		cijena_bistro = 2 * bistroC + bistroP;
		restoran_sa_popustom = cijena_restorana - ((10./100) * restoranP);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	else if(jelo_za_tarika == 'C' && jelo_za_bojana == 'H' && jelo_za_mirzu == 'C')
	{
		cijena_restorana = 2 * restoranC + restoranH;
		cijena_fast_food = 2 * fast_foodC + fast_foodH;
		cijena_bistro = 2 * bistroC + bistroH;
		restoran_sa_popustom = cijena_restorana - ((10. / 100) * 2 * restoranC);
		if(cijena_restorana < cijena_fast_food && cijena_restorana < cijena_bistro)
		{
			printf("Najjeftiniji je restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_restorana);
		}
		else if(cijena_fast_food < cijena_restorana && cijena_fast_food < cijena_bistro)
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast_food);
		}
		else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
		if(restoran_sa_popustom < cijena_restorana && restoran_sa_popustom < cijena_fast_food && restoran_sa_popustom < cijena_bistro)
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran_sa_popustom);
		}
	}
	return 0;
}
