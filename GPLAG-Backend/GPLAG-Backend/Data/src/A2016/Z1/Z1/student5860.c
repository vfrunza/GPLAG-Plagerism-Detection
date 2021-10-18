#include <stdio.h>
#define GGP1 20.0
#define GGP2 20.0
#define GGZA 10.0
#define GGP 10.0
#define GGZ 40.0

int main() {
    
	double MP1, MP2, MZA, MP, MZ, TP1, TP2, TZA, TP, TZ, BP1, BP2, BZA, BP, BZ;
	double SUMAM, SUMAT, SUMAB;
	int OT, OM, OB;
	
  scanf("%lf", &TP1);
  printf("Unesite bodove za Tarika: \n");
  printf("I parcijalni ispit: ");
  if(TP1<0 || TP1>GGP1){
     printf("Neispravan broj bodova ");
          return 0;
}
  scanf("%lf", &TP2);
  printf("II parcijalni ispit: ");
  if(TP2<0 || TP2>GGP2){
    printf("Neispravan broj bodova ");
      return 0;
}

scanf("%lf", &TP);
printf("Prisustvo: ");
if(TP<0 || TP>GGP){
     printf("Neispravan broj bodova ");
    return 0;
}
scanf("%lf", &TZA);
printf("Zadace: ");
if(TZA<0 || TZA>GGZA){
   printf("Neispravan broj bodova ");
  
 return 0;
}
scanf("%lf", &TZ);
printf("Zavrsni ispit: ");
if(TZ<0 || TZ>GGZ){ 
     printf("Neispravan broj bodova "); 
    return 0;
}
   scanf("%lf", &BP1);
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   
  if(BP1<0 || BP1>GGP1){ 
   printf("Neispravan broj bodova ");
    return 0;
}
    scanf("%lf", &BP2);
    printf("II parcijalni ispit: ");
   
if(BP2<0 || BP2>GGP2){
  printf("Neispravan broj bodova ");
 return 0;
}


 scanf("%lf", &BP);
 printf("Prisustvo: ");
 
if(BP<0 || BP>GGP){
  printf("Neispravan broj bodova ");
 return 0;
}
 scanf("%lf", &BZA);
 printf("Zadace: ");
  
if(BZA<0 || BZA>GGZA){
  printf("Neispravan broj bodova ");
 return 0;
}

   scanf("%lf", &BZ);
   printf("Zavrsni ispit: ");
if(BZ<0 || BZ>GGZ){
  printf("Neispravan broj bodova ");
 return 0;
}
   
   scanf("%lf", &MP1);
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
       
if(MP1<0 || MP1>GGP1) {       
 printf("Neispravan broj bodova ");
 return 0;
}
scanf("%lf", &MP2);
printf("II parcijalni ispit: ");
  
if(MP2<0 || MP2>GGP2){
 printf("Neispravan broj bodova ");
 return 0;
}

   scanf("%lf", &MP);
   printf("Prisustvo: ");
   
if(MP<0 || MP>GGP){
  printf("Neispravan broj bodova ");
 return 0;
}

scanf("%lf", &MZA);
printf("Zadace: ");
   
if(MZA<0 || MZA>GGZA){
  printf("Neispravan broj bodova ");
 return 0;
}

scanf("%lf", &MZ);
printf("Zavrsni ispit: ");
if(MZ<0 || MZ>GGZ){
  printf("Neispravan broj bodova ");
 return 0;
}

if((MP1+MP2+MZA+MP+MZ)<55 && (TP1+TP2+TZA+TZ+TP)<55 && (BP1+BP2+BZA+BZ+BP)<55)
printf("Nijedan student nije polozio. ");
else if((MP1+MP2+MZA+MP+MZ)<55 && ((TP1+TP2+TZA+TZ+TP)<55 || (BP1+BP2+BZA+BZ+BP)<55))
printf("Jedan student je polozio. ");
else if((TP1+TP2+TZA+TZ+TP)<55 && ((BP1+BP2+BZA+BZ+BP)<55 || (MP1+MP2+MZA+MP+MZ)<55))
printf("Jedan student je polozio. ");
else if((BP1+BP2+BZA+BZ+BP)<55 && ((TP1+TP2+TZA+TZ+TP)<55 || (MP1+MP2+MZA+MP+MZ)<55))
printf("Jedan student je polozio. ");



if((MP1+MP2+MZA+MP+MZ)<55 && (TP1+TP2+TZA+TZ+TP)>55 && (BP1+BP2+BZA+BZ+BP)>55)
printf("Dva studenta su polozila. ");
else if((MP1+MP2+MZA+MP+MZ)>55 && (TP1+TP2+TZA+TZ+TP)>55 && (BP1+BP2+BZA+BZ+BP)<55)
printf("Dva studenta su polozila. ");
else if((TP1+TP2+TZA+TZ+TP)<55 && ((BP1+BP2+BZA+BZ+BP)>55 && (MP1+MP2+MZA+MP+MZ)>55))
printf("Dva studenta su polozila. ");

if((MP1+MP2+MZA+MP+MZ)>55 && (TP1+TP2+TZA+TZ+TP)>55 && (BP1+BP2+BZA+BZ+BP)>55){
 
printf("Sva tri studenta su polozila. \n");

 SUMAM=MP1+MP2+MZA+MP+MZ;
 SUMAB=BP1+BP2+BZA+BP+BZ;
 SUMAT=TP1+TP2+TZA+TP+TZ;
 
if(SUMAM>=55.0 && SUMAM<65.0){
 OM=6;
}
else if(SUMAM>=65.0 && SUMAM<75.0){
 OM=7;
}
else if(SUMAM>=75.0 && SUMAM<85.0){
 OM=8;
}
else if(SUMAM>=85.0 && SUMAM<92.0){
 OM=9;}
 else if(SUMAM>=92.0 && SUMAM<100.0){
  OM=10;
}
if(SUMAB>=55.0 && SUMAB<65.0){
 OB=6;
}
else if(SUMAB>=65.0 && SUMAB<75.0){
 OB=7;
}
else if(SUMAB>=75.0 && SUMAB<85.0){
 OB=8;
}
else if(SUMAB>=85.0 && SUMAB<92.0){
 OB=9;}
 else if(SUMAB>=92.0 && SUMAB<100.0){
  OB=10;
}
if(SUMAT>=55.0 && SUMAT<65.0)
 OT=6;

else if(SUMAT>=65.0 && SUMAT<75.0)
 OT=7;
else if(SUMAT>=75.0 && SUMAT<85.0)
 OT=8;

else if(SUMAT>=85.0 && SUMAT<92.0)
 OT=9;
 else if(SUMAT>=92.0 && SUMAT<=100.0)
  OT=10;


  if((OT==OM) && (OM==OB) && (OT==OB)){
   printf("Sva tri studenta imaju istu ocjenu. \n");
  }

 else if(((OM==OB) && (OM!=OT)) || ((OB==OT) && (OB!=OM)) || ((OT!=OB) && (OT==OM))){
  printf("Dva od tri studenta imaju istu ocjenu. \n");
 }
 else if((OM!=OT) && (OM!=OB) && (OT!=OB)){
  printf("Svaki student ima razlicitu ocjenu. \n");
 }
 
}


	return 0;
}
