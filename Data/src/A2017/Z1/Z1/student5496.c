#include <stdio.h>
#define RestoranP 6.8
#define RestoranH 3.3
#define RestoranC 5.0
#define FastfoodP 8.0
#define FastfoodH 3.0
#define FastfoodC 3.9
#define BistroP   5.3
#define BistroH   5.0
#define BistroC   6.0
int main() {
	char T, B, M, novi_red;
	float cijenaR, cijenaF, cijenaB, cijenapopust;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c", &novi_red);
	 
	if(T==B && B==M){
		if(T=='P') {cijenaR=3*RestoranP; cijenaF=3*FastfoodP; cijenaB=3*BistroP;}
		if(T=='H') {cijenaR=3*RestoranH; cijenaF=3*FastfoodH; cijenaB=3*BistroH;}
		if(T=='C') {cijenaR=3*RestoranC; cijenaF=3*FastfoodC; cijenaB=3*BistroC;}
	}
	if((T==B && B!=M) || (T==M && M!=B) || (B==M && M!=T)){
		if((T=='P' && M=='C')||(T=='P' && B=='C')||(B=='P' && T=='C')){ 
			cijenaR=2*RestoranP+RestoranC; cijenaF=2*FastfoodP+FastfoodC; cijenaB=2*BistroP+BistroC;
		}
		if((T=='P' && M=='H')||(T=='P' && B=='H')||(B=='P' && T=='H')){
			cijenaR=2*RestoranP+RestoranH; cijenaF=2*FastfoodP+FastfoodH; cijenaB=2*BistroP+BistroH;
		}
		if((T=='H' && M=='P')||(T=='H' && B=='P')||(B=='H' && T=='P')){ 
			cijenaR=2*RestoranH+RestoranP; cijenaF=2*FastfoodH+FastfoodP; cijenaB=2*BistroH+BistroP;
		}
		if((T=='H' && M=='C')||(T=='H' && B=='C')||(B=='H' && T=='C')){ 
			cijenaR=2*RestoranH+RestoranC; cijenaF=2*FastfoodH+FastfoodC; cijenaB=2*BistroH+BistroC;
		}
		if((T=='C' && M=='P')||(T=='C' && B=='P')||(B=='C' && T=='P')){ 
			cijenaR=2*RestoranC+RestoranP; cijenaF=2*FastfoodC+FastfoodP; cijenaB=2*BistroC+BistroP;
		}
		if((T=='C' && M=='H')||(T=='C' && B=='P')) { 
			cijenaR=2*RestoranC+RestoranH; cijenaF=2*FastfoodC+FastfoodH; cijenaB=2*BistroC+BistroH;
		}
	}
	if(T!=B && B!=M && T!=M){
		cijenaR=RestoranH+RestoranC+RestoranP;
		cijenaF=FastfoodH+FastfoodC+FastfoodP;
		cijenaB=BistroH+BistroC+BistroP;
	}
	
	/*Najjeftinije mjesto*/
	if(cijenaR<cijenaB && cijenaR<cijenaF){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cijenaR);
	}
	else if(cijenaB<cijenaR && cijenaB<cijenaF){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cijenaB);
	}
	else if(cijenaF<cijenaR && cijenaF<cijenaB){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cijenaF);
	}
	return 0;
}
