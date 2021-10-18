#include <stdio.h>


int main() {
	double I1,I2,I3,I4,I5,I6,P1,P2,P3,ZAD1,ZAD2,ZAD3,ZI1,ZI2,ZI3,ZT,ZM,ZB;
	int OCT,OCB,OCM;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&I1);
   if(I1<0||I1>20)  { printf("Neispravan broj bodova "); return 0; }
   
	printf("II parcijalni ispit: ");
	scanf("%lf",&I2);
    if(I2<0||I2>20) { printf("Neispravan broj bodova "); return 0; }
	
	printf("Prisustvo: ");
	scanf("%lf",&P1);
    if(P1<0||P1>10) { printf("Neispravan broj bodova "); return 0; }
	
	printf("Zadace: ");
	scanf("%lf",&ZAD1);
   if(ZAD1<0||ZAD1>10) {printf("Neispravan broj bodova "); return 0; }
   
	printf("Zavrsni ispit: ");
	scanf("%lf",&ZI1);
    if(ZI1<0||ZI1>40) { printf("Neispravan broj bodova "); return 0; }
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&I3);
    if(I3<0||I3>20) { printf("Neispravan broj bodova "); return 0;  }
	
	printf("II parcijalni ispit: ");
	scanf("%lf",&I4);
    if(I4<0||I4>20) {printf("Neispravan broj bodova "); return 0; }
    
	printf("Prisustvo: ");
	scanf("%lf",&P2);
    if(P2<0||P2>10) { printf("Neispravan broj bodova "); return 0; }
    
	printf("Zadace: ");
	scanf("%lf",&ZAD2);
   if(ZAD2<0||ZAD2>10) { printf("Neispravan broj bodova "); return 0; }
   
	printf("Zavrsni ispit: ");
	scanf("%lf",&ZI2);
    if(ZI2<0||ZI2>40) {printf("Neispravan broj bodova "); return 0; }
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&I5);
    if(I5<0||I5>20) {printf("Neispravan broj bodova "); return 0; }

	printf("II parcijalni ispit: ");
	scanf("%lf",&I6);
	if(I6<0||I6>20) {printf("Neispravan broj bodova "); return 0; }
	
	printf("Prisustvo: ");
	scanf("%lf",&P3);
    if(P3<0||P3>10) {printf("Neispravan broj bodova "); return 0; }

	printf("Zadace: ");
	scanf("%lf",&ZAD3);
    if(ZAD3<0||ZAD3>10) { printf("Neispravan broj bodova "); return 0; }
  
	printf("Zavrsni ispit: ");
	scanf("%lf",&ZI3);
	if(ZI3<0||ZI3>40) {printf("Neispravan broj bodova "); return 0; }

   
	ZT=I1+I2+P1+ZAD1+ZI1; 
	ZB=I3+I4+P2+ZAD2+ZI2; 
	ZM=I5+I6+P3+ZAD3+ZI3; 
	
	
	
	
	  if(ZT<55) {
		OCT=5;
	}
	else if(ZT>=55 && ZT<=65) {
		OCT=6;
	}
	else if(ZT>=65 && ZT<=75) {
		OCT=7;
	}
		else if(ZT>=75 && ZT<=85) {
		OCT=8;
		}
	else if(ZT>=85 && ZT<=92) {
	    OCT=9;
	}
	else if(ZT>=92 && ZT<=100) {
		OCT=10;
	}
	if(ZB<55) {
		OCB=5;
	}
	else if(ZB>=55 && ZB<=65) {
		OCB=6;
	}
	else if(ZB>=65 && ZB<=75) {
		OCB=7;
	}
		else if(ZB>=75 && ZB<=85) {
			OCB=8;
		}
	else if(ZB>=85 && ZB<=92) {
		OCB=9;
	}
	else if(ZB>=92 && ZB<=100) {
		OCB=10;
	}
	if(ZM<55) {
		OCM=5;
	}
	else if(ZM>=55 && ZM<=65) {
		OCM=6;
	}
	else if(ZM>=65 && ZM<=75) {
		OCM=7;
	}
		else if(ZM>=75 && ZM<=85) {
			OCM=8;
		}
	else if(ZM>=85 && ZM<=92) {
		OCM=9;
	}
	else if(ZM>=92 && ZM<=100) {
	    OCM=10;
	}

	if(OCT<6 && OCB<6 && OCM<6) {
		printf("Nijedan student nije polozio. \n");
	}
	 else if(OCT>=6 && OCB<6 && OCM<6 || OCB>=6 && OCT<6 && OCM<6 || OCM>=6 && OCB<6 && OCT<6) {
		printf("Jedan student je polozio. \n");
	}
	 else if(OCT>=6 && OCB>=6 && OCM<6 || OCB>=6 && OCM>=6 && OCT<6 || OCM>=6 && OCB>=6 && OCT<6) {
		printf("Dva studenta su polozila. \n");
	}
	 if(OCT>=6 && OCB>=6 && OCM>=6) {
		printf("Sva tri studenta su polozila. \n");
	
	if(OCT==OCB&&OCM==OCT&&OCM==OCB) {
		printf("Sva tri studenta imaju istu ocjenu. \n");
		
	}
	else if(OCT==OCB && OCT!=OCM || OCT==OCM && OCT!=OCB ) {
		printf("Dva od tri studenta imaju istu ocjenu. \n");
	}
	else if(OCT!=OCB&&OCT!=OCM&&OCB!=OCM) {
		printf("Svaki student ima razlicitu ocjenu. \n");
	}
	}
    
		

	

	return 0;
}
