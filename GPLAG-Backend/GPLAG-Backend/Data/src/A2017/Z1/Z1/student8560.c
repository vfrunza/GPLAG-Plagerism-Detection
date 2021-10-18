#include<stdio.h>
#define cevapi_kkik 5.00
#define cevapi_tr 3.90
#define cevapi_lor 6.00
#define pizza_kkik 6.80
#define pizza_tr 8.00
#define pizza_lor 5.30
#define hamburger_kkik 3.30
#define hamburger_tr 3.00
#define hamburger_lor 5.00
int main() {
	char jelo_tarik,jelo_bojan,jelo_mirza,nr1,nr2,z='"';
	double cijena_kkik=0,cijena_tr=0,cijena_lor=0,najjeftinije,sa_popustom;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&jelo_tarik);
	scanf("%c",&nr1);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&jelo_bojan);
	scanf("%c",&nr2);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&jelo_mirza);
	if(jelo_tarik=='H') {
		cijena_kkik+=hamburger_kkik;
		cijena_lor+=hamburger_lor;
		cijena_tr+=hamburger_tr;
	} else if(jelo_tarik=='C') {
		cijena_kkik+=cevapi_kkik;
		cijena_lor+=cevapi_lor;
		cijena_tr+=cevapi_tr;
	} else if(jelo_tarik=='P') {
		cijena_kkik+=pizza_kkik;
		cijena_lor+=pizza_lor;
		cijena_tr+=pizza_tr;
	}
	if(jelo_bojan=='H') {
		cijena_kkik+=hamburger_kkik;
		cijena_lor+=hamburger_lor;
		cijena_tr+=hamburger_tr;
	} else if(jelo_bojan=='C') {
		cijena_kkik+=cevapi_kkik;
		cijena_lor+=cevapi_lor;
		cijena_tr+=cevapi_tr;
	} else if(jelo_bojan=='P') {
		cijena_kkik+=pizza_kkik;
		cijena_lor+=pizza_lor;
		cijena_tr+=pizza_tr;
	}
	if(jelo_mirza=='H') {
		cijena_kkik+=hamburger_kkik;
		cijena_lor+=hamburger_lor;
		cijena_tr+=hamburger_tr;
	} else if(jelo_mirza=='C') {
		cijena_kkik+=cevapi_kkik;
		cijena_lor+=cevapi_lor;
		cijena_tr+=cevapi_tr;
	} else if(jelo_mirza=='P') {
		cijena_kkik+=pizza_kkik;
		cijena_lor+=pizza_lor;
		cijena_tr+=pizza_tr;
	}
	if(cijena_kkik<cijena_tr && cijena_kkik<cijena_lor) {
		najjeftinije=cijena_kkik;
		printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",z,z,najjeftinije);
	} else if(cijena_lor<cijena_kkik && cijena_lor<cijena_tr) {
		najjeftinije=cijena_lor;
		printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).",z,z,najjeftinije);
	} else {
		najjeftinije=cijena_tr;
		printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).",z,z,najjeftinije);
	}
	if(najjeftinije!=cijena_kkik) {
		if(jelo_tarik=='P' && jelo_mirza=='P' && jelo_bojan=='P') sa_popustom=cijena_kkik-(3*pizza_kkik*10)/100;
		else if((jelo_bojan=='P' && jelo_mirza=='P' && jelo_tarik=='H') || (jelo_bojan=='P' && jelo_tarik=='P' && jelo_mirza!='P') || (jelo_mirza=='P' && jelo_tarik=='P' && jelo_bojan!='P')) sa_popustom=cijena_kkik-(2*pizza_kkik*10)/100;
		else if((jelo_tarik=='P' && jelo_mirza!='P' && jelo_bojan!='P') || (jelo_mirza=='P' && jelo_tarik!='P' && jelo_bojan!='P') || (jelo_bojan=='P' && jelo_tarik!='P' && jelo_mirza!='P')) sa_popustom=cijena_kkik-(pizza_kkik*10)/100;
		else if(jelo_bojan=='C' && jelo_mirza=='C' && jelo_tarik=='C') sa_popustom=cijena_kkik-(3*cevapi_kkik*10)/100;
		else if((jelo_tarik=='C' && jelo_mirza=='C' && jelo_bojan!='C') || (jelo_bojan=='C' && jelo_tarik=='C' && jelo_mirza!='C') || (jelo_mirza=='C' && jelo_tarik=='C' && jelo_bojan!='C')) sa_popustom=cijena_kkik-(2*cevapi_kkik*10)/100;
		else if((jelo_tarik=='C' && jelo_bojan!='C' && jelo_mirza!='C') || (jelo_bojan=='C' && jelo_tarik!='C' && jelo_mirza!='C') || (jelo_mirza=='C' && jelo_tarik!='C' && jelo_bojan!='C')) sa_popustom=cijena_kkik-(cevapi_kkik*10)/100;
		else if(jelo_tarik=='H' && jelo_mirza=='H' && jelo_bojan=='H') sa_popustom=cijena_kkik-(3*hamburger_kkik*10)/100;
		else if((jelo_bojan=='H' && jelo_mirza=='H' && jelo_tarik!='H') || (jelo_bojan=='H' && jelo_tarik=='H' && jelo_mirza!='H') || (jelo_mirza=='H' && jelo_tarik=='H' && jelo_bojan!='H')) sa_popustom=cijena_kkik-(2*hamburger_kkik*10)/100;
		else if((jelo_tarik=='H' && jelo_mirza!='H' && jelo_bojan!='H') || (jelo_mirza=='H' && jelo_tarik!='H' && jelo_bojan!='H') || (jelo_bojan=='H' && jelo_tarik!='H' && jelo_mirza!='H')) sa_popustom=cijena_kkik-(hamburger_kkik*10)/100;
		if(sa_popustom<najjeftinije)  printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",sa_popustom);
	}
	return 0;
}
