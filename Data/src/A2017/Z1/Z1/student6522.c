#include <stdio.h>
#define RP 6.80
#define FP 8.00
#define BP 5.30
#define RH 3.30
#define FH 3.00
#define BH 5.00
#define RC 5.00
#define FC 3.90
#define BC 6.00

int main() {
	char T,B,M,nr;
	float SR=0; float SF=0; float SB=0; float S4=0; float S5=0; float S6=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &nr);
	if(T=='H'){
		SR=SR+RH;
		SF=SF+FH;
		SB=SB+BH;
		S5=S5+RH*0.9;
		S6=S6+RH;
		S4=S4+RH;
		
	}
	else if(T=='P'){
		SB=SB+BP;
		SF=SF+FP;
		SR=SR+RP;
		S4=S4+RP*0.9;
		S5=S5+RP;
		S6=S6+RP;
	}
	else if(T=='C'){
		SR=SR+RC;
		SB=SB+BC;
		SF=SF+FC;
		S6=S6+RC*0.9;
		S5=S5+RC;
		S4=S4+RC;
	}
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &nr);
	if(B=='H'){
		SR=SR+RH;
		SF=SF+FH;
		SB=SB+BH;
		S4=S4+RH;
		S5=S5+RH*0.9;
		S6=S6+RH;
	}
	else if(B=='P'){
		SR=SR+RP;
		SF=SF+FP;
		SB=SB+BP;
		S4=S4+RP*0.9;
		S5=S5+RP;
		S6=S6+RP;
	}
	else if(B=='C'){
		SR=SR+RC;
		SF=SF+FC;
		SB=SB+BC;
		S4=S4+RC;
		S5=S5+RC;
		S6=S6+RC*0.9;
	}
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	if(M=='P'){
		SR=SR+RP;
		SF=SF+FP;
		SB=SB+BP;
		S4=S4+RP*0.9;
		S5=S5+RP;
		S6=S6+RP;
		}
	else if(M=='C'){
		SR=SR+RC;
		SF=SF+FC;
		SB=SB+BC;
		S4=S4+RC;
		S5=S5+RC;
		S6=S6+RC*0.9;
	}	
	else if(M=='H'){
		SR=SR+RH;
		SF=SF+FH;
		SB=SB+BH;
		S4=S4+RH;
		S5=S5+RH*0.9;
		S6=S6+RH;
	}
	if((SR<SB) && (SR<SF))
		 printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", SR);
	else if((SB<SR) && (SB<SF)){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", SB);
		if((S5<S4) &&(S5<S6)){
		if((S5<SB) && (S5<SF)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", S5);}
		else if((S6<S4) &&(S6<S5)){
		if((S6<SB) && (S6<SF)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", S6);}
		else if((S4<S5) &&(S4<S6)){
		if((S4<SB) && (S4<SF)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", S4);}
		
	}
	else if((SF<SB) && (SF<SR)){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", SF);
			if((S5<S4) &&(S5<S6)){
		if((S5<SB) && (S5<SF)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", S5);}
		else if((S6<S4) &&(S6<S5)){
		if((S6<SB) && (S6<SF)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", S6);}
		else if((S4<S5) &&(S4<S6)){
		if((S4<SB) && (S4<SF)) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", S4);}
	}
	
	return 0;
}
