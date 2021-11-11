#include <stdio.h>   

int main()
{
    int c, bc=0, bb=0, bs=0, bp=0, bv=0, ukupnobr;
    float postotak;
    printf("Unesite vozila: ");
    do {
        
        c=getchar();
        
        if (c=='B' || c=='b')
        {
            bb++;
        }
        
        if (c=='C' || c=='c')
        {
            bc++;
        }
        
        if (c=='V' || c=='v')
        {
            bv++;
        }
        
        if (c=='S' || c=='s')
        {
            bs++;
        }
        
        if (c=='P' || c=='p')
        {
            bp++;
        }
        
        if (c!='B' && c!='b'&& c!='P' && c!='p' && c!='V' && c!='v' && c!='C' && c!='c' && c!='S' && c!='s' && c!='k' && c!='K')
        {
            printf("Neispravan unos\n");
        }
        
    } while (c!='k' && c!='K');
    
    ukupnobr=bc+bb+bv+bs+bp;
    
    printf("Ukupno evidentirano %d vozila.\n", ukupnobr);

if (ukupnobr!=0)
{
    if (bb>=bc && bb>=bv && bb>=bs && bb>=bp)
    {
        postotak=(float)bb*100./ukupnobr;
        printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
    }
    else if (bc>=bb && bc>=bv && bc>=bs && bc>=bp)
    {
        postotak=(float)bc*100./ukupnobr;
        printf("Najpopularnija boja je crna (%.2f%%).", postotak);
    }
     else if (bs>=bb && bs>=bc && bs>=bv && bs>=bp)
    {
        postotak=(float)bs*100./ukupnobr;
        printf("Najpopularnija boja je siva (%.2f%%).", postotak);
    }
    else if (bv>=bb && bv>=bc && bv>=bs && bv>=bp)
    {
        postotak=(float)bv*100./ukupnobr;
        printf("Najpopularnija boja je crvena (%.2f%%).", postotak);
    }
    else 
    {
        postotak=(float)bp*100./ukupnobr;
        printf("Najpopularnija boja je plava (%.2f%%).", postotak);
    }
}
else 
{
    printf("Najpopularnija boja je crna (0.00%%).");
}
return 0;
}