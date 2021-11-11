#include <stdio.h>
int main () {
    int brojac=0;
    double brc=0,brs=0,brv=0,brb=0,brp=0;
    double f=0.00,b=0.00,c=0.00,d=0.00,e=0.00;
    char a;
    printf ("Unesite vozila: ");
    scanf("%c", &a);
    while (a!='k'&& a!='K'){
        if (a=='c'||a=='C'){ brojac++; brc++;}
        else if (a=='b'||a=='B'){ brojac++; brb++;}
        else if (a=='v'||a=='V'){ brojac++; brv++;}
        else if (a=='p'||a=='P'){ brojac++; brp++;}
        else if (a=='s'||a=='S'){ brojac++; brs++;}
        else if (a=='k'||a=='K');
        else { printf("Neispravan unos \n");}
        scanf ("%c", &a);}
    
    printf("Ukupno evidentirano %d vozila.\n",brojac);
    {  if(brojac!=0) {
        f=brc/brojac*100;
        b=brs/brojac*100;
        c=brv/brojac*100;  
        d=brb/brojac*100;
        e=brp/brojac*100;}
        else {f=0.00;b=0.00;c=0.00;d=0.00;e=0.00;}}
    
    if (brc>=brs && brc>=brv && brc>=brb && brc>=brp){ printf("Najpopularnija boja je crna (%.2lf%%).",f);}
    else if (brb>=brc && brb>=brs && brb>=brv && brb>=brp){ printf("Najpopularnija boja je bijela (%.2lf%%).",d);}
    else if (brs>=brc && brs>=brb && brs>=brv && brs>=brp){printf("Najpopularnija boja je siva (%.2lf%%).",b);}
    else if (brv>=brc && brv>=brb && brv>=brs && brv>=brp){printf ("Najpopularnija boja je crvena (%.2lf%%).",c);}
    else printf ("Najpopularnija boja je plava (%.2lf%%).",e);
    return 0;
}