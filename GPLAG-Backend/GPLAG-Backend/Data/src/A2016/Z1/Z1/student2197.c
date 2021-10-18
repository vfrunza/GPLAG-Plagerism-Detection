#include <stdio.h>

int main() {
double PPI1,PPI2,PPI3,DPI1,DPI2,DPI3,P1,P2,P3,Z1,Z2,Z3,ZI1,ZI2,ZI3,OT,OB,OM;
	/*PPI - I parcijalni ispit*/
	/*DRI - II parcijalni ispit*/
	/*P - Prisustvo*/
	/*Z - Zadace*/
	/*ZI - Zavrsni ispit*/
	/*OT - Ocjena Tarik*/
	/*OB - Ocjena Bojan*/
	/*OM - Ocjena Mirza*/
	
	/*Tarik*/
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &PPI1);
	if(PPI1<0 || PPI1>20) { printf("Neispravan broj bodova\n");
	return 0;}
	else { 
		printf("II parcijalni ispit: ");
	scanf("%lf", &DPI1); }
	if(DPI1<0 || DPI1>20) { printf("Neispravan broj bodova\n");
	return 0;}
	else { 
		printf("Prisustvo: ");
	scanf("%lf", &P1);}
	if(P1<0 || P1>10) { printf("Neispravan broj bodova\n");
	return 0;}
	else { 
		printf("Zadace: ");
	scanf("%lf", &Z1);}
	if(Z1<0 || Z1>10) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("Zavrsni ispit: ");
	scanf("%lf", &ZI1);}
	if(ZI1<0 || ZI1>40) { printf("Neispravan broj bodova\n");
	return 0;}
	
	/*Bojan*/
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &PPI2);
	if(PPI2<0 || PPI2>20) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("II parcijalni ispit: ");
	scanf("%lf", &DPI2);}
	if(DPI2<0 || DPI2>20) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("Prisustvo: ");
	scanf("%lf", &P2);}
	if(P2<0 || P2>10) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("Zadace: ");
	scanf("%lf", &Z2);}
	if(Z2<0 || Z2>10) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("Zavrsni ispit: ");
	scanf("%lf", &ZI2);}
	if(ZI2<0 || ZI2>40) { printf("Neispravan broj bodova\n");
	return 0;}
	
	/*Mirza*/
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &PPI3);
	if(PPI3<0 || PPI3>20) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("II parcijalni ispit: ");
	scanf("%lf", &DPI3);}
	if(DPI3<0 || DPI3>20) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("Prisustvo: ");
	scanf("%lf", &P3);}
	if(P3<0 || P3>10) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("Zadace: ");
	scanf("%lf", &Z3);}
	if(Z3<0 || Z3>10) { printf("Neispravan broj bodova\n");
	return 0;}
	else {
		printf("Zavrsni ispit: ");
	scanf("%lf", &ZI3);}
	if(ZI3<0 || ZI3>40) { printf("Neispravan broj bodova\n");
	return 0;}
	
	/*Ocjene*/

	if(PPI1+DPI1+P1+Z1+ZI1>=55 && PPI1+DPI1+P1+Z1+ZI1<65) { OT=6;
	} else if(PPI1+DPI1+P1+Z1+ZI1>=65 && PPI1+DPI1+P1+Z1+ZI1<75) { OT=7;
	} else if(PPI1+DPI1+P1+Z1+ZI1>=75 && PPI1+DPI1+P1+Z1+ZI1<85) { OT=8;
	} else if(PPI1+DPI1+P1+Z1+ZI1>=85 && PPI1+DPI1+P1+Z1+ZI1<92) { OT=9;
	} else if(PPI1+DPI1+P1+Z1+ZI1>=92 && PPI1+DPI1+P1+Z1+ZI1<=100) { OT=10;
	}
	if(PPI2+DPI2+P2+Z2+ZI2>=55 && PPI2+DPI2+P2+Z2+ZI2<65) { OB=6;
	} else if(PPI2+DPI2+P2+Z2+ZI2>=65 && PPI2+DPI2+P2+Z2+ZI2<75) { OB=7;
	} else if(PPI2+DPI2+P2+Z2+ZI2>=75 && PPI2+DPI2+P2+Z2+ZI2<85) { OB=8;
	} else if(PPI2+DPI2+P2+Z2+ZI2>=85 && PPI2+DPI2+P2+Z2+ZI2<92) { OB=9;
	} else if(PPI2+DPI2+P2+Z2+ZI2>=92 && PPI2+DPI2+P2+Z2+ZI2<=100) { OB=10;
	}
	
	if(PPI3+DPI3+P3+Z3+ZI3>=55 && PPI3+DPI3+P3+Z3+ZI3<65) { OM=6;
	} else if(PPI3+DPI3+P3+Z3+ZI3>=65 && PPI3+DPI3+P3+Z3+ZI3<75) { OM=7;
	} else if(PPI3+DPI3+P3+Z3+ZI3>=75 && PPI3+DPI3+P3+Z3+ZI3<85) { OM=8;
	} else if(PPI3+DPI3+P3+Z3+ZI3>=85 && PPI3+DPI3+P3+Z3+ZI3<92) { OM=9;
	} else if(PPI3+DPI3+P3+Z3+ZI3>=92 && PPI3+DPI3+P3+Z3+ZI3<=100) { OM=10;
	}
	
	/*Poruke ovisno o situaciji*/
	
	if(PPI1+DPI1+P1+Z1+ZI1<55 && PPI2+DPI2+P2+Z2+ZI2<55 && PPI3+DPI3+P3+Z3+ZI3<55) printf("Nijedan student nije polozio.\n");
	else if((PPI1+DPI1+P1+Z1+ZI1<55 && PPI2+DPI2+P2+Z2+ZI2<55 && PPI3+DPI3+P3+Z3+ZI3>=55) || (PPI1+DPI1+P1+Z1+ZI1>=55 && PPI2+DPI2+P2+Z2+ZI2<55 && PPI3+DPI3+P3+Z3+ZI3<55) || (PPI1+DPI1+P1+Z1+ZI1<55 && PPI2+DPI2+P2+Z2+ZI2>=55 && PPI3+DPI3+P3+Z3+ZI3<55))
	printf("Jedan student je polozio.\n");
	else if((PPI1+DPI1+P1+Z1+ZI1<55 && PPI2+DPI2+P2+Z2+ZI2>=55 && PPI3+DPI3+P3+Z3+ZI3>=55) || (PPI1+DPI1+P1+Z1+ZI1>=55 && PPI2+DPI2+P2+Z2+ZI2<55 && PPI3+DPI3+P3+Z3+ZI3>=55) || (PPI1+DPI1+P1+Z1+ZI1>=55 && PPI2+DPI2+P2+Z2+ZI2>=55 && PPI3+DPI3+P3+Z3+ZI3<55))
	printf("Dva studenta su polozila.\n");
	else if((PPI1+DPI1+P1+Z1+ZI1>=55 && PPI2+DPI2+P2+Z2+ZI2>=55 && PPI3+DPI3+P3+Z3+ZI3>=55)) printf("Sva tri studenta su polozila.\n");
	
	/*Poruke ako su sva tri studenta polozila*/
	
	if(PPI1+DPI1+P1+Z1+ZI1>=55 && PPI2+DPI2+P2+Z2+ZI2>=55 && PPI3+DPI3+P3+Z3+ZI3>=55) {if(OT==OB && OB==OM) {
		printf("Sva tri studenta imaju istu ocjenu.\n");
	}
	else if((OT==OB && OT!=OM) || (OB==OM && OB!=OT) || (OT==OM && OM!=OB)) {
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	else if((OT!=OB && OT!=OM && OB!=OM)) {
		printf("Svaki student ima razlicitu ocjenu.\n");
		}
		return 0;
}}
