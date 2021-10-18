#include <stdio.h>
int main() {
    char slova;
    float postotak=0,plava=0,crvena=0,crna=0,bijela=0,siva=0;
    int i=0,brojac=0;
    printf("Unesite vozila: ");
    for(i=0;i<1100;i++){
        scanf("%c",&slova);
        if(slova=='C' || slova=='c' || slova=='B' || slova=='b' || slova=='V' || slova=='v' || slova=='P' || slova=='p' || slova=='S' || slova=='s')
        brojac++;
        if(slova=='P' || slova=='p'){plava++;}
        else if(slova=='C' || slova=='c'){crna++;}
        else if(slova=='V' || slova=='v'){crvena++;}
        else if(slova=='B' || slova=='b'){bijela++;}
        else if(slova=='S' || slova=='s'){siva++;}
        if(slova!='P' && slova!='p' && slova!='C' && slova!='c' && slova!='V' && slova!='v' && slova!='B' && slova!='b' && slova!='S' && slova!='s' && slova!='K' && slova!='k' && slova!='\n')
        printf("Neispravan unos\n");
        if(slova=='K' || slova=='k') break;
    }printf("Ukupno evidentirano %d vozila.",brojac);
    if(brojac!=0){
    if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
        postotak=(crna/brojac)*100;
         printf("\nNajpopularnija boja je crna (%.2f%%).",postotak);
    }else if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava){
            postotak=(bijela/brojac)*100;
            printf("\nNajpopularnija boja je bijela (%.2f%%).",postotak);
    }else if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava){
            postotak=(siva/brojac)*100;
            printf("\nNajpopularnija boja je siva (%.2f%%).",postotak);
    }else if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava){
            postotak=(crvena/brojac)*100;
            printf("\nNajpopularnija boja je crvena (%.2f%%).",postotak);
    }else if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena){
            postotak=(plava/brojac)*100;
            printf("\nNajpopularnija boja je plava (%.2f%%).",postotak);
    }}else if(brojac==0){
        postotak=brojac*100;
        printf("\nNajpopularnija boja je crna (%.2f%%).",postotak);
    }return 0;
}
