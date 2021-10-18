#include <stdio.h>

int main() {
double IT,IIT,ZT,PT,ZIT,UT,IB,IIB,ZB,PB,ZIB,UB,IM,IIM,ZM,PM,ZIM,UM; 
double TB=0.00,BB=0.00, MB=0.00;
printf("Unesite bodove za Tarika:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&IT);
if(IT<0 || IT>20 ) {
printf("Neispravan broj bodova"); 
 return 0; }
 
printf("II parcijalni ispit: ");
scanf("%lf",&IIT);
if(IIT<0 || IIT>20 ) {
    printf("Neispravan broj bodova");
    return 0; } 
    
    printf("Prisustvo: ");
scanf("%lf",&PT);
if(PT<0 || PT>10 ) {
    printf("Neispravan broj bodova");
return 0; } 
printf("Zadace: ");
scanf("%lf",&ZT);
if(ZT<0 || ZT>10 ) {
    printf("Neispravan broj bodova"); 
    return 0;}

printf("Zavrsni ispit: ");
scanf("%lf",&ZIT);
if(ZIT<0 || ZIT>40 ) {
    printf("Neispravan broj bodova");
    return 0; } 



printf("Unesite bodove za Bojana:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&IB);
if(IB<0 || IB>20 ) {
    printf("Neispravan broj bodova");
return 0; } 
printf("II parcijalni ispit: ");
scanf("%lf",&IIB);
if(IIB<0 || IIB>20 ) {
    printf("Neispravan broj bodova");
return 0;} 
printf("Prisustvo: ");
scanf("%lf",&PB);
if(PB<0 || PB>10 ) {
    printf("Neispravan broj bodova");
return 0;} 
printf("Zadace: ");
scanf("%lf",&ZB);
if(ZB<0 || ZB>10 ) {
    printf("Neispravan broj bodova");
return 0;} 

printf("Zavrsni ispit: ");
scanf("%lf",&ZIB);
if(ZIB<0 || ZIB>40 ) {
    printf("Neispravan broj bodova");
    return 0;}


printf("Unesite bodove za Mirzu:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&IM);
if(IM<0 || IM>20 ) {
    printf("Neispravan broj bodova");
return 0;} 
printf("II parcijalni ispit: ");
scanf("%lf",&IIM);
if(IIM<0 || IIM>20 ) {
    printf("Neispravan broj bodova");
return 0;} 
printf("Prisustvo: ");
scanf("%lf",&PM);
if(PM<0 || PM>10 ) {
    printf("Neispravan broj bodova");
return 0;}
printf("Zadace: ");
scanf("%lf",&ZM);
if(ZM<0 || ZM>10 ) {
    printf("Neispravan broj bodova");
   return 0; }
    
printf("Zavrsni ispit: ");
scanf("%lf",&ZIM);
if(ZIM<0 || ZIM>40 ) {
    printf("Neispravan broj bodova");
return 0;} 


TB=IT+IIT+ZT+PT+ZIT;
BB=IB+IIB+ZB+PB+ZIB;
MB=IM+IIM+ZM+PM+ZIM;

UT=0;
UB=0;
UM=0;

if(TB<55 && BB<55 && MB<55){
    printf("Nijedan student nije polozio.");
    } else if (TB<55 && BB>=55 && MB>=55 || TB>=55 && BB>=55 && MB<55 || TB>=55 && MB>=55 && BB<55){
  printf ("Dva studenta su polozila.\n");
} else if  (TB>=55 && BB<55 && MB<55 || TB<55 && MB>=55 && BB<55 || TB<55 && MB<55 && BB>=55 ){
   printf("Jedan student je polozio.\n");

 } else if (TB>55 && BB>55 && MB>55){
 printf("Sva tri studenta su polozila.\n");
}
if (TB>=55 && TB<65){
UT=6;
}else if  (TB>=65 && TB<75){
UT=7;
}else if  (TB>=75 && TB<85){
UT=8;
}else if  (TB>=85 && TB<92){
UT=9;
}else if  (TB>=92 && TB<100){
UT=10;
}
 if (MB>=55 && MB<65){
UM=6;
}else if  (MB>=65 && MB<75){
UM=7;
}else if  (MB>=75 && MB<85){
UM=8;
}else if  (MB>=85 && MB<92){
UM=9;
}else if  (MB>=92 && MB<100){
UM=10;
}



 if (BB>=55 && BB<=65){
UB=6;
} else if  (BB>=65 && BB<75){
UB=7;
}else if  (BB>=75 && BB<85){
UB=8;
}else if  (BB>=85 && BB<92){
UB=9;
}else if  (BB>=92 && BB<100){
UB=10;
}
if(TB>=55 && TB<=100 && MB>=55 && MB<=100 && BB>=55 && BB<=100 && UB==UT && UT==UM )
{  printf("Sva tri studenta imaju istu ocjenu.");
 } else if  (TB>=55 && TB<=100 && MB>=55 && MB<=100 && BB>=55 && BB<=100 && ((UB==UM && UM!=UB) || (UM==UB && UB!=UT) || (UT==UB && UM!=UB))){
 printf("Dva od tri studenta imaju istu ocjenu.");
 } else if  (TB>=55 && TB<=100 && MB>=55 && MB<=100 && BB>=55 && BB<=100 && (UM!=UT && UT!=UB && UM!=UB)) {
 printf("Svaki student ima razlicitu ocjenu.");
 }
 
 return 0;
 }
