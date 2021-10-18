#include <stdio.h>


int main () {
    char t, b, m, e;
    float cr=0, cf=0, cb=0, pop=0, maxp=0;
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &t);
    scanf("%c", &e);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &b);
    scanf("%c", &e);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &m);
    
    if(t=='P' || b=='P' || m=='P') pop=0.68;
    if(t=='p' && b=='P' || t=='P' && m=='P' || b=='P' && m=='P') pop=1.36;
    if(t=='P' && b=='P' && m=='P') pop=2.04;
    if(maxp<pop)maxp=pop;
    
    if(t=='C' || b=='C' || m=='C') pop=0.5;
    if(t=='C' && b=='C' || t=='C' && m=='C' || b=='C' && m=='C') pop=1;
    if(t=='C' && b=='C' && m=='C') pop=1.5;
    if(maxp<pop)maxp=pop;
    
    if(t=='H' || b=='H' || m=='H') pop=0.33;
    if(t=='H' && b=='H' || t=='H' && m=='H' || b=='H' && m=='H') pop=0.66;
    if(t=='H' && b=='H' && m=='H') pop=0.99;
    if(maxp<pop)maxp=pop;
    
    if(t=='P'){
        cr+=6.8;
        cf+=8;
        cb+=5.3;
    }
    else if(t=='H'){
        cr+=3.3;
        cf+=3;
        cb+=5;
    }
    else{
        cr+=5;
        cf+=3.9;
        cb+=6;
    }
    
     if(b=='P'){
        cr+=6.8;
        cf+=8;
        cb+=5.3;
    }
    else if(b=='H'){
        cr+=3.3;
        cf+=3;
        cb+=5;
    }
    else{
        cr+=5;
        cf+=3.9;
        cb+=6;
    }
     if(m=='P'){
        cr+=6.8;
        cf+=8;
        cb+=5.3;
    }
    else if(m=='H'){
        cr+=3.3;
        cf+=3;
        cb+=5;
    }
    else{
        cr+=5;
        cf+=3.9;
        cb+=6;
    }
    
    float min;
    if(cr<cf && cr<cb)min=cr;
    else if(cf<cr && cf<cb)min=cf;
    else min=cb;
    
    if(min==cr) 
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%0.2f KM).", min);
    else if (min==cf)
        printf("Najjeftiniji je Fast-food \"Trovac\" (%0.2f KM).", min);
    else
        printf("Najjeftiniji je Bistro \"Lorelei\" (%0.2f KM).", min);
    printf("\n");
    
    if(min!=cr){
        if(cr-maxp<min)
            printf("Sa popustom bi Restoran bio jeftiniji (%0.2f KM).", cr-maxp);
    }
    return 0;
}