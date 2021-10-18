#include <stdio.h>

int main () {
    int k=0;
    char x, c1='c', c2='C', b1='b', b2='B', s1='s', s2='S', v1='v', v2='V', p1='p', p2='P', k1='k', k2='K';
    double ocp, obp, osp, ovp, opp, oc=0, ob=0, os=0, ov=0, op=0, ou;
    printf("Unesite vozila: ");
    for( ; ; ) {
    x=getchar();
    if(x==k1 || x==k2)
        { break; }
    else if(x==c1 || x==c2)
        { oc=oc+1; }
    else if(x==b1 || x==b2)   
        { ob=ob+1; }
    else if(x==s1 || x==s2)
        { os=os+1; }
    else if(x==v1 || x==v2)
        { ov=ov+1; }
    else if(x==p1 || x==p2)
        { op=op+1; }
    else if(x!=c1 && x!=c2 && x!=b1 && x!=b2 && x!=s1 && x!=s2 && x!=v1 && x!=v2 && x!=p1 && x!=p2 && x!=k1 && x!=k2) 
    { if(k!=0) { printf("\nNeispravan unos"); }
      else if(k<1) { printf("Neispravan unos");
      k++; } }
    }

ou=oc+ob+os+ov+op;

if(k==0)
printf("Ukupno evidentirano %g vozila.", ou);
else if(k!=0)
printf("\nUkupno evidentirano %g vozila.", ou);
ocp=(oc/ou)*100;
obp=(ob/ou)*100; 
osp=(os/ou)*100;
ovp=(ov/ou)*100;
opp=(op/ou)*100;
if(oc==0) ocp=0.00;
if(ob==0) obp=0.00;
if(os==0) osp=0.00;
if(ov==0) ovp=0.00;
if(op==0) opp=0.00;

if(oc>=ob && oc>=os && oc>=ov && oc>=op) 
    { printf("\nNajpopularnija boja je crna (%.2f%%).", ocp); }
else if(ob>oc && ob>=os && ob>=ov && ob>=op) 
    { printf("\nNajpopularnija boja je bijela (%.2f%%).", obp); }
else if(os>oc && os>ob && os>=ov && os>=op) 
    { printf("\nNajpopularnija boja je siva (%.2f%%).", osp); }
else if(ov>oc && ov>ob && ov>os && ov>=op) 
    { printf("\nNajpopularnija boja je crvena (%.2f%%).", ovp); }
else if(op>oc && op>ob && op>ov && op>os) 
    { printf("\nNajpopularnija boja je plava (%.2f%%).", opp); }        

return 0;
} 