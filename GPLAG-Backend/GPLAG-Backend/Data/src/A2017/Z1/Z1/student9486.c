#include <stdio.h>

int main() {
 double cp, p1=6.80, p2=8.00, p3=5.30, h1=3.30, h2=3.00, h3=5.00, c1=5.00, c2=3.90, c3=6.00, RP, R, F, B;
 char M, Bo, T, novi_red;
 printf ("Unesite jelo za Tarika: ");
 scanf ("%c", &T);
 scanf ("%c", &novi_red); 
 printf ("Unesite jelo za Bojana: ");
 scanf ("%c", &Bo);
 scanf ("%c", &novi_red);
 printf ("Unesite jelo za Mirzu: ");
 scanf ("%c", &M);
 scanf ("%c", &novi_red);
  if (T=='H'&&Bo=='H'&&M=='H'){
  R=3*h1;
  F=3*h2;
  B=3*h3;
  cp=(h1*10)/100;
  RP=R-3*cp;
 }
  else if (T=='C'&& Bo=='C'&& M=='C'){
   R=3*c1;
   F=3*c2;
   B=3*c3;
   cp=(c1*10)/100;
   RP=R-3*cp;
  }
  else if (T=='P' && Bo=='P'&& M=='P'){
   R=3*p1;
   F=3*p2;
   B=3*p3;
   cp=(p1*10)/100;
   RP=R-3*cp;
   }
  else if ((T=='H'&& Bo=='H'&& M=='C')||(T=='H'&&Bo=='C'&&M=='H')||(T=='C'&&Bo=='H'&&M=='H')){
   R=2*h1+c1;
   F=2*h2 +c2;
   B=2*h3+c3;
   if (h1<c1)
   cp=(c1*10)/100;
   else cp=2*(h1*10)/100;
   RP=R- cp;
  }
  else if ((T=='H'&&Bo=='H'&&M=='P')||(T=='H'&&Bo=='P'&&M=='H')||(T=='P'&&Bo=='H'&&M=='H')){
   R=2*h1+p1;
   F=2*h2+p2;
   B=2*h3+p2;
   if (h1<p1)
   cp=(p1*10)/100;
   else  cp=2*(h1*10)/100;
   RP=R-cp;
   }
  else if ((T=='C'&& Bo=='C'&& M=='H')||(T=='C'&& Bo=='H'&&M=='C')||(T=='H'&&Bo=='C'&&M=='C')){
   R=2*c1+h1;
   F=2*c2+h2;
   B=2*c3+h3;
   if (c1<h1)
   cp=(h1*10)/100;
   else cp=2*(c1*10)/100;
   RP=R-cp;
     }
    else if ((T=='C'&& Bo=='C'&& M=='P')|| (T=='C'&& Bo=='P'&& M=='C')||(T=='P'&&Bo=='C'&& M=='C')){
     R=2*c1+p1;
     F=2*c2+p2;
     B=2*c3+p3;
     if (c1<p1)
     cp=(p1*10)/100;
     else cp=2*(c1*10)/100;
     RP= R-cp;
     }
     else if ((T=='P'&& Bo=='P'&& M=='H')||(T=='P'&& Bo=='H'&&M=='P')||(T=='H'&& Bo=='P'&&M=='P')){
     R=2*p1+h1;
     F=2*p2+h2;
     B=2*p3+h3;
     if (p1<h1)
     cp=(h1*10)/100;
     else  cp=2*(p1*10)/100;
     RP=R-cp;
 }
    else if ((T=='P'&& Bo=='P'&&M=='C')||(T=='P'&& Bo=='C'&& M=='P')||(T=='C'&& Bo=='P'&& M=='P')){
     R=2*p1 + c1;
     F=2*p2+c2;
     B=2*p3+c3;
     if (p1<c1)
     cp=(c1*10)/100;
     else cp=2*(p1*10)/100;
     RP=R -cp;
    }
    else if ((T=='P'&& Bo=='H'&&M=='C')||(T=='C'&&Bo=='P'&&M=='H')||(T=='H'&&Bo=='P'&&M=='C')||(T=='C'&& Bo=='H'&&M=='P')||(T=='H'&&Bo=='C'&&M=='P')||(T=='P'&&Bo=='C'&& M=='H')){
     R=c1+h1+p1;
     F=c2+p2+h2;                                                                                                                                                                                                   
     B=c3+h3+p3;
     if (p1>h1 && p1>c1)                                                 
     cp=(p1*10)/100;
     else if (h1>p1&& h1>c1)
     cp=(h1*10)/100;
     else cp=(c1*10)/100;
     RP=R- cp;
     }
     if (R<F && R<B)
     printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", R);
     else if (F<R && F<B){
      printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", F);
      if (RP<F)
      printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", RP); }
      else {
      printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", B);
      if (RP<B)
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", RP); }
      
     
     

 return 0;
}
