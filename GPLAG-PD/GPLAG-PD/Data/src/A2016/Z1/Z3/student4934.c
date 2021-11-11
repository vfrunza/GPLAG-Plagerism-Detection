#include <stdio.h>
int main () {
    int C,B,S,V,P,U,M;
    double X;
    char slovo;
    C=0;
    B=0;
    S=0;
    V=0;
    P=0;
    M=0;
    X=0;
   printf ("Unesite vozila: ");
   do {
    scanf ("%c", &slovo);
        if (slovo=='c'||slovo=='C') {
            C++;
            if (C>M) {
                M=C;
            }
        } else if (slovo=='b'||slovo=='B') {
            B++;
            if (B>M) {
                M=B;
            }
        } else if (slovo=='s'||slovo=='S') {
            S++;
            if (S>M) {
                M=S;
            }
        } else if (slovo=='v'||slovo=='V') {
            V++;
            if (V>M) {
                M=V;
            }
        } else if (slovo=='p'||slovo =='P') {
            P++;
            if (P>M) {
                M=P;
            }
        } else if (!(slovo=='k'||slovo=='K')) {
            printf ("Neispravan unos\n");
        }
    } while (!(slovo== 'k' || slovo=='K'));
    U=C+B+V+P+S;
    X=(M*100.)/U;
   if (U==0) {
   printf ("Ukupno evidentirano 0 vozila.\n");
   printf ("Najpopularnija boja je crna (0.00%).\n");
   return 0;
    }
    else {printf ("Ukupno evidentirano %d vozila.\n",U);
    }
    if (M==C) {
    printf ("Najpopularnija boja je crna (%.2f%%).", X);
        return 0;
    } else if (M==B) {
        printf ("Najpopularnija boja je bijela (%.2f%%).", X);
        return 0;
    } else if (M==S) {
        printf ("Najpopularnija boja je siva (%.2f%%).", X);
        return 0;
    } else if (M==V) {
        printf ("Najpopularnija boja je crvena (%.2f%%).", X);
        return 0;
    } else if (M==P) {
        printf ("Najpopularnija boja je plava (%.2f%%).", X);
        return 0;
    }
    return 0;
}
