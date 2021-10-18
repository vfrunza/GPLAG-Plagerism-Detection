#include <stdio.h>

int main() {
    char T,B,M;
    float NC,NC1,NC2,NC3,m;
    float PR=6.80,HR=3.30,CR=5.00;
    float PFF=8.00,HFF=3.00,CFF=3.90;
    float PB=5.30,HB=5.00,CB=6.00;

    
	printf("Unesite jelo za Tarika: ");
	scanf("\n%c", &T);
	printf("Unesite jelo za Bojana: ");
	scanf("\n%c", &B);
	printf("Unesite jelo za Mirzu: ");
	scanf("\n%c", &M);
	
	/* Tri hamburgera */
	if(T=='H' && B=='H' && M=='H'){
	    NC1=3*HFF;
	    NC2=3*HR;
	    NC3=3*HB;
	    m=NC1;
	    if(NC2<m && NC2<NC3){ m=NC2; }
	    else if(NC3<m){ m=NC3; }
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", m);
	    NC=3*(HR-(10*HR)/100);
	    if(NC<m){
	        printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
	    }
	/* Tri pice */
	} else if(T=='P' && B=='P' && M=='P'){
	    NC1=3*PB;
	    NC2=3*PFF;
	    NC3=3*PB;
	    m=NC1;
	    if(NC2<m && NC2<NC3){ m=NC2; }
	    else if(NC3<m) { m=NC3; }
	    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", m);
	    NC=3*(PR-(10*PR)/100);
	    if(NC<m){
	        printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM)", NC1);
	    }
	/* Tri porcije cevapa */
	} else if(T=='C' && B=='C' && M=='C'){
	    NC1=3*CFF;
	    NC2=3*CB;
	    NC3=3*CR;
	    m=NC1;
	    if(NC2<m && NC2<NC3){ m=NC2; }
	    else if(NC3<m) { m=NC3; }
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", m);
	    NC=3*(CR-(10*CR)/100);
	    if(NC<m){ 
	        printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
	    }
	/* Svi jedu razlicito */
	} else if(T!=B && B!=M && M!=T){
	    NC1=PFF+HFF+CFF;
	    NC2=PB+HB+CB;
	    NC3=PR+HR+CR;
	    m=NC1;
	    if(NC2<m && NC2<NC3) { m=NC2; }
	    else if(NC3<m) { m=NC3; }
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", m);
	    NC=(PR-(10*PR)/100)+HR+CR;
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
	/* Dvije pice, jedan hamburger */
	} else if((T=='P' && (B==T || M==T) && (B=='H' || M=='H')) || (B=='P' && M=='P' && T=='H')){
		NC1=2*PR+HR;
		NC2=2*PFF+HFF;
		NC3=2*PB+HB;
		NC=2*(PR-(10*PR)/100)+HR;
		if(NC2<NC1 && NC2<NC3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", NC2);
		} else if(NC3<NC2 && NC3<NC1){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", NC3);
		}
		if(NC<NC2 && NC<NC3){
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
		}
	/* Dvije pice, jedna porcija cevapa */
	} else if((T=='P' && (B==T || M==T) && (B=='C' || M=='C')) || (B=='P' && M=='P' && T=='C')){
		NC1=2*PR+CR;
		NC2=2*PFF+CFF;
		NC3=2*PB+CB;
		NC=2*(PR-(10*PR)/100)+CR;
		if(NC2<NC1 && NC2<NC3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", NC2);
		} else if(NC3<NC1 && NC3<NC2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", NC3);
		}
		if(NC<NC2 && NC<NC3){
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
		}
	/* Dva Hamburgera, jedna pica */
	} else if((T=='H' && (B==T || M==T) && (B=='P' || M=='P')) || (T=='P' && B=='H' && M=='H')){
		NC1=2*HR+PR;
		NC2=2*HFF+PFF;
		NC3=2*HB+PB;
		NC=2*(HR-(10*HR)/100)+PR;
		if(NC2<NC1 && NC3<NC1){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", NC2);
		} else if(NC3<NC1 && NC3<NC2){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", NC3);
		} else {
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", NC1);
		} 
		if(NC1>NC2 || NC1>NC3){
		if(NC<NC2 && NC<NC3){
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
		}}
	/* Dva hamburgera, jedna porcija cevapa */
	} else if((T=='H' && (B==T || M==T) && (B=='C' || M=='C')) || (T=='C' && B=='H' && M=='H')){
		NC1=2*HR+CR;
		NC2=2*HFF+CFF;
		NC3=2*HB+CB;
		NC=2*(HR-(10*HR)/100)+CR;
		if(NC2<NC3 && NC2<NC1){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", NC2);
		} else if(NC3<NC2 && NC3<NC1){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", NC3);
		}
		if(NC<NC2 && NC<NC3){
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
		}
	/* Dvije porcije cevapa, jedan hamburger */
	} else if((T=='C' && (B==T || M==T) && (B=='H' || M=='H')) || (T=='H' && B=='C' && M=='C')){
		NC1=2*CR+HR;
		NC2=2*CFF+HFF;
		NC3=2*CB+HB;
		NC=2*(CR-(10*CR)/100)+HR;
		if(NC2<NC3 && NC2<NC1){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", NC2);
		} else if(NC3<NC2 && NC3<NC1){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", NC3);
		}
		if(NC<NC2 && NC<NC3){
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
		}
	/* Dvije porcije cevapa, jedna pica */
	} else if((T=='C' && B=='C' && M=='P') || (T=='P' && B=='C' && M=='C') || (T=='C' && B=='P' && M=='C')){
		NC1=2*CR+PR;
		NC2=2*CFF+PFF;
		NC3=2*CB+PB;
		NC=2*(CR-(10*CR)/100)+PR;
		if(NC2<NC1 && NC2<NC3){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", NC2);
		} else if(NC3<NC2 && NC3<NC1){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", NC3);
		} 
		if(NC<NC2 && NC<NC3){
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", NC);
		}
	}
	return 0;
}
