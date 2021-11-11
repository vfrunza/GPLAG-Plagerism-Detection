#include <stdio.h>

int main ()
{
    char m;
    int n=0;
    double bc=0.00, bb=0.00, bs=0.00, bp=0.00, bv=0.00;
    double cr=0,bi=0,si=0,pl=0,vr=0;
    printf("Unesite vozila: ");
    scanf("%c", &m);
    while (m!='k' && m!='K')
    {
    if(m=='c' || m=='C')
    { bc++;
      n++;
    } else if (m=='b' || m=='B')
    { bb++;
    n++;
    } else if(m=='v' || m=='V')
    { bv++;
    n++;
    } else if(m=='p' || m=='P')
    { bp++;
    n++;
    } else if(m=='s' || m=='S')
    { bs++;
    n++ ;
    }
    else if(m=='k' || m=='K'){
      
    } else{
        printf("Neispravan unos \n");
       
    }
    scanf ("%c", &m);
}
printf("Ukupno evidentirano %d vozila.\n",n);
{if (n!=0){
    cr=bc/n*100;
    bi=bb/n*100;
    vr=bv/n*100;
    si=bs/n*100;
    pl=bp/n*100; }
else { bi=0.00;si=0.00;vr=0.00;pl=0.00;cr=0.00;}}

if(bc>=bb && bc>=bs && bc>=bv && bc>=bp){
    printf("Najpopularnija boja je crna (%.2lf%%).",cr);
}else if(bb>=bc && bb>=bs && bb>=bv && bb>=bp){
    printf("Najpopularnija boja je bijela (%.2lf%%).",bi);
} else if(bs>=bb && bs>=bc && bs>=bv && bs>=bp){
    printf("Najpopularnija boja je siva (%.2lf%%).",si);
} else if (bv>=bc && bv>=bs && bv>=bb && bv>=bp){
    printf("Najpopularnija boja je crvena (%.2lf%%).",vr);
} else if (bp>=bc && bp>=bs && bp>=bv && bp>=bb) {
    printf("Najpopularnija boja je plava (%.2lf%%).",pl);
}
    return 0;
    }
    
    
    
    
    
    
    