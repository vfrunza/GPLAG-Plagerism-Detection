#include <stdio.h>
int main (){
    double crna=0,crvena=0,bijela=0,plava=0,siva=0;
    double PC=0.00,PV=0.00,PB=0.00,PP=0.00,PS=0.00,U;
    char boja;
    
    printf("Unesite vozila: ");
    scanf("%c", &boja);
    while(boja!='K' &&boja!='k'){
        if(boja=='c'|| boja=='C'){
            crna++;
        }
        else if (boja=='v'||boja=='V'){
            crvena++;
        }
        else if (boja=='b'||boja=='B'){
            bijela++;
        }
        else if(boja=='P'||boja=='p'){
            plava++;
        }
        else if (boja=='s'||boja=='S'){
            siva++;
        }
        else if (boja=='k'||boja=='K');
        else {printf("Neispravan unos \n");}
        scanf("%c", &boja);
    }
        U=crna+crvena+bijela+plava+siva;
        printf("Ukupno evidentirano %g vozila.\n", U);
        if (U!=0){
            PC=(crna/U)*100;
            PV=(crvena/U)*100;
            PB=(bijela/U)*100;
            PP=(plava/U)*100;
            PS=(siva/U)*100;
        }
        else{PC=0;PV=0;PB=0;PP=0;PS=0;
            
        }
        if(crna>=crvena&&crna>=bijela&&crna>=plava&&crna>=siva){
            printf("\nNajpopularnija boja je crna (%.2lf%%).", PC);
        }
        else if (bijela>=crna&&bijela>=crvena&&bijela>=plava&&bijela>=siva){
            printf("Najpopularnija boja je bijela (%.2lf%%).", PB);
        }
         else if (siva>=crna&&siva>=crvena&&siva>=bijela&&siva>=plava){
            printf("Najpopularnija boja je siva (%.2lf%%).", PS);
        }
         else if (crvena>=crna&&crvena>=bijela&&crvena>=plava&&crvena>=siva){
            printf("Najpopularnija boja je crvena (%.2lf%%).", PV);
        }
        else if (plava>=crna&&plava>=crvena&&plava>=bijela&&plava>=siva){
            printf("Najpopularnija boja je plava (%.2lf%%).", PP);
        }
       
        return 0;
}