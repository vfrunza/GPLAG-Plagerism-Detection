#include <stdio.h>

int main () {
    char unoskorisnika;
    float Cuk=0, Buk=0, Suk=0, Vuk=0, Puk=0, ukupnovozila=0;
    float udiocuk, udiobuk, udiosuk, udiovuk, udiopuk;
    printf("Unesite vozila: ");
    do {
        scanf("%c", &unoskorisnika);
        
        if(unoskorisnika=='c' || unoskorisnika=='C') {
            Cuk++;
        }
        else if(unoskorisnika=='b' || unoskorisnika=='B') {
            Buk++;
        }
        else if(unoskorisnika=='s' || unoskorisnika=='S') {
            Suk++;
        }
        else if(unoskorisnika=='v' || unoskorisnika=='V') {
            Vuk++;
        }
        else if(unoskorisnika=='p' || unoskorisnika=='P') {
            Puk++;
        }
        else if(unoskorisnika=='k' || unoskorisnika=='K') {
    
        } 
        else {
            printf("Neispravan unos\n");
        }
    } 
    while (unoskorisnika!='k' && unoskorisnika!='K');
    
    ukupnovozila=Cuk+Buk+Suk+Vuk+Puk;
    printf("Ukupno evidentirano %g vozila.", ukupnovozila);
    
    if(ukupnovozila!=0) {
        udiocuk=(Cuk/ukupnovozila)*100;
        udiobuk=(Buk/ukupnovozila)*100;
        udiosuk=(Suk/ukupnovozila)*100;
        udiovuk=(Vuk/ukupnovozila)*100;
        udiopuk=(Puk/ukupnovozila)*100;
    }
    if(ukupnovozila==0) {
        printf("\nNajpopularnija boja je crna (0.00%%).");
    }
    else if(Cuk>=Buk && Cuk>=Suk && Cuk>=Vuk && Cuk>=Puk) {
        printf("\nNajpopularnija boja je crna (%.2f%%).", udiocuk);
    }
    else if(Buk>=Cuk && Buk>=Suk && Buk>=Vuk && Buk>=Puk) {
        printf("\nNajpopularnija boja je bijela (%.2f%%).", udiobuk);
    }
    else if(Suk>=Buk && Suk>=Cuk && Suk>=Vuk && Suk>=Puk) {
        printf("\nNajpopularnija boja je siva (%.2f%%).", udiosuk);
    }
    else if(Vuk>=Buk && Vuk>=Suk && Vuk>=Cuk && Vuk>=Puk) {
        printf("\nNajpopularnija boja je crvena (%.2f%%).", udiovuk);
    }
    else if(Puk>=Buk && Puk>=Suk && Puk>=Cuk && Puk>=Vuk) {
        printf("\nNajpopularnija boja je plava (%.2f%%).", udiopuk);
    }
    
    return 0;
}