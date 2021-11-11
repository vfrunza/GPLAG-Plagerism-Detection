#include <stdio.h>

#define PR 6.80
#define HR 3.30
#define CR 5.00
#define PF 8.00
#define HF 3.00
#define CF 3.90
#define PB 5.30
#define HB 5.00
#define CB 6.00

int main() {
	char tarik,bojan,mirza,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	if (tarik=='H' && bojan=='H' && mirza=='H') {
		float HHHR=HR*3;
		float HHHF=HF*3;
		float HHHB=HB*3;
			if (HHHR<HHHF && HHHR<HHHB) {
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2f KM).", HHHR);
			} else if (HHHF<HHHR && HHHF<HHHB) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HHHF);
				double cijena1=(HR*3)*0.9;
				if (cijena1<HHHF) {
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", cijena1);
				} else { 
					return 0;
				}
			} else {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", HHHB);
				double cijena1=(HR*3)*0.9;
				if (cijena1<HHHB) {
					printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).", cijena1);
				} else {
					return 0;
				}
			}
	} else if ((tarik=='H' && bojan=='H' && mirza=='P')||(tarik=='P' && bojan=='H' && mirza=='H')||(tarik=='H' && bojan=='P' && mirza=='H')) {
		float HHPR=HR*2+PR;
		float HHPF=HF*2+PF;
		float HHPB=HB*2+PB;
			if (HHPR<HHPF && HHPR<HHPB) {
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", HHPR);
			} else if (HHPF<HHPR && HHPF<HHPB) {
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",HHPF);
				float cijena2=(HF*2*0.9)+PF;
				float cijena3=(PF*0.9)+HF+HF;
				if (cijena2<HHPF && cijena2<cijena3) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2 KM).", cijena2);
				} else if (cijena3<HHPF && cijena3<cijena2) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena3);
				} else { 
				return 0;
				}
			} else {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", HHPB);
				float cijena3=(HR*2*0.9)+PR;
				float cijena4=(PR*0.9)+HR+HR;
				if (cijena3<HHPB && cijena3<cijena4) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2 KM).", cijena3);
				} else if (cijena4<cijena3 && cijena4<HHPB) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena4);
				} else {
				return 0;
				}
			}
	} else if((tarik=='P' && bojan=='H' && mirza=='P')||(tarik=='P' && bojan=='P' && mirza=='H')||(tarik=='H' && bojan=='P' && mirza=='P')) {
		float HPPR=PR*2+HR;
		float HPPF=PF*2+HF;
		float HPPB=PB*2+HB;
		if (HPPR<HPPF && HPPR<HPPB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", HPPR);
		} else if(HPPF<HPPR && HPPF<HPPB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HPPF);
			float cijena5=(HR*0.9)+PR*2;
			float cijena6=(PR*2*0.9)+HR;
			if (cijena5<HPPF && cijena5<cijena6) {
				printf("\nSa popustom bi Restoran bio jetfiniji (%.2f KM).", cijena5);
			} else if( cijena6<cijena5 && cijena6<HPPF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena6);
			} else { 
			return 0;
			}
		} else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", HPPB);
			float cijena7=(HR*0.9)+PR*2;
			float cijena8=(PR*2*0.9)+HR;
			if (cijena7<HPPB && cijena7<cijena8) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena7);
			} else if(cijena8<cijena7 && cijena8<HPPB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena8);
			} else {
				return 0;
			}
			}
	} else if ((tarik=='H' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='H')||(tarik=='H' && bojan=='C' && mirza=='H')) {
		float HHCR=HR*2+CR;
		float HHCF=HF*2+CF;
		float HHCB=HB*2+CB;
		if (HHCR<HHCF && HHCR<HHCB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", HHCR);
		} else if (HHCF<HHCR && HHCF<HHCB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HHCF);
			float cijena9=(HR*2*0.9)+CR;
			float cijena10=(CR*0.9)+HR*2;
			if (cijena9<HHCF && cijena9<cijena10) {
				printf("Sa popustom bi Restoran bio jetfiniji (%.2f KM).", cijena9);
			} else if (cijena10<cijena9 && cijena10<HHCF) {
				printf("Sa popustom bi Restoran bio jetfiniji (%.2f KM).", cijena10);
			} else {
				return 0;
			}
		} else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", HHCB);
			float cijena11=(HR*2*0.9)+CR;
			float cijena12=(CR*0.9)+HR*2;
			if (cijena11<cijena12 && cijena11<HHCB) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena11);
			} else if (cijena12<cijena11 && cijena12<HHCB) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena12);
			} else {
				return 0;
			}
		}
	} else if ((tarik=='H' && bojan=='C' && mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='H')) {
		float HCCR=HR+CR*2;
		float HCCF=HF+CF*2;
		float HCCB=HB+CB*2;
		if (HCCR<HCCF && HCCR<HCCB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", HCCR);
		} else if (HCCF<HCCB && HCCF<HCCR) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HCCF);
			float cijena13=(HR*0.9)+CR*2;
			float cijena14=(CR*2*0.9)+HR;
			if (cijena13<HCCF && cijena13<cijena14) {
				printf("\nSa popustom bi Restoran bio jetfiniji (%.2f KM).", cijena13);
			} else if (cijena14<HCCF && cijena14<cijena13) {
				printf("\nSa popustom bi Restoran bio jetfiniji (%.2f KM).", cijena14);
			} else {
				return 0;
			}
		} else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", HCCB);
			float cijena15=(HR*0.9)+CR*2;
			float cijena16=(CR*2*0.9)+HR;
			if (cijena15<cijena16 && cijena15<HCCB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena15);
			} else if (cijena16<cijena15 && cijena16<HCCB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena16);
			} else {
				return 0;
			}
		}
	} else if (tarik=='C' && bojan=='C' && mirza=='C') {
		float CCCR=CR*3;
		float CCCF=CF*3;
		float CCCB=CB*3;
		if (CCCR<CCCB && CCCR<CCCF) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", CCCR);
		} else if (CCCF<CCCR && CCCF<CCCB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", CCCF);
			float cijena17=(CR*3*0.9);
			if (cijena17<CCCF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena17);
			} else {
				return 0;
			}
		} else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", CCCB);
			float cijena18=(CR*3*0.9);
			if (cijena18<CCCB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena18);
			} else {
				return 0;
			}
			}
	} else if(tarik=='P' && bojan=='P' && mirza=='P') {
		float PPPR=PR*3;
		float PPPF=PF*3;
		float PPPB=PB*3;
		if (PPPR<PPPF && PPPR<PPPB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", PPPR);
		} else if (PPPF<PPPR && PPPF<PPPB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", PPPF);
			float cijena19=(PR*3*0.9);
			if (cijena19<PPPF) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena19);
			} else {
				return 0;
			}
		} else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", PPPB);
			float cijena20=(PR*3*0.9);
			if (cijena20<PPPB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena20);
			} else {
				return 0;
			}
		}
	} else if((tarik=='H'  && bojan=='P' && mirza=='C')||(tarik=='H' && bojan=='C' && mirza=='P')||(tarik=='P' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='P')||(tarik=='P' && bojan=='C' && mirza=='H')||(tarik=='C' && bojan=='P' && mirza=='H')) {
		float HPCR=HR+PR+CR;
		float HPCF=HF+PF+CF;
		float HPCB=HB+PB+CB;
		if (HPCR<HPCF  && HPCR<HPCB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", HPCR);
		} else if (HPCF<HPCR && HPCF<HPCB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", HPCF);
			float cijena21=(HR*0.9)+PR+CR;
			float cijena22=HR+(PR*0.9)+CR;
			float cijena23=HR+PR+(CR*0.9);
			if (cijena21<cijena22 && cijena21<cijena23 && cijena21<HPCF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena21);
			} else if (cijena22<cijena21 && cijena22<cijena23 && cijena21<HPCF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena22);
			} else if (cijena23<cijena21 && cijena23<cijena22 && cijena23<HPCF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena23);
			} else {
				return 0;
			}
		} else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", HPCB);
			float cijena24=(HR*0.9)+PR+CR;
			float cijena25=HR+(PR*0.9)+CR;
			float cijena26=HR+PR+(CR*0.9);
			if (cijena24<cijena25 && cijena24<cijena26 && cijena24<HPCB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena24);
			} else if (cijena25<cijena24 && cijena25<cijena26 && cijena25<HPCB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena25);
			} else if (cijena26<cijena24 && cijena26<cijena25 && cijena26<HPCB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena26);
			} else {
				return 0;
			}
		}
	} else if ((tarik=='P' && bojan=='P' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='P')) {
		float PPCR=PR*2+CR;
		float PPCF=PF*2+CF;
		float PPCB=PB*2+CB;
		if (PPCR<PPCF && PPCR<PPCB) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", PPCR);
		} else if (PPCF<PPCR && PPCF<PPCB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", PPCF);
			float cijena27=(PR*2*0.9)+CR;
			float cijena28=(CR*0.9)+PR*2;
			if (cijena27<cijena28 && cijena27<PPCF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena27);
			} else if (cijena28<cijena27 && cijena28<PPCF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena28);
			} else {
				return 0;
			}
		} else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", PPCB);
			float cijena29=(PR*2*0.9)+CR;
			float cijena30=(CR*0.9)+PR*2;
			if (cijena29<cijena30 && cijena29<PPCB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM)", cijena29);
			} else if (cijena30<cijena29 && cijena30<PPCB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM)", cijena30);
			} else {
				return 0;
			}
		}
	} else {
		float CCPR=CR*2+PR;
		float CCPF=CF*2+PF;
		float CCPB=CB*2+PB;
		if (CCPR<CCPB && CCPR<CCPF) {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", CCPR);
		} else if (CCPF<CCPR && CCPF<CCPB) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", CCPF);
			float cijena31=(CR*2*0.9)+PR;
			float cijena32=(PR*0.9)+CR*2;
			if (cijena31<cijena32 && cijena31<CCPF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena31);
			} else if (cijena32<cijena31 && cijena32<CCPF) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena32);
			} else {
				return 0;
			}
		} else {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", CCPB);
			float cijena33=(CR*2*0.9)+PR;
			float cijena34=(PR*0.9)+CR*2;
			if (cijena33<cijena34 && cijena33<CCPB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena33);
			} else if ( cijena34<cijena33 && cijena34<CCPB) {
				printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena34);
			} else {
				return 0;
			}
		}
	}
	return 0;
	}
