#include <stdio.h>
#include <math.h>
int main() {
    char L;
    int UV=0,C=0,B=0,S=0,V=0,P=0;
    float PC,PB,PS,PV,PP;
    printf("Unesite vozila: ");
    do {
    scanf("%c",&L);
    if (L!='C' && L!='c' && L!='B' && L!='b' && L!='S' && L!='s' && L!='V' && L!='v' && L!='P' && L!='p' && L!='k' && L!='K' && L!='\n') {printf("Neispravan unos\n");}
    else if (L=='C' || L=='c' || L=='B' || L=='b' || L=='S' || L=='s' || L=='V' || L=='v' || L=='P' || L=='p') {UV++;}
    if (L=='p' || L=='P') {P++;}
    if (L=='v' || L=='V') {V++;}
    if (L=='s' || L=='S') {S++;}
    if (L=='b' || L=='B') {B++;}
    if (L=='c' || L=='C') {C++;}
    } while (L!='k' && L!='K');
    printf("Ukupno evidentirano %d vozila.\n", UV);
    if (UV!=0) {
    if (C>=V && C>=S && C>=B && C>=P) {PC=(C*100.0)/UV; printf("Najpopularnija boja je crna (%.2f%%).", PC);}
    else if (B>=V && B>=S && B>=P && B>=C) {PB=(B*100.0)/UV; printf("Najpopularnija boja je bijela (%.2f%%).", PB);}
    else if (S>=V && S>=P && S>=B && S>=C) {PS=(S*100.0)/UV; printf("Najpopularnija boja je siva (%.2f%%).", PS);}
    else if (V>=P && V>=S && V>=B && V>=C) {PV=(V*100.0)/UV; printf("Najpopularnija boja je crvena (%.2f%%).", PV);}
    else if (P>=V && P>=S && P>=B && P>=C) {PP=(P*100.0)/UV; printf("Najpopularnija boja je plava (%.2f%%).", PP);}
    }
    else {printf("Najpopularnija boja je crna (0.00%%).");}
	return 0;
}
