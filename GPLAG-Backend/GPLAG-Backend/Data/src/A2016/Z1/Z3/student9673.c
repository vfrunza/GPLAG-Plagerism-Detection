#include <stdio.h>

int main() {
char a,maxz;
int brc=0,brb=0,brs=0,brv=0,brp=0,bru,max=0;
double broj,broj1=0;
printf("Unesite vozila: ");
while(1==1)
{
scanf("%c",&a);
if(a=='C' || a=='c')
{
brc++;
if(brc>max)
{
max=brc;
maxz='C';
}
continue;
}
if(a=='S' || a=='s')
{
brs++;
if(brs>max)
{
max=brs;
maxz='S';
}
continue;
}
if(a=='b' || a=='B')
{
brb++;
if(brb>max)
{
max=brb;
maxz='B';
}
continue;
}
if(a=='V' || a=='v')
{
brv++;
if(brv>max)
{
max=brv;
maxz='V';
}
continue;
}
if(a=='p' || a=='P')
{
brp++;
if(brp>max)
{
max=brp;
maxz='P';
}
continue;
}
if(a=='K' || a=='k')
{
break;
}
else
{
printf("Neispravan unos\n");
continue;
}
}
bru=brc+brp+brv+brs+brb;
if(bru!=0)
{
broj=(max*100.)/bru;
printf("Ukupno evidentirano %d vozila.\n",bru);
if(maxz=='C')
{
printf("Najpopularnija boja je crna (%.2f%%).",broj);
}
else if(maxz=='B')
{
printf("Najpopularnija boja je bijela (%.2f%%).",broj);
}
else if(maxz=='V')
{
printf("Najpopularnija boja je crvena (%.2f%%).",broj);
}
else if(maxz=='P')
{
printf("Najpopularnija boja je plava (%.2f%%).",broj);
}
else if(maxz=='S')
{
printf("Najpopularnija boja je siva (%.2f%%).",broj);
}
}
else if(bru==0)
{
printf("Ukupno evidentirano 0 vozila.\n");
printf("Najpopularnija boja je crna (%.2f%%).",broj1);
}
return 0;
}




