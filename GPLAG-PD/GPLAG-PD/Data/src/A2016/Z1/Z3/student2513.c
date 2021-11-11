#include <stdio.h>
int main () {
    int crna=0, bijela=0, siva=0, crvena=0, plava=0, ukupno=0;
    double procenatc,procenatb,procenats,procenatcr,procenatp;
    
    char boja;
    printf("Unesite vozila: ");
    do{scanf("%c",&boja);
    
        if(boja=='K' || boja=='k') {break;}
        else if(boja=='C' || boja=='c') {crna++; ukupno++;}
        else if(boja=='B' || boja=='b') {bijela++; ukupno++;}
        else if(boja=='S' || boja=='s') {siva++; ukupno++;}
        else if(boja=='V' || boja=='v') {crvena++; ukupno++;}
        else if(boja=='P' || boja=='p') {plava++; ukupno++;}
        else printf("Neispravan unos\n");
        
    }
    while(boja!='K' && boja!='k');
    
    printf("Ukupno evidentirano %d vozila.",ukupno);
    
    if(ukupno == 0)
    ukupno = 1;
    
    procenatc= ((int)(((((double) crna*100)/ukupno)*100)+0.5))/100.0;
    procenatb= ((int)(((((double) bijela*100)/ukupno)*100)+0.5))/100.0;
    procenats= ((int)(((((double) siva*100)/ukupno)*100)+0.5))/100.0;
    procenatcr=((int)(((((double) crvena*100)/ukupno)*100)+0.5))/100.0;
    procenatp= ((int)(((((double) plava*100)/ukupno)*100)+0.5))/100.0;
    
    if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) 
    printf("\nNajpopularnija boja je crna (%.2f%%).",procenatc);
    else if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) 
    printf("\nNajpopularnija boja je bijela (%.2f%%).",procenatb);
    else if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava)
    printf("\nNajpopularnija boja je siva (%.2f%%).",procenats);
    else if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava)
    printf("\nNajpopularnija boja je crvena (%.2f%%).",procenatcr);
    else if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena)
    printf("\nNajpopularnija boja je plava (%.2f%%).",procenatp);
    
    
    
    
    
    return 0;
}
