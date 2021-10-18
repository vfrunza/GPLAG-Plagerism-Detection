#include <stdio.h>
int main ( ){
 char x;
 int i, c=0, b=0, s=0, v=0, p=0, max=0;
 float procenat, najcesci;
 printf("Unesite vozila: ");
 for (i=1; i>0; i++) {
  scanf("%c", &x);
  if (x=='c' || x=='C'){ 
   c++;
   max++;}
   else if (x=='b' || x=='B'){
    b++;
    max++;}
    else if (x=='s' || x=='S'){
    s++;
    max++;}
    else if (x=='v' || x=='V'){
    v++;
    max++;}
    else if (x=='p' || x=='P'){
    p++;
    max++;}
    else if (x=='k' || x=='K'){
     break;}
     else if (x!='k' && x!='b' &&  x!='c' && x!='s' && x!='v' && x!='p' && x!='K' && x!='B' && x!='C' && x!='S' && x!='V' && x!='P')
     { printf("Neispravan unos\n");}
     if (c>=v && c>=b && c>=s && c>=p && c!=0) { najcesci=c;}
     if (v>=c && v>=b && v>=s && v>=p && v!=0) { najcesci=v;}
     if (b>=c && b>=v && b>=s && b>=p && b!=0) { najcesci=b;}
     if (s>=c && s>=b && s>=v && s>=p && s!=0) { najcesci=s;}
     if (p>=c && p>=b && p>=s && p>=v && p!=0) { najcesci=p;}
 }
      procenat=(najcesci/max)*100;
      printf("Ukupno evidentirano %d vozila.\n", max);
      if (max==0) { printf("Najpopularnija boja je crna (0.00%).");
                   return 0;}
      if (najcesci==c) { printf("Najpopularnija boja je crna (%.2f%).", procenat);
                   return 0;}
      if (najcesci==b) { printf("Najpopularnija boja je bijela (%.2f%).", procenat);
                   return 0;}
      if (najcesci==s) { printf("Najpopularnija boja je siva (%.2f%).", procenat);
                   return 0;}    
      if (najcesci==v) { printf("Najpopularnija boja je crvena (%.2f%).", procenat);
                   return 0;}      
      if (najcesci==p) { printf("Najpopularnija boja je plava (%.2f%).", procenat);
                   return 0;}
      return 0;
}
    