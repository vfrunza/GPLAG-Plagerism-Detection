#include <stdio.h>
#define PR 6.80
#define HR 3.30
#define CR 5.00
#define PT 8.00
#define HT 3.00
#define CT 3.90
#define PL 5.30
#define HL 5.00
#define CL 6.00
int main() {
	char tarik,bojan,mirza,novi_red;
	float ucr=0,uct=0,ucl=0,ucrsp=0;
	int brp=0,brh=0,brc=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

	
	if(tarik == 'P')
		brp++;
		
		else if(tarik =='H')
			brh++;
		
		else if(tarik =='C')
			brc++;
		
	
	if(bojan=='P')
		brp++;
		else if(bojan=='H')
			brh++;
			else if(bojan=='C')
			brc++;
				
	if(mirza=='P')
		brp++;
		
		else if(mirza=='H')
		brh++;
		else if(mirza == 'C')
		brc++;
		
	//Ispituje se popust		
	if(brp==3)
	ucrsp=2.7*PR;
	else if(brh==3)
	ucrsp=2.7*HR;
	else if(brc==3)
	ucrsp=2.7*CR;
	else if(brp==2){
		if(brc==1)
		ucrsp=brp*0.9*PR+CR;
		else ucrsp=brp*0.9*PR+HR;
	}
	else if(brp==1){
		if(brc==2)
		ucrsp=0.9*PR+2*CR;
		else if(brh==2)
		ucrsp=0.9*PR+2*HR;
		else ucrsp=0.9*PR+HR+CR;
	}
	else if(brc==2)
	ucrsp=1.8*CR+HR;
	else
	ucrsp=0.9*CR+2*HR;
	//Racuna se ukupna cijena
	ucr=brp*PR+brh*HR+brc*CR;
	uct=brp*PT+brh*HT+brc*CT;
	ucl=brp*PL+brh*HL+brc*CL;
			

	if(ucr<uct && ucr<ucl)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",ucr);
	
	else if(uct<ucr && uct<ucl)
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",uct);
		if(ucrsp<uct)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",ucrsp);
	}
	
	else if(ucl<ucr && ucl<uct){
		
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ucl);
		if(ucrsp<ucl)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",ucrsp);
	}
	
	return 0;
}
