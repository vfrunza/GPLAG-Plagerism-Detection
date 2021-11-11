#include<stdio.h>

char x;
int sumab=0, sumas=0, sumav=0, sumac=0, sumap=0, suma=0, max=0;
float procenat;
int main() {
    printf("Unesite vozila: ");
    for(;;) {
        scanf("%c", &x);
        
        if     (x=='c' || x=='C') sumac++;
        else if(x=='b' || x=='B') sumab++;
        else if(x=='s' || x=='S') sumas++;
        else if(x=='v' || x=='V') sumav++;
        else if(x=='p' || x=='P') sumap++;
        else if(x=='k' || x=='K') break;
        else {printf("Neispravan unos\n"); continue;}
        
    }
    
    suma=sumab+sumas+sumav+sumap+sumac;
     
     
     if(sumac>max) max=sumac;
     if(sumab>max) max=sumab;
     if(sumas>max) max=sumas;
     if(sumav>max) max=sumav;
     if(sumap>max) max=sumap;
     
     procenat=(max*100.)/suma; 
     if(suma==0) procenat=0;
     
     printf("Ukupno evidentirano %d vozila.\n", suma);
     printf("Najpopularnija boja je ");
     
     if(max==sumac) printf("crna (%.2f%%).", procenat);
     else if(max==sumab) printf("bijela (%.2f%%).", procenat);
     else if(max==sumas) printf("siva (%.2f%%).", procenat);
     else if(max==sumav) printf("crvena (%.2f%%).", procenat);
     else if(max==sumap) printf("plava (%.2f%%).", procenat);

     else printf("crna (0.00%%).");
     return 0;
}