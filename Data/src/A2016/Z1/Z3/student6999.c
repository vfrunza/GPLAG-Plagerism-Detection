#include <stdio.h>

int main() {
    float crna=0,bijela=0,siva=0,crvena=0,plava=0,postotak=0;
    float ukupnovozila=0,postcrne=0.0,postcrvene=0.0,postbijele=0.0,postsive=0.0,postplave=0.0;
    char unos;
    printf("Unesite vozila: ");
        do
        {
            scanf("%c",&unos);
        
            if((unos=='C')||(unos=='c')){ crna++; continue;}
     if((unos=='B')||(unos=='b')){ bijela++; continue;}
     if((unos=='S')||(unos=='s')){ siva++; continue;}
     if((unos=='V')||(unos=='v')){ crvena++; continue;}
     if((unos=='P')||(unos=='p')){plava++; continue;}
    if(((unos!='P')&&(unos!='p'))&&((unos!='V')&&(unos!='v'))&&((unos!='S')&&(unos!='s'))&&((unos!='B')&&(unos!='b'))&&((unos!='C')&&(unos!='c'))&&((unos!='K')&&(unos!='k'))){
 printf("Neispravan unos\n");}
   }while((unos!='K')&&(unos!='k'));
        ukupnovozila=crna+bijela+siva+crvena+plava;
        printf("Ukupno evidentirano %g vozila.\n",ukupnovozila);
        if(ukupnovozila!=0){
        postcrne=(crna*100)/ukupnovozila;
        postbijele=(bijela*100)/ukupnovozila;
        postsive=(siva*100)/ukupnovozila;
        postcrvene=(crvena*100)/ukupnovozila;
        postplave=(plava*100)/ukupnovozila;}
        if((crna>=bijela)&&(crna>=siva)&&(crna>=crvena)&&(crna>=plava)){ printf("Najpopularnija boja je crna (%.2f%%).",postcrne); return 0;}
        if((bijela>=crna)&&(bijela>=siva)&&(bijela>=crvena)&&(bijela>=plava)){ printf("Najpopularnija boja je bijela (%.2f%%).",postbijele); return 0;}
        if((siva>=crna)&&(siva>=bijela)&&(siva>=crvena)&&(siva>=plava)){ printf("Najpopularnija boja je siva (%.2f%%).",postsive); return 0;}
        if((crvena>=crna)&&(crvena>=bijela)&&(crvena>=siva)&&(crvena>=plava)){ printf("Najpopularnija boja je crvena (%.2f%%).",postcrvene); return 0;}
        if((plava>=crna)&&(plava>=bijela)&&(plava>=siva)&&(plava>=crvena)){ printf("Najpopularnija boja je plava (%.2f%%).",postplave); return 0;}
    return 0;
}
