#include <stdio.h>


int main() {
	float pizzar=6.80,pizzat=8.00,pizzal=5.30;
	float hamburgerr=3.30,hamburgert=3.00,hamburgerl=5.00;
	float cevapr=5.00,cevapt=3.90,cevapl=6.00;
	char tarik,bojan,mirza,novi_red;
	float racun;
	float novi_racun;
	float popust;
	printf ("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	 if(tarik == 'P' &&  bojan == 'P' && mirza == 'P' ){
	 	racun = pizzal + pizzal + pizzal;
	 	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun);
	 }
	if(tarik == 'H' && bojan == 'H' && mirza == 'P'){
		racun=hamburgerr + hamburgerr + pizzar;
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racun);
	}
	if(tarik== 'H' && bojan== 'H' && mirza == 'H'){
		racun=hamburgert+hamburgert+hamburgert;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun );
		novi_racun=hamburgerr-(hamburgerr*10)/100;
		popust=3*novi_racun;
		if(popust<racun){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
		}
		
	}
	if(tarik == 'C' && bojan== 'C' && mirza=='C'){
		racun=3*cevapt;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun);
	}
	if(tarik == 'H' && bojan== 'P' && mirza=='P'){
		racun=hamburgerl+2*pizzal;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",racun);
		if(hamburgerr>pizzar){
		 novi_racun=hamburgerr-(hamburgerr*10)/100;
		 popust= novi_racun + 2*pizzar;
		 printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
		}
		if(hamburgerr<pizzar){
			novi_racun=pizzar-(pizzar*10)/100;
			popust=2*novi_racun + hamburgerr;
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
		}
	}
	if(tarik== 'C' && bojan== 'H' && mirza=='P'){
		racun=cevapt+cevapl+cevapr;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
		if(cevapr>pizzar && cevapr>hamburgerr){
			novi_racun=cevapr-(cevapr*10)/100;
			popust=novi_racun+pizzar+hamburgerr;
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
		}
		if(pizzar>cevapr && pizzar>hamburgerr){
			novi_racun=pizzar-(pizzar*10)/100;
			popust=novi_racun+cevapr+hamburgerr;
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
		}
		if(hamburgerr>pizzar && hamburgerr>cevapr){
			novi_racun=hamburgerr-(hamburgerr*10)/100;
			popust=novi_racun + pizzar + cevapr;
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
		}
	}
	if(tarik== 'C' && bojan =='P' && mirza== 'C'){
		racun=2*cevapt+pizzat;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
	}
	if(tarik == 'P' && bojan == 'P' && mirza== 'C'){
		racun=2*pizzal+cevapl;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",racun);
	}
	if(tarik=='H' && bojan == 'C' && mirza =='C'){
		racun=2*cevapt+hamburgert;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
	}
	if(tarik =='C' && bojan == 'H' && mirza == 'H'){
		racun = cevapt + 2*hamburgert ;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",racun);
	}
	
	
	return 0;
}
