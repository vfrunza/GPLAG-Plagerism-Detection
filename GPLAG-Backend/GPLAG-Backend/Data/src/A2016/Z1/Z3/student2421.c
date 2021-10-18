#include <stdio.h>
#define EPSILON 0.0001

int main() {
    float c=0,b=0,s=0,crv=0,p=0;
    float n=0,pc=0.0,pcrv=0.0,pb=0.0,ps=0.0,pp=0.0;
    char vo;
    printf("Unesite vozila: ");
    do {
        scanf("%c",&vo);
        if ((vo=='C') || (vo=='c')){
            c++;
            continue;
        }
        if ((vo=='B') || (vo=='b')){
            b++;
            continue;
        }
        if ((vo=='S') || (vo=='s')){
            s++;
            continue;
        }
        if ((vo=='V') || (vo=='v')){
            crv++;
            continue;
        }
        if ((vo=='P') || (vo=='p')){
            p++;
            continue;
        }
        if((vo!='P' && vo!='p') && (vo!='V' && vo!='v') && (vo!='S' && vo!='s') && (vo!='B' && vo!='b') && (vo!='C' && vo!='c') && (vo!='K' && vo!='k')){
            printf("Neispravan unos\n");
        }
    }
    while ((vo!='K') && (vo!='k'));
    
    n=c+b+s+crv+p;
    
    printf("Ukupno evidentirano %g vozila.\n",n);
    
    if ((n-0)>EPSILON){
        pc=(c*100)/n;
        pb=(b*100)/n;
        ps=(s*100)/n;
        pcrv=(crv*100)/n;
        pp=(p*100)/n;
    }
    
    if ((c>=b)&&(c>=s)&&(c>=crv)&&(c>=p)){
        printf("Najpopularnija boja je crna (%.2f%%).",pc);
        return 0;
    }
    if ((b>=c)&&(b>=s)&&(b>=crv)&&(b>=p)){
        printf("Najpopularnija boja je bijela (%.2f%%).",pb);
        return 0;
    }
    if ((s>=c)&&(s>=b)&&(s>=crv)&&(s>=p)){
        printf("Najpopularnija boja je siva (%.2f%%).",ps);
        return 0;
    }
    if ((crv>=c)&&(crv>=b)&&(crv>=s)&&(crv>=p)){
        printf("Najpopularnija boja je crvena (%.2f%%).",pcrv);
        return 0;
    }
    if ((p>=c)&&(p>=b)&&(p>=s)&&(p>=crv)){
        printf("Najpopularnija boja je plava (%.2f%%).",pp);
        return 0;
    }
    
    return 0;
}