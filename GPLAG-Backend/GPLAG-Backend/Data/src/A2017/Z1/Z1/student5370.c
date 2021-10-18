#include <stdio.h>
#include <math.h>



int main() {
	
	char tarik;
	char bojan;
	char mirza;
	char novi_red;
	double PR=6.80, PF=8.00, PB=5.30;
	double HR=3.30, HF=3.00, HB=5.00;
	double CR=5.00, CF=3.90, CB=6.00;
	double cijena_restorana=0, cijena_fastfood=0, cijena_bistro=0;
	int brojac_pizza=0, brojac_hamburgera=0, brojac_cevapa=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	switch (tarik)
	{
		case 'P':
		cijena_restorana=cijena_restorana+PR;
		cijena_fastfood=cijena_fastfood+PF;
		cijena_bistro=cijena_bistro+PB;
		brojac_pizza++;
		break;
		case 'H':
		cijena_restorana=cijena_restorana+HR;
		cijena_fastfood=cijena_fastfood+HF;
		cijena_bistro=cijena_bistro+HB;
		brojac_hamburgera++;
		break;
		case 'C':
		cijena_restorana=cijena_restorana+CR;
		cijena_bistro=cijena_bistro+CB;
		cijena_fastfood=cijena_fastfood+CF;
		brojac_cevapa++;
		break;
	}
	switch (bojan)
	{
		case 'P':
		cijena_restorana=cijena_restorana+PR;
		cijena_fastfood=cijena_fastfood+PF;
		cijena_bistro=cijena_bistro+PB;
		brojac_pizza++;
		break;
		case 'H':
		cijena_restorana=cijena_restorana+HR;
		cijena_fastfood=cijena_fastfood+HF;
		cijena_bistro=cijena_bistro+HB;
		brojac_hamburgera++;
		break;
		case 'C':
		cijena_restorana=cijena_restorana+CR;
		cijena_bistro=cijena_bistro+CB;
		cijena_fastfood=cijena_fastfood+CF;
		brojac_cevapa++;
		break;
	}
	switch (mirza)
	{
		case 'P':
		cijena_restorana=cijena_restorana+PR;
		cijena_fastfood=cijena_fastfood+PF;
		cijena_bistro=cijena_bistro+PB;
		brojac_pizza++;
		break;
		case 'H':
		cijena_restorana=cijena_restorana+HR;
		cijena_fastfood=cijena_fastfood+HF;
		cijena_bistro=cijena_bistro+HB;
		brojac_hamburgera++;
		break;
		case 'C':
		cijena_restorana=cijena_restorana+CR;
		cijena_bistro=cijena_bistro+CB;
		cijena_fastfood=cijena_fastfood+CF;
		brojac_cevapa++;
		break;
	}
	if(cijena_restorana<cijena_fastfood && cijena_restorana<cijena_bistro){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena_restorana);
		return 1;
	}
	else if(cijena_fastfood<cijena_restorana && cijena_fastfood<cijena_bistro)
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena_fastfood);
			if(brojac_hamburgera>brojac_cevapa && brojac_hamburgera>brojac_pizza)
			{
				cijena_restorana=cijena_restorana-((brojac_hamburgera*HR)*10/100);
				if(cijena_restorana<cijena_fastfood)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restorana);
			}
			else if(brojac_cevapa>brojac_hamburgera && brojac_cevapa>brojac_pizza)
			{
				cijena_restorana=cijena_restorana-((brojac_cevapa*CR)*10/100);
				if(cijena_restorana<cijena_fastfood)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restorana);
			}
			else if(brojac_pizza>brojac_cevapa && brojac_pizza>brojac_hamburgera)
			{
				cijena_restorana=cijena_restorana-((brojac_pizza*PR)*10/100);
				if(cijena_restorana<cijena_fastfood)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restorana);
			}
			else if(brojac_pizza==brojac_hamburgera && brojac_pizza==brojac_cevapa)
			{
				cijena_restorana=cijena_restorana-((brojac_pizza*PR)*10/100);
				if(cijena_restorana<cijena_fastfood)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restorana);
			}
			
				
			
		
	}
	else if(cijena_bistro<cijena_fastfood && cijena_bistro<cijena_restorana)
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena_bistro);
			if(brojac_hamburgera>brojac_cevapa && brojac_hamburgera>brojac_pizza)
			{
				cijena_restorana=cijena_restorana-((brojac_hamburgera*HR)*10/100);
				if(cijena_restorana<cijena_bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restorana);
			}
			else if(brojac_cevapa>brojac_hamburgera && brojac_cevapa>brojac_pizza)
			{
				cijena_restorana=cijena_restorana-((brojac_cevapa*CR)*10/100);
				if(cijena_restorana<cijena_bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restorana);
			}
			else if(brojac_pizza>brojac_cevapa && brojac_pizza>brojac_hamburgera)
			{
				cijena_restorana=cijena_restorana-((brojac_pizza*PR)*10/100);
				if(cijena_restorana<cijena_bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restorana);
			}
			else if(brojac_pizza==brojac_hamburgera && brojac_pizza==brojac_cevapa)
			{
				cijena_restorana=cijena_restorana-((brojac_pizza*PR)*10/100);
				if(cijena_restorana<cijena_fastfood)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restorana);
			}
		
	} 
	
	
		
	
	
	
	
	return 0;
}
