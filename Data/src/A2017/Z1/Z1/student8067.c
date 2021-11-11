#include <stdio.h>
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00

int main() {
	char tarik,bojan,mirza,novi_red;
	float PHC1,PPP1,HHH1,CCC1,PPH1,PPC1,HHP1,HHC1,CCP1,CCH1,PHC2,PPP2,HHH2,CCC2,PPH2,PPC2,HHP2,HHC2,CCP2,CCH2,PHC3,PPP3,HHH3,CCC3,PPH3,PPC3,HHP3,HHC3,CCP3,CCH3,najskuplji=0,PHC1p,PPP1p,HHH1p,CCC1p,PPH1p,PPC1p,HHP1p,HHC1p,CCP1p,CCH1p,najjeftiniji=0;
    float srednji=0,zadnji=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	
	/* kod konja i konjusara */
    PHC1=P1+H1+C1;
	PPP1=3*P1;
	HHH1=3*H1;
	CCC1=3*C1;
	PPH1=2*P1+H1;
	PPC1=2*P1+C1;
	HHP1=2*H1+P1;
	HHC1=2*H1+C1;
	CCP1=2*C1+P1;
	CCH1=2*C1+H1;
	
	/* trovac */
	PHC2=P2+H2+C2;
	PPP2=3*P2;
	HHH2=3*H2;
	CCC2=3*C2;
	PPH2=2*P2+C2;
	PPC2=2*P2+C2;
	HHP2=2*H2+P2;
	HHC2=2*H2+C2;
	CCP2=2*C2+P2;
	CCH2=2*C2+H2;
	
	/* bistro lorelei */
	PHC3=P3+H3+C3;
	PPP3=3*P3;
	HHH3=3*H3;
	CCC3=3*C3;
	PPH3=2*P3+H3;
	PPC3=2*P3+C3;
	HHP3=2*H3+P3;
	HHC3=2*H3+C2;
	CCP3=2*C3+P3;
	CCH3=2*C3+H3;
	
	 PHC1p=PHC1-(P1*0.1);
     PPP1p=3*P1-(3*P1*0.1);
	 HHH1p=3*H1-(3*H1*0.1);
	CCC1p=3*C1*3*C1*0.1;
	PPH1p=PPH1-(P1*0.1*2);
	PPC1p=2*P1+C1-2*C1*0.1;
	HHP1p=2*H1+P1-P1*0.1;
	HHC1p=2*H1+C1-H1*0.1;
	CCP1p=2*C1+P1-C1*0.1;
	CCH1p=2*C1+H1-C1*0.1;
	
	

	if(tarik=='P' && bojan=='P' && mirza=='P') {
			if(PPP1<PPP2 && PPP1<PPP3) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",PPP1); najjeftiniji==PPP1; }
			else if(PPP2<PPP1 && PPP2<PPP3) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",PPP2); najjeftiniji==PPP2; }
			else if(PPP3<PPP1 && PPP3<PPP2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",PPP3); najjeftiniji==PPP3; }
			else if(HHH1p<najjeftiniji)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",HHH1p);
		
	}
	
	else if(tarik=='H' && bojan=='H' && mirza=='H') {
		if(HHH1<HHH2 && HHH1<HHH3) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",HHH1); najjeftiniji==HHH1;}
        else if(HHH2<HHH1 && HHH2<HHH3) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",HHH2); najjeftiniji==HHH2;}
        else if(HHH3<HHH1 && HHH3<HHH2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",HHH3); najjeftiniji==HHH3;}
	}
	
	else if(tarik=='C' && bojan=='C' && mirza=='C') {
		if(CCC1<CCC2 && CCC1<CCC3) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",CCC1); najjeftiniji==CCC1;}
		else if(CCC2<CCC1 && CCC2<CCC3) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",CCC2); najjeftiniji==CCC2;}
		else if(CCC3<CCC1 && CCC3<CCC2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",CCC3); najjeftiniji==CCC3;}
	}
	
	else if((tarik=='P' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='H' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='H') ||  (tarik=='H' && bojan=='P' && mirza=='C')  ||  (tarik=='C' && bojan=='P' && mirza=='H') ) {
		if(PHC1<PHC2 && PHC1<PHC3) {printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",PHC1); najjeftiniji==PHC1;}
		else if(PHC2<PHC1 && PHC2<PHC3) {  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",PHC2);  najjeftiniji==PHC2;}
		else if(PHC3<PHC2 && PHC3<PHC1) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",PHC3); najjeftiniji==PHC3;}
	}
	else if((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P')) {
		if(PPH1<PPH2 && PPH1<PPH3) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",PPH1); najjeftiniji==PPH1;}
		else if(PPH2<PPH1 && PPH2<PPH3) {  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",PPH2); najjeftiniji==PPH2;}
		else if(PPH3<PPH1 && PPH3<PPH2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",PPH3); najjeftiniji==PPH3;}
		
	}
	else if((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')) {
		if(PPC1<PPC2 && PPC1<PPC3) { printf("Najjeftini je Restoran \"Kod konja i konjusara\" (%.2f KM).",PPC1); najjeftiniji==PPC1;}
		else if(PPC2<PPC1 && PPC2<PPC3) {  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",PPC2); najjeftiniji==PPC2;}
		else if(PPC3<PPC1 && PPC3<PPC2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",PPC3); najjeftiniji==PPC3; }
	}
	else if((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P')) {
		if(HHP1<HHP2 && HHP1<HHP3) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",HHP1); najjeftiniji==HHP1;}
		else if(HHP2<HHP1 && HHP2<HHP3) {  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",HHP2); najjeftiniji==HHP2;}
		else if(HHP3<HHP1 && HHP3<HHP2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",HHP3); najjeftiniji==HHP3;}
	}
    else if((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='C' && mirza=='H')) {
    	if(HHC1<HHC2 && HHC1<HHC3) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",HHC1); najjeftiniji==HHC1;}
		else if(HHC2<HHC1 && HHC2<HHC3) {  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",HHC2); najjeftiniji==HHC2;}
		else if(HHC3<HHC1 && HHC3<HHC2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",HHC3); najjeftiniji==HHC3;}
    }
	else if((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='C')) {
		if(CCP1<CCP2 && CCP1<CCP3) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",CCP1); najjeftiniji==CCP1;}
		else if(CCP2<CCP1 && CCP2<CCP3) {  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",CCP2); najjeftiniji==CCP2;}
		else if(CCP3<CCP1 && CCP3<CCP2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",CCP3); najjeftiniji==CCP3;}
	}
	else if((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='C')) {
			if(CCH1<CCH2 && CCH1<CCH3) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",CCH1); najjeftiniji==CCH1;}
		else if(CCH2<CCH1 && CCH2<CCH3) {  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",CCH2); najjeftiniji==CCH2;}
		else if(CCH3<CCH1 && CCH3<CCH2) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",CCH3); najjeftiniji==CCH3;}
	} 
	
	
	 
	 PHC1p=PHC1-(P1*0.1);
     PPP1p=3*P1-(3*P1*0.1);
	 HHH1p=3*H1-(3*H1*0.1);
	CCC1p=3*C1*3*C1*0.1;
	PPH1p=PPH1-(P1*0.1*2);
	PPC1p=2*P1+C1-2*C1*0.1;
	HHP1p=2*H1+P1-P1*0.1;
	HHC1p=2*H1+C1-H1*0.1;
	CCP1p=2*C1+P1-C1*0.1;
	CCH1p=2*C1+H1-C1*0.1;
	 	
	
	 if(tarik=='P' && bojan=='P' && mirza=='P' && PPP1>najjeftiniji && PPP1p<najjeftiniji) {
	 	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",PPP1p);
	 }
	 else if(tarik=='C' && bojan=='C' && mirza=='C' && CCC1>najjeftiniji && CCC1p<najjeftiniji) {
	 	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",CCC1p);
	 }
	 else if((tarik=='P' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='H' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='H') ||  (tarik=='H' && bojan=='P' && mirza=='C')  ||  (tarik=='C' && bojan=='P' && mirza=='H') && PHC1>najjeftiniji && PHC1p<najjeftiniji) {
	 	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",PHC1p);
	 }
	else if(((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P')) &&  PPH1p<najjeftiniji) {
		printf("%.2f",najjeftiniji);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",PPH1p);
	}
	else if((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')  || PPC1p<najjeftiniji) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",PPC1p);
	}
    else if((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') && (HHP1>najjeftiniji && HHP1p<najjeftiniji)) {
    	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",HHP1p);
    }
	

	return 0;
}

 
