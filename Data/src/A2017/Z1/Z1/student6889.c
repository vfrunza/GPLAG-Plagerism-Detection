#include <stdio.h>
#define Pk 6.80
#define Hk 3.30
#define Ck 5.00
#define Pt 8.00
#define Ht 3.00
#define Ct 3.90
#define Pl 5.30
#define Hl 5.00
#define Cl 6.00


int main() {

	float R, Rp;
	char tarik, bojan, mirza, novi_red;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	
	if(tarik=='H' && bojan=='H' && mirza=='H'){
		R=3*Ht;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", R);
		Rp=Hk+Hk+Hk;
		Rp=Rp*0.9;
		if(Rp<R){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Rp);
		}
	}
	else if(tarik=='P' && bojan=='P' && mirza=='P'){
		R=3*Pl;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",R);
		Rp=Pk+Pk+Pk;
		Rp=Rp*0.9;
		if(Rp<R){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Rp);
		}
	}
	else if(tarik=='C' && bojan=='C' && mirza=='C'){
		R=3*Ct;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
		Rp=Ck+Ck*Ck;
		Rp=Rp*0.9;
		if(Rp<R){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",Rp);
		}
	}
	else if((tarik=='C' && bojan=='H' && mirza=='H')||(tarik=='H' && bojan=='C' && mirza=='H')||(tarik=='H' && bojan=='H' && mirza=='C')){
		R=2*Ht+Ct;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
		Rp=2*Hk*0.9+Ck;
		if(Rp<R){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Rp);
		}
	}
	else if((tarik=='P' && bojan=='H' && mirza=='H')||(tarik=='H' && bojan=='P' && mirza=='H')||(tarik=='H' && bojan=='H' && mirza=='P')){
		R=2*Hk+Pk;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R);
		}
	else if((tarik=='H' && bojan=='P' && mirza=='P')||(tarik=='P' && bojan=='H' && mirza=='P')||(tarik=='P' && bojan=='P' && mirza=='H')){
		R=2*Pl+Hl;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",R);
		Rp=2*Pk*0.9+Hk;
		if(Rp<R){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Rp);
		}
	}
	else if((tarik=='C' && bojan=='P' && mirza=='P')||(tarik=='P' && bojan=='C' && mirza=='P')||(tarik=='P' && bojan=='P' && mirza=='C')){
		R=2*Pl+Cl;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",R);
		Rp=2*Pk*0.9+Ck;
		if(Rp<R){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Rp);
		}
	}
	else if((tarik=='H' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='H')){
		R=2*Ct+Ht;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
		Rp=2*Ck*0.9+Hk;
		if(Rp<R){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Rp);
		}
	}
	else if((tarik=='P' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='P' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='P')){
		R=2*Ct+Pt;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
		Rp=2*Ck*0.9+Pk;
		if(Rp<R){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Rp);
		}
	}
	else if((tarik=='H' && bojan=='C' && mirza=='P')||(tarik=='H' && bojan=='P' && mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='H')||(tarik=='P' && bojan=='H' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='H')){
  		R=Ct+Pt+Ht;
  		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",R);
  		Rp=Ck+Pk*0.9+Hk;
  		if(Rp<R){
  			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Rp);
  		}
	}
  		
  		
	return 0;
}
