#include <stdio.h>

int main() {
	char T,B,M,novi_red;
	float PR=6.80,PF=8.00,PB=5.30,HR=3.30,HF=3.00,HB=5.00,CR=5.00,CF=3.90,CB=6.00,U1,U2,U3,min;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&T);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&B);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&M);
	scanf("%c",&novi_red);
	if(T=='H' && B=='H' && M=='H'){
		U1=3*HR;
		U2=3*HF;
		U3=3*HB;
	    min=U1-(U1/10); 
	    if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		}
	else if(T=='P' && B=='P' && M=='P'){
		U1=3*PR;
		U2=3*PF;
		U3=3*PB;
		min=U1-(U1/10);
	 if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		}
	else if(T=='C' && B=='C' && M=='C'){
		U1=3*CR;
		U2=3*CF;
		U3=3*CB;
		min=U1-(U1/10);
	     if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		}
	else if((T=='H' && B=='P' && M=='C') || (T=='C' && B=='H' && M=='P') || (T=='H' && B=='C' && M=='P') || (T=='P' && B=='C' && M=='H') || (T=='C' && B=='P' && M=='H') || (T=='P' && B=='H' && M=='C')){
		U1=HR+PR+CR;
		U2=HF+PF+CF;
		U3=HB+PB+CB;
		min=PR*0.9+HR+CR;
	 if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
	}
	else if((T=='H' && B=='H' && M=='P') || (T=='H' && B=='P' && M=='H') || (T=='P' && B=='H' && M=='H')){
		U1=2*HR+PR;
		U2=2*HF+PF;
		U3=2*HB+PB;
		min=2*HR+PR*0.9;
	 if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
	}
	
	else if((T=='P' && B=='P' && M=='H') || (T=='P' && B=='H' && M=='P') || (T=='H' && B=='P' && M=='P')){
		U1=2*PR+HR;
		U2=2*PF+HF;
		U3=2*PB+HB;
		min=2*(PR*0.9)+HR;
	     if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		}
    else if((T=='H' && B=='H' && M=='C') || (T=='H' && M=='C' && B=='H') || (T=='C' && B=='H' && M=='H'))
    {
    	U1=2*HR+CR;
    	U2=2*HF+CF;
    	U3=2*HB+CB;
    	min=2*HR+CR*0.9;
     if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
    }
    else if((T=='C' && B=='C' && M=='H') || (T=='C' && B=='H' && M=='C') || (T=='H' && B=='C' && M=='C')){
    	U1=2*CR+HR;
    	U2=2*CF+HF;
    	U3=2*CB+HB;
    	min=2*(CR*0.9)+HR;
 if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
    }
    else if((T=='P' && B=='P' && M=='C') || (T=='P' && B=='C' && M=='P') || (T=='C' && B=='P' && M=='P')){
    	U1=2*PR+CR;
    	U2=2*PF+CF;
    	U3=2*PB+CB;
    	min=2*(PR*0.9)+CR;
    	 if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
    }
    else if((T=='C' && B=='C' && M=='P') || (T=='C' && B=='P' && M=='C') || (T=='P' && B=='C' && M=='C')){
    	U1=2*CR+PR;
    	U2=2*CF+PF;
    	U3=2*CB+PB;
    	min=2*CR+PR*0.9;
    	 if(U1<U2 && U1<U3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",U1);
		if(U2<U1 && U2<U3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",U2);
		if(min<U2 && U2<U1 && U2<U3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		if(U3<U2 && U3<U1 ) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",U3);
		if(min<U3 && U3<U2 && U3<U2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
    }
		
	return 0;
}
