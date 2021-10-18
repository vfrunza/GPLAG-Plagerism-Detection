#include <stdio.h>
#include <math.h>
#define E 0.00000000000000001

int main() {
	
char t='t';
int s;
float a=0;
float b=0;
float c=0;
float  d=0;
float  e=0;
float j;

s=0;

printf ("Unesite vozila: ");


    
  while (t!='k' && t!='K') {
    scanf ("%c",&t);
    if(t!='\n')
    {
    if (t!='c' && t!='C' && t!='v' && t!='V' && t!='p' && t!='P' && t!='b' && t!='B'&&t!='s' && t!='S' && t!='K' && t!='k')
    {printf ("Neispravan unos\n");}
     if(t=='c' || t=='C') {a=a+1;s=s+1;}
     if(t=='b' || t=='B') {b=b+1;s=s+1;}
     if(t=='s' || t=='S') {c=c+1;s=s+1;}
     if(t=='v' || t=='V') {d=d+1;s=s+1;}
     if(t=='p' || t=='P') {e=e+1;s=s+1;}
    }
 


}  





printf ("Ukupno evidentirano %d vozila.\n",s);
if (fabs(s-0)<E){printf ("Najpopularnija boja je crna (0.00%).");} else {
if (a>=b && a>=c && a>=d && a>=e){ j=(a/s)*100 ;printf ("Najpopularnija boja je crna (%.2f%).",j);}

else {
       if (b>=c && b>=d && b>=e && b>=a){ j=(b/s)*100; printf ("Najpopularnija boja je bijela (%.2f%).",j);}
    
           else {
               if (c>=d && c>=e && c>=a && c>=b) { j=(c/s)*100; printf ("Najpopularnija boja je siva (%.2f%).",j);}
                   else {
                       if(d>=e && d>=a && d>=b && d>=c){ j=(d/s)*100; printf ("Najpopularnija boja je crvena (%.2f%).",j);}
                            else {
                                 if (e>=a && e>=b && e>=c && e>=d){ j=(e/s)*100; printf ("Najpopularnija boja je plava (%.2f%).",j);}
                                    }}}}
}






    return 0;
}


    