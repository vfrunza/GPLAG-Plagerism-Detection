#include<stdio.h>

int main(){
    char c;
    int crna, plava, crvena, bijela, siva, ukupno,i;
    int prva_crna, prva_plava, prva_bijela, prva_siva;
    int prva_crvena;
    ukupno=0;
    i=crna=plava=bijela=siva=crvena=0;
    printf("Unesite vozila: ");
    
    for(;;){
        i++;
        scanf("%c", &c);
        if(c=='K' || c=='k') break;
        else if(c=='C' || c=='c'){
            crna++;
            if(crna==1) prva_crna=i;
        }
        else if(c=='P' || c=='p'){
            plava++;
            if(plava==1) prva_plava=i;
        }
        else if(c=='B' || c=='b'){
            bijela++;
            if(bijela==1) prva_bijela=i;
        }
        else if(c=='V' || c=='v'){
            crvena++;
            if(crvena==1) prva_crvena=i;
        }
        else if(c=='S' || c=='s'){
            siva++;
            if(siva==1) prva_siva=i;
        }
        else {
            printf("Neispravan unos\n");
            continue;
        }
        
        
    }
    ukupno=crna+bijela+siva+plava+crvena;
    printf("Ukupno evidentirano %d vozila.\n", ukupno);
    
    if(ukupno==0) printf("Najpopularnija boja je crna (0.00%%).");
   else if(siva>=plava && siva>=crvena && siva>=bijela && crna<=siva){
        if(siva==plava){
            if(prva_siva<prva_plava) 
                printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
            else
                printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
        }
        else if(siva==crvena){
            if(prva_siva<prva_crvena) 
                printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
            else
                printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
        }
        else if(siva==bijela){
            if(prva_siva<prva_bijela) 
                printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
            else
                printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
        }
        else if(crna==siva){
            if(prva_crna<prva_siva) 
                printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
            else
                printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
        }
        else printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
    }
    else if(crna>=plava && crna>=crvena && crna>=bijela && crna>=siva){
        if(crna==plava){
            if(prva_crna<prva_plava) 
                printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
            else
                printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
        }
        else if(crna==crvena){
            if(prva_crna<prva_crvena) 
                printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
            else
                printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
        }
        else if(crna==bijela){
            if(prva_crna<prva_bijela) 
                printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
            else
                printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
        }
        else if(crna==siva){
            if(prva_crna<prva_siva) 
                printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
            else
                printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
        }
        else{
            printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
        }
    }
    
    
    else if(plava>=crna && plava>=crvena && plava>=bijela && plava>=siva){
        if(crna==plava){
            if(prva_crna<prva_plava) 
                printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
            else
                printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
        }
        else if(plava==crvena){
            if(prva_plava<prva_crvena) 
                printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
            else
                printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
        }
        else if(plava==bijela){
            if(prva_plava<prva_bijela) 
                printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
            else
                printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
        }
        else if(plava==siva){
            if(prva_plava<prva_siva) 
                printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
            else
                printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
        }
        else{
            printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
        }
    }
    else if(crvena>=plava && crna<=crvena && crvena>=bijela && crvena>=siva){
        if(crvena==plava){
            if(prva_crvena<prva_plava) 
                printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
            else
                printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
        }
        else if(crna==crvena){
            if(prva_crna<prva_crvena) 
                printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
            else
                printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
        }
        else if(crvena==bijela){
            if(prva_crvena<prva_bijela) 
                printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
            else
                printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
        }
        else if(crvena==siva){
            if(prva_crvena<prva_siva) 
                printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
            else
                printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
        }
        else printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
    }
    else if(bijela>=plava && bijela>=crvena && crna<=bijela && bijela>=siva){
        if(bijela==plava){
            if(prva_bijela<prva_plava) 
                printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
            else
                printf("Najpopularnija boja je plava (%.2f%%).",(float)(plava*100)/ukupno);
        }
        else if(bijela==crvena){
            if(prva_bijela<prva_crvena) 
                printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
            else
                printf("Najpopularnija boja je crvena (%.2f%%).",(float)(crvena*100)/ukupno);
        }
        else if(crna==bijela){
            if(prva_crna<prva_bijela) 
                printf("Najpopularnija boja je crna (%.2f%%).",(float)(crna*100)/ukupno);
            else
                printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
        }
        else if(bijela==siva){
            if(prva_bijela<prva_siva) 
                printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
            else
                printf("Najpopularnija boja je siva (%.2f%%).",(float)(siva*100)/ukupno);
        }
        else printf("Najpopularnija boja je bijela (%.2f%%).",(float)(bijela*100)/ukupno);
    }
    
    return 0;
}