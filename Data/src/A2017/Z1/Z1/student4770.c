#include <stdio.h>

int main() {
	double P1=6.80,P2=8,P3=5.30,H1=3.30,H2=3,H3=5,C1=5,C2=3.90;
	double kkk,trov,lorelei;
	char tarik,bojan,mirza,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	if(tarik=='H' && bojan=='H'&& mirza=='H'){
		printf("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).\n");
		trov=H2*3;
		kkk=(H1*0.9)*3;
		if(kkk<trov){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",kkk);
		}
	}
	if((tarik=='H' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='H')||(tarik=='H' && bojan=='C' && mirza=='H')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	if((tarik=='H' && bojan=='H' && mirza=='P')||(tarik=='P' && bojan=='H' && mirza=='H')||(tarik=='H' && bojan=='P' && mirza=='H')){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
		
	}
	if((tarik=='H' && bojan=='P' && mirza=='P')||(tarik=='P' && bojan=='H' && mirza=='P')||(tarik=='P' && bojan=='P' && mirza=='H')){
		printf("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\n");
		lorelei=P3*2+H3;
		kkk=(P1*0.9)*2+H1;
		if(kkk<lorelei){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",kkk);
		}
	}
	if((tarik=='H' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='H')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}if((tarik=='H' && bojan=='P' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='P')||(tarik=='P' && bojan=='H' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='H')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		trov=P2+H2+C2;
		kkk=(P1*0.9)+H1+C1;
		if(kkk<trov){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",kkk);
		}
	}if((tarik=='C' && bojan=='H' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='H')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
		trov=P2+H2+C2;
		kkk=(P1*0.9)+H1+C1;
		if(kkk<trov){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",kkk);
		}
	}if(tarik=='P' && bojan=='P' && mirza=='P'){
		printf("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
	}if((tarik=='P' && bojan=='P' && mirza=='C')||(tarik=='C' && bojan=='P' && mirza=='P')||(tarik=='P' && bojan=='C' && mirza=='P')){
		printf("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}if((tarik=='P' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='P' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='P')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).");
	}if((tarik=='C' && bojan=='C' && mirza=='C')){
		printf("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM).");
	}
	return 0;
}
