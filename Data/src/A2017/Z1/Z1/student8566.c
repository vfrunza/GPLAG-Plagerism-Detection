#include <stdio.h>

int main() {
   
	char tarik;
	char bojan;
	char mirza;
	char novi_red;
	
	double cijenaPizzaRestoran = 6.80;
	double cijenaHamburgerRestoran = 3.30;
	double cijenaCevapiRestoran = 5.00;
	
	double cijenaPizzaFastFood = 8.00;
	double cijenaHamburgerFastFood = 3.00;
	double cijenaCevapiFastFood = 3.90;
	
	double cijenaPizzaBistro = 5.30;
	double cijenaHamburgerBistro = 5.00;
	double cijenaCevapiBistro = 6.00;
	
	double racunRestoran;
	double racunFastFood;
	double racunBistro;
	double racunRestoranSaPopustom;
    	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
		if((tarik=='H' || bojan=='H' || mirza=='H') && (tarik=='C' || bojan=='C' || mirza=='C') && (tarik=='P' || bojan=='P' || mirza=='P')){
	   		racunRestoran = cijenaHamburgerRestoran + cijenaCevapiRestoran + cijenaPizzaRestoran;
	   		racunBistro = cijenaHamburgerBistro + cijenaCevapiBistro + cijenaPizzaBistro;
	   		racunFastFood = cijenaHamburgerFastFood + cijenaCevapiFastFood + cijenaPizzaFastFood;
	   		if(cijenaHamburgerRestoran > cijenaPizzaRestoran && cijenaHamburgerRestoran > cijenaCevapiRestoran) {
				racunRestoranSaPopustom = (cijenaHamburgerRestoran - (cijenaHamburgerRestoran* 0.1)) + cijenaCevapiRestoran + cijenaPizzaRestoran;		   		
		   	}
		   	else if(cijenaPizzaRestoran > cijenaHamburgerRestoran && cijenaPizzaRestoran > cijenaCevapiRestoran) {
				racunRestoranSaPopustom = (cijenaPizzaRestoran - (cijenaPizzaRestoran* 0.1)) + cijenaHamburgerRestoran + cijenaCevapiRestoran;		   		
		   	}
		   	else if(cijenaCevapiRestoran > cijenaHamburgerRestoran && cijenaCevapiRestoran > cijenaPizzaRestoran) {
				racunRestoranSaPopustom = (cijenaCevapiRestoran - (cijenaCevapiRestoran* 0.1)) + cijenaHamburgerRestoran + cijenaPizzaRestoran;		   		
		   	}
		}
		else if(tarik=='H' && bojan=='H' && mirza=='H'){
	   		racunRestoran = 3 * cijenaHamburgerRestoran;
	   		racunBistro = 3* cijenaHamburgerBistro;
	   		racunFastFood = 3 * cijenaHamburgerFastFood;
	   		racunRestoranSaPopustom = 3 * (cijenaHamburgerRestoran - (cijenaHamburgerRestoran * 0.1));
		}
		else if((tarik=='C' || bojan=='C' || mirza=='C') && ((tarik=='H' && bojan=='H') || (mirza=='H' && bojan=='H') || (mirza=='H' && tarik=='H'))){
	   		racunRestoran = cijenaCevapiRestoran + cijenaHamburgerRestoran + cijenaHamburgerRestoran;
	   		racunBistro = cijenaCevapiBistro + cijenaHamburgerBistro + cijenaHamburgerBistro;
	   		racunFastFood = cijenaCevapiFastFood + cijenaHamburgerFastFood + cijenaHamburgerFastFood;
	   		if(2*cijenaHamburgerRestoran > cijenaCevapiRestoran	) {
			   	racunRestoranSaPopustom = 2* (cijenaHamburgerRestoran - (cijenaHamburgerRestoran * 0.1)) + cijenaCevapiRestoran;
  			}
  			else{
			  	racunRestoranSaPopustom = 2* cijenaHamburgerRestoran + (cijenaCevapiRestoran - (cijenaCevapiRestoran * 0.1));
			  }
		}
		else if((tarik=='H' || bojan=='H' || mirza=='H') && ((tarik=='C' && bojan=='C') || (mirza=='C' && bojan=='C') || (mirza=='C' && tarik=='C'))){
	   		racunRestoran = cijenaHamburgerRestoran + cijenaCevapiRestoran + cijenaCevapiRestoran;
   			racunBistro = cijenaHamburgerBistro + cijenaCevapiBistro + cijenaCevapiBistro;
	   		racunFastFood = cijenaHamburgerFastFood + cijenaCevapiFastFood + cijenaCevapiFastFood;
	   		if(2*cijenaCevapiRestoran > cijenaHamburgerRestoran) {
			   	racunRestoranSaPopustom = 2* (cijenaCevapiRestoran - (cijenaCevapiRestoran * 0.1)) + cijenaHamburgerRestoran;
  			}
  			else{
			  	racunRestoranSaPopustom = 2* cijenaCevapiRestoran + (cijenaHamburgerRestoran - (cijenaHamburgerRestoran * 0.1));
			  }
		}
		else if((tarik=='P' || bojan=='P' || mirza=='P') && ((tarik=='C' && bojan=='C') || (mirza=='C' && bojan=='C') || (mirza=='C' && tarik=='C'))){
	   		racunRestoran = cijenaPizzaRestoran + cijenaCevapiRestoran + cijenaCevapiRestoran;
   			racunBistro = cijenaPizzaBistro + cijenaCevapiBistro + cijenaCevapiBistro;
	   		racunFastFood = cijenaPizzaFastFood + cijenaCevapiFastFood + cijenaCevapiFastFood;
	   		if(2*cijenaCevapiRestoran > cijenaPizzaRestoran) {
			   	racunRestoranSaPopustom = 2* (cijenaCevapiRestoran - (cijenaCevapiRestoran * 0.1)) + cijenaPizzaRestoran;
  			}
  			else{
			  	racunRestoranSaPopustom = 2* cijenaCevapiRestoran + (cijenaPizzaRestoran - (cijenaPizzaRestoran * 0.1));
			  }
		}
		else if((tarik=='H' || bojan=='H' || mirza=='H') && ((tarik=='P' && bojan=='P') || (mirza=='P' && bojan=='P') || (mirza=='P' && tarik=='P'))){
	   		racunRestoran = cijenaHamburgerRestoran + cijenaPizzaRestoran + cijenaPizzaRestoran;
	   		racunBistro = cijenaHamburgerBistro + cijenaPizzaBistro + cijenaPizzaBistro;
	   		racunFastFood = cijenaHamburgerFastFood + cijenaPizzaFastFood + cijenaPizzaFastFood;
	   		if(2*cijenaPizzaRestoran > cijenaHamburgerRestoran) {
			   	racunRestoranSaPopustom = 2* (cijenaPizzaRestoran - (cijenaPizzaRestoran * 0.1)) + cijenaHamburgerRestoran;
  			}
  			else{
			  	racunRestoranSaPopustom = 2* cijenaPizzaRestoran + (cijenaHamburgerRestoran - (cijenaHamburgerRestoran * 0.1));
			  }
		}
		else if(tarik=='P' && bojan=='P' && mirza=='P'){
	   		racunRestoran = 3 * cijenaPizzaRestoran;
	   		racunBistro = 3 * cijenaPizzaBistro;
	   		racunFastFood = 3* cijenaPizzaFastFood;
   			racunRestoranSaPopustom = 3 * (cijenaPizzaRestoran - (cijenaPizzaRestoran * 0.1));
		}
		else if((tarik=='C' || bojan=='C' || mirza=='C') && ((tarik=='P' && bojan=='P') || (mirza=='P' && bojan=='P') || (mirza=='P' && tarik=='P'))){
	   		racunRestoran = cijenaCevapiRestoran + cijenaPizzaRestoran + cijenaPizzaRestoran;
	   		racunBistro  = cijenaCevapiBistro + cijenaPizzaBistro + cijenaPizzaBistro;
	   		racunFastFood = cijenaCevapiFastFood + cijenaPizzaFastFood + cijenaPizzaFastFood;
   			if(2*cijenaPizzaRestoran > cijenaCevapiRestoran) {
			   	racunRestoranSaPopustom = 2* (cijenaPizzaRestoran - (cijenaPizzaRestoran * 0.1)) + cijenaCevapiRestoran;
  			}
  			else{
			  	racunRestoranSaPopustom = 2* cijenaPizzaRestoran + (cijenaCevapiRestoran - (cijenaCevapiRestoran * 0.1));
            }
		}
		else if(tarik=='C' && bojan=='C' && mirza=='C'){
	   		racunRestoran = 3 * cijenaCevapiRestoran;
	   		racunBistro = 3* cijenaCevapiBistro;
	   		racunFastFood = 3 * cijenaCevapiFastFood;
   			racunRestoranSaPopustom = 3 * (cijenaCevapiRestoran - (cijenaCevapiRestoran * 0.1));
		}
		else if((tarik=='P' || bojan=='P' || mirza=='P') && ((tarik=='H' && bojan=='H') || (mirza=='H' && bojan=='H') || (mirza=='H' && tarik=='H'))){
	   		racunRestoran = cijenaPizzaRestoran + cijenaHamburgerRestoran + cijenaHamburgerRestoran;
	   		racunBistro = cijenaPizzaBistro + cijenaHamburgerBistro + cijenaHamburgerBistro;
	   		racunFastFood = cijenaPizzaFastFood + cijenaHamburgerFastFood + cijenaHamburgerFastFood;
	   		if(2*cijenaHamburgerRestoran  > cijenaPizzaRestoran	) {
			   	racunRestoranSaPopustom = 2* (cijenaHamburgerRestoran - (cijenaHamburgerRestoran * 0.1)) + cijenaPizzaRestoran;
  			}
  			else{
			  	racunRestoranSaPopustom = 2* cijenaHamburgerRestoran + (cijenaPizzaRestoran - (cijenaPizzaRestoran * 0.1));
            }
		}
		
		if(racunBistro < racunFastFood && racunBistro < racunRestoran) {
  			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n",racunBistro);
  			if(racunRestoranSaPopustom < racunBistro) {
			  	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).",racunRestoranSaPopustom);
			  }
		}
		else if(racunFastFood < racunBistro && racunFastFood < racunRestoran) {
  			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n",racunFastFood);
		   	if(racunRestoranSaPopustom < racunFastFood) {
			  	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).",racunRestoranSaPopustom);
			  }
		}
		else if(racunRestoran < racunBistro && racunRestoran < racunFastFood) {
  			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).",racunRestoran);
		}
	
           getchar();
}