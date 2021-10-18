#include <stdio.h>
#define Rp 6.80
#define Rh 3.30
#define Rc 5.00
#define Fp 8.00
#define Fh 3.00
#define Fc 3.90
#define Bp 5.30
#define Bh 5.00
#define Bc 6.00
#define POPUST 0.90

int main() {
    int brojacP=0, brojacH=0, brojacC=0;
    char tarik, bojan, mirza, novi_red;
    float restoran, fastfood, bistro, pop, popP, popH, popC;
    /* tarik, bojan, mirza su jela */
    /* brojacP, brojacH, brojacC su brojaci */
    /* restoran, fastfood, bistro su ukupne cijene u tim restoranima */
    /* pop je ukupna cijena sa popustom */
    /* popP, popH, popC su popusti na obrok */
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza);
    scanf("%c", &novi_red);
    
    /*tarik brojac*/
     switch(tarik) {
    	case 'P':
    		brojacP++;
    		break;
    	case 'H':
    		brojacH++;
    		break;
    	case 'C':
    		brojacC++;
    		break;
    }
    
    /*bojan brojac*/
     switch(bojan) {
    	case 'P':
    		brojacP++;
    		break;
    	case 'H':
    		brojacH++;
    		break;
    	case 'C':
    		brojacC++;
    		break;
    }
    
    /*mirza brojac*/
    switch(mirza) {
    	case 'P':
    		brojacP++;
    		break;
    	case 'H':
    		brojacH++;
    		break;
    	case 'C':
    		brojacC++;
    		break;
    }
    
    /*cijene*/
    restoran = Rp*brojacP + Rh*brojacH + Rc*brojacC;
    fastfood = Fp*brojacP + Fh*brojacH + Fc*brojacC;
    bistro = Bp*brojacP + Bh*brojacH + Bc*brojacC;
    
    /*popust u restoranu*/
    if(brojacP!=0) {
        popP = POPUST*Rp;
        pop = popP*brojacP + Rh*brojacH + Rc*brojacC;
    }
    else if(brojacC!=0 && brojacP==0) {
        popC = POPUST*Rc;
        pop = Rp*brojacP + Rh* brojacH + popC*brojacC;
    }
    else if(brojacH!=0) {
        popH = POPUST*Rh;
        pop = Rp*brojacP + popH* brojacH + Rc*brojacC;
    }
    
    if((restoran<bistro) && (restoran<fastfood)) {
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
    }
    else if((restoran>bistro) && (restoran<fastfood)) {
        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", bistro);
        if(bistro>pop) {
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", pop);
        }
        
    }
    else if((restoran<bistro) && (restoran>fastfood)) {
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", fastfood);
        if(fastfood>pop) {
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", pop);
        }
    }
    
    
	return 0;
}
