#include <stdio.h>

int main() {

	char tarik, bojan, mirza, novired;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novired);
	
	float kkP=6.80, kkH=3.30, kkC=5.00;
	float tP=8.00, tH=3.00, tC=3.90;
	float lP=5.30, lH=5.00, lC=6.00;
	float kkU, tU, lU, kkS;
	

	if (tarik=='P' && bojan=='P' && mirza=='P'){
		kkU=3*kkP;
		tU=3*tP;
		lU=3*lP;
		kkS=3*(0.9*kkP);
	} else if (tarik=='H' && bojan=='H' && mirza=='H'){
        kkU=3*kkH;
		tU=3*tH;
		lU=3*lH;
		kkS=3*(0.9*kkH);
	} else if (tarik=='C' && bojan=='C' && mirza=='C'){
		kkU=3*kkC;
		tU=3*tC;
		lU=3*lC;
		kkS=3*(0.9*kkC);
	} else if ((tarik=='P' && bojan=='P' && mirza=='H' ) || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P')) {
		kkU=2*kkP+kkH;
		tU=2*tP+tH;
		lU=2*lP+lH;
		kkS=2*(0.9*kkP)+kkH;
	} else if ((tarik=='P' && bojan=='P' && mirza=='C' ) || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')){
		kkU=2*kkP+kkC;
		tU=2*tP+tC;
		lU=2*lP+lC;
		kkS=2*(0.9*kkP)+kkC;
	} else if ((tarik=='P' && bojan=='H' && mirza=='H' ) || (tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H')){
		kkU=2*kkH+kkP;
		tU=2*tH+tP;
		lU=2*lH+lP;
		kkS=(0.9*kkP)+(kkH+kkH);
	} else if ((tarik=='C' && bojan=='H' && mirza=='H' ) || (tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='H')){
		kkU=2*kkH+kkC;
		tU=2*tH+tC;
		lU=2*lH+lC;
		kkS=(0.9*kkC)+(kkH+kkH);
	} else if ((tarik=='C' && bojan=='C' && mirza=='P' ) || (tarik=='C' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='C')){
		kkU=2*kkC+kkP;
		tU=2*tC+tP;
		lU=2*lC+lP;
		kkS=(0.9*kkP)+(kkC+kkC);
	} else if ((tarik=='C' && bojan=='C' && mirza=='H' ) || (tarik=='C' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='C')){
		kkU=2*kkC+kkH;
		tU=2*tC+tH;
		lU=2*lC+lH;
		kkS=2*(0.9*kkC)+kkH;
	} else if ((tarik=='P' && bojan=='H' && mirza=='C' ) || (tarik=='H' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='H') || (tarik=='H' && bojan=='P' && mirza=='C')){
		kkU=kkP+kkC+kkH;
		tU=tP+tC+tH;
		lU=lP+lC+lH;
		kkS=(0.9*kkP)+kkH+kkC;
	}
	
	    
    if(kkU<tU && kkU<lU){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", kkU);
		return 0;
   	} else if (tU<kkU && tU<lU) {printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", tU);}
	  else if (lU<kkU && lU<tU) {printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", lU);}
	 
	if (kkS<lU && kkS<tU) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", kkS);
   
	return 0;
}
