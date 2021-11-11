#include <stdio.h>

int main() {
	double pizza_trovac=8.0;
	double hamburger_trovac=3.0;
	double cevapi_trovac=3.9;
	
	double pizza_konj=6.8;
	double hamburger_konj=3.3;
	double cevapi_konj=5.0;
	
	double pizza_lorelei=5.3;
	double hamburger_lorelei=5.0;
	double cevapi_lorelei=6.0;
	
	char novi_red = '\n';
	double konj_suma=0,trovac_suma=0,lorelei_suma=0,najmanja_suma=0,suma_sa_popustom=0;
	
	char tarik_jelo,bojan_jelo,mirza_jelo;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik_jelo);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan_jelo);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza_jelo);
	
	
	
	switch (tarik_jelo) {
		case 'h':
		trovac_suma+=hamburger_trovac;
		break;
		case 'p':
		trovac_suma+=pizza_trovac;
		break;
		case 'c':
		trovac_suma+=cevapi_trovac;
		break;
		default:
		break;
		
	}
	
	switch (bojan_jelo) {
		case 'h':
		trovac_suma+=hamburger_trovac;
		break;
		case 'p':
		trovac_suma+=pizza_trovac;
		break;
		case 'c':
		trovac_suma+=cevapi_trovac;
		break;
		default:
		break;
	}
	switch (mirza_jelo) {
		case 'h':
		trovac_suma+=hamburger_trovac;
		break;
		case 'p':
		trovac_suma+=pizza_trovac;
		break;
		case 'c': 
		trovac_suma+=cevapi_trovac;
		break;
		default:
		break;
	}
	switch (tarik_jelo) {
		case 'h':
		konj_suma+=hamburger_konj;
		break;
		case 'p':
		konj_suma+=pizza_konj;
		break;
		case 'c':
		konj_suma+=cevapi_konj;
		break;
		default:
		break;
	}
	switch (bojan_jelo) {
		case 'h':
		konj_suma+=hamburger_konj;
		break;
		case 'p':
		konj_suma+=pizza_konj;
		break;
		case 'c':
		konj_suma+=cevapi_konj;
		break;
		default:
		break;
	}
	switch (mirza_jelo) {
		case 'h':
		konj_suma+=hamburger_konj;
		break;
		case 'p':
		konj_suma+=pizza_konj;
		break;
		case 'c':
		konj_suma+=cevapi_konj;
		break;
		default:
		break;
		
	}
	switch (tarik_jelo) {
		case 'h':
		lorelei_suma+=hamburger_lorelei;
		break;
		case 'p':
		lorelei_suma+=pizza_lorelei;
		break;
		case 'c':
		lorelei_suma+=cevapi_lorelei;
		break;
		default:
		break;
	}
	switch (bojan_jelo) {
		case 'h':
		lorelei_suma+=hamburger_lorelei;
		break;
		case 'p':
		lorelei_suma+=pizza_lorelei;
		break;
		case 'c':
		lorelei_suma+=cevapi_lorelei;
		break;
		default:
		break;
	}
	switch (mirza_jelo) {
		case 'h':
		lorelei_suma+=hamburger_lorelei;
		break;
		case 'p':
		lorelei_suma+=pizza_lorelei;
		break;
		case 'c':
		lorelei_suma+=cevapi_lorelei;
		break;
		default:
		break;
	}
	 
	 double pizza_konj_popust=6.8;
	 double hamburger_konj_popust=3.3;
	 double cevapi_konj_popust=5.0;
	 
	 if((tarik_jelo=='p'&&bojan_jelo=='p')||(tarik_jelo=='p'&&mirza_jelo=='p')||(bojan_jelo=='p'&&mirza_jelo=='p')){
	 	pizza_konj_popust=pizza_konj_popust-(pizza_konj_popust*0.1);
	 }else if ((tarik_jelo=='c'&&bojan_jelo=='c')||(tarik_jelo=='c'&&mirza_jelo=='c')||(bojan_jelo=='c'&&mirza_jelo=='c')){
	 	cevapi_konj_popust=cevapi_konj_popust-(cevapi_konj_popust*0.1);
	 }else {
	 	hamburger_konj_popust=hamburger_konj_popust-(hamburger_konj_popust*0.1);
	 }
     switch (tarik_jelo) {
     	case 'h':
     	suma_sa_popustom+=hamburger_konj_popust;
     	break;
     	case 'p':
     	suma_sa_popustom+=pizza_konj_popust;
     	break;
     	case 'c':
     	suma_sa_popustom+=cevapi_konj_popust;
     	break;
     	default:
     	break;
     } 
     switch (bojan_jelo) {
     	case 'h':
     	suma_sa_popustom+=hamburger_konj_popust;
     	break;
     	case 'p':
     	suma_sa_popustom+=pizza_konj_popust;
     	break;
     	case 'c':
     	suma_sa_popustom+=cevapi_konj_popust;
     	break;
     	default:
     	break;
     }
     switch (mirza_jelo) {
     	case 'h':
     	suma_sa_popustom+=hamburger_konj_popust;
     	break;
     	case 'p':
     	suma_sa_popustom+=pizza_konj_popust;
     	break;
     	case 'c':
     	suma_sa_popustom+=cevapi_konj_popust;
     	break;
     	default:
     	break;
     }
     if(trovac_suma<konj_suma&&trovac_suma<lorelei_suma){
     	najmanja_suma=trovac_suma;
     	printf("Najjeftiniji je Fast-food Trovac: (%.2f KM).\n",najmanja_suma);
     }else if (konj_suma<lorelei_suma) {
     	najmanja_suma=konj_suma;
        printf("Najjeftiniji je Restoran Kod konja i konjusara: (%.2f KM).\n",najmanja_suma);      	
     }else{
     	najmanja_suma=lorelei_suma;
     	printf("Najjeftiniji je Bistro Lorelei: (%.2f KM).\n",najmanja_suma);
     }
     if(suma_sa_popustom<trovac_suma||suma_sa_popustom<lorelei_suma)
     printf("Sa popustom bi Restoran bio jeftiniji: (%.2f KM).\n",suma_sa_popustom);
	return 0;
}