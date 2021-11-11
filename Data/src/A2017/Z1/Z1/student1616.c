#include <stdio.h>
#define RP 6.80
#define RH 3.30
#define RC 5.0
#define FP 8.0
#define FH 3.0
#define FC 3.9
#define BP 5.30
#define BH 5.0
#define BC 6.0
int main() {
	int sum_znakova;
	char tarik, bojan, mirza, novi_red, znak = '"';
	float sum1, sum2, sum3;
	printf("Unesite jelo za Tarika: "); 
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: "); 
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: "); 
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	sum_znakova = tarik + bojan + mirza;
	if( sum_znakova == 201 ) {
		sum1 = 3 * RC ;
		sum2 = 3 * FC;
		sum3 = 3 * BC;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
        if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 = sum1 - sum1 * 0.1;
        	if( sum2 <= sum1 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else if( sum1 < sum2 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if(sum3 < sum1 && sum3 < sum2) {
        	sum1 = sum1 - sum1 * 0.1;
        	if(sum3 <= sum1) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else if( sum1 < sum3 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
        }
	}
	if( sum_znakova == 216 ) {
		sum1 = 3 * RH;
		sum2 = 3 * FH;
		sum3 = 3 * BH;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 = sum1 - sum1 * 0.1;
        	if( sum2 <= sum1 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else if( sum1 < sum2 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if(sum3 < sum1 && sum3 < sum2) {
        	sum1 = sum1 - sum1 * 0.1;
        	if( sum3 <= sum1 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else if( sum1 < sum3 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
	    }
	}
	if( sum_znakova == 240 ) {
		sum1 = 3 * RP;
		sum2 = 3 * FP;
		sum3 = 3 * BP;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 = sum1 - sum1 * 0.1;
        	if( sum2 <= sum1 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else if( sum1 < sum2 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        } 
        if(sum3 < sum1 && sum3 < sum2) {
        	sum1 = sum1 - sum1 * 0.1;
        	if( sum3 <= sum1 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else if( sum1 < sum3 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
        
	    }
	}
	if( sum_znakova == 206 ) {
		sum1 = 2 * RC + RH;
		sum2 = 2 * FC + FH;
		sum3 = 2 * BC + BH;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 = 2 * RC - 2 * RC * 0.1 + RH;
        	if( sum2 <= sum1 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else if( sum1 < sum2 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if(sum3 < sum1 && sum3 < sum2) {
        	sum1 = 2 * RC - 2 * RC * 0.1 + RH;
        	if(sum3 <= sum1) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else if( sum1 < sum3 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
        
	    }
	} 
	if(sum_znakova == 214) { 
		sum1 = 2 * RC + RP;
		sum2 = 2 * FC + FP;
		sum3 = 2 * BC + BP;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 = 2 * RC - 2 * RC * 0.1 + RP;
        	if(sum2 <= sum1) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else if(sum1 < sum2) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if(sum3 < sum1 && sum3 < sum2) {
        	sum1 = 2 * RC - 2 * RC * 0.1 + RP;
        	if(sum3 <= sum1) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else if( sum1 < sum3 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
        
	    }
	}
	if(sum_znakova == 211) {
		sum1 = 2 * RH + RC;
		sum2 = 2 * FH + FC;
		sum3 = 2 * BH + BC;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 =  2 * RH - 2 * RH * 0.1 + RC;
        	if( sum2 <= sum1 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else if( sum1 < sum2 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if( sum3 < sum1 && sum3 < sum2 ) {
        	sum1 =  2 * RH - 2 * RH * 0.1 + RC;
        	if( sum3 <= sum1 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else if( sum1 < sum3 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
	    }
	}
	if ( sum_znakova == 224 ) {
		sum1 = 2 * RH + RP;
		sum2 = 2 * FH + FP;
		sum3 = 2 * BH + BP;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 =  RP - RP * 0.1 + 2 * RH;
        	if( sum2 <= sum1 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else if( sum1 < sum2 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if(sum3 < sum1 && sum3 < sum2) {
        	sum1 =  RP - RP * 0.1 + 2 * RH;
        	if( sum3 <= sum1 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else if( sum1 < sum3 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
        
	    }
	}
	if( sum_znakova == 232 ) { 
		sum1 = 2 * RP + RH;
		sum2 = 2 * FP + FH;
		sum3 = 2 * BP + BH;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 = ( (2 * RP) - (2 * RP * 0.1) + RH );
        	if(sum2 < sum1) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if(sum3 < sum1 && sum3 < sum2) {
        	sum1 = ( (2 * RP) - (2 * RP * 0.1) + RH );
        	if(sum3 < sum1) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
        
	    }
	}
	if( sum_znakova == 227 ) {
		sum1 = 2 * RP + RC;
		sum2 = 2 * FP + FC;
		sum3 = 2 * BP + BC;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 = 2 * RP - 2 * RP * 0.1 + RC;
        	if( sum2 <= sum1 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else if( sum1 < sum2 ) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if( sum3 < sum1 && sum3 < sum2 ) {
        	sum1 = 2 * RP - 2 * RP * 0.1 + RC;
        	if( sum3 <= sum1 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else if( sum1 < sum3 ) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
        
	    }
	}
	if( sum_znakova == 219 ) {
		sum1 = RP + RH + RC;
		sum2 = FP + FH + FC;
		sum3 = BP + BH + BC;
		if( sum1 < sum2 && sum1 < sum3 ) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", znak, znak, sum1);
		if( sum2 < sum1 && sum2 < sum3 ) {
        	sum1 = RP - RP*0.1 + RH + RC;
        	if(sum2 < sum1) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", znak, znak, sum2);
        	else printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum2, sum1);
        }
        if(sum3 < sum1 && sum3 < sum2) {
        	sum1 = RP - RP * 0.1 + RH + RC;
        	if(sum3 < sum1) printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", znak, znak, sum3);
        	else printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", znak, znak, sum3, sum1);
        
	    }
	}
	return 0;
}
