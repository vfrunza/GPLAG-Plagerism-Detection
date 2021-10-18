#include <stdio.h>

int main() {
	  double P1T,P2T,PRT,ZT,ZIT,P1B,P2B,PRB,ZB,ZIB,P1M,P2M,PRM,ZM,ZIM,Tarik,Bojan,Mirza;
	  double ocTarik,ocMirza,ocBojan;
	  printf("Unesite bodove za Tarika: ");
	  printf("\n");
	
	  printf("I parcijalni ispit: ");
	  scanf("%lf", &P1T);
  	if(P1T<0 || P1T>20){
	     printf("Neispravan broj bodova");
	     return 0;
    }
    
   printf("II parcijalni ispit: ");
   scanf("%lf" ,&P2T);
   if(P2T<0 || P2T>20 ){
    	 printf("Neispravan broj bodova");
     	return 0;
    }
    
   printf("Prisustvo: ");
   scanf("%lf", &PRT);
   if(PRT<0 || PRT>10){
     	printf("Neispravan broj bodova");
     	return 0;
    }   
    
   printf("Zadace: ");
   scanf("%lf", &ZT);
   if(ZT<0 || ZT>10) {
     	printf("Neispravan broj bodova");
     	return 0;
    } 
    
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIT);
   if(ZIT<0 || ZIT>40) {
     	printf("Neispravan broj bodova");
     	return 0;
    }  
    
    Tarik=P1T+P2T+PRT+ZT+ZIT;
    
   printf("Unesite bodove za Bojana: ");
   printf("\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P1B);
   if(P1B<0 || P1B>20) {
     	printf("Neispravan broj bodova");
     	return 0;
    }
    
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2B);
   if (P2B<0 || P2B>20) {
     	printf("Neispravan broj bodova");
     	return 0;
    }
    
   printf("Prisustvo: ");
   scanf("%lf", &PRB);
   if (PRB<0 || PRB>10) {
     	printf("Neispravan broj bodova");
     	return 0;
    }
    
   printf("Zadace: ");
   scanf("%lf", &ZB);
   if (ZB<0 || ZB>10) {
     	printf("Neispravan broj bodova");
     	return 0;
    }
    
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIB);
   if (ZIB<0 || ZIB>40) {
  	    printf("Neispravan broj bodova");
  	    return 0;
    }  
    
    Bojan=P1B+P2B+PRB+ZB+ZIB;
    
   printf("Unesite bodove za Mirzu: ");
   printf("\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P1M);
   if (P1M<0 || P1M>20) {
       printf("Neispravan broj bodova");
   	   return 0;
    }
    
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2M);
   if (P2M<0 || P2M>20) {
      	printf("Neispravan broj bodova");
      	return 0;
    }
    
   printf("Prisustvo: ");
   scanf("%lf", &PRM);
   if (PRM<0 || PRM>10) {
      	printf("Neispravan broj bodova");
      	return 0;
    }
    
   printf("Zadace: ");
   scanf("%lf", &ZM);
   if (ZM<0 || ZM>10) {
      	printf("Neispravan broj bodova");
      	return 0;
    }
    
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIM);
   if (ZIM<0 || ZIM>40) {
      	printf("Neispravan broj bodova");
      	return 0;
    }
    
    Mirza=P1M+P2M+PRM+ZM+ZIM;
    ocTarik=Tarik;
    ocBojan=Bojan;
    ocMirza=Mirza;
   if (ocTarik<55 && ocBojan<55 && ocMirza<55) {
     	printf("Nijedan student nije polozio.");printf("\n");
     	return 0;
    }
    
   else if((ocTarik>=55 && ocBojan<55 && ocMirza<55) || (ocTarik<55 && ocBojan>=55 && ocMirza<55) || (ocTarik<55 && ocBojan<55 && ocMirza>=55)) {
     	printf("Jedan student je polozio.");printf("\n");
     	return 0;
    } 
    
   else if((ocTarik>=55 && ocBojan>=55 && ocMirza<55) || (ocTarik>=55 && ocBojan<55 && ocMirza>=55) || (ocTarik<55 && ocBojan>=55 && ocMirza>=55)) {
     	printf("Dva studenta su polozila.");printf("\n");
     	return 0;
    }
    
   else if(ocTarik>=55 && ocBojan>=55 && ocMirza>=55) {
     	printf("Sva tri studenta su polozila.");printf("\n");
    }  
    
   if ((ocTarik>=55 && ocTarik<65) && (ocBojan>=55 && ocBojan<65) && (ocMirza>=55 && ocMirza<65)) {
    	 printf("Sva tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((ocTarik>=65 && ocTarik<75) && (ocBojan>=65 && ocBojan<75) && (ocMirza>=65 && ocMirza<75)) {
     	printf("Sva tri studenta imaju istu ocjenu.");printf("\n");
    }  
    
   else if((ocTarik>=75 && ocTarik<85) && (ocBojan>=75 && ocBojan<85) && (ocMirza>=75 && ocMirza<85)) {
     	printf("Sva tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((ocTarik>=85 && ocTarik<92) && (ocBojan>=85 && ocBojan<92) && (ocMirza>=85 && ocMirza<92)) {
     	printf("Sva tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((ocTarik>=92 && ocTarik<=100) && (ocBojan>=92 && ocBojan<=100) && (ocMirza>=92 && ocMirza<=100)) {
     	printf("Sva tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((ocTarik>=55 && ocTarik<65) && (ocBojan>=55 && ocBojan<65) && (ocMirza>=65)) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    } 
    
   else if((ocTarik>=65 && ocTarik<75) && (ocBojan>=65 && ocBojan<75) && ((ocMirza>=55) && (ocMirza<65) || (ocMirza>=75))) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((ocTarik>=75 && ocTarik<85) && (ocBojan>=75 && ocBojan<85) && ((ocMirza>=55) && (ocMirza<75) || (ocMirza>=85))) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((ocTarik>=85 && ocTarik<92) && (ocBojan>=85 && ocBojan<92) && ((ocMirza>=55) && (ocMirza<85) || (ocMirza>=92))) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    } 
    
   else if((ocTarik>=92 && ocTarik<=100) && (ocBojan>=92 && ocBojan<=100) && (ocMirza<92)) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((ocTarik>=65) && (ocBojan>=55 && ocBojan<65) && (ocMirza>=55) && (ocMirza<65)) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if(((ocTarik>=55) && (ocTarik<65) || (ocTarik>=75)) && (ocBojan>=65 && ocBojan<75) && (Mirza>=65) && (Mirza<75)) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if(((Tarik>=55) && (Tarik<75) || (Tarik>=85)) && (Bojan>=75 && Bojan<85) && (Mirza>=75) && (Mirza<85)) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if(((Tarik>=55) && (Tarik<85) || (Tarik>=92)) && (Bojan>=85 && Bojan<92) && (Mirza>=85) && (Mirza<92)) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((Tarik<92) && (Bojan>=92 && Bojan<=100) && (Mirza>=92) && (Mirza<=100)) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((Tarik>=55) && (Tarik<65) && (Bojan>=65) && (Mirza>=55) && (Mirza<65)) {
      printf("Dva od tri studenta imaju istu ocjenu.");printf("\n");
    }
    
   else if((Tarik>=65) && (Tarik<75) && ((Bojan<65) || (Bojan>=75)) && (Mirza>=65) && (Mirza<75)) {
      printf("Dva od tri studenta imaju istu ocjenu.");
      printf("\n");
     }
     
   else if((Tarik>=75) && (Tarik<85) && ((Bojan<75) || (Bojan>=85)) && (Mirza>=75) && (Mirza<85)) {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
    }
    
   else if((Tarik>=85) && (Tarik<92) && ((Bojan<85) || (Bojan>=92)) && (Mirza>=85) && (Mirza<92)) {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
    }
    
   else if((Tarik>=92) && (Tarik<=100) && (Bojan<92) && (Mirza>=92) && (Mirza<=100)) {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
    }
    
   else {
      printf("Svaki student ima razlicitu ocjenu.\n");
    }
    return 0;
}
