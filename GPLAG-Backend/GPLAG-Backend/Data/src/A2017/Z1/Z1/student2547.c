#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    char tarik,bojan,mirza,novi_red;
    float racun1=0,racun2=0,racun3=0,popust=0;
    int najjeftinije=0;
    printf("Unesite jelo za Tarika: ");
    scanf("%c",&tarik);
    scanf("%c",&novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&bojan);
    scanf("%c",&novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&mirza);
    scanf("%c",&novi_red);
    /* Restoran     Fast Food       Bistor
    P   6,80KM       8,00KM         5,30KM  
    H   3.30KM       3,00KM         5,00KM  
    C   5,00KM       3,90KM         6,00KM  
        racun1       racun2         racun3*/
    if(tarik=='P')
    {
        racun1=racun1+6.80;
        racun2=racun2+8.00;
        racun3=racun3+5.30;
    }
    else if(tarik=='H')
    {
        racun1=racun1+3.30;
        racun2=racun2+3.00;
        racun3=racun3+5.00;
    }
    else if(tarik=='C')
    {
        racun1=racun1+5.00;
        racun2=racun2+3.90;
        racun3=racun3+6.00;
    }
    if(bojan=='P')
    {
        racun1=racun1+6.80;
        racun2=racun2+8.00;
        racun3=racun3+5.30;
    }
    else if(bojan=='H')
    {
        racun1=racun1+3.30;
        racun2=racun2+3.00;
        racun3=racun3+5.00;
    }
    else if(bojan=='C')
    {
        racun1=racun1+5.00;
        racun2=racun2+3.90;
        racun3=racun3+6.00;
    }
    if(mirza=='P')
    {
        racun1=racun1+6.80;
        racun2=racun2+8.00;
        racun3=racun3+5.30;
    }
    else if(mirza=='H')
    {
        racun1=racun1+3.30;
        racun2=racun2+3.00;
        racun3=racun3+5.00;
    }
    else if(mirza=='C')
    {
        racun1=racun1+5.00;
        racun2=racun2+3.90;
        racun3=racun3+6.00;
    }
    if(racun2<racun1 && racun2<racun3)
    {
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racun2);
    }
    else if(racun1<racun2 && racun1<racun3)
    {
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racun1);
        najjeftinije=1;
    }
    else if(racun3<racun1 && racun3<racun2)
    {
        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racun3);
    }
    if(tarik==bojan && tarik==mirza && bojan==mirza)
    {
        popust=racun1*0.1;
    }
    if((tarik=='P' && mirza!='P' && bojan!='P') || (tarik!='P' && mirza=='P' && bojan!='P') || (tarik!='P' && mirza!='P' && bojan=='P'))
    {
        popust=6.80*0.1;
    }
    else if((tarik=='C' && mirza!='C' && bojan!='C') || (tarik!='C' && mirza=='C' && bojan!='C') || (tarik!='C' && mirza!='C' && bojan=='C'))
    {
        popust=5.00*0.1;
    }
    else if((tarik=='H' && mirza!='H' && bojan!='H') || (tarik!='H' && mirza=='H' && bojan!='H') || (tarik!='H' && mirza!='H' && bojan=='H'))
    {
        popust=3.30*0.1;
    }
    if((tarik=='P' && mirza=='P' && bojan!='P') || (tarik=='P' && mirza!='P' && bojan=='P') || (tarik!='P' && mirza=='P' && bojan=='P'))
    {
        popust=(2*6.80)*0.1;
    }
    else if((tarik=='C' && mirza=='C' && bojan!='C') || (tarik=='C' && mirza!='C' && bojan=='C') || (tarik!='C' && mirza=='C' && bojan=='C'))
    {
        popust=(2*5.00)*0.1;
    }
    else if((tarik=='H' && mirza=='H' && bojan!='H') || (tarik=='H' && mirza!='H' && bojan=='H') || (tarik!='H' && mirza=='H' && bojan=='H'))
    {
        popust=(2*3.30)*0.1;
    }
    racun1=racun1-popust;
    if(racun1<racun2 && racun1<racun3 && najjeftinije!=1)
    {
        printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racun1);
    }
    return 0;
}