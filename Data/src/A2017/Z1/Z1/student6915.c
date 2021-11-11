#include <stdio.h>
#include <math.h>

int main() {
	char tarik, bojan, mirza, novi_red, navodnik='"';
	double racun1, racun2, racun3, popust, najjeftiniji;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	if(tarik=='P' && bojan=='P' && mirza=='P'){
		racun1=20.4;
		racun2=24;
		racun3=15.9;
		popust=18.36;
	}
	if(tarik=='H' && bojan=='H' && mirza=='H'){
		racun1=9.9;
		racun2=9;
		racun3=15;
		popust=8.91;
	}
	if(tarik=='C' && bojan=='C' && mirza=='C'){
		racun1=15;
		racun2=11.7;
		racun3=18;
		popust=13.5;
	}
	if((tarik=='P' && bojan=='P' && mirza=='H')||(tarik=='P' && bojan=='H' && mirza=='P')||(tarik=='H' && bojan=='P' && mirza=='P')){
		racun1=16.9;
		racun2=19;
		racun3=15.6;
		popust=15.54;
	}
	if((tarik=='P' && bojan=='P' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='P')){
		racun1=18.6;
		racun2=19.9;
		racun3=16.6;
		popust=17.24;
	}
	if((tarik=='H' && bojan=='H' && mirza=='P')||(tarik=='H' && bojan=='P' && mirza=='H')||(tarik=='P' && bojan=='H' && mirza=='H')){
		racun1=13.4;
		racun2=14;
		racun3=15.3;
		popust=999;
	}
	if((tarik=='H' && bojan=='H' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='H')||(tarik=='C' && bojan=='H' && mirza=='H')){
		racun1=11.6;
		racun2=9.9;
		racun3=16;
		popust=10.94;
	}
	if((tarik=='C' && bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='C')){
		racun1=16.8;
		racun2=15.8;
		racun3=17.3;
		popust=15.8;
	}
	if((tarik=='C' && bojan=='C' && mirza=='H')||(tarik=='C' && bojan=='H' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='C')){
		racun1=13.3;
		racun2=10.8;
		racun3=17;
		popust=12.3;
	}
	if((tarik=='P' && bojan=='H' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='H')||(tarik=='H' && bojan=='P' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='H')||(tarik=='C' && bojan=='H' && mirza=='P')){
		racun1=15.1;
		racun2=14.9;
		racun3=16.3;
		popust=racun1 - 0.68;
	}
	
	if(racun1<racun2 && racun1<racun3){
		najjeftiniji=racun1;
	}
	 else if(racun2<racun1 && racun2<racun3){
		najjeftiniji=racun2;
	}
	else if(racun3<racun1 && racun3<racun2){
		najjeftiniji=racun3;
	}
	if(najjeftiniji==racun1){
		printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n", navodnik, navodnik, racun1);
	}
	else if(najjeftiniji==racun2){
		printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n", navodnik, navodnik, racun2);
	}
	else if(najjeftiniji==racun3){
		printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n", navodnik, navodnik, racun3);
	}
	if(popust<najjeftiniji){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", popust);
	}
	return 0;
	}

