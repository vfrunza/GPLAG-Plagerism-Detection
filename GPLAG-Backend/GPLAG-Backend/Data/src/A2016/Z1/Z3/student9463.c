#include <stdio.h>

int main() {
    char inpt, unos;
    int blk=0, wht=0, gry=0, red=0, blu=0, i=0;
    float blkp, whtp, gryp, redp, blup;
    printf("Unesite vozila: ");
    do{
        scanf("%c", &inpt);
        if( ((inpt!='C') && (inpt!='B') && (inpt!='S') && (inpt!='V') && (inpt!='P') && (inpt!='K')) && ((inpt!='c') && (inpt!='b') && (inpt!='s') && (inpt!='v') && (inpt!='p')) && (inpt!='k') ){
            printf("Neispravan unos\n");
        }
                 if(inpt== 'C' || inpt== 'c'){
                blk++;
            }
            else if(inpt== 'B' || inpt== 'b'){
                wht++;
            }
            else if(inpt== 'S' || inpt== 's'){;
                gry++;
            }
            else if(inpt== 'V' || inpt== 'v'){
                red++;
            }
            else if(inpt== 'P' || inpt== 'p'){
                blu++;
            }
            if((inpt!='k' && inpt!='K') && ((inpt=='C') || (inpt=='c') || (inpt=='B') || (inpt=='b') || (inpt=='S') || (inpt=='s') || (inpt=='V') || (inpt=='v') || (inpt=='P') || (inpt=='p'))){
                i++;
            }
            if(inpt=='k' || inpt=='K'){
                break;
            }
    }while(inpt != 'k');
    printf("Ukupno evidentirano %d vozila.\n", i);
    blkp = ((blk)/((float)i))*100;
    whtp = ((wht)/((float)i))*100;
    gryp = ((gry)/((float)i))*100;
    redp = ((red)/((float)i))*100;
    blup = ((blu)/((float)i))*100;
         if(((blk >= wht) && (blk >= gry) && (blk >= red) && (blk >= blu)) && i==0){
             printf("Najpopularnija boja je crna (0.00%).");
         }
    else if((blk >= wht) && (blk >= gry) && (blk >= red) && (blk >= blu)){
             printf("Najpopularnija boja je crna (%.2f%).", blkp);
    }
    else if((wht >= blk) && (wht >= gry) && (wht >= red) && (wht >= blu)){
            printf("Najpopularnija boja je bijela (%.2f%).", whtp);
    }
    else if((gry >= wht) && (gry >= blk) && (gry >= red) && (gry >= blu)){
            printf("Najpopularnija boja je siva (%.2f%).", gryp);
    }
    else if((red >= wht) && (red >= gry) && (red >= blk) && (red >= blu)){
            printf("Najpopularnija boja je crvena (%.2f%).", redp);        
    }
    else if((blu >= wht) && (blu >= gry) && (blu >= red) && (blu >= blk)){
            printf("Najpopularnija boja je plava (%.2f%).", blup);        
    }
    
}