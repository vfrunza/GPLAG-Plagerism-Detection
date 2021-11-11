#include <stdio.h>
int main () {
    
    int C, B, S, V, P, ukupno_automobila; char boja_automobila; float procenti;
    C=0;
    B=0;
    S=0;
    V=0;
    P=0;
    printf ("Unesite vozila: ");
    scanf ("%c", &boja_automobila);
    
    if (boja_automobila=='C' || boja_automobila=='c')
        C++;
    else if (boja_automobila=='B' || boja_automobila=='b') {
        B++;
    }
    else if (boja_automobila=='S' || boja_automobila=='s') {
        S++;
    }
    else if (boja_automobila=='V' || boja_automobila=='v') {
        V++;
    }
    else if (boja_automobila=='P' || boja_automobila=='p') {
        P++;
    }
    else if (boja_automobila=='K' || boja_automobila=='k') {
        printf ("Neispravan unos\n");
    }
    else {
        printf ("Neispravan unos\n");
    }
    while (100==100)
    {
    scanf ("%c", &boja_automobila);
    if (boja_automobila=='C' || boja_automobila=='c') {
        C++;
    }
    else if (boja_automobila=='B' || boja_automobila=='b') {
        B++;
    }
    else if (boja_automobila=='S' || boja_automobila=='s') {
        S++;
    }
    else if (boja_automobila=='V' || boja_automobila=='v') {
        V++;
    }
    else if (boja_automobila=='P' || boja_automobila=='p') {
        P++;
    }
    else if (boja_automobila=='K' || boja_automobila=='k') {
        break;   
    }
    else {
        printf("Neispravan unos\n");
    }
    
    }
    ukupno_automobila=B+C+S+V+P;
    
    printf ("Ukupno evidentirano %d vozila.\n", ukupno_automobila);
    
    if (ukupno_automobila==0) {
        printf ("Najpopularnija boja je crna (0.00%).");
        return 0;
    }
    if (C>=B && C>=S && C>=V && C>=P) {
        procenti=(100.*C)/ukupno_automobila;
        printf ("Najpopularnija boja je crna (%.2f%%).", procenti);
        return 0;
    }
   if (B>=C && B>=S && B>=V && B>=P) {
       procenti=(100.*B)/ukupno_automobila;
       printf ("Najpopularnija boja je bijela (%.2f%%).", procenti);
       return 0;
   }
    if (S>=C && S>=B && S>=V && S>=P) {
        procenti=(100.*S)/ukupno_automobila;
        printf ("Najpopularnija boja je siva (%.2f%%).", procenti);
        return 0;
    }
    if (V>=C && V>=B && V>=S && V>=P) {
        procenti=(100.*V)/ukupno_automobila;
        printf ("Najpopularnija boja je crvena (%.2f%%).", procenti);
        return 0;
    }
    if (P>=C && P>=B && P>=S && P>=V) {
        procenti=(100.*P)/ukupno_automobila;
        printf ("Najpopularnija boja je plava (%.2f%%).", procenti);
        return 0;
    }
    return 0;
}



