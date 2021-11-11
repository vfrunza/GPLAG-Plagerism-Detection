#include <stdio.h>
#define cp1 6.80 /*Restoran "Kod konja i konjusara", Pizza*/ 
#define ch1 3.30 /*Restoran "Kod konja i konjusara", Hamburger*/ 
#define cc1 5.00 /*Restoran "Kod konja i konjusara", Cevapi*/ 
#define cp2 8.00 /*Fast food "Trovac", Pizza*/
#define ch2 3.00 /*Fast food "Trovac", Hamburger*/
#define cc2 3.90 /*Fast food "Trovac", Cevapi*/
#define cp3 5.30 /*Bistro "Lorelei", Pizza*/
#define ch3 5.00 /*Bistro "Lorelei", Hamburger*/
#define cc3 6.00 /*Bistro "Lorelei", Cevapi*/

int main() {
    int P=0, H=0, C=0;
    float cijena1,cijena2,cijena3,cpp,chp,ccp,ucijena1,ucijena2,ucijena3,mincijena,minucijena;
    char T,B,M,novi_red;
    printf ("Unesite jelo za Tarika: ");
    scanf ("%c", &T);
    scanf ("%c",&novi_red);
    printf ("Unesite jelo za Bojana: ");
    scanf ("%c", &B);
    scanf ("%c",&novi_red);
    printf ("Unesite jelo za Mirzu: ");
    scanf ("%c", &M);
    scanf ("%c",&novi_red);
    if (T=='P') P++;
    if (T=='H') H++;
    if (T=='C') C++;
    if (B=='P') P++;
    if (B=='H') H++;
    if (B=='C') C++;
    if (M=='P') P++;
    if (M=='H') H++;
    if (M=='C') C++;
    cijena1=cp1*P+ch1*H+cc1*C;
    cijena2=cp2*P+ch2*H+cc2*C;
    cijena3=cp3*P+ch3*H+cc3*C;
    
     if (cijena1<cijena2)	{ 
    	if (cijena1<cijena3) {
    		mincijena=cijena1;
    		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena1);
    	}
    	else {
    		mincijena=cijena3;
    		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena3);
    	}
    }
    else {
    	if (cijena2<cijena3) {
    		mincijena=cijena2;
    		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena2);
    	}
    	else {
    		mincijena=cijena3;
    		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena3);
    	}
    }
    
    cpp=cp1*10/100;
    chp=ch1*10/100;
    ccp=cc1*10/100;
    
    ucijena1=cijena1-cpp*P;
    ucijena2=cijena1-chp*H;
    ucijena3=cijena1-ccp*C; 
    
    if (ucijena1<ucijena2)	{ 
    	if (ucijena1<ucijena3) {
    		minucijena=ucijena1;
    	}
    	else {
    		minucijena=ucijena3;
    	}
    }
    else {
    	if (ucijena2<ucijena3) {
    		minucijena=ucijena2;
    	}
    	else {
    		minucijena=ucijena3;
    	}
    }
    
    
    if (mincijena==cijena1) return 0;
    else {
        if (minucijena<mincijena) {
            printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",minucijena); }
            
        }
    
    
	return 0;
}
