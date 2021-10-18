#include <stdio.h>

int main() {
	double  iznosRestoran=0,iznosFast_food=0,iznosBistro=0;
	double pPizza,pHamburger,pCevapi,P=0,H=0,C=0;
	char Tarik,Mirza,Bojan,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);
	
	/*Unosi Tarik jelo*/
	if(Tarik=='P') 	P++; 
	if(Tarik=='H') 	H++; 
	if(Tarik=='C')	C++; 
	/*Sljedeci unosi Bojan*/
	if(Bojan=='P') 	P++;
	if(Bojan=='H') 	H++; 
	if(Bojan=='C')  C++; 
	/*Mirza*/ 
	if(Mirza=='P') P++;
	if(Mirza=='H') H++;
	if(Mirza=='C') C++;
	
	 /*Iznos racuna u sva tri objekta*/
	 
     iznosRestoran=P*6.80+H*3.30+C*5.00;
     iznosFast_food=P*8.00+H*3.00+C*3.90;
     iznosBistro=P*5.30+H*5.00+C*6.00;
     
     
     pPizza=P*(6.80*0.9)+H*3.30+C*5.00;
     pHamburger=P*6.80+H*(3.30-0.33)+C*5.00;
     pCevapi=P*6.80+H*3.30+C*(5.00-0.05);
     
     if(iznosBistro<iznosFast_food && iznosBistro<iznosRestoran ) {
	     	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", iznosBistro );
     	if (pPizza<iznosBistro) {
	     	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",pPizza);
	     }
     }
	    else if(iznosRestoran<iznosBistro && iznosRestoran<iznosFast_food) {
	     	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",iznosRestoran);
	     } 
	    else if(iznosFast_food<iznosRestoran && iznosFast_food<iznosBistro ) {
	     	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",iznosFast_food); 
	     	  if (pPizza<pCevapi  && pPizza<iznosFast_food) {
	     	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",pPizza); return 0;
	     }
	      else if(iznosFast_food>pHamburger) {
	     	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",pHamburger);
	     } else if (P==2) {
	     	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", pPizza);
	     } else if(iznosFast_food>pPizza) {
	     	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",pPizza);
	     }
	     }
	    
	return 0;
}
