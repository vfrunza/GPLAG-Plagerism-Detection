#include <stdio.h>

int main() {
    double crna=0,bijela=0,siva=0,crvena=0,plava=0,ukupno=0,pc=0,pb=0,ps=0,pcv=0,pp=0;
    char boja;
    printf("Unesite vozila: ");
    do{
        scanf("%c", &boja);
        
        
        if(boja=='C' || boja =='c'){
            crna++;
            continue;
        }
        if(boja=='B' || boja=='b'){
            bijela++;
            continue;
        }
        if(boja=='S' || boja=='s'){
            siva++;
            continue;
        }
        if(boja=='V' || boja=='v'){
            crvena++;
            continue;
        }
        if(boja=='P' || boja=='p')
        {
            plava++;
            continue;
        }
        if(boja!='c' && boja!='C' && boja!='b' && boja!='B' && boja!='s' && boja!='S' && boja!='v' && boja!='V' && boja!='p' && boja!='V' && boja!='k' && boja!='K'){
            printf("Neispravan unos\n");
        }
    }
    while (boja!='K' && boja!='k');
    ukupno=crna+bijela+siva+crvena+plava;
    printf("Ukupno evidentirano %g vozila.", ukupno);
    if(ukupno!=0){
    pc=(crna/ukupno)*100;
    pb=(bijela/ukupno)*100;
    ps=(siva/ukupno)*100;
    pcv=(crvena/ukupno)*100;
    pp=(plava/ukupno)*100;
    }
        if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
            printf("\nNajpopularnija boja je crna (%.2lf%%).", pc);
            return 0;
        }
        if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava){
            printf("\nNajpopularnija boja je bijela (%.2lf%%).", pb);
            return 0;
        }
        if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava){
            printf("\nNajpopularnija boja je siva (%.2lf%%).", ps);
            return 0;
        }
        if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava){
            printf("\nNajpopularnija boja je crvena (%.2lf%%).", pcv);
            return 0;
        }
        if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena){
           printf("\nNajpopularnija boja je plava (%.2lf%%).", pp);
           return 0;
        }
    
	return 0;
}
