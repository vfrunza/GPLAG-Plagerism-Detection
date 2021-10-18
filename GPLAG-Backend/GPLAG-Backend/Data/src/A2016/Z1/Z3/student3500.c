#include <stdio.h>

int main(){
    float Cr, Bj, Si, Crv, Pl;
    int counter;
    char unos;
    float nova;
    Cr=0; Bj=0; Si=0; Crv=0; Pl=0; counter=0;
    printf("Unesite vozila: ");
    do{
        scanf("%c", &unos);
        if ((unos=='C')||(unos=='c')) { Cr++; counter++; }
        else if ((unos=='B')||(unos=='b')) { Bj++; counter++; }
        else if ((unos=='S')||(unos=='s')) { Si++; counter++; }
        else if ((unos=='P')||(unos=='p')) { Pl++; counter++; }
        else if ((unos=='V')||(unos=='v')) { Crv++; counter++;}
        else if ((unos=='K')||(unos=='k')) break; 
        else printf("Neispravan unos \n");
        
    }while(unos!='K');
    printf("Ukupno evidentirano %d vozila.\n", counter);
    if((Cr>=Bj)&&(Cr>=Si)&&(Cr>=Crv)&&(Cr>=Pl)) {
        nova=(100*(Cr/counter));
        printf("Najpopularnija boja je crna (%.2f%%).", nova);
    }
    else if((Bj>Cr)&&(Bj>=Si)&&(Bj>=Crv)&&(Bj>=Pl)) {
        nova=(100*(Bj/counter));
        printf("Najpopularnija boja je bijela (%.2f%%).", nova);
    }
    else if((Si>Cr)&&(Si>Bj)&&(Si>=Crv)&&(Si>=Pl)) {
        nova=(100*(Si/counter));
        printf("Najpopularnija boja je siva (%.2f%%).", nova);
    }
    else if((Crv>Cr)&&(Crv>Bj)&&(Crv>Si)&&(Crv>=Pl)) {
        nova=(100*(Crv/counter));
        printf("Najpopularnija boja je crvena (%.2f%%).", nova);
    }
    else if((Pl>Bj)&&(Pl>Si)&&(Pl>Cr)&&(Pl>Crv)) {
        nova=(100*(Pl/counter));
        printf("Najpopularnija boja je plava (%.2f%%).", nova);
    }
    return 0;
}