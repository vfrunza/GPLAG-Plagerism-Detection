#include <stdio.h>
#include <math.h>

#define KONJUSAR_PIZZA 6.80
#define KONJUSAR_HAMBURGER 3.30
#define KONJUSAR_CEVAPI 5.00

#define TROVAC_PIZZA 8.00
#define TROVAC_HAMBURGER 3.00
#define TROVAC_CEVAPI 3.90

#define LORELEI_PIZZA 5.30
#define LORELEI_HAMBURGER 5.00
#define LORELEI_CEVAPI 6.00

int main() {
    char izborTarik;
    char izborMirza;
    char izborBojan;
    char noviRed;
    
    float naplataKonjusar=0;
    float naplataTrovac=0;
    float naplataLorelei=0;
    float popustKonjusar=0;
    int narudzbineH = 0;
    int narudzbineP = 0;
    int narudzbineC = 0;

     
    do {
        printf("Unesite jelo za Tarika: ");
        izborTarik = getchar();
        scanf("%c", &noviRed);

    } while (izborTarik != 'H' && izborTarik != 'P' && izborTarik != 'C');

    do {
        printf("Unesite jelo za Bojana: ");
        izborBojan = getchar();
        scanf("%c", &noviRed);
    } while (izborBojan != 'H' && izborBojan != 'P' && izborBojan != 'C');

    do {
        printf("Unesite jelo za Mirzu: ");
        izborMirza = getchar();
        scanf("%c", &noviRed);
    } while (izborMirza != 'H' && izborMirza != 'P' && izborMirza != 'C');


    
    if (izborTarik == 'H'){
        naplataKonjusar += KONJUSAR_HAMBURGER;
        naplataLorelei += LORELEI_HAMBURGER;
        naplataTrovac += TROVAC_HAMBURGER;
        narudzbineH++;
    }

    if (izborTarik == 'P'){
        naplataKonjusar += KONJUSAR_PIZZA;
        naplataLorelei += LORELEI_PIZZA;
        naplataTrovac += TROVAC_PIZZA;
        narudzbineP++;
    }

    if (izborTarik == 'C'){
        naplataKonjusar += KONJUSAR_CEVAPI;
        naplataLorelei += LORELEI_CEVAPI;
        naplataTrovac += TROVAC_CEVAPI;
        narudzbineC++;
    }

    if (izborMirza == 'H'){
        naplataKonjusar += KONJUSAR_HAMBURGER;
        naplataLorelei += LORELEI_HAMBURGER;
        naplataTrovac += TROVAC_HAMBURGER;
        narudzbineH++;
    }

    if (izborMirza == 'P'){
        naplataKonjusar += KONJUSAR_PIZZA;
        naplataLorelei += LORELEI_PIZZA;
        naplataTrovac += TROVAC_PIZZA;
        narudzbineP++;
    }

    if (izborMirza == 'C'){
        naplataKonjusar += KONJUSAR_CEVAPI;
        naplataLorelei += LORELEI_CEVAPI;
        naplataTrovac += TROVAC_CEVAPI;
        narudzbineC++;
    }

    if (izborBojan == 'H'){
        naplataKonjusar += KONJUSAR_HAMBURGER;
        naplataLorelei += LORELEI_HAMBURGER;
        naplataTrovac += TROVAC_HAMBURGER;
        narudzbineH++;
    }

    if (izborBojan == 'P'){
        naplataKonjusar += KONJUSAR_PIZZA;
        naplataLorelei += LORELEI_PIZZA;
        naplataTrovac += TROVAC_PIZZA;
        narudzbineP++;
    }

    if (izborBojan == 'C'){
        naplataKonjusar += KONJUSAR_CEVAPI;
        naplataLorelei += LORELEI_CEVAPI;
        naplataTrovac += TROVAC_CEVAPI;
        narudzbineC++;
    }

    
    float kostaHamburegra = narudzbineH * KONJUSAR_HAMBURGER;
    float kostaPice = narudzbineP * KONJUSAR_PIZZA;
    float kostaCevapa = narudzbineC * KONJUSAR_CEVAPI;

    if (kostaHamburegra > kostaPice && kostaHamburegra > kostaCevapa){
        popustKonjusar = kostaPice + kostaCevapa;
        popustKonjusar += kostaHamburegra - (kostaHamburegra / 10);
    }

    if (kostaPice > kostaHamburegra && kostaPice > kostaCevapa){
        popustKonjusar = kostaHamburegra + kostaCevapa;
        popustKonjusar += kostaPice - (kostaPice / 10);
    }

    if (kostaCevapa > kostaPice && kostaCevapa > kostaHamburegra){
        popustKonjusar = kostaPice + kostaHamburegra;
        popustKonjusar += kostaCevapa - (kostaCevapa / 10);
    }

    
    if (naplataKonjusar < naplataLorelei && naplataKonjusar < naplataTrovac){
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", naplataKonjusar);
    }
    else if (naplataTrovac < naplataLorelei && naplataTrovac < naplataKonjusar){
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", naplataTrovac);
        if (popustKonjusar < naplataTrovac)
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", popustKonjusar);
    }
    else if (naplataLorelei < naplataTrovac && naplataLorelei < naplataKonjusar){
        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", naplataLorelei);
        if (popustKonjusar < naplataLorelei)
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", popustKonjusar);
    }
    
     
	return 0;
}