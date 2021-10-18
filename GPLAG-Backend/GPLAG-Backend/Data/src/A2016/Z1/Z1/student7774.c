#include "stdio.h"

int main() {
	
	float TI, TII, TP, TZ, TZI, BI, BII, BP, BZ, BZI, MI, MII, MP, MZ, MZI, TU, BU, MU;
	int TO, BO, MO, temp;
	float eps = 0.0001;
	
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%g", &TI);
	
	if(TI<0 || TI>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%g", &TII);
	
	if(TII<0 || TII>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%g", &TP);
	
	if(TP<0 || TP>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%g", &TZ);
	
	if(TZ<0 || TZ>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%g", &TZI);
	
	if(TZI<0 || TZI>40){
		printf(" Neispravan broj bodova");
		return 0;
	}
	
    printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%g", &BI);
	
	if(BI<0 || BI>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%g", &BII);
	
		
	if(BII<0 || BII>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%g", &BP);
	
		
	if(BP<0 || BP>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%g", &BZ);
	
		
	if(BZ<0 || BZ>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%g", &BZI);
	
		
	if(BZI<0 || BZI>40){
		printf(" Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu: ");
	printf(" \nI parcijalni ispit: ");
	scanf("%g", &MI);
	
		
	if(MI<0 || MI>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%g", &MII);
	
		
	if(MII<0 || MII>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%g", &MP);
	
	if(MP<0 || MP>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%g", &MZ);
	
	if(MZ<0 || MZ>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%g", &MZI);
	
	if(MZI<0 || MZI>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	TU=TI+TII+TP+TZ+TZI;
	
	BU=BI+BII+BP+BZ+BZI;
	
	MU=MI+MII+MP+MZ+MZI;
	
	
	if(TU<55-eps && BU<55-eps && MU<55-eps) {
		printf("Nijedan student nije polozio.");
		return 0;
		
	} else 	if(TU>=55-eps && BU<55-eps && MU<55-eps) {
		printf("Jedan student je polozio.");
		
	} else 	if(TU<55-eps && BU>=55-eps && MU<55-eps) {
		printf("Jedan student je polozio.");
		
	} else 	if(TU<55-eps && BU<55-eps && MU>=55-eps) {
		printf("Jedan student je polozio.");
	
	} else 	if(TU>=55-eps && BU>=55-eps && MU<55-eps) {
		printf("Dva studenta su polozila.");
		
	} else 	if(TU<55-eps && BU>=55-eps && MU>=55-eps) {
		printf("Dva studenta su polozila.");
		
	} else 	if(TU>=55-eps && BU>=55-eps && MU>=55-eps) {
		printf("Sva tri studenta su polozila.");
	}	
		
		
		
		
	if (TU<55) {
		TO=5;
		
	} else if (TU>=55 && TU<65) {
        TO=6;
        
	} else if (TU>=65 && TU<75) {
		TO=7;
		
	} else if (TU>=75 && TU<85) {
		TO=8;
		
	} else if (TU>=85 && TU<92){
		TO=9;
		
	} else if(TU>=92 && TU<100){
		TO=10;
		
	}
	
	if (BU<55){
		BO=5;
		
	} else if (BU>=55 && BU<65){
		BO=6;
		
	} else if (BU>=65 && BU<75){
		BO=7;
		
	} else if (BU>=75 && BU<85){
		BO=8;
		
	} else if (BU>=85 && BU<92){
		BO=9;
		
	} else if (BU>=92 && BU<100){
		BO=10;
	}
	
	if (MU<55){
		MO=5;
		
	} else if (MU>=55 && MU<65){
	    MO=6;
	    
	} else if (MU>=65 && MU<75){
		MO=7;
		
	} else if (MU>=75 && MU<85){
		MO=8;
		
	} else if (MU>=85 && MU<92){
		MO=9;
		
	} else if(MU>=92 && MU<100){
		MO=10;
	}
		
	if(TO>BO) {
		
		temp=TO;
		TO=BO;
		BO=temp ;
	}
	if(BO>MO) {
		
		temp=BO;
		BO=MO;
		MO=temp;
	}
	if(TO>BO) {
		
		temp=TO;
		TO=BO;
		BO=temp;
	}  
	
	 if (TO>5 && BO>5 && MO>5) {
		
		if ((TO!=BO) && (BO!=MO)) {
			printf("\nSvaki student ima razlicitu ocjenu.");
			
		} 	else if (((TO==BO) && (BO!=MO)) || ((TO!=BO) && (BO==MO))) {
			printf("\nDva od tri studenta imaju istu ocjenu.");
		
		} 	else if (TO==MO && MO==BO) {
			printf("\nSva tri studenta imaju istu ocjenu.");
        }
	    
	  }
	
	return 0;
}
