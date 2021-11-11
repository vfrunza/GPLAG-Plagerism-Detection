#include <stdio.h>
#include<string.h>
int main()
{
float cr,si,bi,cv,pl,i,cp,sp,bp,cvp,pp,k,l;

char a,j;
cr=0;
si=0;
bi=0;
cv=0;
pl=0;
printf("Unesite vozila: ");
i=0;

do 
{
scanf("%c",&a);
if((a!='0' && a!='1') && (a!=' ') && (a!=',')&&(a=='C'||a=='c'||a=='S'||a=='s'||a=='B'||a=='b'||a=='V'||a=='v'||a=='P'||a=='p'||a=='k'||a=='K')) { i++; }
     if(a!='C'&&a!='c'&&a!='S'&&a!='s'&&a!='B'&&a!='b'&&a!='V'&&a!='v'&&a!='P'&&a!='p'&&a!='K'&&a!='k')
    printf("Neispravan unos\n");{
if ((a=='C') || (a=='c')) cr=cr+1; 
if ((a=='S') || (a=='s')) si=si+1;
if ((a=='B') || (a=='b')) bi=bi+1;
if ((a=='V') || (a=='v')) cv=cv+1;
if ((a=='P') || (a=='p')) pl=pl+1;
}
}
while(a!='k'&& a!='K' );
if(i-1!=0) {
cp=cr/(i-1)*100;
sp=si/(i-1)*100;
bp=bi/(i-1)*100;
cvp=cv/(i-1)*100;
pp=pl/(i-1)*100;
}
else { cp=0;sp=0,bp=0;cvp=0;pp=0; }
printf("Ukupno evidentirano %1.f vozila.\n",i-1);
if(cr>=si&&cr>=bi&&cr>=cv&&cr>=pl)
printf("Najpopularnija boja je crna (%4.2f%).",cp);
if(si>cr&&si>=bi&&si>=cv&&si>=pl)
printf("Najpopularnija boja je siva (%4.2f%).",sp);
if(bi>cr&&bi>si&&bi>=cv&&bi>=pl)
printf("Najpopularnija boja je bijela (%4.2f%).",bp);
if(cv>cr&&cv>si&&cv>bi&&cv>=pl)
printf("Najpopularnija boja je crvena (%4.2f%).",cvp);
if(pl>cr&&pl>si&&pl>bi&&pl>cv)
printf("Najpopularnija boja je plava (%4.2f%).",pp);
   


	return 0;
}
