#include <stdio.h>
#include <math.h>
const double ep=1e-9;

int main() {
	double p1,p2,pp,z,zi,bodoviT,bodoviB,bodoviM;
	int brojac_polozili,ocjenaM=5,ocjenaB=5,ocjenaT=5;
	

	printf("Unesite bodove za Tarika:");
 printf("\nI parcijalni ispit:"); scanf("%lf",&p1); if(( ( p1-0<ep  )  && (fabs(p1-0)>ep)) ||( (p1-20>ep) && (fabs(p1-20)>ep))) {printf(" Neispravan broj bodova");return 0; } 
 printf(" II parcijalni ispit:");scanf("%lf",&p2);if(( ( (p2-0<ep )&& (fabs(p2-0)>ep)))||( ( p2-20>ep)   &&( fabs(p2-20)>ep))) {printf(" Neispravan broj bodova");return 0; }
 printf(" Prisustvo:"); scanf("%lf",&pp);if (( (pp-0<ep) &&(fabs(pp-0)>ep)) || ((pp-10>ep)&&(fabs(pp-10)>ep))) {printf(" Neispravan broj bodova");return 0; } 
 printf(" Zadace:");scanf("%lf",&z); if ((((z-0<ep )&&(fabs(z-0)>ep)) || ( (z-10>ep) && (fabs(z-10)>ep)))){printf(" Neispravan broj bodova");return 0; } 
 printf(" Zavrsni ispit: ");scanf("%lf",&zi);if (    (  ( zi-0<ep )  &&  ( fabs(zi-0)>ep)) ||(( zi-40>ep) &&(fabs(zi-40)>ep)))    {printf(" Neispravan broj bodova");return 0; }
    bodoviT=p1+p2+pp+z+zi;
    
    if(   (  (bodoviT>55)|| (fabs(bodoviT-55)>ep))   && ( (bodoviT<65 ) )) {ocjenaT=6;}
   else  if(   (  (bodoviT>65)|| (fabs(bodoviT-65)>ep))   && ( (bodoviT<75 ) )) {ocjenaT=7;}
   else  if(   (  (bodoviT>75)|| (fabs(bodoviT-75)>ep))   && ( (bodoviT<85 ) )) {ocjenaT=8;}
   else  if(   (  (bodoviT>85)|| (fabs(bodoviT-85)>ep))   && ( (bodoviT<92 ) ) ){ocjenaT=9;}
   else  if(   (  (bodoviT>92)|| (fabs(bodoviT-92)>ep))   && (fabs(bodoviT-100)<ep))  {ocjenaT=10;}
  
  
 
  
  
  
    
    printf("Unesite bodove za Bojana:");
    printf("\nI parcijalni ispit:"); scanf("%lf",&p1); if(( ( p1-0<ep  )  && (fabs(p1-0)>ep)) ||( (p1-20>ep) && (fabs(p1-20)>ep))) {printf(" Neispravan broj bodova");return 0; } 
    printf(" II parcijalni ispit:");scanf("%lf",&p2);if(( ( (p2-0<ep )&& (fabs(p2-0)>ep)))||( ( p2-20>ep)   &&( fabs(p2-20)>ep))) {printf(" Neispravan broj bodova");return 0; }
    printf(" Prisustvo:"); scanf("%lf",&pp);if (( (pp-0<ep) &&(fabs(pp-0)>ep)) || ((pp-10>ep)&&(fabs(pp-10)>ep))) {printf(" Neispravan broj bodova");return 0; } 
    printf(" Zadace:");scanf("%lf",&z); if ((((z-0<ep )&&(fabs(z-0)>ep)) || ( (z-10>ep) && (fabs(z-10)>ep)))){printf(" Neispravan broj bodova");return 0; } 
    printf(" Zavrsni ispit: ");scanf("%lf",&zi);if (    (  ( zi-0<ep )  &&  ( fabs(zi-0)>ep)) ||(( zi-40>ep) &&(fabs(zi-40)>ep)))    {printf(" Neispravan broj bodova");return 0; }
    bodoviB=p1+p2+pp+z+zi;
   if( (  (bodoviB>55)|| (fabs(bodoviB-55)>ep))     &&  (bodoviB<65 )) {ocjenaB=6;}
  else  if( (  (bodoviB>65)|| (fabs(bodoviB-65)>ep))     &&  (bodoviB<75 ) ) {ocjenaB=7;}
  else  if( (  (bodoviB>75)|| (fabs(bodoviB-75)>ep))    &&  (bodoviB<85 ))  {ocjenaB=8;}
  else  if( (  (bodoviB>85)|| (fabs(bodoviB-85)>ep))    &&  (bodoviB<92 )  ) {ocjenaB=9;}
  else  if( (  (bodoviB>92)|| (fabs(bodoviB-92)>ep))    &&  (fabs(bodoviB-100)<ep)){ocjenaB=10;}
    
    
 
 
    printf("Unesite bodove za Mirzu:");
     printf("\nI parcijalni ispit:"); scanf("%lf",&p1); if(( ( p1-0<ep  )  && (fabs(p1-0)>ep)) ||( (p1-20>ep) && (fabs(p1-20)>ep))) {printf(" Neispravan broj bodova");return 0; } 
    printf(" II parcijalni ispit:");scanf("%lf",&p2);if(( ( (p2-0<ep )&& (fabs(p2-0)>ep)))||( ( p2-20>ep)   &&( fabs(p2-20)>ep))) {printf(" Neispravan broj bodova");return 0; }
    printf(" Prisustvo:"); scanf("%lf",&pp);if (( (pp-0<ep) &&(fabs(pp-0)>ep)) || ((pp-10>ep)&&(fabs(pp-10)>ep))) {printf(" Neispravan broj bodova");return 0; } 
    printf(" Zadace:");scanf("%lf",&z); if ((((z-0<ep )&&(fabs(z-0)>ep)) || ( (z-10>ep) && (fabs(z-10)>ep)))){printf(" Neispravan broj bodova");return 0; } 
    printf(" Zavrsni ispit: ");scanf("%lf",&zi);if (    (  ( zi-0<ep )  &&  ( fabs(zi-0)>ep)) ||(( zi-40>ep) &&(fabs(zi-40)>ep)))    {printf(" Neispravan broj bodova");return 0; }

       bodoviM=p1+p2+pp+z+zi;
   if(  (  (bodoviM>55)|| (fabs(bodoviM-55)>ep))     &&   (bodoviM<65 ) ) {ocjenaM=6;}
 else   if(  (  (bodoviM>65)|| (fabs(bodoviM-65)>ep))      &&  (bodoviM<75 )  ) {ocjenaM=7;}
  else  if(  (  (bodoviM>75)|| (fabs(bodoviM-75)>ep))    &&   (bodoviM<85 ) ) {ocjenaM=8;}
  else  if(  (  (bodoviM>85)|| (fabs(bodoviM-85)>ep)  )   &&   (bodoviM<92 ) ) {ocjenaM=9;}
  else  if(  (  (bodoviM>92)|| (fabs(bodoviM-92)>ep) )    && (fabs(bodoviM-100)<ep)) {ocjenaM=10;}
    

   
   
   if( (bodoviT<55) &&  (bodoviB<55) && (bodoviM<55)  ) {printf("Nijedan student nije polozio.");
   return 0;
   }
   brojac_polozili=0;
   if (   (bodoviT>55)|| (fabs(bodoviT-55)<ep))   brojac_polozili++;
   if (   (bodoviB>55) || (fabs(bodoviB-55)<ep))  brojac_polozili++;
   if (   (bodoviM>55) || (fabs(bodoviM-55)<ep))  brojac_polozili++;
   
 
 
  if(brojac_polozili==1){printf("Jedan student je polozio.");return 0;}
 else if(brojac_polozili==2){printf("Dva studenta su polozila.");return 0;}
 else if(brojac_polozili==3) { printf("Sva tri studenta su polozila.");
 
 
 
 if(( ocjenaB != ocjenaM) &&   ( ocjenaB != ocjenaT)    &&( ocjenaT != ocjenaM)){ printf("\nSvaki student ima razlicitu ocjenu.");return 0;}   
 
else if(((ocjenaB == ocjenaT) &&( ocjenaB != ocjenaM))|| ((ocjenaB == ocjenaM) &&( ocjenaB != ocjenaT))||((ocjenaM == ocjenaT) &&( ocjenaM != ocjenaB)))  printf("\nDva od tri studenta imaju istu ocjenu.");    
 
else printf("\nSva tri studenta imaju istu ocjenu.");  

  return 0;

 }

    

 
    
   
   
       
   return 0;
}
