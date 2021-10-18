#include <stdio.h>

int main(){
    char n;
    int brc=0,brb=0,brs=0,brv=0,brp=0,u;
    float bru=0;
    printf("Unesite vozila: ");
    do {
        scanf("%c",&n);
        if (n=='c' || n=='C') {
            brc++;
            bru++;
        }
        else if (n=='b' || n=='B') {
            brb++;
            bru++;
        }
        else if (n=='s' || n=='S') {
            brs++;
            bru++;
        } 
        else if (n=='v' || n=='V') {
            brv++;
            bru++;
        }
        else if (n=='p' || n=='P') {
            brp++;
            bru++;
        }
        else if (n!='c' && n!='C' && n!='b' && n!='B' && n!='s' && n!='S'&& n!='v' && n!='V'&& n!='p' && n!='P' && n!='\n' && n!='k' && n!='K' ) {
           printf("Neispravan unos\n");
           
        }       
       
    } while(n!='K' && n!='k');
    u=(int)bru;
    printf("Ukupno evidentirano %d vozila.",u);
    if(brc>=brb && brc>=brs && brc>=brv && brc>=brp) printf("\nNajpopularnija boja je crna (%.2f%%).",(brc/bru)*100.);
    else if(brb>=brc && brb>=brs && brb>=brv && brb>=brp) printf("\nNajpopularnija boja je bijela (%.2f%%).",(brb/bru)*100.);
    else if(brs>=brb && brs>=brc && brs>=brv && brs>=brp) printf("\nNajpopularnija boja je siva (%.2f%%).",(brs/bru)*100.);
    else if(brv>=brb && brv>=brs && brv>=brc && brv>=brp) printf("\nNajpopularnija boja je crvena (%.2f%%).",(brv/bru)*100.);
    else if(brp>=brb && brp>=brs && brp>=brv && brp>=brc) printf("\nNajpopularnija boja je plava (%.2f%%).",(brp/bru)*100.);
    else if (bru==0) printf("\nNajpopularnija boja je crna (0.00%%).");
    return 0;
    
}