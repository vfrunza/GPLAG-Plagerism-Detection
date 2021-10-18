#include <stdio.h>
#define CIJENA_PIZZE_RESTORAN 6.8f
#define CIJENA_PIZZE_FAST_FOOD 8.0f
#define CIJENA_PIZZE_BISTRO 5.3f

#define CIJENA_HAMBURGERA_RESTORAN 3.3f
#define CIJENA_HAMBURGERA_FAST_FOOD 3.0f
#define CIJENA_HAMBURGERA_BISTRO 5.0f

#define CIJENA_CEVAPA_RESTORAN 5.0f
#define CIJENA_CEVAPA_FAST_FOOD 3.9f
#define CIJENA_CEVAPA_BISTRO 6.0f

#define RESTORAN_POPUST 0.1f

#define PIZZA 'P'
#define HAMBURGER 'H' 
#define CEVAPI 'C'

int main() {
	char noviRed, tarikjelo, bojanjelo, mirzajelo;
	float cijenaRestoranPopust;
	float cijenaRestoran = 0.0, cijenaFastFood=0.0, cijenaBistro=0.0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarikjelo);
	scanf("%c",&noviRed);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojanjelo);
	scanf("%c",&noviRed);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirzajelo);
	scanf("%c",&noviRed);
	
	
	 
	 if(tarikjelo==PIZZA)
	 {
	 	cijenaRestoran+= CIJENA_PIZZE_RESTORAN;
	 	cijenaFastFood+=CIJENA_PIZZE_FAST_FOOD;
	 	cijenaBistro+=CIJENA_PIZZE_BISTRO;
	 	
	 }
	 else if (tarikjelo==HAMBURGER)
	 {
	 	cijenaRestoran+=CIJENA_HAMBURGERA_RESTORAN;
	 	cijenaFastFood+=CIJENA_HAMBURGERA_FAST_FOOD;
	 	cijenaBistro+=CIJENA_HAMBURGERA_BISTRO;
	 }
	else if (tarikjelo==CEVAPI)
	{ 
		cijenaRestoran+=CIJENA_CEVAPA_RESTORAN;
		cijenaFastFood+=CIJENA_CEVAPA_FAST_FOOD;
		cijenaBistro+=CIJENA_CEVAPA_BISTRO;
	}
	
	if(bojanjelo==PIZZA)
	{
		cijenaRestoran+=CIJENA_PIZZE_RESTORAN;
		cijenaFastFood+=CIJENA_PIZZE_FAST_FOOD;
		cijenaBistro+=CIJENA_PIZZE_BISTRO;
	}
	else if (bojanjelo==HAMBURGER)
	{
		cijenaRestoran+=CIJENA_HAMBURGERA_RESTORAN;
		cijenaFastFood+=CIJENA_HAMBURGERA_FAST_FOOD;
		cijenaBistro+=CIJENA_HAMBURGERA_BISTRO;
	}
	else if (bojanjelo==CEVAPI)
	{
		cijenaRestoran+=CIJENA_CEVAPA_RESTORAN;
		cijenaFastFood+=CIJENA_CEVAPA_FAST_FOOD;
		cijenaBistro+=CIJENA_CEVAPA_BISTRO;
	}
	
	if (mirzajelo==PIZZA)
	{
		cijenaRestoran+=CIJENA_PIZZE_RESTORAN;
		cijenaFastFood+=CIJENA_PIZZE_FAST_FOOD;
		cijenaBistro+=CIJENA_PIZZE_BISTRO;
	}
	else if (mirzajelo==HAMBURGER)
	{
		cijenaRestoran+=CIJENA_HAMBURGERA_RESTORAN;
		cijenaFastFood+=CIJENA_HAMBURGERA_FAST_FOOD;
		cijenaBistro+=CIJENA_HAMBURGERA_BISTRO;
	}
	else if (mirzajelo==CEVAPI)
	{
		cijenaRestoran+=CIJENA_CEVAPA_RESTORAN;
		cijenaFastFood+=CIJENA_CEVAPA_FAST_FOOD;
		cijenaBistro+=CIJENA_CEVAPA_BISTRO;
	}
	
	if (tarikjelo == PIZZA || bojanjelo==PIZZA || mirzajelo==PIZZA)
	{   
		  int brojPizza=0;
		  if(tarikjelo==PIZZA)
		   {
		   	brojPizza++;
		   }
		   if (bojanjelo==PIZZA)
		   {
		   	brojPizza++;
		   }
		   if(mirzajelo==PIZZA)
		   {
		   	brojPizza++;
		   }
		   cijenaRestoranPopust=cijenaRestoran-brojPizza*CIJENA_PIZZE_RESTORAN*RESTORAN_POPUST;
	}
	else if (tarikjelo==CEVAPI || bojanjelo==CEVAPI || mirzajelo==CEVAPI)
	{
		int brojCevapa=0;
		if (tarikjelo==CEVAPI)
		{
			brojCevapa++;
		}
		if (bojanjelo==CEVAPI)
		{
			brojCevapa++;
		}
		if(mirzajelo==CEVAPI)
		{
			brojCevapa++;
		}
		cijenaRestoranPopust=cijenaRestoran-brojCevapa * CIJENA_CEVAPA_RESTORAN*RESTORAN_POPUST;
	}
	
	else
	{
		int brojHamburgera=0;
		if (tarikjelo==HAMBURGER)
		{
			brojHamburgera++;
		}
		if (bojanjelo==HAMBURGER)
		{
			brojHamburgera++;
		}
		if (mirzajelo==HAMBURGER)
		{
			brojHamburgera++;
		}
		cijenaRestoranPopust = cijenaRestoran - brojHamburgera * CIJENA_HAMBURGERA_RESTORAN * RESTORAN_POPUST;
		}
		
		if (cijenaRestoran < cijenaFastFood && cijenaRestoran < cijenaBistro)
		
		{
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFastFood < cijenaRestoran && cijenaFastFood < cijenaBistro)
		
		{
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijenaFastFood);
		if (cijenaRestoranPopust < cijenaFastFood)
		{
	   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenaRestoranPopust);
		}
	
		}
	else if (cijenaBistro < cijenaRestoran && cijenaBistro < cijenaFastFood)
	
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijenaBistro);
		if (cijenaRestoranPopust < cijenaBistro)
		
		{
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijenaRestoranPopust);
			
		}
		}
		
		return 0;
	}
