#include <stdio.h>
#include <math.h>
int main () {
    char A;
    int C=0,B=0,S=0,V=0,P=0,UV=0;
    float PC,PB,PS,PV,PP;
    
    printf("Unesite vozila: ");
    do {
    scanf("%c", &A);
    if(A!='C' &&  A!='c' &&  A!='B' &&  A!='b' &&  A!='S' &&  A!='s' &&  A!='V' &&  A!='v' &&  A!='P' &&  A!='p' &&  A!='k' &&  A!='K'){
        printf("Neispravan unos\n");}
    else if(A=='C' || A=='c' || A=='B' || A=='b' || A=='S' || A=='s' || A=='V' || A=='v' || A=='P' || A=='p')
    {UV++;}
        if(A=='C' || A=='c'){C++;}
        if(A=='B' || A=='b'){B++;}
        if(A=='S' || A=='s'){S++;}
        if(A=='V' || A=='v'){V++;}
        if(A=='P' || A=='p'){P++;}
        } while (A!='K' && A!='k');
        printf("Ukupno evidentirano %d vozila.\n", UV);
    
    if(UV!=0){
        if(C>=B && C>=S && C>=V && C>=P){
            PC=(C*100.0/UV); 
            printf("Najpopularnija boja je crna (%.2f%%).", PC);}
        else if(B>=C && B>=S && B>=V && B>=P){
            PB=(B*100.0/UV); 
            printf("Najpopularnija boja je bijela (%.2f%%).", PB);}
        else if(S>=C && S>=B && S>=V && S>=P){
            PS=(S*100.0/UV);
            printf("Najpopularnija boja je siva (%.2f%%).", PS);}
        else if(V>=C && V>=B && V>=S && V>=P){
            PV=(V*100.0/UV);
            printf("Najpopularnija boja je crvena (%.2f%%).", PV);}
        else if(P>=C && P>=B && P>=S && P>=V){
            PP=(P*100.0/UV); 
            printf("Najpopularnija boja je plava (%.2f%%).", PP);}}
    else {
        printf("Najpopularnija boja je crna (0.00%%).");
        }
    return 0;
}