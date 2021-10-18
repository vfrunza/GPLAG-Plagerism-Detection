#include <stdio.h>
#include <math.h>
int main() {
    char M;
    int CA=0, BA=0, SA=0, PA=0, VA=0, Ubv=0;
    float CB, BB, SB, PB, VB;
    printf("Unesite vozila: ");
    do {
        scanf("%c",&M);
        if (M!='C' && M!='c' && M!='B'&& M!='b'&& M!='S'&& M!='s'&& M!='P'&& M!='p'&& M!='K' && M!='k' && M!='V' && M!='v' && M!='\n')
            {printf("Neispravan unos\n"); 
        }
        else if (M=='C'|| M=='c'|| M=='B'|| M=='b'|| M=='S'|| M=='s'|| M=='P'|| M=='p' || M=='V' || M=='v') {Ubv++;} 
        if (M=='c' || M=='C') {CA++;} 
        if (M=='b' || M=='B') {BA++;}
        if (M=='s' || M=='S') {SA++;}
        if (M=='p' || M=='P') {PA++;}
        if (M=='v' || M=='V') {VA++;} 
    } while (M!='k' && M!='K');
    printf("Ukupno evidentirano %d vozila. \n", Ubv);
    
    if(Ubv!=0) {
        if (CA>=BA && CA>=SA && CA>=PA && CA>=VA) { 
            CB=(CA*100.0)/Ubv; printf("Najpopularnija boja je crna (%.2f%).", CB);}
        else if (BA>=CA && BA>=SA && BA>=PA && BA>=VA) { 
            BB=(BA*100.0)/Ubv; printf("Najpopularnija boja je bijela (%.2f%).", BB);}
        else if (SA>=BA && SA>=CA && SA>=PA && SA>=VA) { 
            SB=(SA*100.0)/Ubv; printf("Najpopularnija boja je siva (%.2f%).", SB);}
        else if (PA>=BA && PA>=SA && PA>=CA && PA>=VA) { 
            PB=(PA*100.0)/Ubv; printf("Najpopularnija boja je plava (%.2f%).", PB);}
        else if (VA>=BA && VA>=SA && VA>=PA && VA>=CA) { 
            VB=(VA*100.0)/Ubv; printf("Najpopularnija boja je crvena (%.2f%).", VB); }
    } 
    
    else {
        printf("Najpopularnija boja je crna (0.00%).");
    }
    return 0;
}
