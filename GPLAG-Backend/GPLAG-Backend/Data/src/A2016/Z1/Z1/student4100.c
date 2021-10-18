#include <stdio.h>
int main() {
    double P1T,P2T,pT,zT,ZIT,P1B,P2B,pB,zB,ZIB,P1M,P2M,pM,zM,ZIM,P1,P2,p,z,ZI,TUK,MUK,BUK;
    int TOC,MOC,BOC;
    P1=20;
    P2=20;
    p=10;
    z=10;
    ZI=40;
    
   // Tarik
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit:");
   scanf("%lf", &P1T);
   if(P1T<0 || P1T>P1) {
   printf("Neispravan broj bodova.");
   } 
   else { printf(" II parcijalni ispit:");
   scanf("%lf", &P2T);
   if (P2T<0 || P2T>P2) {
   printf("Neispravan broj bodova.");
   }
   else { printf(" Prisustvo:");
   scanf("%lf", &pT);
   if(pT<0 || pT>p) {
   printf("Neispravan broj bodova.");
   }
   else { printf(" Zadace:");
   scanf("%lf", &zT);
   if (zT<0 || zT>z) {
   printf("Neispravan broj bodova.");
   }
   else { printf(" Zavrsni ispit:");
   scanf("%lf", &ZIT);
   if (ZIT<0 || ZIT>ZI) {
   printf("Neispravan broj bodova.");
   }
       
    //Bojan
    printf(" Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit:");
   scanf("%lf", &P1B);
   if(P1B<0 || P1B>P1) {
   printf(" Neispravan broj bodova");
   } 
   else { printf(" II parcijalni ispit:");
   scanf("%lf", &P2B);
   if (P2B<0 || P2B>P2) {
   printf("Neispravan broj bodova");
   }
   else { printf(" Prisustvo:");
   scanf("%lf", &pB);
   if(pB<0 || pB>p) {
   printf("Neispravan broj bodova");
   }
   else { printf(" Zadace:");
   scanf("%lf", &zB);
   if (zB<0 || zB>z) {
   printf("Neispravan broj bodova");
   }
   else { printf(" Zavrsni ispit:");
   scanf("%lf", &ZIB);
   if (ZIB<0 || ZIB>ZI) {
   printf("Neispravan broj bodova");
   }
   
   //Mirza
   printf(" Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit:");
   scanf("%lf", &P1M);
   if(P1M<0 || P1M>P1) {
   printf("Neispravan broj bodova");
   } 
   else { printf(" II parcijalni ispit:");
   scanf("%lf", &P2M);
   if (P2M<0 || P2M>P2) {
   printf("Neispravan broj bodova");
   }
   else { printf(" Prisustvo:");
   scanf("%lf", &pM);
   if(pM<0 || pM>p) {
   printf(" Neispravan broj bodova");
   }
   else { printf(" Zadace:");
   scanf("%lf", &zM);
   if (zM<0 || zM>z) {
   printf("Neispravan broj bodova");
   }
   else { printf(" Zavrsni ispit:");
   scanf("%lf", &ZIM);
   if (ZIM<0 || ZIM>ZI) {
   printf("Neispravan broj bodova");
   }
    
   else {
       TUK=P1T+P2T+pT+zT+ZIT;
       BUK=P1B+P2B+pB+zB+ZIB;
       MUK=P1M+P2M+pM+zM+ZIM;
       
       if (TUK>=55 && TUK<65) {TOC=6;}
       else if (TUK>=65 && TUK<75) {TOC=7;}
       else if (TUK>=75 && TUK<85) {TOC=8;}
       else if (TUK>=85 && TUK<92) {TOC=9;}
       else if (TUK>=92 && TUK<=100) {TOC=10;}
       
        if (BUK>=55 && BUK<65) {BOC=6;}
       else if (BUK>=65 && BUK<75) {BOC=7;}
       else if (BUK>=75 && BUK<85) {BOC=8;}
       else if (BUK>=85 && BUK<92) {BOC=9;}
       else if (BUK>=92 && BUK<=100) {BOC=10;}
       
        if (MUK>=55 && MUK<65) {MOC=6;}
       else if (MUK>=65 && MUK<75) {MOC=7;}
       else if (MUK>=75 && MUK<85) {MOC=8;}
       else if (MUK>=85 && MUK<92) {MOC=9;}
       else if (MUK>=92 && MUK<=100) {MOC=10;}
       
   if(TUK<55 && BUK<55 && MUK<55) {
       printf(" Nijedan student nije polozio.");
   }
   else if (TUK>54 && BUK>54 && MUK>54) {
       printf(" Sva tri studenta su polozila.\n");
    if (TOC==BOC && TOC==MOC) { 
        printf("Sva tri studenta imaju istu ocjenu.\n");}
    else if (TOC!=BOC && TOC!=MOC && BOC!=MOC) {
    printf("Svaki student ima razlicitu ocjenu.");}
    else {printf("Dva od tri studenta imaju istu ocjenu.");}
   }
   else if ((TUK>54 && BUK<55 && MUK<55) || (TUK<55 && BUK>54 && MUK<55) || (TUK<55 && BUK<55 && MUK>54)) {
       printf(" Jedan student je polozio.");}
   else { printf(" Dva studenta su polozila.");}
   }
   }}}}}}}}}}}}
   
   return 0;
  }
