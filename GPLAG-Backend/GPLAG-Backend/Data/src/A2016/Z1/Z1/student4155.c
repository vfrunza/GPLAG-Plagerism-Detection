#include <stdio.h>


int main() 
{ double P1T, P2T, PRISUSTVOT, ZADACET, ZIT, BODOVIT, P1B, P2B, PRISUSTVOB, ZADACEB, ZIB, BODOVIB, P1M, P2M, PRISUSTVOM, ZADACEM, ZIM, BODOVIM, O1, O2, O3 ;
  
  printf("Unesite bodove za Tarika:\n");
  printf("I parcijalni ispit: ");
  scanf("%lf",&P1T);
  if(P1T>20 || P1T<0) {printf("Neispravan broj bodova");
  return 0;}
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2T);
   if(P2T<0 || P2T>20) {printf("Neispravan broj bodova");
   return 0;}
    printf("Prisustvo: ");
    scanf("%lf", &PRISUSTVOT);
    if(PRISUSTVOT<0 || PRISUSTVOT>10) {printf("Neispravan broj bodova");
    return 0;}
     printf("Zadace: ");
     scanf("%lf", &ZADACET);
     if(ZADACET<0 || ZADACET>10) {printf("Neispravan broj bodova");
     return 0;}
      printf("Zavrsni ispit: ");
      scanf("%lf", &ZIT);
      if(ZIT<0 || ZIT>40) {printf("Neispravan broj bodova");
      }
      
  printf("Unesite bodove za Bojana:\n");
  printf("I parcijalni ispit: ");
  scanf("%lf",&P1B);
  if(P1B>20 || P1B<0) {printf("Neispravan broj bodova");
  return 0;}

   printf("II parcijalni ispit: ");
   scanf("%lf", &P2B);
   if(P2B<0 || P2B>20) {printf("Neispravan broj bodova");
   return 0;}

    printf("Prisustvo: ");
    scanf("%lf", &PRISUSTVOB);
    if(PRISUSTVOB<0 || PRISUSTVOB>10) {printf("Neispravan broj bodova");
    return 0;}

     printf("Zadace: ");
     scanf("%lf", &ZADACEB);
     if(ZADACEB<0 || ZADACEB>10) {printf("Neispravan broj bodova");
     return 0;}

      printf("Zavrsni ispit: ");
      scanf("%lf", &ZIB);
      if(ZIB<0 || ZIB>40) {printf("Neispravan broj bodova");
      }
      
     printf("Unesite bodove za Mirzu:\n");
  printf("I parcijalni ispit: ");
  scanf("%lf",&P1M);
  if(P1M>20 || P1M<0) {printf("Neispravan broj bodova");
  return 0;}

   printf("II parcijalni ispit: ");
   scanf("%lf", &P2M);
   if(P2M<0 || P2M>20) {printf("Neispravan broj bodova");
   return 0;}

    printf("Prisustvo: ");
    scanf("%lf", &PRISUSTVOM);
    if(PRISUSTVOM<0 || PRISUSTVOM>10) {printf("Neispravan broj bodova");
    return 0;}

     printf("Zadace: ");
     scanf("%lf", &ZADACEM);
     if(ZADACEM<0 || ZADACEM>10) {printf("Neispravan broj bodova");
     return 0;}

      printf("Zavrsni ispit: ");
      scanf("%lf", &ZIM);
      if(ZIM<0 || ZIM>40) {printf("Neispravan broj bodova");
      }
    
  BODOVIT=P1T+P2T+PRISUSTVOT+ZADACET+ZIT;
  if(BODOVIT<55){O1=5;}
  else if(BODOVIT<65){O1=6;}
  else if(BODOVIT<75){O1=7;}
  else if(BODOVIT<85){O1=8;}
  else if(BODOVIT<92){O1=9;}
  else {O1=10;}
  
  
  BODOVIB=P1B+P2B+PRISUSTVOB+ZADACEB+ZIB;
  if(BODOVIT<55){O1=5;}
  else if(BODOVIB<65){O2=6;}
  else if(BODOVIB<75){O2=7;}
  else if(BODOVIB<85){O2=8;}
  else if(BODOVIB<92){O2=9;}
  else {O2=10;}
  
  
  BODOVIM=P1M+P2M+PRISUSTVOM+ZADACEM+ZIM;
  if(BODOVIT<55){O1=5;}
  else if(BODOVIM<75){O3=7;}
  else if(BODOVIM<85){O3=8;}
  else if(BODOVIM<92){O3=9;}
  else {O3=10;}
  
  
  if(BODOVIT>=55 && BODOVIB>=55 && BODOVIM>=55)
  {printf("Sva tri studenta su polozila.");}
  else if(BODOVIT>=55 && BODOVIB<55 && BODOVIM<55 || BODOVIT<55 && BODOVIB>=55 && BODOVIM<55 || BODOVIT<55 && BODOVIB>=55 && BODOVIM>=55 || BODOVIT<55 && BODOVIB<55 && BODOVIM>=55)
  {printf("Jedan student je polozio.");}
  else if(BODOVIT<55 && BODOVIB<55 && BODOVIM<55)
  {printf("Nijedan student nije polozio.");}
  else if(BODOVIT>=55 && BODOVIB>=55 && BODOVIM<55 || BODOVIT>=55 && BODOVIB<55 && BODOVIM>=55 || BODOVIT<55 && BODOVIB>=55 && BODOVIM>=55)
  {printf("Dva studenta su polozila.");}
  
  
   
   if(BODOVIT>=55 && BODOVIB>=55 && BODOVIM>=55){
   if(O1==O2 && O1==O3){printf ("\nSva tri studenta imaju istu ocjenu.");}
   else if(O1==O2 && O1!=O3 || O1==O3 && O2!=O3){printf ("\nDva od tri studenta imaju istu ocjenu.");}
   else if(O1!=O2 && O1!=O3) {printf("\nSvaki student ima razlicitu ocjenu.");}}
   
   
   
  
   return 0;
  }
  
  
  
  
  
  
  
  
  
  

  
  
  
  
  
  
  
  
  
  
   
   
  
   
  
      
 
	
