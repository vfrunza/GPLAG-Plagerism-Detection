#include <stdio.h>
#include <string.h>

int main() {
    char unos;
    int crna = 0;
    int bijela = 0;
    int siva = 0;
    int crvena = 0;
    int plava = 0;

    
    printf("Unesite vozila:");
    scanf(" %c", &unos);
    
    
    while(unos != 'K' && unos != 'k'){
        if(unos == 'C' || unos == 'c'){
            crna++;
        }
        else if(unos == 'B' || unos == 'b'){
            bijela++;
        }
        else if(unos == 'S' || unos == 's'){
            siva++;
        }
        else if(unos == 'V' || unos == 'v'){
            crvena++;
        }
        else if(unos == 'P' || unos == 'p'){
            plava++;
        }
        scanf("%c", &unos);
        
    }
    
    int ukupno;
    float procenat;
    ukupno = crna + bijela + siva + crvena + plava;
    
    printf(" Ukupno evidentirano %d vozila.", ukupno);
    
    
    if(crna >= bijela && crna >= siva && crna >= crvena && crna >= plava){
        procenat = (crna*100)/(float)ukupno;
        printf("\nNajpopularnija boja je crna (%.2f%%).", procenat);
    }
    else if(bijela >= crna && bijela >= siva && bijela >= crvena && bijela >= plava){
        procenat = (bijela*100)/(float)ukupno;
        printf("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
    }
    

        else if(siva >= crna && siva >= bijela && siva >= crvena && siva >= plava){
        procenat = (siva*100)/(float)ukupno;
        printf("\nNajpopularnija boja je siva (%.2f%%).", procenat);
    }
    
        else if(crvena >= crna && crvena >= bijela && crvena >= siva && crvena >= plava){
        procenat = (crvena*100)/(float)ukupno;
        printf("\nNajpopularnija boja je crvena (%.2f%%).", procenat);
    }
    
        else if(plava >= crna && plava >= bijela && plava >= siva && plava >= crvena){
        procenat = (plava*100)/(float)ukupno;
        printf("\nNajpopularnija boja je plava (%.2f%%).", procenat);
    }
        else 
    {   printf("\nNeispravan unos");
    }
    return 0;
}
