#include <stdio.h>

int main() {
	
	double IPT, IPB, IPM, IIPT, IIPB, IIPM, ZT, ZB, ZM, PrT, PrB, PrM, brojacP = 0, bodoviT, bodoviB, bodoviM, ocjenaT, ocjenaB, ocjenaM, ZIT, ZIB, ZIM;
	
	/*TARIK*/
	
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf", &IPT);
	if(IPT < 0 ||IPT > 20) { printf("Neispravan broj bodova"); return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPT);
	if (IIPT < 0 ||IIPT > 20) { printf("Neispravan broj bodova"); return 0; }
	printf("Prisustvo: ");
	scanf("%lf", &PrT);
	if(PrT < 0 ||PrT > 10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zadace: ");
	scanf("%lf", &ZT);
	if(ZT < 0 ||ZT > 10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIT);
	if (ZIT < 0 ||ZIT > 40) { printf("Neispravan broj bodova"); return 0; }
	
	/*BOJAN*/
	
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf", &IPB);
	if (IPB < 0 || IPB > 20) { printf("Neispravan broj bodova"); return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPB);
	if (IIPT < 0 ||IIPT > 20) { printf("Neispravan broj bodova"); return 0; }
	printf("Prisustvo: ");
	scanf("%lf", &PrB);
	if (PrB < 0 ||PrB > 10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zadace: ");
	scanf("%lf", &ZB);
	if(ZB < 0 ||ZB > 10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIB);
	if(ZIB < 0 ||ZIB > 40) { printf("Neispravan broj bodova"); return 0; }
	
	/*MIRZA*/
	
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf", &IPM);
	if(IPM < 0 || IPM > 20) { printf("Neispravan broj bodova"); return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPM);
	if(IIPT < 0 || IIPT > 20) { printf("Neispravan broj bodova"); return 0; }
	printf("Prisustvo: ");
	scanf("%lf", &PrM);
	if (PrM < 0 || PrM > 10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zadace: ");
	scanf("%lf", &ZM);
	if (ZB < 0 || ZB > 10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIM);
	if (ZIB < 0 || ZIB > 40) { printf("Neispravan broj bodova"); return 0; }

	
	bodoviT = IPT + IIPT + PrT + ZT + ZIT; 
	bodoviB = IPB + IIPB + PrB + ZB + ZIB;
	bodoviM = IPM + IIPM + PrM + ZM + ZIM;
	
	if(bodoviT >= 55 && bodoviT < 65)  ocjenaT = 6;
	if(bodoviT >= 65 && bodoviT < 75)  ocjenaT = 7;
	if(bodoviT >= 75 && bodoviT< 85)  ocjenaT = 8;
	if(bodoviT >= 85 && bodoviT < 92)  ocjenaT = 9;
	if(bodoviT >= 92 && bodoviT <= 100)  ocjenaT = 10;
	
	if(bodoviB >= 55 && bodoviB < 65)  ocjenaB = 6;
	if(bodoviB >= 65 && bodoviB < 75)  ocjenaB = 7;
	if(bodoviB >= 75 && bodoviB < 85)  ocjenaB = 8;
	if(bodoviB >= 85 && bodoviB < 92)  ocjenaB = 9;
	if(bodoviB >= 92 && bodoviB <= 100)  ocjenaB = 10;
	
	if(bodoviM >= 55 && bodoviM < 65)  ocjenaM = 6;
	if(bodoviM >= 65 && bodoviM < 75)  ocjenaM = 7;
	if(bodoviM >= 75 && bodoviM < 85)  ocjenaM = 8;
	if(bodoviM >= 85 && bodoviM < 92)  ocjenaM = 9;
	if(bodoviM >= 92 && bodoviM <= 100)  ocjenaM = 10;
	
	
	if(bodoviT >= 55) brojacP++;
	if(bodoviB >= 55) brojacP++;
	if(bodoviM >= 55) brojacP++;
	
	if(brojacP == 0) printf("Nijedan student nije polozio.");
	if(brojacP == 1) printf("Jedan student je polozio.");
	if(brojacP == 2) printf("Dva studenta su polozila.");
	if(brojacP == 3) printf("Sva tri studenta su polozila.");
	
	if(brojacP == 3) {
	if((ocjenaT == ocjenaB) && (ocjenaT == ocjenaM) && (ocjenaB == ocjenaM)) { printf("\nSva tri studenta imaju istu ocjenu."); return 0; }
	if((ocjenaT != ocjenaB) && (ocjenaT != ocjenaM) && (ocjenaB != ocjenaM)) { printf("\nSvaki student ima razlicitu ocjenu."); return 0; }
		 else printf("\nDva od tri studenta imaju istu ocjenu.");
	
	
	
	}
	
	return 0;
}
