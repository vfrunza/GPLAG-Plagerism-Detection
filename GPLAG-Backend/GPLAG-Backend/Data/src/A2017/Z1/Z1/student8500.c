#include <stdio.h>
#include <stdlib.h>
//Cijene u restoranu
#define r_pizza 6.80
#define r_ham 3.30
#define r_cevapi 5

//Cijene u fast-food
#define fa_pizza 8.00
#define fa_ham 3.00
#define fa_cevapi 3.90

//Cijene u bistru
#define bi_pizza 5.30
#define bi_ham 5.00
#define bi_cevapi 6.00


int main() {
    
    int i;
    char izbor,new_line;
    float brojacP = 0,brojacH = 0,brojacC = 0;
	double rest=0;
	double fast = 0;
	double bistro = 0;
	double pPopust = r_pizza / 10 ; // Popust na pizzu u restoranu
	double hPopust = r_ham / 10 ;  // Popust na hamburger u restoranu
	double cPopust = r_cevapi / 10 ; // Popust na cevape u restoranu
	
	for(i=0;i<3;i++) {
	    if(i==0) {
	        printf("Unesite jelo za Tarika: ");
	        scanf("%c",&izbor);
	        scanf("%c",&new_line);
	    }
	    if(i==1) {
	        printf("Unesite jelo za Bojana: ");
	        scanf("%c",&izbor);
	        scanf("%c",&new_line);
	    }
	    if(i==2) {
	        printf("Unesite jelo za Mirzu: ");
	        scanf("%c",&izbor);
	        scanf("%c",&new_line);
	    }
	    if(izbor=='P') {
	        rest+=r_pizza;
	        fast+=fa_pizza;
	        bistro+=bi_pizza;
	        brojacP++;
	    }
	    if(izbor=='H') {
	        rest+=r_ham;
	        fast+=fa_ham;
	        bistro+=bi_ham;
	        brojacH++;
	    }
	    if(izbor=='C') {
	        rest+=r_cevapi;
	        fast+=fa_cevapi;
	        bistro+=bi_cevapi;
	        brojacC++;
	    }
	}
	
	if(rest < fast && rest < bistro) {
	    printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",rest);
	}
	else if(fast < rest && fast < bistro) {
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",fast);
	}
	else {
	    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bistro);
	}
	
	if(!(rest < fast && rest < bistro)) {
	    double restP = rest - brojacP * pPopust;
	    double restH = rest - brojacH * hPopust;
	    double restC = rest - brojacC * cPopust;
	    if ( restP < fast && restP < bistro ) {
	    	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restP);
	    }
	    else if ( restH < fast && restH < bistro ) {
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restH);
	    }
	    else if ( restC < fast && restC < bistro ) {
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restC);
	    }
	    
	}
	
	return 0;
}
