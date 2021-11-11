#include <stdio.h>

int main() {
    char boja;
    int brojac, crna, bijela, siva, crvena, plava;
    float C, B, S, V, P, brojac1;
    brojac=0;
    crna=0; bijela=0; siva=0; crvena=0; plava=0;
    printf("Unesite vozila: ");
    do {
        
        scanf("%c", &boja);
        if (boja=='\n') continue;
        if((boja=='C') || (boja=='c')) crna++;
        else if((boja=='B') || (boja=='b')) bijela++;
        else if((boja=='S') || (boja=='s')) siva++;
        else if((boja=='V') || (boja=='v')) crvena++;
        else if((boja=='P') || (boja=='p')) plava++;
        else if(boja!='C' && boja!='c' && boja!='B' && boja!='b' && boja!='S' && boja!='s' && boja!='V' && boja!='v' && boja!='P' && boja!='p' && boja!='K' && boja!='k')
        { printf("Neispravan unos\n");  continue; } 
        brojac++;
    } while((boja!='K') && (boja!='k'));
    brojac--;
    brojac1=brojac;
    C=(crna/brojac1)*100.;
    B=(bijela/brojac1)*100.;
    S=(siva/brojac1)*100.;
    V=(crvena/brojac1)*100.;
    P=(plava/brojac1)*100.;
    printf("Ukupno evidentirano %d vozila.\n", brojac);
    if(brojac==0) printf("Najpopularnija boja je crna (0.00%).");
    else if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) printf("Najpopularnija boja je crna (%.2f%%).", C);
    else if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) printf("Najpopularnija boja je bijela (%.2f%%).", B);
    else if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava) printf("Najpopularnija boja je siva (%.2f%%).", S);
    else if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava) printf("Najpopularnija boja je crvena (%.2f%%).", V);
    else printf("Najpopularnija boja je plava (%.2f%%).", P);
    
    
    
    
    return 0;
}