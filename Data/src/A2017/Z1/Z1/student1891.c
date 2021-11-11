#include <stdio.h>
#define RESTORAN_PIZZA 6.80f
#define RESTORAN_HAMBURGER 3.30f
#define RESTORAN_CEVAPI 5.00f
#define TROVAC_PIZZA 8.00f
#define TROVAC_HAMBURGER 3.00f
#define TROVAC_CEVAPI 3.90f
#define BISTRO_PIZZA 5.30f
#define BISTRO_HAMBURGER 5.00f
#define BISTRO_CEVAPI 6.00f

int main() {
    char jeloTarik,jeloBojan,jeloMirza,novired;
    float restoranTotal=0,trovacTotal=0,bistroTotal=0,najskupljeJelo=0,restoranPopust=0;
    printf("Unesite jelo za Tarika: ");
    scanf("%c",&jeloTarik);
    scanf("%c",&novired);
	printf("Unesite jelo za Bojana: ");
    scanf("%c",&jeloBojan);
    scanf("%c",&novired);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&jeloMirza);
    scanf("%c",&novired);
    
    if((jeloTarik=='H' || jeloBojan=='H' || jeloMirza=='H')) {
        najskupljeJelo=RESTORAN_HAMBURGER;
    }
    
    if((jeloTarik=='P' || jeloBojan=='P' || jeloMirza=='P') && RESTORAN_PIZZA>najskupljeJelo) {
        najskupljeJelo=RESTORAN_PIZZA;
    } 
    
    if ((jeloTarik=='C' || jeloBojan=='C' || jeloMirza=='C') && RESTORAN_CEVAPI >najskupljeJelo) {
        najskupljeJelo=RESTORAN_CEVAPI;
    }
    switch(jeloTarik) {
        case 'P':
        restoranTotal += RESTORAN_PIZZA;
        if(najskupljeJelo==RESTORAN_PIZZA) {
            restoranPopust += 0.9f * RESTORAN_PIZZA;
        } else {
            restoranPopust += RESTORAN_PIZZA;
        }
        trovacTotal += TROVAC_PIZZA;
        bistroTotal += BISTRO_PIZZA;
        break;
        case 'H':
        restoranTotal += RESTORAN_HAMBURGER;
        if(najskupljeJelo==RESTORAN_HAMBURGER) {
            restoranPopust += 0.9f * RESTORAN_HAMBURGER;
        } else {
            restoranPopust += RESTORAN_HAMBURGER;
        }        
        trovacTotal += TROVAC_HAMBURGER;
        bistroTotal += BISTRO_HAMBURGER;
        break;
        case 'C':
        restoranTotal += RESTORAN_CEVAPI;
        if(najskupljeJelo==RESTORAN_CEVAPI) {
            restoranPopust += 0.9f * RESTORAN_CEVAPI;
        } else {
            restoranPopust += RESTORAN_CEVAPI;
        }        
        trovacTotal += TROVAC_CEVAPI;
        bistroTotal += BISTRO_CEVAPI;
        break;
    }
    switch(jeloBojan) {
        case 'P':
        restoranTotal += RESTORAN_PIZZA;
        if(najskupljeJelo==RESTORAN_PIZZA) {
            restoranPopust += 0.9f * RESTORAN_PIZZA;
        } else {
            restoranPopust += RESTORAN_PIZZA;
        }        
        trovacTotal += TROVAC_PIZZA;
        bistroTotal += BISTRO_PIZZA;
        break;
        case 'H':
        restoranTotal += RESTORAN_HAMBURGER;
        if(najskupljeJelo==RESTORAN_HAMBURGER) {
            restoranPopust += 0.9f * RESTORAN_HAMBURGER;
        } else {
            restoranPopust += RESTORAN_HAMBURGER;
        }        
        trovacTotal += TROVAC_HAMBURGER;
        bistroTotal += BISTRO_HAMBURGER;
        break;
        case 'C':
        restoranTotal += RESTORAN_CEVAPI;
        if(najskupljeJelo==RESTORAN_CEVAPI) {
            restoranPopust += 0.9f * RESTORAN_CEVAPI;
        } else {
            restoranPopust += RESTORAN_CEVAPI;
        }        
        trovacTotal += TROVAC_CEVAPI;
        bistroTotal += BISTRO_CEVAPI;
        break;
    }
    switch(jeloMirza) {
        case 'P':
        restoranTotal += RESTORAN_PIZZA;
        if(najskupljeJelo==RESTORAN_PIZZA) {
            restoranPopust += 0.9f * RESTORAN_PIZZA;
        } else {
            restoranPopust += RESTORAN_PIZZA;
        }
        trovacTotal += TROVAC_PIZZA;
        bistroTotal += BISTRO_PIZZA;
        break;
        case 'H':
        restoranTotal += RESTORAN_HAMBURGER;
        if(najskupljeJelo==RESTORAN_HAMBURGER) {
            restoranPopust += 0.9f * RESTORAN_HAMBURGER;
        } else {
            restoranPopust += RESTORAN_HAMBURGER;
        }
        trovacTotal += TROVAC_HAMBURGER;
        bistroTotal += BISTRO_HAMBURGER;
        break;
        case 'C':
        restoranTotal += RESTORAN_CEVAPI;
        if(najskupljeJelo==RESTORAN_CEVAPI) {
            restoranPopust += 0.9f * RESTORAN_CEVAPI;
        } else {
            restoranPopust += RESTORAN_CEVAPI;
        }
        trovacTotal += TROVAC_CEVAPI;
        bistroTotal += BISTRO_CEVAPI;
        break;
    }
    
    char pobjednik;
    if(restoranTotal<bistroTotal && restoranTotal<trovacTotal) {
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoranTotal);
        pobjednik = 'R';
    } else if(bistroTotal<trovacTotal) {
        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bistroTotal);
        pobjednik = 'B';
    } else {
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",trovacTotal);
        pobjednik = 'T';
    }
    
    if (pobjednik != 'R' && (restoranPopust<bistroTotal && restoranPopust<trovacTotal)) {
        printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoranPopust);
    } 
	return 0;
}
