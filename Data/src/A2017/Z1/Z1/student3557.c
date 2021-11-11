#include <stdio.h>
#define pizzarestoran 6.80
#define hamburgerrestoran 3.30
#define cevapirestoran 5.00
#define pizzafast 8.00
#define hamburgerfast 3.00
#define cevapifast 3.90
#define pizzabistro 5.30
#define hamburgerbistro 5.00
#define cevapibistro 6.00

int main() {
	
	char T, B, M, novi_red;
	double cijenaRestoran, cijenaFast, cijenaBistro, popust1, popust2, popust3, popust4;
	
	printf("Unesite jelo za Tarika: ");
	scanf ("%c", &T);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &B);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c",&M);
	scanf ("%c", &novi_red);
	
	
	
	
	if ((T=='P' && B=='H' && M=='C') || (T=='P' && B=='C' && M=='H') || (T=='H' && B=='P' && M=='C') || (T=='H' && B=='C' && M=='P') || (T=='C' && B=='H' && M=='P') || (T=='C' && B=='P' && M=='H')){
		cijenaRestoran = pizzarestoran + hamburgerrestoran + cevapirestoran;
		cijenaFast = pizzafast + hamburgerfast + cevapifast;
		cijenaBistro = pizzabistro + hamburgerbistro + cevapibistro;
		
		popust2= cevapirestoran + hamburgerrestoran + pizzarestoran*9/10;
		popust3= cevapirestoran + hamburgerrestoran*9/10 + pizzarestoran;
		popust4= cevapirestoran*9/10 + hamburgerrestoran + pizzarestoran;
		
		if (popust2<popust3 && popust2<popust4){
			popust1=popust2;
		}
		else if (popust3<popust2 && popust3<popust4){
			popust1=popust3;
		}
		else {
			popust1=popust4;
		}
		
		if (cijenaRestoran<cijenaFast && cijenaRestoran<cijenaBistro){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	else if (T=='P' && B=='P' && M=='P'){
		cijenaRestoran= 3* pizzarestoran;
		cijenaFast= 3* pizzafast;
		cijenaBistro= 3* pizzabistro;
		popust1=3*pizzarestoran*9/10;
		
		if (cijenaRestoran<cijenaFast && cijenaRestoran<cijenaBistro){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	else if (T=='H' && B=='H' && M=='H'){
		cijenaRestoran= 3* hamburgerrestoran; 
		cijenaFast= 3* hamburgerfast;
		cijenaBistro= 3* hamburgerbistro;
		popust1 = 3* hamburgerrestoran *9/10;
		
		if (cijenaRestoran<cijenaBistro && cijenaRestoran<cijenaFast){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else{
			{
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
		}
		 if (popust1<cijenaBistro){
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
		    }
		}
	}
	
	
	
	else if (T=='C' && B=='C' && M=='C'){
		cijenaRestoran=3* cevapirestoran;
		cijenaFast= 3* cevapifast;
		cijenaBistro = 3* cevapibistro;
		popust1 = 3* cevapirestoran *9/10;
		
		if (cijenaRestoran<cijenaBistro && cijenaRestoran<cijenaFast){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	else if ((T=='P' && B=='P' && M=='H') || (T=='P' && B=='H' && M=='P') || (T=='H' && B=='P' && M=='P')){
		cijenaRestoran= 2* pizzarestoran + hamburgerrestoran;
		cijenaFast= 2* pizzafast + hamburgerfast;
		cijenaBistro =2* pizzabistro + hamburgerbistro;
		
		popust2= 2* pizzarestoran +hamburgerrestoran*9/10;
		popust3= 2*pizzarestoran*9/10 + hamburgerrestoran;
		
		if(popust2<popust3){
			popust1=popust2;
		}
		else{
			popust1=popust3;
		}
		if (cijenaRestoran<cijenaFast && cijenaRestoran<cijenaBistro){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	else if ((T=='P' && B=='P' && M=='C') || (T=='P' && B=='C' && M=='P') || (T=='C' && B=='P' && M=='P')){
		cijenaRestoran = 2* pizzarestoran + cevapirestoran;
		cijenaFast = 2* pizzafast + cevapifast;
		cijenaBistro = 2* pizzabistro + cevapibistro;
		
		popust2= cevapirestoran + 2*pizzarestoran*9/10;
		popust3= cevapirestoran*9/10 + 2*pizzarestoran;
		
		if (popust2<popust3){
			popust1=popust2;
		}
		else{
			popust1=popust3;
		}
		
		if (cijenaRestoran<cijenaFast && cijenaRestoran<cijenaBistro){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	else if ((T=='H' && B=='H' && M=='P') || (T=='H' && B=='P' && M=='H') || (T=='P' && B=='H' && M=='H')){
		cijenaRestoran= 2* hamburgerrestoran + pizzarestoran;
		cijenaFast= 2* hamburgerfast + pizzafast;
		cijenaBistro= 2* hamburgerbistro + pizzabistro;
		
		popust2= pizzarestoran + 2*hamburgerrestoran*9/10;
		popust3= pizzarestoran*9/10 + 2*hamburgerrestoran;
		
		if(popust2<popust3){
			popust1=popust2;
		}
		else{
			popust1=popust3;
		}
		if (cijenaRestoran<cijenaFast && cijenaRestoran<cijenaBistro){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	else if ((T=='H' && B=='H' && M=='C') || (T=='H' && B=='C' && M=='H') || (T=='C' && B=='H' && M=='H')){
		cijenaRestoran= 2* hamburgerrestoran + cevapirestoran;
		cijenaFast=2* hamburgerfast + cevapifast;
		cijenaBistro= 2* hamburgerbistro + cevapibistro;
		
		popust2=2* hamburgerrestoran + cevapirestoran*9/10;
		popust3= 2* hamburgerrestoran*9/10 + cevapirestoran;
		
		if(popust2<popust3){
			popust1=popust2;
		}
		else{
			popust1=popust3;
		}
		if (cijenaRestoran<cijenaFast && cijenaRestoran<cijenaBistro){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	else if ((T=='C' && B=='C' && M=='P') || (T=='C' && B=='P' && M=='C') || (T=='P' && B=='C' && M=='C')){
		cijenaRestoran = 2* cevapirestoran + pizzarestoran;
		cijenaFast = 2* cevapifast + pizzafast;
		cijenaBistro = 2* cevapibistro + pizzabistro;
		
		popust2 = pizzarestoran + 2* cevapirestoran*9/10;
		popust3 = pizzarestoran*9/10 + 2* cevapirestoran;
		
		if(popust2<popust3){
			popust1=popust2;
		}
		else{
			popust1=popust3;
		}
		if (cijenaRestoran<cijenaFast && cijenaRestoran<cijenaBistro){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	else if ((T=='C' && B=='C' && M=='H') || (T=='C' && B=='H' && M=='C') || (T=='H' && B=='C' && M=='C')){
		cijenaRestoran= 2*cevapirestoran + hamburgerrestoran;
		cijenaBistro=2* cevapibistro + hamburgerbistro;
		cijenaFast= 2*cevapifast + hamburgerfast;
		
		popust2 = hamburgerrestoran +2*cevapirestoran*9/10;
		popust3 = hamburgerrestoran*9/10 +2* cevapirestoran;
		
		if (popust2<popust3){
			popust1=popust2;
		}
		else {
			popust1=popust3;
		}
		
		if (cijenaRestoran<cijenaFast && cijenaRestoran<cijenaBistro){
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaRestoran);
		}
		else if (cijenaFast<cijenaRestoran && cijenaFast<cijenaBistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", cijenaFast);
			if (popust1<cijenaFast){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
		else {
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", cijenaBistro);
			if (popust1<cijenaBistro){
				printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust1);
			}
		}
	}
	
	
	
	return 0;
}
