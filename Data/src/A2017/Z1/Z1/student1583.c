#include <stdio.h>

#define PIZZA_R 6.80
#define PIZZA_F 8.00
#define PIZZA_B 5.30

#define HAMBURGER_R 3.30
#define HAMBURGER_F 3.00
#define HAMBURGER_B 5.00

#define CEVAPI_R 5.00
#define CEVAPI_F 3.90
#define CEVAPI_B 6.00



int main() {
	
	char tarik, bojan, mirza, novi_red;
	float cijenaR=0, cijenaF=0, cijenaB=0;
	float cijena1,cijena2,cijena3,cijena4,cijena5,cijena6,cijena7,cijena8,cijena9,cijena10,cijena11,cijena12,cijena13,cijena14,cijena15,cijena16,cijena17,cijena18;
	
	printf("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf("%c", &novi_red);
	
	if(tarik == 'H')  {cijenaR+=HAMBURGER_R;}
	if (bojan == 'H') {cijenaR+=HAMBURGER_R;}
	if(mirza == 'H') {cijenaR+=HAMBURGER_R;}
	if(tarik == 'P')  {cijenaR+=PIZZA_R;}
	if (bojan =='P')  { cijenaR+=PIZZA_R;}
	if(mirza =='P')  {cijenaR+=PIZZA_R;}
	if(tarik == 'C') {cijenaR+=CEVAPI_R;}
	if( bojan == 'C') { cijenaR+=CEVAPI_R;}
	if (mirza == 'C') { cijenaR+=CEVAPI_R;}
	
	if(tarik == 'H')  {cijenaF+=HAMBURGER_F;}
	if (bojan == 'H') {  cijenaF+=HAMBURGER_F;}
	if(mirza == 'H') { cijenaF+=HAMBURGER_F;}
	if(tarik == 'P')  {cijenaF+=PIZZA_F;}
	if (bojan =='P')  {cijenaF+=PIZZA_F;}
	if(mirza =='P')  {cijenaF+=PIZZA_F;}
	if(tarik == 'C') {  cijenaF+=CEVAPI_F;}
	if( bojan == 'C') { cijenaF+=CEVAPI_F;}
	if (mirza == 'C') { cijenaF+=CEVAPI_F;}
	
	if(tarik == 'H')  {cijenaB+=HAMBURGER_B;}
	if (bojan == 'H') { cijenaB+=HAMBURGER_B;}
	if(mirza == 'H') { cijenaB+=HAMBURGER_B;}
	if(tarik == 'P')  { cijenaB+=PIZZA_B;}
	if (bojan =='P')  { cijenaB+=PIZZA_B;}
	if(mirza =='P')  {cijenaB+=PIZZA_B;}
	if(tarik == 'C') { cijenaB+=CEVAPI_B;}
	if( bojan == 'C') { cijenaB+=CEVAPI_B;}
	if (mirza == 'C') { cijenaB+=CEVAPI_B;}
	
	printf("Najjeftiniji je ");
	
	if (cijenaR<cijenaF && cijenaR<cijenaB){ 
		printf("Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaR );
	return 0;
	}
	if (cijenaF<cijenaR && cijenaF<cijenaB) printf("Fast-food \"Trovac\" (%.2f KM).", cijenaF );
	if (cijenaB<cijenaF && cijenaB<cijenaR) printf("Bistro \"Lorelei\" (%.2f KM).", cijenaB );
	

	
	cijena1=2.7*HAMBURGER_R;
	cijena2=2*HAMBURGER_R+0.9*PIZZA_R;
	cijena3=1.8*HAMBURGER_R+PIZZA_R;
	cijena4=1.8*HAMBURGER_R+CEVAPI_R;
	cijena5=2*HAMBURGER_R+0.9*CEVAPI_R;
	cijena6=HAMBURGER_R+1.8*PIZZA_R;
	cijena7=HAMBURGER_R+1.8*CEVAPI_R;
	cijena8=2*PIZZA_R+0.9*HAMBURGER_R;
	cijena9=2*CEVAPI_R+0.9*HAMBURGER_R;
	
	cijena10=2.7*PIZZA_R;
	cijena11=2*PIZZA_R+0.9*CEVAPI_R;
	cijena12=1.8*PIZZA_R+CEVAPI_R;
	cijena13=PIZZA_R+1.8*CEVAPI_R;
	cijena14=0.9*PIZZA_R+2*CEVAPI_R;
	
	cijena15=2.7*CEVAPI_R;
	
	cijena16=0.9*CEVAPI_R+HAMBURGER_R+PIZZA_R;
	cijena17=CEVAPI_R+0.9*HAMBURGER_R+PIZZA_R;
	cijena18=CEVAPI_R+HAMBURGER_R+0.9*PIZZA_R;
	
	if (cijenaR>cijenaF || cijenaR>cijenaB){
		
	
	if(tarik=='H'&& mirza=='H' && bojan=='H'){
	if(cijena1<cijenaF && cijena1<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena1);}
	
	if(tarik=='H'&& mirza=='H' && bojan=='P'){
	if(cijena2<cijena3 && cijena2<cijenaB && cijena2<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena2);
	if(cijena3<cijena2 && cijena3<cijenaB && cijena3<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena3);}
	
	if(tarik=='H'&& mirza=='H' && bojan=='C'){
	if(cijena5<cijena4 && cijena5<cijenaF && cijena5<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena5);
	if(cijena4<cijena5 && cijena4<cijenaF && cijena4<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena4);}
	
	if(tarik=='H'&& mirza=='P' && bojan=='H'){
	if(cijena2<cijena3 && cijena2<cijenaB && cijena2<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena2);
	if(cijena3<cijena2 && cijena3<cijenaB && cijena3<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena3);}
	
	if(tarik=='H'&& mirza=='P' && bojan=='P'){
	if(cijena6<cijena8 && cijena6<cijenaB && cijena6<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena6);
	if(cijena8<cijena6 && cijena8<cijenaB && cijena8<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena8);}
	
	if(tarik=='H'&& mirza=='P' && bojan=='C'){
	if(cijena16<cijena17 && cijena16<cijena18 && cijena16<cijenaB && cijena16<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena16);
	if(cijena17<cijena16 && cijena17<cijena18 && cijena17<cijenaB && cijena17<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena17);
	if(cijena18<cijena16 && cijena18<cijena17 && cijena18<cijenaB && cijena18<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena18);}
	
	
	if(tarik=='H'&& mirza=='C' && bojan=='H'){
	if(cijena4<cijena5 && cijena4<cijenaB && cijena4<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena4);
	if(cijena5<cijena4 && cijena5<cijenaB && cijena5<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena5);}
	
	if(tarik=='H'&& mirza=='C' && bojan=='P'){
	if(cijena16<cijena17 && cijena16<cijena18 && cijena16<cijenaB && cijena16<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena16);
	if(cijena17<cijena16 && cijena17<cijena18 && cijena17<cijenaB && cijena17<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena17);
	if(cijena18<cijena16 && cijena18<cijena17 && cijena18<cijenaB && cijena18<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena18);}
	
	
	if(tarik=='H'&& mirza=='C' && bojan=='C'){
	if(cijena7<cijena9  && cijena7<cijenaB && cijena7<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena7);
	if(cijena9<cijena7 && cijena9<cijenaB && cijena9<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena9);}
	
	
	if(tarik=='P'&& mirza=='H' && bojan=='H'){
	if(cijena2<cijena3 && cijena2<cijenaB && cijena2<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena2);
	if(cijena3<cijena2 && cijena3<cijenaB && cijena3<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena3);}
	
	if(tarik=='P'&& mirza=='H' && bojan=='P'){
	if(cijena6<cijena8 && cijena6<cijenaB && cijena6<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena6);
	if(cijena8<cijena6 && cijena8<cijenaB && cijena8<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena8);}
	
	if(tarik=='P'&& mirza=='H' && bojan=='C'){
	if(cijena16<cijena17 && cijena16<cijena18 && cijena16<cijenaB && cijena16<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena16);
	if(cijena17<cijena16 && cijena17<cijena18 && cijena17<cijenaB && cijena17<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena17);
	if(cijena18<cijena16 && cijena18<cijena17 && cijena18<cijenaB && cijena18<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena18);}
	
	if(tarik=='P'&& mirza=='P' && bojan=='H'){
	if(cijena6<cijena8 && cijena6<cijenaB && cijena6<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena6);
	if(cijena8<cijena6 && cijena8<cijenaB && cijena8<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena8);}
	
	if(tarik=='P'&& mirza=='P' && bojan=='P'){
	if(cijena10<cijenaF && cijena10<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena10);}
	
	if(tarik=='P'&& mirza=='P' && bojan=='C'){
	if(cijena11<cijena12 && cijena11<cijenaF && cijena11<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena11);
	if(cijena12<cijena11 && cijena12<cijenaF && cijena12<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena12);}
	
	
	if(tarik=='P'&& mirza=='C' && bojan=='H'){
	if(cijena16<cijena17 && cijena16<cijena18 && cijena16<cijenaB && cijena16<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena16);
	if(cijena17<cijena16 && cijena17<cijena18 && cijena17<cijenaB && cijena17<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena17);
	if(cijena18<cijena16 && cijena18<cijena17 && cijena18<cijenaB && cijena18<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena18);}
	
	if(tarik=='P'&& mirza=='C' && bojan=='P'){
	if(cijena11<cijena12 && cijena11<cijenaF && cijena11<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena11);
	if(cijena12<cijena11 && cijena12<cijenaF && cijena12<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena12);}
	
	if(tarik=='P'&& mirza=='C' && bojan=='C'){
		if(cijena13<cijena14 && cijena13<cijenaF && cijena13<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena13);
		if(cijena14<cijena13 && cijena14<cijenaF && cijena14<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena14);}
	
	if(tarik=='C'&& mirza=='H' && bojan=='H'){
	if(cijena5<cijena4 && cijena5<cijenaF && cijena5<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena5);
	if(cijena4<cijena5 && cijena4<cijenaF && cijena4<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena4);}
	
	if(tarik=='C'&& mirza=='H' && bojan=='P'){
	if(cijena16<cijena17 && cijena16<cijena18 && cijena16<cijenaB && cijena16<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena16);
	if(cijena17<cijena16 && cijena17<cijena18 && cijena17<cijenaB && cijena17<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena17);
	if(cijena18<cijena16 && cijena18<cijena17 && cijena18<cijenaB && cijena18<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena18);}
	
	if(tarik=='C'&& mirza=='H' && bojan=='C'){
	if(cijena7<cijena9  && cijena7<cijenaB && cijena7<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena7);
	if(cijena9<cijena7 && cijena9<cijenaB && cijena9<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena9);}
	
	if(tarik=='C'&& mirza=='P' && bojan=='H'){
	if(cijena16<cijena17 && cijena16<cijena18 && cijena16<cijenaB && cijena16<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena16);
	if(cijena17<cijena16 && cijena17<cijena18 && cijena17<cijenaB && cijena17<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena17);
	if(cijena18<cijena16 && cijena18<cijena17 && cijena18<cijenaB && cijena18<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena18);}
	
	if(tarik=='C'&& mirza=='P' && bojan=='P'){
	if(cijena11<cijena12 && cijena11<cijenaF && cijena11<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena11);
	if(cijena12<cijena11 && cijena12<cijenaF && cijena12<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena12);}
	
	if(tarik=='C'&& mirza=='P' && bojan=='C'){
	if(cijena13<cijena14 && cijena13<cijenaF && cijena13<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena13);
	if(cijena14<cijena13 && cijena14<cijenaF && cijena14<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena14);}
	
	if(tarik=='C'&& mirza=='C' && bojan=='H'){
	if(cijena7<cijena9  && cijena7<cijenaB && cijena7<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena7);
	if(cijena9<cijena7 && cijena9<cijenaB && cijena9<cijenaF) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena9);}
	
	if(tarik=='C'&& mirza=='C' && bojan=='P'){
	if(cijena13<cijena14 && cijena13<cijenaF && cijena13<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena13);
	if(cijena14<cijena13 && cijena14<cijenaF && cijena14<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena14);}
	
	if(tarik=='C'&& mirza=='C' && bojan=='C'){
		if(cijena15<cijenaF && cijena13<cijenaB) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena15);}
		
}

	 return 0;
	 
	}
