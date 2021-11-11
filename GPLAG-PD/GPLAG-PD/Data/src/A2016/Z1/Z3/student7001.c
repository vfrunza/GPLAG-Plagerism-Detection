#include <stdio.h>
int main () {
    char slovo = ' ';
    int i, crna=0, bijela=0, siva=0, crvena=0, plava=0, br_v=0;
    float kolicnik, procenat;
    
    /*Unos prvog slova boje automobila neprekidno do unosa K ili k & prebrojavanje pojedinacnog i ukupnog broja unosa u beskonacnoj petlji*/
    
    printf ("Unesite vozila: ");
    for (i=0;;i++) {
        scanf ("%c", &slovo);
        if (slovo=='c' || slovo=='C') {
            crna++;
            br_v++;
        }
        else if (slovo=='b' || slovo=='B') {
            bijela++;
            br_v++;
        }
        else if (slovo=='s' || slovo=='S') {
            siva++;
            br_v++;
        }
        else if (slovo=='v' || slovo=='V') {
            crvena++;
            br_v++;
        }
        else if (slovo=='p' || slovo=='P') {
            plava++;
            br_v++;
        }
        else if (slovo=='K' || slovo=='k') break;
        else printf ("Neispravan unos\n");
        }
        
        /*Obrada unesenih podataka & ispis najpopularnije boje & ispis njenog procentualnog udjela u ukupnom broju automobila*/
        
        printf ("Ukupno evidentirano %d vozila.", br_v);
        
        if (crna==0 && bijela==0 && siva==0 && crvena==0 && plava==0) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (0.00%%).");
            return 0;
            }
        else if (crna>bijela && crna>siva && crna>crvena && crna>plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (bijela>crna && bijela>siva && bijela>crvena && bijela>plava) {
            kolicnik = (float) bijela/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
            }
        else if (siva>crna && siva>bijela && siva>crvena && siva>plava) {
            kolicnik = (float) siva/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je siva (%.2f%%).", procenat);
            }
        else if (crvena>crna && crvena>bijela && crvena>siva && crvena>plava) {
            kolicnik = (float) crvena/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crvena (%.2f%%).", procenat);
            }
        else if (plava>crvena && plava>bijela && plava>siva && plava>crvena) {
            kolicnik = (float) plava/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je plava (%.2f%%).", procenat);
            }
        else if (crna==bijela && crna>siva && crna>crvena && crna>plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==siva && crna>bijela && crna>crvena && crna>plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==crvena && crna>bijela && crna>siva && crna>plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==plava && crna>bijela && crna>siva && crna>plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==bijela && crna==siva && crna>crvena && crna>plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==bijela && crna==crvena && crna>siva && crna>plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==bijela && crna==plava && crna>siva && crna>crvena) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==siva && crna==plava && crna>bijela && crna>crvena) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }   
        else if (crna==siva && crna==crvena && crna>bijela && crna>crvena) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==crvena && crna==plava && crna>bijela && crna>siva) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==bijela && crna==siva && crna==crvena && crna>plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==bijela && crna==siva && crna==plava && crna>crvena) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (crna==bijela && crna==siva && crna==crvena && crna==plava) {
            kolicnik = (float) crna/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crna (%.2f%%).", procenat);
            }
        else if (bijela==siva && bijela>crna && bijela>crvena && bijela>plava) {
            kolicnik = (float) bijela/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
            }
        else if (bijela==crvena && bijela>crna && bijela>siva && bijela>plava) {
            kolicnik = (float) bijela/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
            }
        else if (bijela==plava && bijela>crna && bijela>siva && bijela>crvena) {
            kolicnik = (float) bijela/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
            }
        else if (bijela==siva && bijela==crvena && bijela>crna && bijela>plava) {
            kolicnik = (float) bijela/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
            }
        else if (bijela==siva && bijela==plava && bijela>crna && bijela>crvena) {
            kolicnik = (float) bijela/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
            }
        else if (bijela==siva && bijela==crvena && bijela==plava && bijela>crna) {
            kolicnik = (float) bijela/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
            }
        else if (siva==plava && siva>crna && siva>bijela && siva>crvena) {
            kolicnik = (float) siva/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je siva (%.2f%%).", procenat);
            }
        else if (siva==crvena && siva>crna && siva>bijela && siva>plava) {
            kolicnik = (float) siva/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je siva (%.2f%%).", procenat);
            }
        else if (siva==plava && siva==crvena && siva>crna && siva>bijela) {
            kolicnik = (float) siva/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je siva (%.2f%%).", procenat);
            }
        else if (crvena==plava && crvena>crna && crvena>siva && crvena>bijela) {
            kolicnik = (float) crvena/br_v;
            procenat = kolicnik*100;
            printf ("\nNajpopularnija boja je crvena (%.2f%%).", procenat);
            }
return 0;
}